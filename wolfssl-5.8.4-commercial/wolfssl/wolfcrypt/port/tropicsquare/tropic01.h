/* tropic01.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef _WOLFPORT_TROPIC01_H_
#define _WOLFPORT_TROPIC01_H_

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/aes.h>
#include <wolfssl/wolfcrypt/ecc.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

#ifdef WOLF_CRYPTO_CB
#include <wolfssl/wolfcrypt/cryptocb.h>
#endif


#ifdef WOLFSSL_TROPIC01

/* The TROPIC01 interface layer */
/* Please contact wolfSSL for the TROPIC01 port files */
#define LT_USE_TREZOR_CRYPTO 1
#define LT_HELPERS

#include <libtropic.h>
#include <libtropic_common.h>


#ifdef WOLF_CRYPTO_CB

/* Device ID that's unique and valid (not INVALID_DEVID -2) */
#define WOLF_TROPIC01_DEVID 0x75757 /* TROPIC01 ID*/


#define TROPIC01_AES_MAX_KEY_SIZE 32
#define TROPIC01_PAIRING_KEY_SIZE 32
#define TROPIC01_ED25519_PRIV_KEY_SIZE 32
#define TROPIC01_ED25519_PUB_KEY_SIZE 32

/* R-Memory slots allocation */
#ifndef TROPIC01_AES_KEY_RMEM_SLOT
#define TROPIC01_AES_KEY_RMEM_SLOT 0
#endif /* TROPIC01_AES_KEY_RMEM_SLOT */

#ifndef TROPIC01_AES_IV_RMEM_SLOT
#define TROPIC01_AES_IV_RMEM_SLOT 1
#endif /* TROPIC01_AES_IV_RMEM_SLOT */

#ifndef TROPIC01_ED25519_PUB_RMEM_SLOT_DEFAULT
#define TROPIC01_ED25519_PUB_RMEM_SLOT_DEFAULT 2
#endif /* TROPIC01_ED25519_PUB_RMEM_SLOT_DEFAULT */

#ifndef TROPIC01_ED25519_PRIV_RMEM_SLOT_DEFAULT
#define TROPIC01_ED25519_PRIV_RMEM_SLOT_DEFAULT 3
#endif /* TROPIC01_ED25519_PRIV_RMEM_SLOT_DEFAULT */

#ifndef TROPIC01_ED25519_ECC_SLOT_DEFAULT
#define TROPIC01_ED25519_ECC_SLOT_DEFAULT 1
#endif /* TROPIC01_ED25519_ECC_SLOT_DEFAULT */

#ifndef PAIRING_KEY_SLOT_INDEX_0
#define PAIRING_KEY_SLOT_INDEX_0 0
#endif /* PAIRING_KEY_SLOT_INDEX_0 */

typedef struct {
    int keySlot;       /* Slot ID in TROPIC01 secure memory */
    word32 keySize;    /* Size of the key in bytes (16, 24, or 32) */
    byte keyType;      /* Type of key (e.g., AES_CBC, AES_GCM) */
    byte isValid;      /* Flag indicating if this reference is valid */
} Tropic01KeyRef;

/* Context for TROPIC01 secure element */
typedef struct {
    int initialized;
} Tropic01CryptoDevCtx;


WOLFSSL_API int Tropic01_Init(void);
WOLFSSL_API int Tropic01_Deinit(void);
WOLFSSL_API int Tropic01_SetPairingKeys(
    int kIndex, const byte* kPub, const byte* kPriv);
WOLFSSL_API int Tropic01_CryptoCb(int devId, wc_CryptoInfo* info, void* ctx);


#endif /* WOLF_CRYPTO_CB */

#endif /* WOLFSSL_TROPIC01*/

#endif /* _WOLFPORT_TROPIC01_H_ */
