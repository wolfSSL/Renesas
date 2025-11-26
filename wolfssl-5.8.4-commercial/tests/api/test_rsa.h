/* test_rsa.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_RSA_H
#define WOLFCRYPT_TEST_RSA_H

#include <tests/api/api_decl.h>

int test_wc_InitRsaKey(void);
int test_wc_RsaPrivateKeyDecode(void);
int test_wc_RsaPublicKeyDecode(void);
int test_wc_RsaPublicKeyDecodeRaw(void);
int test_wc_RsaPrivateKeyDecodeRaw(void);
int test_wc_MakeRsaKey(void);
int test_wc_CheckProbablePrime(void);
int test_wc_RsaPSS_Verify(void);
int test_wc_RsaPSS_VerifyCheck(void);
int test_wc_RsaPSS_VerifyCheckInline(void);
int test_wc_RsaKeyToDer(void);
int test_wc_RsaKeyToPublicDer(void);
int test_wc_RsaPublicEncryptDecrypt(void);
int test_wc_RsaPublicEncryptDecrypt_ex(void);
int test_wc_RsaEncryptSize(void);
int test_wc_RsaSSL_SignVerify(void);
int test_wc_RsaFlattenPublicKey(void);
int test_wc_RsaDecrypt_BoundsCheck(void);

#define TEST_RSA_DECLS                                          \
    TEST_DECL_GROUP("rsa", test_wc_InitRsaKey),                 \
    TEST_DECL_GROUP("rsa", test_wc_RsaPrivateKeyDecode),        \
    TEST_DECL_GROUP("rsa", test_wc_RsaPublicKeyDecode),         \
    TEST_DECL_GROUP("rsa", test_wc_RsaPublicKeyDecodeRaw),      \
    TEST_DECL_GROUP("rsa", test_wc_RsaPrivateKeyDecodeRaw),     \
    TEST_DECL_GROUP("rsa", test_wc_MakeRsaKey),                 \
    TEST_DECL_GROUP("rsa", test_wc_CheckProbablePrime),         \
    TEST_DECL_GROUP("rsa", test_wc_RsaPSS_Verify),              \
    TEST_DECL_GROUP("rsa", test_wc_RsaPSS_VerifyCheck),         \
    TEST_DECL_GROUP("rsa", test_wc_RsaPSS_VerifyCheckInline),   \
    TEST_DECL_GROUP("rsa", test_wc_RsaKeyToDer),                \
    TEST_DECL_GROUP("rsa", test_wc_RsaKeyToPublicDer),          \
    TEST_DECL_GROUP("rsa", test_wc_RsaPublicEncryptDecrypt),    \
    TEST_DECL_GROUP("rsa", test_wc_RsaPublicEncryptDecrypt_ex), \
    TEST_DECL_GROUP("rsa", test_wc_RsaEncryptSize),             \
    TEST_DECL_GROUP("rsa", test_wc_RsaSSL_SignVerify),          \
    TEST_DECL_GROUP("rsa", test_wc_RsaFlattenPublicKey),        \
    TEST_DECL_GROUP("rsa", test_wc_RsaDecrypt_BoundsCheck)

#endif /* WOLFCRYPT_TEST_RSA_H */
