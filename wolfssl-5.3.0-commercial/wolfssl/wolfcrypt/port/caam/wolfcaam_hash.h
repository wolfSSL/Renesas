/* wolfcaam_hash.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfssl/wolfcrypt/settings.h>

#ifndef WOLFCAAM_HASH_H
#define WOLFCAAM_HASH_H

#include <wolfssl/wolfcrypt/sha256.h>

WOLFSSL_LOCAL int wc_CAAM_ShaHash(wc_Sha* sha, const byte* in, word32 inSz,
    byte* digest);
#ifdef WOLFSSL_SHA224
WOLFSSL_LOCAL int wc_CAAM_Sha224Hash(wc_Sha224* sha224, const byte* in,
    word32 inSz, byte* digest);
#endif
WOLFSSL_LOCAL int wc_CAAM_Sha256Hash(wc_Sha256* sha256, const byte* in,
    word32 inSz, byte* digest);
WOLFSSL_LOCAL int wc_CAAM_Sha384Hash(wc_Sha384* sha384, const byte* in,
    word32 inSz, byte* digest);
WOLFSSL_LOCAL int wc_CAAM_Sha512Hash(wc_Sha512* sha512, const byte* in,
    word32 inSz, byte* digest);


#if !defined(NO_HMAC)
#ifndef WC_HMAC_TYPE_DEFINED
    typedef struct Hmac Hmac;
    #define WC_HMAC_TYPE_DEFINED
#endif
WOLFSSL_LOCAL int wc_CAAM_Hmac(Hmac* hmac, int macType, const byte* msg,
    int msgSz, byte* digest);
#endif

#endif

