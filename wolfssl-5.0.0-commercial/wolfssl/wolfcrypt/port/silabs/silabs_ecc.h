/* silabs_ecc.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef _SILABS_ECC_H_
#define _SILABS_ECC_H_


#if defined(WOLFSSL_SILABS_SE_ACCEL)

#include <wolfssl/wolfcrypt/types.h>

#include <sl_se_manager.h>
#include <sl_se_manager_defines.h>
#include <sl_se_manager_key_derivation.h>
#include <sl_se_manager_signature.h>

typedef enum ecc_curve_id ecc_curve_id;
typedef struct ecc_key ecc_key;

int silabs_ecc_sign_hash (const byte* in, word32 inlen,
                          byte* out, word32 *outlen,
                          ecc_key* key);
int silabs_ecc_verify_hash (const byte* sig, word32 siglen,
                            const byte* hash, word32 hashlen,
                            int* stat, ecc_key* key);



int silabs_ecc_make_key(ecc_key* key, int keysize);

int silabs_ecc_import(ecc_key* key, word32 keysize);

int silabs_ecc_import_private(ecc_key* key, word32 keysize);

int silabs_ecc_sig_to_rs(ecc_key* key, word32 keySz);

int silabs_ecc_import_private_raw(ecc_key* key, word32 keySz, const char* d, int encType);

int silabs_ecc_shared_secret(ecc_key* private_key, ecc_key* public_key,
                             byte* out, word32* outlen);

#endif /* WOLFSSL_SILABS_SE_ACCEL */

#endif /* _SILABS_ECC_H_ */
