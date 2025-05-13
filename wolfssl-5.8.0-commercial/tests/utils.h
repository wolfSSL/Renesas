/* utils.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/ssl.h>
#include <wolfssl/test.h>

#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#if !defined(NO_FILESYSTEM) && !defined(NO_CERTS) && !defined(NO_RSA) && \
    !defined(NO_WOLFSSL_SERVER) && !defined(NO_WOLFSSL_CLIENT) && \
    (!defined(WOLFSSL_NO_TLS12) || defined(WOLFSSL_TLS13))
#define HAVE_MANUAL_MEMIO_TESTS_DEPENDENCIES
#define TEST_MEMIO_BUF_SZ (64 * 1024)
struct test_memio_ctx
{
    byte c_buff[TEST_MEMIO_BUF_SZ];
    int c_len;
    const char* c_ciphers;
    byte s_buff[TEST_MEMIO_BUF_SZ];
    int s_len;
    const char* s_ciphers;
};
int test_memio_write_cb(WOLFSSL *ssl, char *data, int sz, void *ctx);
int test_memio_read_cb(WOLFSSL *ssl, char *data, int sz, void *ctx);
int test_memio_do_handshake(WOLFSSL *ssl_c, WOLFSSL *ssl_s,
    int max_rounds, int *rounds);
int test_memio_setup(struct test_memio_ctx *ctx,
    WOLFSSL_CTX **ctx_c, WOLFSSL_CTX **ctx_s, WOLFSSL **ssl_c, WOLFSSL **ssl_s,
    method_provider method_c, method_provider method_s);
int test_memio_setup_ex(struct test_memio_ctx *ctx,
    WOLFSSL_CTX **ctx_c, WOLFSSL_CTX **ctx_s, WOLFSSL **ssl_c, WOLFSSL **ssl_s,
    method_provider method_c, method_provider method_s,
    byte *caCert, int caCertSz, byte *serverCert, int serverCertSz,
    byte *serverKey, int serverKeySz);
#endif

#endif /* TESTS_UTILS_H */
