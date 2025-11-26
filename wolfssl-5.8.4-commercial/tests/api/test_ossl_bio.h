/* test_ossl_bio.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_BIO_H
#define WOLFCRYPT_TEST_OSSL_BIO_H

#include <tests/api/api_decl.h>

#ifndef NO_BIO
int test_wolfSSL_BIO_gets(void);
int test_wolfSSL_BIO_puts(void);
int test_wolfSSL_BIO_dump(void);
int test_wolfSSL_BIO_should_retry(void);
int test_wolfSSL_BIO_connect(void);
int test_wolfSSL_BIO_tls(void);
int test_wolfSSL_BIO_datagram(void);
int test_wolfSSL_BIO_s_null(void);
int test_wolfSSL_BIO_accept(void);
int test_wolfSSL_BIO_write(void);
int test_wolfSSL_BIO_printf(void);
int test_wolfSSL_BIO_f_md(void);
int test_wolfSSL_BIO_up_ref(void);
int test_wolfSSL_BIO_reset(void);
int test_wolfSSL_BIO_get_len(void);

#define TEST_OSSL_BIO_DECLS                                       \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_gets),           \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_puts),           \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_dump),           \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_should_retry),   \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_s_null),         \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_write),          \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_printf),         \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_f_md),           \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_up_ref),         \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_reset),          \
    TEST_DECL_GROUP("ossl_bio", test_wolfSSL_BIO_get_len)

#define TEST_OSSL_BIO_TLS_DECLS                                   \
    TEST_DECL_GROUP("ossl_bio_tls", test_wolfSSL_BIO_connect),    \
    TEST_DECL_GROUP("ossl_bio_tls", test_wolfSSL_BIO_accept),     \
    TEST_DECL_GROUP("ossl_bio_tls", test_wolfSSL_BIO_tls),        \
    TEST_DECL_GROUP("ossl_bio_tls", test_wolfSSL_BIO_datagram)

#endif

#endif /* WOLFCRYPT_TEST_OSSL_BIO_H */
