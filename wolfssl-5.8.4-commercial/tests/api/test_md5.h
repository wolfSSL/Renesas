/* test_md5.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_MD5_H
#define WOLFCRYPT_TEST_MD5_H

#include <tests/api/api_decl.h>

int test_wc_InitMd5(void);
int test_wc_Md5Update(void);
int test_wc_Md5Final(void);
int test_wc_Md5_KATs(void);
int test_wc_Md5_other(void);
int test_wc_Md5Copy(void);
int test_wc_Md5GetHash(void);
int test_wc_Md5Transform(void);
int test_wc_Md5_Flags(void);

#define TEST_MD5_DECLS                              \
    TEST_DECL_GROUP("md5", test_wc_InitMd5),        \
    TEST_DECL_GROUP("md5", test_wc_Md5Update),      \
    TEST_DECL_GROUP("md5", test_wc_Md5Final),       \
    TEST_DECL_GROUP("md5", test_wc_Md5_KATs),       \
    TEST_DECL_GROUP("md5", test_wc_Md5_other),      \
    TEST_DECL_GROUP("md5", test_wc_Md5Copy),        \
    TEST_DECL_GROUP("md5", test_wc_Md5GetHash),     \
    TEST_DECL_GROUP("md5", test_wc_Md5Transform),   \
    TEST_DECL_GROUP("md5", test_wc_Md5_Flags)

#endif /* WOLFCRYPT_TEST_MD5_H */
