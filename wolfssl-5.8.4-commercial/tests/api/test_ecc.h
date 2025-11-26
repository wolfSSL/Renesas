/* test_ecc.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ECC_H
#define WOLFCRYPT_TEST_ECC_H

#include <tests/api/api_decl.h>

int test_wc_ecc_get_curve_size_from_name(void);
int test_wc_ecc_get_curve_id_from_name(void);
int test_wc_ecc_get_curve_id_from_params(void);
int test_wc_ecc_get_curve_id_from_dp_params(void);
int test_wc_ecc_make_key(void);
int test_wc_ecc_init(void);
int test_wc_ecc_check_key(void);
int test_wc_ecc_get_generator(void);
int test_wc_ecc_size(void);
int test_wc_ecc_params(void);
int test_wc_ecc_signVerify_hash(void);
int test_wc_ecc_shared_secret(void);
int test_wc_ecc_export_x963(void);
int test_wc_ecc_export_x963_ex(void);
int test_wc_ecc_import_x963(void);
int test_wc_ecc_import_private_key(void);
int test_wc_ecc_export_private_only(void);
int test_wc_ecc_rs_to_sig(void);
int test_wc_ecc_import_raw(void);
int test_wc_ecc_import_unsigned(void);
int test_wc_ecc_sig_size(void);
int test_wc_ecc_ctx_new(void);
int test_wc_ecc_ctx_reset(void);
int test_wc_ecc_ctx_set_peer_salt(void);
int test_wc_ecc_ctx_set_info(void);
int test_wc_ecc_encryptDecrypt(void);
int test_wc_ecc_del_point(void);
int test_wc_ecc_pointFns(void);
int test_wc_ecc_shared_secret_ssh(void);
int test_wc_ecc_verify_hash_ex(void);
int test_wc_ecc_mulmod(void);
int test_wc_ecc_is_valid_idx(void);
int test_wc_ecc_get_curve_id_from_oid(void);
int test_wc_ecc_sig_size_calc(void);
int test_wc_EccPrivateKeyToDer(void);

#define TEST_ECC_DECLS                                                  \
    TEST_DECL_GROUP("ecc", test_wc_ecc_get_curve_size_from_name),       \
    TEST_DECL_GROUP("ecc", test_wc_ecc_get_curve_id_from_name),         \
    TEST_DECL_GROUP("ecc", test_wc_ecc_get_curve_id_from_params),       \
    TEST_DECL_GROUP("ecc", test_wc_ecc_get_curve_id_from_dp_params),    \
    TEST_DECL_GROUP("ecc", test_wc_ecc_make_key),                       \
    TEST_DECL_GROUP("ecc", test_wc_ecc_init),                           \
    TEST_DECL_GROUP("ecc", test_wc_ecc_check_key),                      \
    TEST_DECL_GROUP("ecc", test_wc_ecc_get_generator),                  \
    TEST_DECL_GROUP("ecc", test_wc_ecc_size),                           \
    TEST_DECL_GROUP("ecc", test_wc_ecc_params),                         \
    TEST_DECL_GROUP("ecc", test_wc_ecc_signVerify_hash),                \
    TEST_DECL_GROUP("ecc", test_wc_ecc_shared_secret),                  \
    TEST_DECL_GROUP("ecc", test_wc_ecc_export_x963),                    \
    TEST_DECL_GROUP("ecc", test_wc_ecc_export_x963_ex),                 \
    TEST_DECL_GROUP("ecc", test_wc_ecc_import_x963),                    \
    TEST_DECL_GROUP("ecc", test_wc_ecc_import_private_key),             \
    TEST_DECL_GROUP("ecc", test_wc_ecc_export_private_only),            \
    TEST_DECL_GROUP("ecc", test_wc_ecc_rs_to_sig),                      \
    TEST_DECL_GROUP("ecc", test_wc_ecc_import_raw),                     \
    TEST_DECL_GROUP("ecc", test_wc_ecc_import_unsigned),                \
    TEST_DECL_GROUP("ecc", test_wc_ecc_sig_size),                       \
    TEST_DECL_GROUP("ecc", test_wc_ecc_ctx_new),                        \
    TEST_DECL_GROUP("ecc", test_wc_ecc_ctx_reset),                      \
    TEST_DECL_GROUP("ecc", test_wc_ecc_ctx_set_peer_salt),              \
    TEST_DECL_GROUP("ecc", test_wc_ecc_ctx_set_info),                   \
    TEST_DECL_GROUP("ecc", test_wc_ecc_encryptDecrypt),                 \
    TEST_DECL_GROUP("ecc", test_wc_ecc_del_point),                      \
    TEST_DECL_GROUP("ecc", test_wc_ecc_pointFns),                       \
    TEST_DECL_GROUP("ecc", test_wc_ecc_shared_secret_ssh),              \
    TEST_DECL_GROUP("ecc", test_wc_ecc_verify_hash_ex),                 \
    TEST_DECL_GROUP("ecc", test_wc_ecc_mulmod),                         \
    TEST_DECL_GROUP("ecc", test_wc_ecc_is_valid_idx),                   \
    TEST_DECL_GROUP("ecc", test_wc_ecc_get_curve_id_from_oid),          \
    TEST_DECL_GROUP("ecc", test_wc_ecc_sig_size_calc),                  \
    TEST_DECL_GROUP("ecc", test_wc_EccPrivateKeyToDer)

#endif /* WOLFCRYPT_TEST_ECC_H */
