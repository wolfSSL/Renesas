/* test_ossl_ecx.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_ECX_H
#define WOLFCRYPT_TEST_OSSL_ECX_H

#include <tests/api/api_decl.h>

#ifdef OPENSSL_EXTRA

int test_EC25519(void);
int test_ED25519(void);
int test_EC448(void);
int test_ED448(void);

#define TEST_OSSL_ECX_DECLS                     \
    TEST_DECL_GROUP("ossl_ecx", test_EC25519),  \
    TEST_DECL_GROUP("ossl_ecx", test_ED25519),  \
    TEST_DECL_GROUP("ossl_ecx", test_EC448),    \
    TEST_DECL_GROUP("ossl_ecx", test_ED448)

#endif

#endif /* WOLFCRYPT_TEST_OSSL_ECX_H */

