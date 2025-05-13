/* test_mldsa.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_MLDSA_H
#define WOLFCRYPT_TEST_MLDSA_H

#include <tests/api/api_decl.h>

int test_wc_dilithium(void);
int test_wc_dilithium_make_key(void);
int test_wc_dilithium_sign(void);
int test_wc_dilithium_verify(void);
int test_wc_dilithium_sign_vfy(void);
int test_wc_dilithium_check_key(void);
int test_wc_dilithium_public_der_decode(void);
int test_wc_dilithium_der(void);
int test_wc_dilithium_make_key_from_seed(void);
int test_wc_dilithium_sig_kats(void);
int test_wc_dilithium_verify_kats(void);
int test_mldsa_pkcs8(void);
int test_mldsa_pkcs12(void);

#define TEST_MLDSA_DECLS                                            \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium),                    \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_make_key),           \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_sign),               \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_verify),             \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_sign_vfy),           \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_check_key),          \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_public_der_decode),  \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_der),                \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_make_key_from_seed), \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_sig_kats),           \
    TEST_DECL_GROUP("mldsa", test_wc_dilithium_verify_kats),        \
    TEST_DECL_GROUP("mldsa", test_mldsa_pkcs8),                     \
    TEST_DECL_GROUP("mldsa", test_mldsa_pkcs12)

#endif /* WOLFCRYPT_TEST_MLDSA_H */
