/* objects.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFSSL_OBJECTS_H_
#define WOLFSSL_OBJECTS_H_

#include <wolfssl/wolfcrypt/types.h>
#ifndef OPENSSL_EXTRA_SSL_GUARD
#define OPENSSL_EXTRA_SSL_GUARD
#include <wolfssl/ssl.h>
#endif /* OPENSSL_EXTRA_SSL_GUARD */

#ifdef __cplusplus
    extern "C" {
#endif

#if defined(OPENSSL_EXTRA) || defined(OPENSSL_EXTRA_X509_SMALL)

#define OBJ_NAME_TYPE_UNDEF     WOLFSSL_OBJ_NAME_TYPE_UNDEF
#define OBJ_NAME_TYPE_MD_METH   WOLFSSL_OBJ_NAME_TYPE_MD_METH
#define OBJ_NAME_TYPE_CIPHER_METH   WOLFSSL_OBJ_NAME_TYPE_CIPHER_METH
#define OBJ_NAME_TYPE_PKEY_METH     WOLFSSL_OBJ_NAME_TYPE_PKEY_METH
#define OBJ_NAME_TYPE_COMP_METH     WOLFSSL_OBJ_NAME_TYPE_COMP_METH
#define OBJ_NAME_TYPE_NUM           WOLFSSL_OBJ_NAME_TYPE_NUM
#define OBJ_NAME_ALIAS              WOLFSSL_OBJ_NAME_ALIAS

#define OBJ_nid2sn       wolfSSL_OBJ_nid2sn
#define OBJ_obj2nid      wolfSSL_OBJ_obj2nid
#define OBJ_sn2nid       wolfSSL_OBJ_sn2nid
#define OBJ_length       wolfSSL_OBJ_length
#define OBJ_get0_data    wolfSSL_OBJ_get0_data
#define OBJ_nid2ln       wolfSSL_OBJ_nid2ln
#define OBJ_ln2nid       wolfSSL_OBJ_ln2nid
#define OBJ_txt2nid      wolfSSL_OBJ_txt2nid
#define OBJ_txt2obj      wolfSSL_OBJ_txt2obj
#define OBJ_nid2obj      wolfSSL_OBJ_nid2obj
#define OBJ_obj2txt      wolfSSL_OBJ_obj2txt
#define OBJ_cleanup      wolfSSL_OBJ_cleanup
#define OBJ_cmp          wolfSSL_OBJ_cmp
#define OBJ_create       wolfSSL_OBJ_create
#define ASN1_OBJECT_free wolfSSL_ASN1_OBJECT_free
#define OBJ_NAME_do_all  wolfSSL_OBJ_NAME_do_all
#define i2t_ASN1_OBJECT  wolfSSL_i2t_ASN1_OBJECT

/* not required for wolfSSL */
#define OPENSSL_load_builtin_modules() WC_DO_NOTHING


#define NID_ad_OCSP                     178
#define NID_ad_ca_issuers               179

#endif /* OPENSSL_EXTRA || OPENSSL_EXTRA_X509_SMALL */


#ifdef __cplusplus
    }  /* extern "C" */
#endif

#endif /* WOLFSSL_OBJECTS_H_ */
