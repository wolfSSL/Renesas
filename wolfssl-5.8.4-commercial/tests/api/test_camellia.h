/* test_camellia.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_CAMELLIA_H
#define WOLFCRYPT_TEST_CAMELLIA_H

#include <tests/api/api_decl.h>

int test_wc_CamelliaSetKey(void);
int test_wc_CamelliaSetIV(void);
int test_wc_CamelliaEncryptDecryptDirect(void);
int test_wc_CamelliaCbcEncryptDecrypt(void);

#define TEST_CAMELLIA_DECLS                                             \
    TEST_DECL_GROUP("camellia", test_wc_CamelliaSetKey),                \
    TEST_DECL_GROUP("camellia", test_wc_CamelliaSetIV),                 \
    TEST_DECL_GROUP("camellia", test_wc_CamelliaEncryptDecryptDirect),  \
    TEST_DECL_GROUP("camellia", test_wc_CamelliaCbcEncryptDecrypt)

#endif /* WOLFCRYPT_TEST_CAMELLIA_H */
