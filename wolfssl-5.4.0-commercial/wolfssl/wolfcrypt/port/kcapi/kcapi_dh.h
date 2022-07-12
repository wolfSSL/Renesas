/* kcapi_dh.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_KCAPI_DH_H
#define WOLF_CRYPT_KCAPI_DH_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/dh.h>
#include <wolfssl/wolfcrypt/port/kcapi/wc_kcapi.h>

#ifndef WC_DH_TYPE_DEFINED
    typedef struct DhKey DhKey;
    #define WC_DH_TYPE_DEFINED
#endif

void KcapiDh_Free(DhKey* key);
int KcapiDh_MakeKey(DhKey* key, byte* pub, word32* pubSz);
int KcapiDh_SharedSecret(DhKey* private_key, const byte* pub, word32 pubSz,
                         byte* out, word32* outlen);

#endif /* WOLF_CRYPT_KCAPI_DH_H  */

