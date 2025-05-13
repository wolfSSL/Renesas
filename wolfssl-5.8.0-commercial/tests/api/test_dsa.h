/* test_dsa.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_DSA_H
#define WOLFCRYPT_TEST_DSA_H

#include <tests/api/api_decl.h>

int test_wc_InitDsaKey(void);
int test_wc_DsaSignVerify(void);
int test_wc_DsaPublicPrivateKeyDecode(void);
int test_wc_MakeDsaKey(void);
int test_wc_DsaKeyToDer(void);
int test_wc_DsaKeyToPublicDer(void);
int test_wc_DsaImportParamsRaw(void);
int test_wc_DsaImportParamsRawCheck(void);
int test_wc_DsaExportParamsRaw(void);
int test_wc_DsaExportKeyRaw(void);

#define TEST_DSA_DECLS                                          \
    TEST_DECL_GROUP("dsa", test_wc_InitDsaKey),                 \
    TEST_DECL_GROUP("dsa", test_wc_DsaSignVerify),              \
    TEST_DECL_GROUP("dsa", test_wc_DsaPublicPrivateKeyDecode),  \
    TEST_DECL_GROUP("dsa", test_wc_MakeDsaKey),                 \
    TEST_DECL_GROUP("dsa", test_wc_DsaKeyToDer),                \
    TEST_DECL_GROUP("dsa", test_wc_DsaKeyToPublicDer),          \
    TEST_DECL_GROUP("dsa", test_wc_DsaImportParamsRaw),         \
    TEST_DECL_GROUP("dsa", test_wc_DsaImportParamsRawCheck),    \
    TEST_DECL_GROUP("dsa", test_wc_DsaExportParamsRaw),         \
    TEST_DECL_GROUP("dsa", test_wc_DsaExportKeyRaw)

#endif /* WOLFCRYPT_TEST_DSA_H */
