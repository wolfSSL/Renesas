/* rc2.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLF_CRYPT_RC2_H
#define WOLF_CRYPT_RC2_H

#include <wolfssl/wolfcrypt/types.h>

#ifdef WC_RC2

#ifdef __cplusplus
    extern "C" {
#endif

enum {
    RC2_MAX_KEY_SIZE = 128, /* max effective key size, octets */
    RC2_BLOCK_SIZE   = 8
};

/* RC2 encryption and decryption */
typedef struct Rc2 {
    ALIGN16 word16 key[RC2_MAX_KEY_SIZE/2];
    ALIGN16 word32 reg[RC2_BLOCK_SIZE / sizeof(word32)];    /* for CBC mode */
    ALIGN16 word32 tmp[RC2_BLOCK_SIZE / sizeof(word32)];    /* same         */
    word32 keylen;      /* key length, octets */
    word32 bits;        /* effective key length, bits */
} Rc2;

WOLFSSL_API int wc_Rc2SetKey(Rc2* rc2, const byte* key, word32 length,
                             const byte* iv, word32 bits);
WOLFSSL_API int wc_Rc2SetIV(Rc2* rc2, const byte* iv);

/* RC2-ECB */
WOLFSSL_API int wc_Rc2EcbEncrypt(Rc2* rc2, byte* out,
                                 const byte* in, word32 sz);
WOLFSSL_API int wc_Rc2EcbDecrypt(Rc2* rc2, byte* out,
                                 const byte* in, word32 sz);

/* RC2-CBC */
WOLFSSL_API int wc_Rc2CbcEncrypt(Rc2* rc2, byte* out,
                                 const byte* in, word32 sz);
WOLFSSL_API int wc_Rc2CbcDecrypt(Rc2* rc2, byte* out,
                                 const byte* in, word32 sz);

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WC_RC2 */
#endif /* WOLF_CRYPT_RC2_H */
