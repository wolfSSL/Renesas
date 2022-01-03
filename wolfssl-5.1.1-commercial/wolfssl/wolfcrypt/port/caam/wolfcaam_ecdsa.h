/* wolfcaam_ecdsa.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfssl/wolfcrypt/settings.h>

#ifndef WOLFCAAM_ECDSA_H
#define WOLFCAAM_ECDSA_H

#if defined(HAVE_ECC) && defined(WOLFSSL_QNX_CAAM)

#include <wolfssl/wolfcrypt/ecc.h>

WOLFSSL_LOCAL int wc_CAAM_EccSign(const byte* in, int inlen, byte* out,
        word32* outlen, WC_RNG *rng, ecc_key *key);
WOLFSSL_LOCAL int wc_CAAM_EccVerify(const byte* sig, word32 siglen,
        const byte* hash, word32 hashlen, int* res, ecc_key* key);
WOLFSSL_LOCAL int wc_CAAM_Ecdh(ecc_key* private_key, ecc_key* public_key,
        byte* out, word32* outlen);
WOLFSSL_LOCAL int wc_CAAM_MakeEccKey(WC_RNG* rng, int keySize, ecc_key* key,
        int curveId);
WOLFSSL_LOCAL int wc_CAAM_EccCheckPrivKey(ecc_key* key, const byte* pubKey,
        word32 pubKeySz);
#endif /* HAVE_ECC && WOLFSSL_QNX_CAAM */
#endif /* WOLFCAAM_ECDSA_H */
