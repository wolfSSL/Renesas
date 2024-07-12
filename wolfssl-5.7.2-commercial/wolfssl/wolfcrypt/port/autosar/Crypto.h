/* Crypto.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_CRYPTO_H
#define WOLFSSL_CRYPTO_H

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h>

#ifdef __cplusplus
    extern "C" {
#endif

/* key format */
enum {
    CRYPTO_KE_FORMAT_BIN_OCTET = 0x01,
    CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY = 0x05,
    CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY = 0x06
};

/* implementation specific structure, for now not used */
typedef struct Crypto_ConfigType {
    void* heap;
} Crypto_ConfigType;

WOLFSSL_LOCAL Std_ReturnType Crypto_KeyElementSet(uint32 keyId, uint32 eId,
        const uint8* key, uint32 keySz);
WOLFSSL_LOCAL void Crypto_Init(const Crypto_ConfigType* config);
WOLFSSL_LOCAL Std_ReturnType Crypto_ProcessJob(uint32 objectId,
        Crypto_JobType* job);

#ifdef __cplusplus
    }  /* extern "C" */
#endif

#endif /* WOLFSSL_CRYPTO_H */

