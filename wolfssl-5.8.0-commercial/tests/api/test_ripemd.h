/* test_ripemd.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_RIPEMD_H
#define WOLFCRYPT_TEST_RIPEMD_H

#include <tests/api/api_decl.h>

int test_wc_InitRipeMd(void);
int test_wc_RipeMdUpdate(void);
int test_wc_RipeMdFinal(void);
int test_wc_RipeMd_KATs(void);
int test_wc_RipeMd_other(void);

#define TEST_RIPEMD_DECLS                               \
    TEST_DECL_GROUP("ripemd", test_wc_InitRipeMd),      \
    TEST_DECL_GROUP("ripemd", test_wc_RipeMdUpdate),    \
    TEST_DECL_GROUP("ripemd", test_wc_RipeMdFinal),     \
    TEST_DECL_GROUP("ripemd", test_wc_RipeMd_KATs),     \
    TEST_DECL_GROUP("ripemd", test_wc_RipeMd_other)

#endif /* WOLFCRYPT_TEST_RIPEMD_H */
