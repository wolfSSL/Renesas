/* err.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_OPENSSL_ERR_
#define WOLFSSL_OPENSSL_ERR_

#include <wolfssl/wolfcrypt/logging.h>

#if defined(OPENSSL_EXTRA) || defined(OPENSSL_EXTRA_X509_SMALL)
/* err.h for openssl */
#define ERR_load_ERR_strings             wolfSSL_ERR_load_ERR_strings
#define ERR_load_crypto_strings          wolfSSL_ERR_load_crypto_strings
#define ERR_load_CRYPTO_strings          wolfSSL_ERR_load_crypto_strings
#define ERR_peek_last_error              wolfSSL_ERR_peek_last_error

/* fatal error */
#define ERR_R_MALLOC_FAILURE                    MEMORY_E
#define ERR_R_PASSED_NULL_PARAMETER             BAD_FUNC_ARG
#define ERR_R_DISABLED                          NOT_COMPILED_IN
#define ERR_R_PASSED_INVALID_ARGUMENT           BAD_FUNC_ARG
#define RSA_R_UNKNOWN_PADDING_TYPE              RSA_PAD_E
#define RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE       WC_KEY_SIZE_E
#define EC_R_BUFFER_TOO_SMALL                   BUFFER_E

#define ERR_TXT_MALLOCED                        1

/* SSL function codes */
#define RSA_F_RSA_PADDING_ADD_SSLV23            0
#define RSA_F_RSA_OSSL_PRIVATE_ENCRYPT          1
#define SSL_F_SSL_CTX_USE_CERTIFICATE_FILE      2
#define SSL_F_SSL_USE_PRIVATEKEY                3
#define EC_F_EC_GFP_SIMPLE_POINT2OCT            4

/* reasons */
#define ERR_R_SYS_LIB                           1
#define PKCS12_R_MAC_VERIFY_FAILURE             2

#define RSAerr(f,r)  ERR_put_error(0,(f),(r),__FILE__,__LINE__)
#define SSLerr(f,r)  ERR_put_error(0,(f),(r),__FILE__,__LINE__)
#define ECerr(f,r)   ERR_put_error(0,(f),(r),__FILE__,__LINE__)

#endif /* OPENSSL_EXTRA || OPENSSL_EXTRA_X509_SMALL */

#endif /* WOLFSSL_OPENSSL_ERR_ */

