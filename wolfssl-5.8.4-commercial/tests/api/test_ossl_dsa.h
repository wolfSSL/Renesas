/* test_ossl_dsa.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_DSA_H
#define WOLFCRYPT_TEST_OSSL_DSA_H

#include <tests/api/api_decl.h>

int test_DSA_do_sign_verify(void);
int test_wolfSSL_DSA_generate_parameters(void);
int test_wolfSSL_DSA_SIG(void);

#define TEST_OSSL_DSA_DECLS                                             \
    TEST_DECL_GROUP("ossl_dsa", test_DSA_do_sign_verify),               \
    TEST_DECL_GROUP("ossl_dsa", test_wolfSSL_DSA_generate_parameters),  \
    TEST_DECL_GROUP("ossl_dsa", test_wolfSSL_DSA_SIG)

#endif /* WOLFCRYPT_TEST_OSSL_DSA_H */

