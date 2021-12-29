/* buffer.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFSSL_BUFFER_H_
#define WOLFSSL_BUFFER_H_

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/openssl/ssl.h>

#ifdef __cplusplus
    extern "C" {
#endif


WOLFSSL_API WOLFSSL_BUF_MEM* wolfSSL_BUF_MEM_new(void);
WOLFSSL_API int wolfSSL_BUF_MEM_grow(WOLFSSL_BUF_MEM* buf, size_t len);
WOLFSSL_API void wolfSSL_BUF_MEM_free(WOLFSSL_BUF_MEM* buf);
WOLFSSL_API size_t wolfSSL_strlcpy(char *dst, const char *src, size_t dstSize);
WOLFSSL_API size_t wolfSSL_strlcat(char *dst, const char *src, size_t dstSize);


#define BUF_MEM_new  wolfSSL_BUF_MEM_new
#define BUF_MEM_grow wolfSSL_BUF_MEM_grow
#define BUF_MEM_free wolfSSL_BUF_MEM_free

#define BUF_strdup strdup
#define BUF_strlcpy wolfSSL_strlcpy
#define BUF_strlcat wolfSSL_strlcat

#ifdef __cplusplus
    }  /* extern "C" */
#endif

#endif /* WOLFSSL_BUFFER_H_ */
