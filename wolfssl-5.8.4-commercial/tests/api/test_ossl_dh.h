/* test_ossl_dh.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_DH_H
#define WOLFCRYPT_TEST_OSSL_DH_H

#include <tests/api/api_decl.h>

int test_wolfSSL_DH(void);
int test_wolfSSL_DH_dup(void);
int test_wolfSSL_DH_check(void);
int test_wolfSSL_DH_prime(void);
int test_wolfSSL_DH_1536_prime(void);
int test_wolfSSL_DH_get_2048_256(void);
int test_wolfSSL_PEM_read_DHparams(void);
int test_wolfSSL_PEM_write_DHparams(void);
int test_wolfSSL_d2i_DHparams(void);
int test_wolfSSL_DH_LoadDer(void);
int test_wolfSSL_i2d_DHparams(void);

#define TEST_OSSL_DH_DECLS                                          \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_DH),                    \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_DH_dup),                \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_DH_check),              \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_DH_prime),              \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_DH_1536_prime),         \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_DH_get_2048_256),       \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_PEM_read_DHparams),     \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_PEM_write_DHparams),    \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_d2i_DHparams),          \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_DH_LoadDer),            \
    TEST_DECL_GROUP("ossl_dh", test_wolfSSL_i2d_DHparams)

#endif /* WOLFCRYPT_TEST_OSSL_DH_H */

