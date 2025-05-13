/* test_wolfmath.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_WOLFMATH_H
#define WOLFCRYPT_TEST_WOLFMATH_H

#include <tests/api/api_decl.h>

int test_get_digit_count(void);
int test_get_digit(void);
int test_get_rand_digit(void);
int test_mp_cond_copy(void);
int test_mp_rand(void);
int test_wc_export_int(void);

#define TEST_WOLFMATH_DECLS                             \
    TEST_DECL_GROUP("wolfmath", test_get_digit_count),  \
    TEST_DECL_GROUP("wolfmath", test_get_digit),        \
    TEST_DECL_GROUP("wolfmath", test_get_rand_digit),   \
    TEST_DECL_GROUP("wolfmath", test_mp_cond_copy),     \
    TEST_DECL_GROUP("wolfmath", test_mp_rand),          \
    TEST_DECL_GROUP("wolfmath", test_wc_export_int)

#endif /* WOLFCRYPT_TEST_WOLFMATH_H */
