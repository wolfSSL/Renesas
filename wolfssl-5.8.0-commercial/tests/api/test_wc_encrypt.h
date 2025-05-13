/* test_wc_encrypt.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_WC_ENCRYPT_H
#define WOLFCRYPT_TEST_WC_ENCRYPT_H

#include <tests/api/api_decl.h>

int test_wc_Des3_CbcEncryptDecryptWithKey(void);

#define TEST_WC_ENCRYPT_DECLS                                               \
    TEST_DECL_GROUP("wc_encrypt", test_wc_Des3_CbcEncryptDecryptWithKey)

#endif /* WOLFCRYPT_TEST_WC_ENCRYPT_H */
