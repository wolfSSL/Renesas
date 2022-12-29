/* wolfcaam_rsa.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfssl/wolfcrypt/settings.h>

#ifndef WOLFCAAM_RSA_H
#define WOLFCAAM_RSA_H

#if !defined(NO_RSA) && defined(WOLFSSL_CAAM)

#include <wolfssl/wolfcrypt/rsa.h>

WOLFSSL_LOCAL int wc_CAAM_Rsa(const byte* in, word32 inLen, byte* out,
    word32* outLen, int type, RsaKey* key, WC_RNG* rng);
#ifdef WOLFSSL_KEY_GEN
WOLFSSL_LOCAL int wc_CAAM_MakeRsaKey(RsaKey* key, int size, long e,
    WC_RNG* rng);
#endif

#endif /* !NO_RSA && WOLFSSL_CAAM */
#endif /* WOLFCAAM_RSA_H */

