/* kcapi_rsa.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_KCAPI_RSA_H
#define WOLF_CRYPT_KCAPI_RSA_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/rsa.h>
#include <wolfssl/wolfcrypt/port/kcapi/wc_kcapi.h>

#ifndef WC_RSAKEY_TYPE_DEFINED
    typedef struct RsaKey RsaKey;
    #define WC_RSAKEY_TYPE_DEFINED
#endif

void KcapiRsa_Free(RsaKey* key);
int KcapiRsa_Decrypt(RsaKey* key, const byte* in, word32 inLen, byte* out,
                     word32* outLen);
int KcapiRsa_Encrypt(RsaKey* key, const byte* in, word32 inLen, byte* out,
                     word32* outLen);

#endif /* WOLF_CRYPT_KCAPI_RSA_H  */

