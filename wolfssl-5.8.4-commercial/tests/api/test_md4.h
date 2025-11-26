/* test_md2.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_MD4_H
#define WOLFCRYPT_TEST_MD4_H

#include <tests/api/api_decl.h>

int test_wc_InitMd4(void);
int test_wc_Md4Update(void);
int test_wc_Md4Final(void);
int test_wc_Md4_KATs(void);
int test_wc_Md4_other(void);

#define TEST_MD4_DECLS                          \
    TEST_DECL_GROUP("md4", test_wc_InitMd4),    \
    TEST_DECL_GROUP("md4", test_wc_Md4Update),  \
    TEST_DECL_GROUP("md4", test_wc_Md4Final),   \
    TEST_DECL_GROUP("md4", test_wc_Md4_KATs),   \
    TEST_DECL_GROUP("md4", test_wc_Md4_other)

#endif /* WOLFCRYPT_TEST_MD4_H */
