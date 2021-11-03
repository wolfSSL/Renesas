/* blake2.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifdef HAVE_BLAKE2

#ifndef CTAOCRYPT_BLAKE2_H
#define CTAOCRYPT_BLAKE2_H

#include <wolfssl/wolfcrypt/blake2.h>

/* for blake2 reverse compatibility */
#ifndef HAVE_FIPS
    #define InitBlake2b   wc_InitBlake2b
    #define Blake2bUpdate wc_Blake2bUpdate
    #define Blake2bFinal  wc_Blake2bFinal
#else
    /* name for when fips hmac calls blake */
    #define wc_InitBlake2b   InitBlake2b
    #define wc_Blake2bUpdate Blake2bUpdate
    #define wc_Blake2bFinal  Blake2bFinal
#endif /* HAVE_FIPS */

#endif  /* CTAOCRYPT_BLAKE2_H */
#endif  /* HAVE_BLAKE2 */

