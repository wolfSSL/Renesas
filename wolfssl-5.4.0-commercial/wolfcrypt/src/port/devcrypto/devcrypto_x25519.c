/* devcrypto_x25519.c
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>

#if defined(WOLFSSL_DEVCRYPTO_CURVE25519)

#include <wolfssl/wolfcrypt/error-crypt.h>
#include <wolfssl/wolfcrypt/curve25519.h>
#include <wolfssl/wolfcrypt/logging.h>
#include <wolfssl/wolfcrypt/port/devcrypto/wc_devcrypto.h>

const unsigned char qle[] = {
    0xED, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F
};
const unsigned char a24le[] = {
    0x42, 0xdb, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* mul mod on montgomery curve */
int wc_DevCryptoCurve25519(byte* out, word32 outSz, const byte* k,
    word32 kSz, const byte* a, word32 aSz, int endian)
{
    struct crypt_kop kop;
    int inIdx  = 0;
    int outIdx = 0;
    int ret;
    WC_CRYPTODEV ctx;
    const unsigned char* a24 = a24le;
    const unsigned char* q   = qle;

    ret = wc_DevCryptoCreate(&ctx, CRYPTO_ASYM_MUL_MOD, NULL, 0);
    if (ret == 0) {
        kop.crk_op = CRK_MUL_MOD;
        kop.ses    = ctx.sess.ses;
        kop.crk_flags = 0;
        if (endian == EC25519_LITTLE_ENDIAN) {
            kop.crk_flags = CAAM_MUL_MOD_LE;
        }

        kop.crk_param[inIdx].crp_p     = (byte*)k;
        kop.crk_param[inIdx].crp_nbits = kSz * WOLFSSL_BIT_SIZE;
        inIdx++;

        kop.crk_param[inIdx].crp_p     = (byte*)a;
        kop.crk_param[inIdx].crp_nbits = aSz * WOLFSSL_BIT_SIZE;
        inIdx++;

        kop.crk_param[inIdx].crp_p     = (byte*)q;
        kop.crk_param[inIdx].crp_nbits = CURVE25519_KEYSIZE * WOLFSSL_BIT_SIZE;
        inIdx++;

        kop.crk_param[inIdx].crp_p     = (byte*)a24;
        kop.crk_param[inIdx].crp_nbits = CURVE25519_KEYSIZE * WOLFSSL_BIT_SIZE;
        inIdx++;

        /* add output buffer */
        kop.crk_param[inIdx + outIdx].crp_p     = out;
        kop.crk_param[inIdx + outIdx].crp_nbits = outSz * WOLFSSL_BIT_SIZE;
        outIdx++;

        kop.crk_iparams   = inIdx;
        kop.crk_oparams   = outIdx;

        if (ioctl(ctx.cfd, CIOCKEY, &kop)) {
        #if defined(DEBUG_DEVCRYPTO)
            perror("Error value with Curve25519 operation was ");
        #endif
            WOLFSSL_MSG("Error with call to ioctl");
            ret = WC_DEVCRYPTO_E;
        }
        wc_DevCryptoFree(&ctx);
    }

    return ret;
}
#endif /* WOLFSSL_DEVCRYPTO_CURVE25519 */

