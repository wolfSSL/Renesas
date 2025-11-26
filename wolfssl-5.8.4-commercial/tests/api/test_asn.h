/* test_asn.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ASN_H
#define WOLFCRYPT_TEST_ASN_H

#include <tests/api/api_decl.h>

int test_SetAsymKeyDer(void);
int test_GetSetShortInt(void);
int test_wc_IndexSequenceOf(void);

#define TEST_ASN_DECLS                                              \
    TEST_DECL_GROUP("asn", test_SetAsymKeyDer),                     \
    TEST_DECL_GROUP("asn", test_GetSetShortInt),                    \
    TEST_DECL_GROUP("asn", test_wc_IndexSequenceOf)

#endif /* WOLFCRYPT_TEST_ASN_H */
