/* test_des3.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_DES3_H
#define WOLFCRYPT_TEST_DES3_H

#include <tests/api/api_decl.h>

int test_wc_Des3_SetIV(void);
int test_wc_Des3_SetKey(void);
int test_wc_Des3_CbcEncryptDecrypt(void);
int test_wc_Des3_EcbEncrypt(void);

#define TEST_DES3_DECLS                                         \
    TEST_DECL_GROUP("des3", test_wc_Des3_SetIV),                \
    TEST_DECL_GROUP("des3", test_wc_Des3_SetKey),               \
    TEST_DECL_GROUP("des3", test_wc_Des3_CbcEncryptDecrypt),    \
    TEST_DECL_GROUP("des3", test_wc_Des3_CbcEncryptDecrypt)

#endif /* WOLFCRYPT_TEST_DES3_H */
