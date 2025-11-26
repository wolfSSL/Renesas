/* test_ossl_sk.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SSL_SK_H
#define WOLFCRYPT_TEST_SSL_SK_H

#include <tests/api/api_decl.h>

int test_wolfSSL_sk_new_free_node(void);
int test_wolfSSL_sk_push_get_node(void);
int test_wolfSSL_sk_free(void);
int test_wolfSSL_sk_push_pop(void);
int test_wolfSSL_sk_insert(void);
int test_wolfSSL_shallow_sk_dup(void);
int test_wolfSSL_sk_num(void);
int test_wolfSSL_sk_value(void);
int test_wolfssl_sk_GENERIC(void);
int test_wolfssl_sk_SSL_COMP(void);
int test_wolfSSL_sk_CIPHER(void);
int test_wolfssl_sk_WOLFSSL_STRING(void);
int test_wolfssl_lh_retrieve(void);

#define TEST_SSL_SK_DECLS                                       \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_new_free_node),  \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_push_get_node),  \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_free),           \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_push_pop),       \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_insert),         \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_shallow_sk_dup),    \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_num),            \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_value),          \
    TEST_DECL_GROUP("ossl_sk", test_wolfssl_sk_GENERIC),        \
    TEST_DECL_GROUP("ossl_sk", test_wolfssl_sk_SSL_COMP),       \
    TEST_DECL_GROUP("ossl_sk", test_wolfSSL_sk_CIPHER),         \
    TEST_DECL_GROUP("ossl_sk", test_wolfssl_sk_WOLFSSL_STRING), \
    TEST_DECL_GROUP("ossl_sk", test_wolfssl_lh_retrieve)

#endif /* WOLFCRYPT_TEST_SSL_SK_H */

