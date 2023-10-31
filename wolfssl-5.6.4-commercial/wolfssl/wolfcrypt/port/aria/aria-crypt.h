/* aria-crypt.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*!
    \file wolfssl/wolfcrypt/port/aria/aria-crypt.h
*/
/*

DESCRIPTION
This library provides the interfaces to the ARIA cipher implementation for
encrypting and decrypting data.

*/
#ifndef WOLF_CRYPT_ARIA_CRYPT_H
#define WOLF_CRYPT_ARIA_CRYPT_H

#include <wolfssl/wolfcrypt/types.h>

#ifdef __cplusplus
    extern "C" {
#endif

#include "mcapi.h"
#include "mcapi_error.h"

#define ARIA_128_KEY_SIZE 16
#define ARIA_192_KEY_SIZE 24
#define ARIA_256_KEY_SIZE 32

#define ARIA_BLOCK_SIZE 16
#define ARIA_GCM_AUTH_SZ 16

#define WC_ARIA_GCM_GET_CIPHERTEXT_SIZE(x) (x+ARIA_GCM_AUTH_SZ)

typedef struct {
    MC_HSESSION hSession;
    MC_ALGID algo;
    MC_HOBJECT hKey;
    word32 nonce[ARIA_BLOCK_SIZE / sizeof(word32)];
    word32 nonceSz;
} wc_Aria;

WOLFSSL_API int wc_AriaInitCrypt(wc_Aria* aria, MC_ALGID algo);
WOLFSSL_API int wc_AriaFreeCrypt(wc_Aria* aria);
WOLFSSL_API int wc_AriaSetKey(wc_Aria* aria, byte* key);
WOLFSSL_API int wc_AriaGcmSetExtIV(wc_Aria* aria, const byte* iv, word32 ivSz);
WOLFSSL_API int wc_AriaGcmSetIV(wc_Aria* aria, word32 ivSz,
                   const byte* ivFixed, word32 ivFixedSz,
                   WC_RNG* rng);

WOLFSSL_API int wc_AriaEncrypt(wc_Aria *aria, byte* out, byte* in, word32 inSz,
                                    byte* iv, word32 ivSz, byte* aad, word32 aadSz,
                                    byte* authTag, word32 authTagSz);
WOLFSSL_API int wc_AriaDecrypt(wc_Aria *aria, byte* out, byte* in, word32 inSz,
                                    byte* iv, word32 ivSz, byte* aad, word32 aadSz,
                                    byte* authTag, word32 authTagSz);

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_ARIA_CRYPT_H */
