/* hmac.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



/*  hmac.h defines mini hmac openssl compatibility layer
 *
 */


#ifndef WOLFSSL_HMAC_H_
#define WOLFSSL_HMAC_H_

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_PREFIX
#include "prefix_hmac.h"
#endif

#include <wolfssl/openssl/compat_types.h>
#include <wolfssl/openssl/opensslv.h>

#ifdef __cplusplus
    extern "C" {
#endif


WOLFSSL_API unsigned char* wolfSSL_HMAC(const WOLFSSL_EVP_MD* evp_md,
                               const void* key, int key_len,
                               const unsigned char* d, size_t n, unsigned char* md,
                               unsigned int* md_len);

WOLFSSL_API WOLFSSL_HMAC_CTX* wolfSSL_HMAC_CTX_new(void);
WOLFSSL_API int wolfSSL_HMAC_CTX_Init(WOLFSSL_HMAC_CTX* ctx);
WOLFSSL_API int wolfSSL_HMAC_CTX_copy(WOLFSSL_HMAC_CTX* des,
                                       WOLFSSL_HMAC_CTX* src);
WOLFSSL_LOCAL int wolfSSL_HmacCopy(Hmac* des, Hmac* src);
WOLFSSL_API int wolfSSL_HMAC_Init(WOLFSSL_HMAC_CTX* ctx, const void* key,
                                 int keylen, const WOLFSSL_EVP_MD* type);
WOLFSSL_API int wolfSSL_HMAC_Init_ex(WOLFSSL_HMAC_CTX* ctx, const void* key,
                             int keylen, const WOLFSSL_EVP_MD* type, WOLFSSL_ENGINE* e);
WOLFSSL_API int wolfSSL_HMAC_Update(WOLFSSL_HMAC_CTX* ctx,
                                   const unsigned char* data, int len);
WOLFSSL_API int wolfSSL_HMAC_Final(WOLFSSL_HMAC_CTX* ctx, unsigned char* hash,
                                  unsigned int* len);
WOLFSSL_API int wolfSSL_HMAC_cleanup(WOLFSSL_HMAC_CTX* ctx);
WOLFSSL_API void wolfSSL_HMAC_CTX_cleanup(WOLFSSL_HMAC_CTX* ctx);
WOLFSSL_API void wolfSSL_HMAC_CTX_free(WOLFSSL_HMAC_CTX* ctx);
WOLFSSL_API size_t wolfSSL_HMAC_size(const WOLFSSL_HMAC_CTX *ctx);
WOLFSSL_API const WOLFSSL_EVP_MD *wolfSSL_HMAC_CTX_get_md(const WOLFSSL_HMAC_CTX *ctx);

#ifndef OPENSSL_COEXIST

typedef struct WOLFSSL_HMAC_CTX HMAC_CTX;

#define HMAC wolfSSL_HMAC

#define HMAC_CTX_new wolfSSL_HMAC_CTX_new
#define HMAC_CTX_init wolfSSL_HMAC_CTX_Init
#define HMAC_CTX_copy wolfSSL_HMAC_CTX_copy
#define HMAC_CTX_free wolfSSL_HMAC_CTX_free
#define HMAC_CTX_cleanup wolfSSL_HMAC_CTX_cleanup
#define HMAC_CTX_reset wolfSSL_HMAC_cleanup
#define HMAC_Init_ex  wolfSSL_HMAC_Init_ex
#define HMAC_Init     wolfSSL_HMAC_Init
#define HMAC_Update   wolfSSL_HMAC_Update
#define HMAC_Final    wolfSSL_HMAC_Final
#define HMAC_cleanup  wolfSSL_HMAC_cleanup
#define HMAC_size     wolfSSL_HMAC_size
#define HMAC_CTX_get_md wolfSSL_HMAC_CTX_get_md

#endif /* !OPENSSL_COEXIST */

#ifdef __cplusplus
    } /* extern "C" */
#endif


#endif /* WOLFSSL_HMAC_H_ */
