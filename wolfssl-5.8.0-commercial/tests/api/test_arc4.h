/* test_arc4.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ARC4_H
#define WOLFCRYPT_TEST_ARC4_H

#include <tests/api/api_decl.h>

int test_wc_Arc4SetKey(void);
int test_wc_Arc4Process(void);

#define TEST_ARC4_DECLS                             \
    TEST_DECL_GROUP("arc4", test_wc_Arc4SetKey),    \
    TEST_DECL_GROUP("arc4", test_wc_Arc4Process)

#endif /* WOLFCRYPT_TEST_ARC4_H */
