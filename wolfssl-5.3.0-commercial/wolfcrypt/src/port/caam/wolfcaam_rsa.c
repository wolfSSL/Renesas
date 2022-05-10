/* wolfcaam_rsa.c
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

#if defined(WOLFSSL_CAAM) && !defined(NO_RSA)

#include <wolfssl/wolfcrypt/logging.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

#ifdef NO_INLINE
    #include <wolfssl/wolfcrypt/misc.h>
#else
    #define WOLFSSL_MISC_INCLUDED
    #include <wolfcrypt/src/misc.c>
#endif

#include <wolfssl/wolfcrypt/port/caam/wolfcaam.h>
#include <wolfssl/wolfcrypt/port/caam/wolfcaam_rsa.h>

#if defined(WOLFSSL_CAAM_DEBUG) || defined(WOLFSSL_CAAM_PRINT)
#include <stdio.h>
#endif

#if defined(WOLFSSL_DEVCRYPTO_RSA)
#include <wolfssl/wolfcrypt/port/devcrypto/wc_devcrypto.h>

/* HSM lib does not support RSA with QXP board, use devcrypto instead */
int wc_CAAM_Rsa(const byte* in, word32 inLen, byte* out, word32* outLen,
    int type, RsaKey* key, WC_RNG* rng)
{
    int ret = -1;

    switch (type) {
        case RSA_PUBLIC_ENCRYPT:
        case RSA_PRIVATE_ENCRYPT:
            ret = wc_DevCrypto_RsaEncrypt(in, inLen, out, outLen, key, type);
            break;

        case RSA_PUBLIC_DECRYPT:
        case RSA_PRIVATE_DECRYPT:
            ret = wc_DevCrypto_RsaDecrypt(in, inLen, out, *outLen, key, type);
    }
    (void)rng;

    return ret;
}

#ifdef WOLFSSL_KEY_GEN
int wc_CAAM_MakeRsaKey(RsaKey* key, int size, long e, WC_RNG* rng)
{
    return wc_DevCrypto_MakeRsaKey(key, size, e, rng);
}
#endif

#else
int wc_CAAM_Rsa(const byte* in, word32 inLen, byte* out, word32* outLen,
    int type, RsaKey* key, WC_RNG* rng)
{
    (void)in;
    (void)inLen;
    (void)out;
    (void)outLen;
    (void)type;
    (void)key;
    (void)rng;
    return CRYPTOCB_UNAVAILABLE;
}

#ifdef WOLFSSL_KEY_GEN
int wc_CAAM_MakeRsaKey(RsaKey* key, int size, long e, WC_RNG* rng)
{
    (void)size;
    (void)e;
    (void)key;
    (void)rng;
    return CRYPTOCB_UNAVAILABLE;
}
#endif
#endif /* WOLFSSL_DEVCRYPTO_RSA */

#endif


