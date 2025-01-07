
/* renesas_tsip_types.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef __RENESAS_TSIP_TYPES_H__
#define __RENESAS_TSIP_TYPES_H__


#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h>

#if (!defined(NO_SHA) || !defined(NO_SHA256)) && \
    !defined(NO_WOLFSSL_RENESAS_TSIP_CRYPT_HASH)
typedef enum {
    TSIP_SHA1 = 0,
    TSIP_SHA256 = 1,
} TSIP_SHA_TYPE;

typedef struct {
    byte*  msg;
    void*  heap;
    word32 used;
    word32 len;
    word32 sha_type;
#if defined(WOLF_CRYPTO_CB)
    word32 flags;
    int devId;
#endif
} wolfssl_TSIP_Hash;

/* RAW hash function APIs are not implemented with TSIP */
#define WOLFSSL_NO_HASH_RAW

#ifndef NO_SHA
typedef wolfssl_TSIP_Hash wc_Sha;
#endif
#ifndef NO_SHA256
typedef wolfssl_TSIP_Hash wc_Sha256;
#endif

#endif /* !NO_SHA || !NO_SHA256 */


typedef enum {
    TSIP_RSA1024 = 1,
    TSIP_RSA2048 = 2,
    TSIP_RSA3072 = 3,
    TSIP_RSA4096 = 4,
    TSIP_ECCP256 = 5,
    TSIP_ECCP384 = 6,
} TSIP_KEY_TYPE;


#if defined(WOLFSSL_RENESAS_TSIP_TLS_AES_CRYPT) || \
    defined(WOLFSSL_RENESAS_TSIP_CRYPTONLY)
#include "r_tsip_rx_if.h"

typedef struct {
    tsip_aes_key_index_t tsip_keyIdx;
    word32               keySize;
    byte                 setup;
} TSIP_AES_CTX;

#endif

#endif /* __RENESAS_TSIP_TYPES_H__ */
