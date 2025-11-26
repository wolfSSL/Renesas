/* test_chacha20_poly1305.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_CHACHA20_POLY1305_H
#define WOLFCRYPT_TEST_CHACHA20_POLY1305_H

#include <tests/api/api_decl.h>

int test_wc_ChaCha20Poly1305_aead(void);

#define TEST_CHACHA20_POLY1305_DECLS                                    \
    TEST_DECL_GROUP("chacha20-poly1305", test_wc_ChaCha20Poly1305_aead)

#endif /* WOLFCRYPT_TEST_CHACHA20_POLY1305_H */
