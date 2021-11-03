/* sha256.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */





#ifndef NO_SHA256

#ifndef CTAO_CRYPT_SHA256_H
#define CTAO_CRYPT_SHA256_H

#include <wolfssl/wolfcrypt/sha256.h>
#define InitSha256   wc_InitSha256
#define Sha256Update wc_Sha256Update
#define Sha256Final  wc_Sha256Final
#define Sha256Hash   wc_Sha256Hash

#ifdef WOLFSSL_SHA224
    #define InitSha224   wc_InitSha224
    #define Sha224Update wc_Sha224Update
    #define Sha224Final  wc_Sha224Final
    #define Sha224Hash   wc_Sha224Hash
#endif

#endif /* CTAO_CRYPT_SHA256_H */
#endif /* NO_SHA256 */

