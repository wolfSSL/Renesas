/* test_sha3.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SHA3_H
#define WOLFCRYPT_TEST_SHA3_H

#include <tests/api/api_decl.h>

int test_wc_InitSha3(void);
int test_wc_Sha3_Update(void);
int test_wc_Sha3_Final(void);
int test_wc_Sha3_224_KATs(void);
int test_wc_Sha3_256_KATs(void);
int test_wc_Sha3_384_KATs(void);
int test_wc_Sha3_512_KATs(void);
int test_wc_Sha3_other(void);
int test_wc_Sha3_Copy(void);
int test_wc_Sha3_GetHash(void);
int test_wc_Sha3_Flags(void);

int test_wc_InitShake128(void);
int test_wc_Shake128_Update(void);
int test_wc_Shake128_Final(void);
int test_wc_Shake128_KATs(void);
int test_wc_Shake128_other(void);
int test_wc_Shake128_Copy(void);
int test_wc_Shake128Hash(void);
int test_wc_Shake128_Absorb(void);
int test_wc_Shake128_SqueezeBlocks(void);
int test_wc_Shake128_XOF(void);

int test_wc_InitShake256(void);
int test_wc_Shake256_Update(void);
int test_wc_Shake256_Final(void);
int test_wc_Shake256_KATs(void);
int test_wc_Shake256_other(void);
int test_wc_Shake256_Copy(void);
int test_wc_Shake256Hash(void);
int test_wc_Shake256_Absorb(void);
int test_wc_Shake256_SqueezeBlocks(void);
int test_wc_Shake256_XOF(void);

#define TEST_SHA3_DECLS                             \
    TEST_DECL_GROUP("sha3", test_wc_InitSha3),      \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_Update),   \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_Final),    \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_224_KATs), \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_256_KATs), \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_384_KATs), \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_512_KATs), \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_other),    \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_Copy),     \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_GetHash),  \
    TEST_DECL_GROUP("sha3", test_wc_Sha3_Flags)

#define TEST_SHAKE128_DECLS                                         \
    TEST_DECL_GROUP("shake128", test_wc_InitShake128),              \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_Update),           \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_Final),            \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_KATs),             \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_other),            \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_Copy),             \
    TEST_DECL_GROUP("shake128", test_wc_Shake128Hash),              \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_Absorb),           \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_SqueezeBlocks),    \
    TEST_DECL_GROUP("shake128", test_wc_Shake128_XOF)

#define TEST_SHAKE256_DECLS                                         \
    TEST_DECL_GROUP("shake256", test_wc_InitShake256),              \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_Update),           \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_Final),            \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_KATs),             \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_other),            \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_Copy),             \
    TEST_DECL_GROUP("shake256", test_wc_Shake256Hash),              \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_Absorb),           \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_SqueezeBlocks),    \
    TEST_DECL_GROUP("shake256", test_wc_Shake256_XOF)

#endif /* WOLFCRYPT_TEST_SHA3_H */
