/* sha512.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef CTAO_CRYPT_SHA512_H
#define CTAO_CRYPT_SHA512_H

#include <wolfssl/wolfcrypt/sha512.h>
#define InitSha512   wc_InitSha512
#define Sha512Update wc_Sha512Update
#define Sha512Final  wc_Sha512Final
#define Sha512Hash   wc_Sha512Hash

#if defined(WOLFSSL_SHA384) || defined(HAVE_AESGCM)
    #define InitSha384   wc_InitSha384
    #define Sha384Update wc_Sha384Update
    #define Sha384Final  wc_Sha384Final
    #define Sha384Hash   wc_Sha384Hash
#endif /* WOLFSSL_SHA384 */

#endif /* CTAO_CRYPT_SHA512_H */

