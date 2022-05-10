/* cmac.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_CMAC_H_
#define WOLFSSL_CMAC_H_

#include <wolfssl/wolfcrypt/cmac.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WOLFSSL_CMAC_CTX {
    void* internal; /* internal Cmac object */
    WOLFSSL_EVP_CIPHER_CTX* cctx;
} WOLFSSL_CMAC_CTX;

typedef WOLFSSL_CMAC_CTX CMAC_CTX;

WOLFSSL_API WOLFSSL_CMAC_CTX* wolfSSL_CMAC_CTX_new(void);
WOLFSSL_API void wolfSSL_CMAC_CTX_free(WOLFSSL_CMAC_CTX *ctx);
WOLFSSL_API WOLFSSL_EVP_CIPHER_CTX* wolfSSL_CMAC_CTX_get0_cipher_ctx(
    WOLFSSL_CMAC_CTX* ctx);
WOLFSSL_API int wolfSSL_CMAC_Init(
    WOLFSSL_CMAC_CTX* ctx, const void *key, size_t keyLen,
    const WOLFSSL_EVP_CIPHER* cipher, WOLFSSL_ENGINE* engine);
WOLFSSL_API int wolfSSL_CMAC_Update(
    WOLFSSL_CMAC_CTX* ctx, const void* data, size_t len);
WOLFSSL_API int wolfSSL_CMAC_Final(
    WOLFSSL_CMAC_CTX* ctx, unsigned char* out, size_t* len);

#define CMAC_CTX_new              wolfSSL_CMAC_CTX_new
#define CMAC_CTX_free             wolfSSL_CMAC_CTX_free
#define CMAC_CTX_get0_cipher_ctx  wolfSSL_CMAC_CTX_get0_cipher_ctx
#define CMAC_Init                 wolfSSL_CMAC_Init
#define CMAC_Update               wolfSSL_CMAC_Update
#define CMAC_Final                wolfSSL_CMAC_Final

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* WOLFSSL_CMAC_H_ */
