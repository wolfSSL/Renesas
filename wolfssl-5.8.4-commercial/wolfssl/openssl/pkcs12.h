/* pkcs12.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* pkcs12.h for openssl */


#include <wolfssl/openssl/ssl.h>
#include <wolfssl/wolfcrypt/pkcs12.h>

#ifndef WOLFSSL_PKCS12_COMPAT_H_
#define WOLFSSL_PKCS12_COMPAT_H_

#define WC_NID_pbe_WithSHA1AndDES_CBC             2
#define WC_NID_pbe_WithSHA1And3_Key_TripleDES_CBC 3
#define WC_NID_pbe_WithSHA1And128BitRC4           1

#ifndef OPENSSL_COEXIST

#define NID_pbe_WithSHA1AndDES_CBC WC_NID_pbe_WithSHA1AndDES_CBC
#define NID_pbe_WithSHA1And3_Key_TripleDES_CBC WC_NID_pbe_WithSHA1And3_Key_TripleDES_CBC
#define NID_pbe_WithSHA1And128BitRC4 WC_NID_pbe_WithSHA1And128BitRC4

#define PKCS12_DEFAULT_ITER WC_PKCS12_ITT_DEFAULT

/* wolfCrypt level does not make use of ssl.h */
#define PKCS12         WC_PKCS12
#define PKCS12_new     wc_PKCS12_new
#define PKCS12_free    wc_PKCS12_free

/* wolfSSL level using structs from ssl.h and calls down to wolfCrypt */
#define d2i_PKCS12_bio wolfSSL_d2i_PKCS12_bio
#define PKCS12_parse   wolfSSL_PKCS12_parse
#define PKCS12_verify_mac wolfSSL_PKCS12_verify_mac
#define PKCS12_create  wolfSSL_PKCS12_create
#define PKCS12_PBE_add wolfSSL_PKCS12_PBE_add

#endif /* !OPENSSL_COEXIST */

#endif /* WOLFSSL_PKCS12_COMPAT_H_ */
