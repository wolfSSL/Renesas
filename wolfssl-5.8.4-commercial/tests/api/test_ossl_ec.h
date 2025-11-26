/* test_ossl_ec.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_EC_H
#define WOLFCRYPT_TEST_OSSL_EC_H

#include <tests/api/api_decl.h>

#if defined(HAVE_ECC) && !defined(OPENSSL_NO_PK)

int test_wolfSSL_EC_GROUP(void);
int test_wolfSSL_PEM_read_bio_ECPKParameters(void);
int test_wolfSSL_i2d_ECPKParameters(void);
int test_wolfSSL_EC_POINT(void);
int test_wolfSSL_SPAKE(void);
int test_wolfSSL_EC_KEY_generate(void);
int test_EC_i2d(void);
int test_wolfSSL_EC_curve(void);
int test_wolfSSL_EC_KEY_dup(void);
int test_wolfSSL_EC_KEY_set_group(void);
int test_wolfSSL_EC_KEY_set_conv_form(void);
int test_wolfSSL_EC_KEY_private_key(void);
int test_wolfSSL_EC_KEY_public_key(void);
int test_wolfSSL_EC_KEY_print_fp(void);
int test_wolfSSL_EC_get_builtin_curves(void);
int test_wolfSSL_ECDSA_SIG(void);
int test_ECDSA_size_sign(void);
int test_ECDH_compute_key(void);


#define TEST_OSSL_EC_DECLS                                                  \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_GROUP),                      \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_PEM_read_bio_ECPKParameters),   \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_i2d_ECPKParameters),            \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_POINT),                      \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_SPAKE),                         \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_KEY_generate),               \
    TEST_DECL_GROUP("ossl_ec", test_EC_i2d),                                \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_curve),                      \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_KEY_dup),                    \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_KEY_set_group),              \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_KEY_set_conv_form),          \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_KEY_private_key),            \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_KEY_public_key),             \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_KEY_print_fp),               \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_EC_get_builtin_curves),         \
    TEST_DECL_GROUP("ossl_ec", test_wolfSSL_ECDSA_SIG),                     \
    TEST_DECL_GROUP("ossl_ec", test_ECDSA_size_sign),                       \
    TEST_DECL_GROUP("ossl_ec", test_ECDH_compute_key)

#endif

#endif /* WOLFCRYPT_TEST_OSSL_EC_H */

