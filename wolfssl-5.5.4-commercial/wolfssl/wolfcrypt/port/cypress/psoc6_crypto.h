/* psoc6_crypto.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef _PSOC6_CRYPTO_PORT_H_
#define _PSOC6_CRYPTO_PORT_H_

#include <wolfssl/wolfcrypt/settings.h>
#include "cy_crypto_core_sha.h"
#include "cy_device_headers.h"
#include "psoc6_02_config.h"
#include "cy_crypto_common.h"
#include "cy_crypto_core.h"


#ifdef WOLFSSL_SHA512
#include <wolfssl/wolfcrypt/sha512.h>
#endif

#ifndef NO_SHA256
#include <wolfssl/wolfcrypt/sha.h>
#include <wolfssl/wolfcrypt/sha256.h>
#endif /* !def NO_SHA256 */


#ifdef HAVE_ECC
#include <wolfssl/wolfcrypt/ecc.h>
int psoc6_ecc_verify_hash_ex(mp_int *r, mp_int *s, const byte* hash,
                    word32 hashlen, int* verif_res, ecc_key* key);
#endif /* HAVE_ECC */

#define PSOC6_CRYPTO_BASE ((CRYPTO_Type*) CRYPTO_BASE)

/* Crypto HW engine initialization */
int psoc6_crypto_port_init(void);

#endif /* _PSOC6_CRYPTO_PORT_H_ */
