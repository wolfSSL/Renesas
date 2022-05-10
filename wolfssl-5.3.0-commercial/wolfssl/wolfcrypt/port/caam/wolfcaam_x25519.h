/* wolfcaam_x25519.h
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

#ifndef WOLFCAAM_X25519_H
#define WOLFCAAM_X25519_H

#if defined(HAVE_CURVE25519) && defined(WOLFSSL_CAAM)

#include <wolfssl/wolfcrypt/curve25519.h>

WOLFSSL_LOCAL int wc_CAAM_MakeCurve25519Key(curve25519_key* key, int keySize,
    WC_RNG* rng);
WOLFSSL_LOCAL int wc_CAAM_Curve25519(byte* out, word32* outlen,
    curve25519_key* k, curve25519_key* pubKey, int endian);

#endif /* !NO_RSA && WOLFSSL_CAAM */
#endif /* WOLFCAAM_X25519_H */

