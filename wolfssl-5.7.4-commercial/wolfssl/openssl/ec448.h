/* ec448.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ec448.h */

#ifndef WOLFSSL_EC448_H_
#define WOLFSSL_EC448_H_

#include <wolfssl/openssl/compat_types.h>

#ifdef __cplusplus
extern "C" {
#endif

WOLFSSL_API
int wolfSSL_EC448_generate_key(unsigned char *priv, unsigned int *privSz,
                               unsigned char *pub, unsigned int *pubSz);

WOLFSSL_API
int wolfSSL_EC448_shared_key(unsigned char *shared, unsigned int *sharedSz,
                             const unsigned char *priv, unsigned int privSz,
                             const unsigned char *pub, unsigned int pubSz);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* header */
