/* wolfcaam_hmac.c
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

#if defined(WOLFSSL_CAAM) && !defined(NO_HMAC) && defined(WOLFSSL_CAAM_HMAC)

#include <wolfssl/wolfcrypt/logging.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

#ifdef NO_INLINE
    #include <wolfssl/wolfcrypt/misc.h>
#else
    #define WOLFSSL_MISC_INCLUDED
    #include <wolfcrypt/src/misc.c>
#endif

#include <wolfssl/wolfcrypt/port/caam/wolfcaam.h>
#include <wolfssl/wolfcrypt/coding.h>
#include <wolfssl/wolfcrypt/asn.h>

#if defined(WOLFSSL_CAAM_DEBUG) || defined(WOLFSSL_CAAM_PRINT)
#include <stdio.h>
#endif

#if defined(WOLFSSL_DEVCRYPTO_HMAC)
#include <wolfssl/wolfcrypt/port/devcrypto/wc_devcrypto.h>

/* HSM lib does not support HMAC with QXP board, use devcrypto instead */
int wc_CAAM_Hmac(Hmac* hmac, int macType, const byte* msg, int msgSz,
    byte* digest)
{
    int ret = 0;

    if (hmac->ctx.cfd == -1 && hmac->keyLen > 0) {
        ret = wc_DevCrypto_HmacSetKey(hmac, macType, hmac->keyRaw,
                    hmac->keyLen);
        if (ret != 0) {
            WOLFSSL_MSG("Error with set key");
            if (ret == HASH_TYPE_E) {
                ret = CRYPTOCB_UNAVAILABLE; /* that hash type is not supported*/
            }
        }
    }

    if (ret == 0 && msgSz > 0) {
        ret = wc_DevCrypto_HmacUpdate(hmac, msg, msgSz);
        if (ret != 0) {
            WOLFSSL_MSG("Issue with hmac update");
        }
    }

    if (ret == 0 && digest != NULL) {
        ret = wc_DevCrypto_HmacFinal(hmac, digest);
        if (ret != 0) {
            WOLFSSL_MSG("Issue with hmac final");
        }
        else {
            wc_DevCrypto_HmacFree(hmac);
        }
    }
    return ret;
}
#else
int wc_CAAM_Hmac(Hmac* hmac, int macType, const byte* msg, int msgSz,
    byte* digest)
{
    (void)hmac;
    (void)macType;
    (void)msg;
    (void)msgSz;
    (void)digest;
    return CRYPTOCB_UNAVAILABLE;
}
#endif /* WOLFSSL_DEVCRYPTO_HMAC */

#endif

