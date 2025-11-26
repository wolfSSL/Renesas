/* test_rc2.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_RC2_H
#define WOLFCRYPT_TEST_RC2_H

#include <tests/api/api_decl.h>

int test_wc_Rc2SetKey(void);
int test_wc_Rc2SetIV(void);
int test_wc_Rc2EcbEncryptDecrypt(void);
int test_wc_Rc2CbcEncryptDecrypt(void);

#define TEST_RC2_DECLS                                      \
    TEST_DECL_GROUP("rc2", test_wc_Rc2SetKey),              \
    TEST_DECL_GROUP("rc2", test_wc_Rc2SetIV),               \
    TEST_DECL_GROUP("rc2", test_wc_Rc2EcbEncryptDecrypt),   \
    TEST_DECL_GROUP("rc2", test_wc_Rc2CbcEncryptDecrypt)

#endif /* WOLFCRYPT_TEST_RC2_H */
