/* test_sm3.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SM3_H
#define WOLFCRYPT_TEST_SM3_H

#include <tests/api/api_decl.h>

int test_wc_InitSm3(void);
int test_wc_Sm3Update(void);
int test_wc_Sm3Final(void);
int test_wc_Sm3FinalRaw(void);
int test_wc_Sm3_KATs(void);
int test_wc_Sm3_other(void);
int test_wc_Sm3Copy(void);
int test_wc_Sm3GetHash(void);
int test_wc_Sm3_Flags(void);

#define TEST_SM3_DECLS                              \
    TEST_DECL_GROUP("sm3", test_wc_InitSm3),        \
    TEST_DECL_GROUP("sm3", test_wc_Sm3Update),      \
    TEST_DECL_GROUP("sm3", test_wc_Sm3Final),       \
    TEST_DECL_GROUP("sm3", test_wc_Sm3FinalRaw),    \
    TEST_DECL_GROUP("sm3", test_wc_Sm3_KATs),       \
    TEST_DECL_GROUP("sm3", test_wc_Sm3_other),      \
    TEST_DECL_GROUP("sm3", test_wc_Sm3Copy),        \
    TEST_DECL_GROUP("sm3", test_wc_Sm3GetHash),     \
    TEST_DECL_GROUP("sm3", test_wc_Sm3_Flags)

#endif /* WOLFCRYPT_TEST_SM3_H */
