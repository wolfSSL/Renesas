/* test_ossl_mac.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_MAC_H
#define WOLFCRYPT_TEST_OSSL_MAC_H

#include <tests/api/api_decl.h>

int test_wolfSSL_HMAC_CTX(void);
int test_wolfSSL_HMAC(void);
int test_wolfSSL_CMAC(void);

#define TEST_OSSL_MAC_DECLS                             \
    TEST_DECL_GROUP("ossl_mac", test_wolfSSL_HMAC_CTX), \
    TEST_DECL_GROUP("ossl_mac", test_wolfSSL_HMAC),     \
    TEST_DECL_GROUP("ossl_mac", test_wolfSSL_CMAC)

#endif /* WOLFCRYPT_TEST_OSSL_MAC_H */

