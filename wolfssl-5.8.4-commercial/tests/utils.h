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

#if !defined(NO_FILESYSTEM) && !defined(NO_CERTS) && \
    (!defined(NO_RSA) || defined(HAVE_RPK)) && \
    !defined(NO_WOLFSSL_SERVER) && !defined(NO_WOLFSSL_CLIENT) && \
    (!defined(WOLFSSL_NO_TLS12) || defined(WOLFSSL_TLS13))
#define HAVE_MANUAL_MEMIO_TESTS_DEPENDENCIES
#define TEST_MEMIO_BUF_SZ (64 * 1024)
#define TEST_MEMIO_MAX_MSGS 32

struct test_memio_ctx
{
    byte c_buff[TEST_MEMIO_BUF_SZ];
    int c_len;
    const char* c_ciphers;
    byte s_buff[TEST_MEMIO_BUF_SZ];
    int s_len;
    const char* s_ciphers;

    int c_force_want_write;
    int s_force_want_write;

    int c_msg_sizes[TEST_MEMIO_MAX_MSGS];
    int c_msg_count;
    int c_msg_pos;

    int s_msg_sizes[TEST_MEMIO_MAX_MSGS];
    int s_msg_count;
    int s_msg_pos;
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
void test_memio_simulate_want_write(struct test_memio_ctx *ctx, int is_client,
        int enable);
void test_memio_clear_buffer(struct test_memio_ctx *ctx, int is_client);
int test_memio_inject_message(struct test_memio_ctx *ctx, int client, const char *data, int sz);
int test_memio_copy_message(const struct test_memio_ctx *ctx, int client,
        char *out, int *out_sz, int msg_pos);
int test_memio_get_message(const struct test_memio_ctx *ctx, int client,
        const char **out, int *out_sz, int msg_pos);
int test_memio_move_message(struct test_memio_ctx *ctx, int client,
        int msg_pos_in, int msg_pos_out);
int test_memio_drop_message(struct test_memio_ctx *ctx, int client, int msg_pos);
int test_memio_modify_message_len(struct test_memio_ctx *ctx, int client, int msg_pos, int new_len);
int test_memio_remove_from_buffer(struct test_memio_ctx *ctx, int client, int off, int sz);
#endif

#endif /* TESTS_UTILS_H */
