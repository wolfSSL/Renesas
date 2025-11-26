/* test_blake2.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_BLAKE2_H
#define WOLFCRYPT_TEST_BLAKE2_H

#include <tests/api/api_decl.h>

int test_wc_InitBlake2b(void);
int test_wc_InitBlake2b_WithKey(void);
int test_wc_Blake2bUpdate(void);
int test_wc_Blake2bFinal(void);
int test_wc_Blake2b_KATs(void);
int test_wc_Blake2b_other(void);

int test_wc_InitBlake2s(void);
int test_wc_InitBlake2s_WithKey(void);
int test_wc_Blake2sUpdate(void);
int test_wc_Blake2sFinal(void);
int test_wc_Blake2s_KATs(void);
int test_wc_Blake2s_other(void);

#define TEST_BLAKE2B_DECLS                                      \
    TEST_DECL_GROUP("blake2b", test_wc_InitBlake2b),            \
    TEST_DECL_GROUP("blake2b", test_wc_InitBlake2b_WithKey),    \
    TEST_DECL_GROUP("blake2b", test_wc_Blake2bUpdate),          \
    TEST_DECL_GROUP("blake2b", test_wc_Blake2bFinal),           \
    TEST_DECL_GROUP("blake2b", test_wc_Blake2b_KATs),           \
    TEST_DECL_GROUP("blake2b", test_wc_Blake2b_other)

#define TEST_BLAKE2S_DECLS                                      \
    TEST_DECL_GROUP("blake2s", test_wc_InitBlake2s),            \
    TEST_DECL_GROUP("blake2s", test_wc_InitBlake2s_WithKey),    \
    TEST_DECL_GROUP("blake2s", test_wc_Blake2sUpdate),          \
    TEST_DECL_GROUP("blake2s", test_wc_Blake2sFinal),           \
    TEST_DECL_GROUP("blake2s", test_wc_Blake2s_KATs),           \
    TEST_DECL_GROUP("blake2s", test_wc_Blake2s_other)

#endif /* WOLFCRYPT_TEST_BLAKE2_H */
