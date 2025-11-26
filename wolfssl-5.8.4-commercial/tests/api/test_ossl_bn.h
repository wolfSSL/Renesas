/* test_ossl_bn.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_BN_H
#define WOLFCRYPT_TEST_OSSL_BN_H

#include <tests/api/api_decl.h>

int test_wolfSSL_BN_CTX(void);
int test_wolfSSL_BN(void);
int test_wolfSSL_BN_init(void);
int test_wolfSSL_BN_enc_dec(void);
int test_wolfSSL_BN_word(void);
int test_wolfSSL_BN_bits(void);
int test_wolfSSL_BN_shift(void);
int test_wolfSSL_BN_math(void);
int test_wolfSSL_BN_math_mod(void);
int test_wolfSSL_BN_math_other(void);
int test_wolfSSL_BN_rand(void);
int test_wolfSSL_BN_prime(void);

#define TEST_OSSL_ASN1_BN_DECLS                             \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_CTX),        \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN),            \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_init),       \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_enc_dec),    \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_word),       \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_bits),       \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_shift),      \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_math),       \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_math_mod),   \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_math_other), \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_rand),       \
    TEST_DECL_GROUP("ossl_bn", test_wolfSSL_BN_prime)

#endif /* WOLFCRYPT_TEST_OSSL_BN_H */
