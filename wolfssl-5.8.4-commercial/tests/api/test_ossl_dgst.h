/* test_ossl_dgst.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_DGST_H
#define WOLFCRYPT_TEST_OSSL_DGST_H

#include <tests/api/api_decl.h>

int test_wolfSSL_MD4(void);
int test_wolfSSL_MD5(void);
int test_wolfSSL_MD5_Transform(void);
int test_wolfSSL_SHA(void);
int test_wolfSSL_SHA_Transform(void);
int test_wolfSSL_SHA224(void);
int test_wolfSSL_SHA256(void);
int test_wolfSSL_SHA256_Transform(void);
int test_wolfSSL_SHA512_Transform(void);
int test_wolfSSL_SHA512_224_Transform(void);
int test_wolfSSL_SHA512_256_Transform(void);

#define TEST_OSSL_DIGEST_DECLS                                       \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_MD4),                  \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_MD5),                  \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_MD5_Transform),        \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA),                  \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA_Transform),        \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA224),               \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA256),               \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA256_Transform),     \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA512_Transform),     \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA512_224_Transform), \
    TEST_DECL_GROUP("ossl_dgst", test_wolfSSL_SHA512_256_Transform)

#endif /* WOLFCRYPT_TEST_OSSL_DGST_H */

