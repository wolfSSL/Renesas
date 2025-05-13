/* test_sm2.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SM2_H
#define WOLFCRYPT_TEST_SM2_H

#include <tests/api/api_decl.h>

int test_wc_ecc_sm2_make_key(void);
int test_wc_ecc_sm2_shared_secret(void);
int test_wc_ecc_sm2_create_digest(void);
int test_wc_ecc_sm2_verify_hash_ex(void);
int test_wc_ecc_sm2_verify_hash(void);
int test_wc_ecc_sm2_sign_hash_ex(void);
int test_wc_ecc_sm2_sign_hash(void);

#define TEST_SM2_DECLS                                          \
    TEST_DECL_GROUP("sm2", test_wc_ecc_sm2_make_key),           \
    TEST_DECL_GROUP("sm2", test_wc_ecc_sm2_shared_secret),      \
    TEST_DECL_GROUP("sm2", test_wc_ecc_sm2_create_digest),      \
    TEST_DECL_GROUP("sm2", test_wc_ecc_sm2_verify_hash_ex),     \
    TEST_DECL_GROUP("sm2", test_wc_ecc_sm2_verify_hash),        \
    TEST_DECL_GROUP("sm2", test_wc_ecc_sm2_sign_hash_ex),       \
    TEST_DECL_GROUP("sm2", test_wc_ecc_sm2_sign_hash)

#endif /* WOLFCRYPT_TEST_SM2_H */
