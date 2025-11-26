/* test_ossl_cipher.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_CIPHER_H
#define WOLFCRYPT_TEST_OSSL_CIPHER_H

#include <tests/api/api_decl.h>

int test_wolfSSL_DES(void);
int test_wolfSSL_DES_ncbc(void);
int test_wolfSSL_DES_ecb_encrypt(void);
int test_wolfSSL_DES_ede3_cbc_encrypt(void);
int test_wolfSSL_AES_encrypt(void);
int test_wolfSSL_AES_ecb_encrypt(void);
int test_wolfSSL_AES_cbc_encrypt(void);
int test_wolfSSL_AES_cfb128_encrypt(void);
int test_wolfSSL_CRYPTO_cts128(void);
int test_wolfSSL_RC4(void);

#define TEST_OSSL_CIPHER_DECLS                                          \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_DES),                   \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_DES_ncbc),              \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_DES_ecb_encrypt),       \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_DES_ede3_cbc_encrypt),  \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_AES_encrypt),           \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_AES_ecb_encrypt),       \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_AES_cbc_encrypt),       \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_AES_cfb128_encrypt),    \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_CRYPTO_cts128),         \
    TEST_DECL_GROUP("ossl_cipher", test_wolfSSL_RC4)

#endif /* WOLFCRYPT_TEST_OSSL_CIPHER_H */

