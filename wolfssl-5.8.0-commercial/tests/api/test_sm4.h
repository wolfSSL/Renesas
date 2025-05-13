/* test_sm4.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SM4_H
#define WOLFCRYPT_TEST_SM4_H

#include <tests/api/api_decl.h>

int test_wc_Sm4(void);
int test_wc_Sm4Ecb(void);
int test_wc_Sm4Cbc(void);
int test_wc_Sm4Ctr(void);
int test_wc_Sm4Gcm(void);
int test_wc_Sm4Ccm(void);

#define TEST_SM4_DECLS                      \
    TEST_DECL_GROUP("sm4", test_wc_Sm4),    \
    TEST_DECL_GROUP("sm4", test_wc_Sm4Ecb), \
    TEST_DECL_GROUP("sm4", test_wc_Sm4Cbc), \
    TEST_DECL_GROUP("sm4", test_wc_Sm4Ctr), \
    TEST_DECL_GROUP("sm4", test_wc_Sm4Gcm), \
    TEST_DECL_GROUP("sm4", test_wc_Sm4Ccm)

#endif /* WOLFCRYPT_TEST_SM4_H */
