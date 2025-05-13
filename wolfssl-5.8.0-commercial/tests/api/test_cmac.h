/* test_cmac.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_CMAC_H
#define WOLFCRYPT_TEST_CMAC_H

#include <tests/api/api_decl.h>

int test_wc_InitCmac(void);
int test_wc_CmacUpdate(void);
int test_wc_CmacFinal(void);
int test_wc_AesCmacGenerate(void);

#define TEST_CMAC_DECLS                                 \
    TEST_DECL_GROUP("cmac", test_wc_InitCmac),          \
    TEST_DECL_GROUP("cmac", test_wc_CmacUpdate),        \
    TEST_DECL_GROUP("cmac", test_wc_CmacFinal),         \
    TEST_DECL_GROUP("cmac", test_wc_AesCmacGenerate)

#endif /* WOLFCRYPT_TEST_CMAC_H */
