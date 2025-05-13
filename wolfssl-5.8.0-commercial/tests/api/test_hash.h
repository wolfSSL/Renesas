/* test_hash.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_HASH_H
#define WOLFCRYPT_TEST_HASH_H

#include <tests/api/api_decl.h>

int test_wc_HashInit(void);
int test_wc_HashUpdate(void);
int test_wc_HashFinal(void);
int test_wc_HashNewDelete(void);
int test_wc_HashGetDigestSize(void);
int test_wc_HashGetBlockSize(void);
int test_wc_Hash(void);
int test_wc_HashSetFlags(void);
int test_wc_HashGetFlags(void);
int test_wc_Hash_Algs(void);
int test_wc_HashGetOID(void);
int test_wc_OidGetHash(void);

#define TEST_HASH_DECLS                                 \
    TEST_DECL_GROUP("hash", test_wc_HashInit),          \
    TEST_DECL_GROUP("hash", test_wc_HashUpdate),        \
    TEST_DECL_GROUP("hash", test_wc_HashFinal),         \
    TEST_DECL_GROUP("hash", test_wc_HashNewDelete),     \
    TEST_DECL_GROUP("hash", test_wc_HashGetDigestSize), \
    TEST_DECL_GROUP("hash", test_wc_HashGetBlockSize),  \
    TEST_DECL_GROUP("hash", test_wc_Hash),              \
    TEST_DECL_GROUP("hash", test_wc_HashSetFlags),      \
    TEST_DECL_GROUP("hash", test_wc_HashGetFlags),      \
    TEST_DECL_GROUP("hash", test_wc_Hash_Algs),         \
    TEST_DECL_GROUP("hash", test_wc_HashGetOID),        \
    TEST_DECL_GROUP("hash", test_wc_OidGetHash)

#endif /* WOLFCRYPT_TEST_HASH_H */
