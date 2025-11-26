/* test_pkcs12.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_PKCS12_H
#define WOLFCRYPT_TEST_PKCS12_H

#include <tests/api/api_decl.h>

int test_wc_i2d_PKCS12(void);
int test_wc_PKCS12_create(void);

#define TEST_PKCS12_DECLS                                       \
    TEST_DECL_GROUP("pkcs12", test_wc_i2d_PKCS12),              \
    TEST_DECL_GROUP("pkcs12", test_wc_PKCS12_create)

#endif /* WOLFCRYPT_TEST_PKCS12_H */
