/* evp.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



/*  evp.h defines mini evp openssl compatibility layer
 *
 */

#ifndef CYASSL_OPENSSL_EVP
#define CYASSL_OPENSSL_EVP

#define CyaSSL_StoreExternalIV       wolfSSL_StoreExternalIV
#define CyaSSL_SetInternalIV         wolfSSL_SetInternalIV
#define CYASSL_EVP_MD                WOLFSSL_EVP_MD
#define CyaSSL_EVP_X_STATE           wolfSSL_EVP_X_STATE
#define CyaSSL_EVP_X_STATE_LEN       wolfSSL_EVP_X_STATE_LEN
#define CyaSSL_3des_iv               wolfSSL_3des_iv
#define CyaSSL_aes_ctr_iv            wolfSSL_aes_ctr_iv

#include <wolfssl/openssl/evp.h>
#endif

