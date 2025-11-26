/* md4.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*!
    \file wolfssl/wolfcrypt/md4.h
*/

#ifndef WOLF_CRYPT_MD4_H
#define WOLF_CRYPT_MD4_H

#include <wolfssl/wolfcrypt/types.h>

#ifndef NO_MD4

#ifdef __cplusplus
    extern "C" {
#endif

/* in bytes */
enum {
    WC_MD4_BLOCK_SIZE  = 64,
    WC_MD4_DIGEST_SIZE = 16,
    WC_MD4_PAD_SIZE    = 56
};

/* MD4 digest */
typedef struct wc_Md4 {
    word32  buffLen;   /* in bytes          */
    word32  loLen;     /* length in bytes   */
    word32  hiLen;     /* length in bytes   */
    word32  digest[WC_MD4_DIGEST_SIZE / sizeof(word32)];
    word32  buffer[WC_MD4_BLOCK_SIZE  / sizeof(word32)];
} wc_Md4;

WOLFSSL_API void wc_InitMd4(wc_Md4* md4);
WOLFSSL_API void wc_Md4Update(wc_Md4* md4, const byte* data, word32 len);
WOLFSSL_API void wc_Md4Final(wc_Md4* md4, byte* hash);

#ifndef OPENSSL_COEXIST

enum {
    MD4             = WC_HASH_TYPE_MD4,
    MD4_BLOCK_SIZE  = WC_MD4_BLOCK_SIZE,
    MD4_DIGEST_SIZE = WC_MD4_DIGEST_SIZE,
    MD4_PAD_SIZE    = WC_MD4_PAD_SIZE
};

typedef struct wc_Md4 Md4;

#endif /* !OPENSSL_COEXIST */


#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* NO_MD4 */
#endif /* WOLF_CRYPT_MD4_H */

