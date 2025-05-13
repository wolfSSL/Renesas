/* test_poly1305.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_POLY1305_H
#define WOLFCRYPT_TEST_POLY1305_H

#include <tests/api/api_decl.h>

int test_wc_Poly1305SetKey(void);

#define TEST_POLY1305_DECLS                             \
    TEST_DECL_GROUP("poly1305", test_wc_Poly1305SetKey)

#endif /* WOLFCRYPT_TEST_POLY1305_H */
