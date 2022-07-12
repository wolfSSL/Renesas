/* wolfcaam_x25519.c
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

#if defined(WOLFSSL_CAAM) && defined(HAVE_CURVE25519)

#include <wolfssl/wolfcrypt/logging.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

#ifdef NO_INLINE
    #include <wolfssl/wolfcrypt/misc.h>
#else
    #define WOLFSSL_MISC_INCLUDED
    #include <wolfcrypt/src/misc.c>
#endif

#include <wolfssl/wolfcrypt/port/caam/wolfcaam.h>
#include <wolfssl/wolfcrypt/port/caam/wolfcaam_x25519.h>

#if defined(WOLFSSL_CAAM_DEBUG) || defined(WOLFSSL_CAAM_PRINT)
#include <stdio.h>
#endif

#if defined(WOLFSSL_DEVCRYPTO_CURVE25519)
#include <wolfssl/wolfcrypt/port/devcrypto/wc_devcrypto.h>

/* HSM lib does not support Curve25519 with QXP board, use devcrypto instead */
static int wc_CAAM_Curve25519Generic(byte* out, word32 outSz, const byte* k,
    word32 kSz, const byte* a, word32 aSz, int endian)
{
    return wc_DevCryptoCurve25519(out, outSz, k, kSz, a, aSz, endian);
}


int wc_CAAM_MakeCurve25519Key(curve25519_key* key, int keySize, WC_RNG* rng)
{
    int ret = 0;

    if (keySize != CURVE25519_KEYSIZE || rng == NULL || key == NULL) {
        ret = BAD_FUNC_ARG;
    }

    if (ret == 0) {
        ret = wc_curve25519_make_priv(rng, keySize, key->k);
    }

    /* create public key from private key */
    if (ret == 0) {
        static const unsigned char basePoint[CURVE25519_KEYSIZE] = {9};
        word32 outlen = (word32)keySize;

        key->privSet = 1;
        ret = wc_CAAM_Curve25519Generic(key->p.point, outlen, key->k,
            CURVE25519_KEYSIZE, basePoint, CURVE25519_KEYSIZE,
            EC25519_LITTLE_ENDIAN);
        if (ret == 0) {
            key->pubSet = 1;
        }
    }

    return ret;
}


int wc_CAAM_Curve25519(byte* out, word32* outlen, curve25519_key* k,
    curve25519_key* pubKey, int endian)
{
    int ret = 0;

    if (*outlen < CURVE25519_KEYSIZE) {
        ret = BAD_FUNC_ARG;
    }

    if (ret == 0) {
        *outlen = CURVE25519_KEYSIZE;
        ret = wc_CAAM_Curve25519Generic(out, *outlen, k->k, CURVE25519_KEYSIZE,
            pubKey->p.point, CURVE25519_KEYSIZE, endian);
    }

    return ret;
}

#else

int wc_CAAM_MakeCurve25519Key(curve25519_key* key, int keySize, WC_RNG* rng)
{
    (void)keySize;
    (void)key;
    (void)rng;
    return CRYPTOCB_UNAVAILABLE;
}


int wc_CAAM_Curve25519(byte* out, word32* outlen, curve25519_key* k,
    curve25519_key* pubKey, int endian)
{
    (void)out;
    (void)outlen;
    (void)k;
    (void)pubKey;
    (void)endian;
    return CRYPTOCB_UNAVAILABLE;
}
#endif /* WOLFSSL_DEVCRYPTO_CURVE25519 */
#endif

