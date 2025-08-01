/* aria-cryptocb.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*!
    \file wolfssl/wolfcrypt/port/aria/aria-cryptocb.h
*/
/*

DESCRIPTION
This library provides the interfaces to the ARIA cipher implementation for
signing, verifying and hashing data.

*/
#ifndef WOLF_CRYPT_ARIA_CRYPTOCB_H
#define WOLF_CRYPT_ARIA_CRYPTOCB_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
    extern "C" {
#endif

#include "mcapi.h"
#include "mcapi_error.h"

int wc_AriaInit(void);
int wc_AriaInitSha(MC_HSESSION* hSession, MC_ALGID algo);
int wc_AriaShaUpdate(MC_HSESSION hSession, byte* data, word32 len);
int wc_AriaShaFinal(MC_HSESSION hSession, byte* out, word32* len);
int wc_AriaFree(MC_HSESSION* hSession, MC_HOBJECT *obj1);

int wc_AriaSign(byte* in, word32 inSz, byte* out, word32* outSz, ecc_key* key);
int wc_AriaVerify(byte* sig, word32 sigSz, byte* hash, word32 hashSz, int* res, ecc_key* key);
int wc_AriaDerive(ecc_key* private_key, ecc_key* public_key, byte* out, word32* outSz);

#ifndef ARIA_KEYASN1_MAXSZ
#define ARIA_KEYASN1_MAXSZ 128
#endif

#ifdef WOLF_CRYPTO_CB

#define WOLFSSL_ARIA_DEVID 8
int wc_AriaCryptoCb(int devIdArg, wc_CryptoInfo* info, void* ctx);
#endif

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_ARIA_CRYPTOCB_H */
