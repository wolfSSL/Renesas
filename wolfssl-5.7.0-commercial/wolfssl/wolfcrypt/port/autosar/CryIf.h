/* CryIf.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_CRYIF_H
#define WOLFSSL_CRYIF_H

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h>

#ifdef __cplusplus
    extern "C" {
#endif

/* implementation specific structure, for now not used */
typedef struct CryIf_ConfigType {
    void* heap;
} CryIf_ConfigType;

WOLFSSL_LOCAL void CryIf_Init(const CryIf_ConfigType* in);
WOLFSSL_LOCAL void CryIf_GetVersionInfo(Std_VersionInfoType* ver);
WOLFSSL_LOCAL Std_ReturnType CryIf_ProcessJob(uint32 id, Crypto_JobType* job);
WOLFSSL_LOCAL Std_ReturnType CryIf_CancelJob(uint32 id, Crypto_JobType* job);
WOLFSSL_LOCAL Std_ReturnType CryIf_KeyElementSet(uint32 keyId, uint32 eId,
        const uint8* key, uint32 keySz);

#ifdef __cplusplus
    }  /* extern "C" */
#endif

#endif /* WOLFSSL_CRYIF_H */

