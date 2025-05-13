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

#ifndef WOLFCRYPT_TEST_MD2_H
#define WOLFCRYPT_TEST_MD2_H

#include <tests/api/api_decl.h>

int test_wc_InitMd2(void);
int test_wc_Md2Update(void);
int test_wc_Md2Final(void);
int test_wc_Md2_KATs(void);
int test_wc_Md2_other(void);
int test_wc_Md2Hash(void);

#define TEST_MD2_DECLS                          \
    TEST_DECL_GROUP("md2", test_wc_InitMd2),    \
    TEST_DECL_GROUP("md2", test_wc_Md2Update),  \
    TEST_DECL_GROUP("md2", test_wc_Md2Final),   \
    TEST_DECL_GROUP("md2", test_wc_Md2_KATs),   \
    TEST_DECL_GROUP("md2", test_wc_Md2_other),  \
    TEST_DECL_GROUP("md2", test_wc_Md2Hash)

#endif /* WOLFCRYPT_TEST_MD2_H */
