/* test_dh.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_DH_H
#define WOLFCRYPT_TEST_DH_H

#include <tests/api/api_decl.h>

int test_wc_DhPublicKeyDecode(void);

#define TEST_DH_DECLS                                   \
    TEST_DECL_GROUP("dh", test_wc_DhPublicKeyDecode)

#endif /* WOLFCRYPT_TEST_DH_H */
