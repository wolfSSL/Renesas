/* test_ossl_asn1.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_OSSL_ASN1_H
#define WOLFCRYPT_TEST_OSSL_ASN1_H

#include <tests/api/api_decl.h>

int test_wolfSSL_ASN1_BIT_STRING(void);
int test_wolfSSL_ASN1_INTEGER(void);
int test_wolfSSL_ASN1_INTEGER_cmp(void);
int test_wolfSSL_ASN1_INTEGER_BN(void);
int test_wolfSSL_ASN1_INTEGER_get_set(void);
int test_wolfSSL_d2i_ASN1_INTEGER(void);
int test_wolfSSL_a2i_ASN1_INTEGER(void);
int test_wolfSSL_i2c_ASN1_INTEGER(void);
int test_wolfSSL_ASN1_OBJECT(void);
int test_wolfSSL_ASN1_get_object(void);
int test_wolfSSL_i2a_ASN1_OBJECT(void);
int test_wolfSSL_i2t_ASN1_OBJECT(void);
int test_wolfSSL_sk_ASN1_OBJECT(void);
int test_wolfSSL_ASN1_STRING(void);
int test_wolfSSL_ASN1_STRING_to_UTF8(void);
int test_wolfSSL_i2s_ASN1_STRING(void);
int test_wolfSSL_ASN1_STRING_canon(void);
int test_wolfSSL_ASN1_STRING_print(void);
int test_wolfSSL_ASN1_STRING_print_ex(void);
int test_wolfSSL_ASN1_UNIVERSALSTRING_to_string(void);
int test_wolfSSL_ASN1_GENERALIZEDTIME_free(void);
int test_wolfSSL_ASN1_GENERALIZEDTIME_print(void);
int test_wolfSSL_ASN1_TIME(void);
int test_wolfSSL_ASN1_TIME_to_string(void);
int test_wolfSSL_ASN1_TIME_diff_compare(void);
int test_wolfSSL_ASN1_TIME_adj(void);
int test_wolfSSL_ASN1_TIME_to_tm(void);
int test_wolfSSL_ASN1_TIME_to_generalizedtime(void);
int test_wolfSSL_ASN1_TIME_print(void);
int test_wolfSSL_ASN1_UTCTIME_print(void);
int test_wolfSSL_ASN1_TYPE(void);
int test_wolfSSL_IMPLEMENT_ASN1_FUNCTIONS(void);
int test_wolfSSL_i2d_ASN1_TYPE(void);
int test_wolfSSL_i2d_ASN1_SEQUENCE(void);
int test_ASN1_strings(void);

#define TEST_OSSL_ASN1_BIT_STRING_DECLS                             \
    TEST_DECL_GROUP("ossl_asn1_bs", test_wolfSSL_ASN1_BIT_STRING)

#define TEST_OSSL_ASN1_INTEGER_DECLS                                        \
    TEST_DECL_GROUP("ossl_asn1_int", test_wolfSSL_ASN1_INTEGER),            \
    TEST_DECL_GROUP("ossl_asn1_int", test_wolfSSL_ASN1_INTEGER_cmp),        \
    TEST_DECL_GROUP("ossl_asn1_int", test_wolfSSL_ASN1_INTEGER_BN),         \
    TEST_DECL_GROUP("ossl_asn1_int", test_wolfSSL_ASN1_INTEGER_get_set),    \
    TEST_DECL_GROUP("ossl_asn1_int", test_wolfSSL_d2i_ASN1_INTEGER),        \
    TEST_DECL_GROUP("ossl_asn1_int", test_wolfSSL_a2i_ASN1_INTEGER),        \
    TEST_DECL_GROUP("ossl_asn1_int", test_wolfSSL_i2c_ASN1_INTEGER)

#define TEST_OSSL_ASN1_OBJECT_DECLS                                         \
    TEST_DECL_GROUP("ossl_asn1_obj", test_wolfSSL_ASN1_OBJECT),             \
    TEST_DECL_GROUP("ossl_asn1_obj", test_wolfSSL_ASN1_get_object),         \
    TEST_DECL_GROUP("ossl_asn1_obj", test_wolfSSL_i2a_ASN1_OBJECT),         \
    TEST_DECL_GROUP("ossl_asn1_obj", test_wolfSSL_i2t_ASN1_OBJECT),         \
    TEST_DECL_GROUP("ossl_asn1_obj", test_wolfSSL_sk_ASN1_OBJECT)

#define TEST_OSSL_ASN1_STRING_DECLS                                            \
    TEST_DECL_GROUP("ossl_asn1_str", test_wolfSSL_ASN1_STRING),                \
    TEST_DECL_GROUP("ossl_asn1_str", test_wolfSSL_ASN1_STRING_to_UTF8),        \
    TEST_DECL_GROUP("ossl_asn1_str", test_wolfSSL_i2s_ASN1_STRING),            \
    TEST_DECL_GROUP("ossl_asn1_str", test_wolfSSL_ASN1_STRING_canon),          \
    TEST_DECL_GROUP("ossl_asn1_str", test_wolfSSL_ASN1_STRING_print),          \
    TEST_DECL_GROUP("ossl_asn1_str", test_wolfSSL_ASN1_STRING_print_ex),       \
    TEST_DECL_GROUP("ossl_asn1_str",                                           \
                                 test_wolfSSL_ASN1_UNIVERSALSTRING_to_string), \
    TEST_DECL_GROUP("ossl_asn1_str", test_ASN1_strings)

#define TEST_OSSL_ASN1_TIME_DECLS                                              \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_GENERALIZEDTIME_free),   \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_GENERALIZEDTIME_print),  \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_TIME),                   \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_TIME_to_string),         \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_TIME_diff_compare),      \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_TIME_adj),               \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_TIME_to_tm),             \
    TEST_DECL_GROUP("ossl_asn1_tm",                                            \
                                   test_wolfSSL_ASN1_TIME_to_generalizedtime), \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_TIME_print),             \
    TEST_DECL_GROUP("ossl_asn1_tm", test_wolfSSL_ASN1_UTCTIME_print)

#define TEST_OSSL_ASN1_TYPE_DECLS                                              \
    TEST_DECL_GROUP("ossl_asn1_type", test_wolfSSL_ASN1_TYPE),                 \
    TEST_DECL_GROUP("ossl_asn1_type", test_wolfSSL_IMPLEMENT_ASN1_FUNCTIONS),  \
    TEST_DECL_GROUP("ossl_asn1_type", test_wolfSSL_i2d_ASN1_TYPE),             \
    TEST_DECL_GROUP("ossl_asn1_type", test_wolfSSL_i2d_ASN1_SEQUENCE)

#endif /* WOLFCRYPT_TEST_OSSL_ASN1_H */
