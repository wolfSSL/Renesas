/* test_random.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_RANDOM_H
#define WOLFCRYPT_TEST_RANDOM_H

#include <tests/api/api_decl.h>

int test_wc_InitRng(void);
int test_wc_RNG_GenerateBlock_Reseed(void);
int test_wc_RNG_GenerateBlock(void);
int test_wc_RNG_GenerateByte(void);
int test_wc_InitRngNonce(void);
int test_wc_InitRngNonce_ex(void);
int test_wc_GenerateSeed(void);
int test_wc_rng_new(void);
int test_wc_RNG_DRBG_Reseed(void);
int test_wc_RNG_TestSeed(void);
int test_wc_RNG_HealthTest(void);

#define TEST_RANDOM_DECLS                                           \
    TEST_DECL_GROUP("random", test_wc_InitRng),                     \
    TEST_DECL_GROUP("random", test_wc_RNG_GenerateBlock_Reseed),    \
    TEST_DECL_GROUP("random", test_wc_RNG_GenerateBlock),           \
    TEST_DECL_GROUP("random", test_wc_RNG_GenerateByte),            \
    TEST_DECL_GROUP("random", test_wc_InitRngNonce),                \
    TEST_DECL_GROUP("random", test_wc_InitRngNonce_ex),             \
    TEST_DECL_GROUP("random", test_wc_GenerateSeed),                \
    TEST_DECL_GROUP("random", test_wc_rng_new),                     \
    TEST_DECL_GROUP("random", test_wc_RNG_DRBG_Reseed),             \
    TEST_DECL_GROUP("random", test_wc_RNG_TestSeed),                \
    TEST_DECL_GROUP("random", test_wc_RNG_HealthTest)

#endif /* WOLFCRYPT_TEST_RANDOM_H */
