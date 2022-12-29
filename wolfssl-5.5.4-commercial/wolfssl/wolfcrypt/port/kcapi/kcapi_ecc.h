/* kcapi_ecc.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_KCAPI_ECC_H
#define WOLF_CRYPT_KCAPI_ECC_H

#define KCAPI_PARAM_SZ     2


#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/ecc.h>
#include <wolfssl/wolfcrypt/port/kcapi/wc_kcapi.h>


#ifndef WC_ECCKEY_TYPE_DEFINED
    typedef struct ecc_key ecc_key;
    #define WC_ECCKEY_TYPE_DEFINED
#endif

WOLFSSL_LOCAL void KcapiEcc_Free(ecc_key* key);
WOLFSSL_LOCAL int KcapiEcc_MakeKey(ecc_key* key, int keysize, int curve_id);
WOLFSSL_LOCAL int KcapiEcc_LoadKey(ecc_key* key, byte* pubkey_raw,
                  word32* pubkey_sz, int release_handle);
WOLFSSL_LOCAL int KcapiEcc_SharedSecret(ecc_key* private_key,
                  ecc_key* public_key, byte* out, word32* outlen);
WOLFSSL_LOCAL int KcapiEcc_Sign(ecc_key* key, const byte* hash, word32 hashLen,
                  byte* sig, word32 sigLen);
WOLFSSL_LOCAL int KcapiEcc_Verify(ecc_key* key, const byte* hash, word32 hashLen,
                  byte* sig, word32 sigLen);

#endif /* WOLF_CRYPT_KCAPI_ECC_H  */

