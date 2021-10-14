/* compat_types.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*
 * Move types that cause cyclical dependency errors here.
 */

#ifndef WOLFSSL_OPENSSL_COMPAT_TYPES_H_
#define WOLFSSL_OPENSSL_COMPAT_TYPES_H_

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/hmac.h>

typedef struct WOLFSSL_HMAC_CTX {
    Hmac hmac;
    int  type;
    word32  save_ipad[WC_HMAC_BLOCK_SIZE  / sizeof(word32)];  /* same block size all*/
    word32  save_opad[WC_HMAC_BLOCK_SIZE  / sizeof(word32)];
} WOLFSSL_HMAC_CTX;

#endif /* WOLFSSL_OPENSSL_COMPAT_TYPES_H_ */
