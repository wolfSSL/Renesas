/* ed448.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ed448.h */

#ifndef WOLFSSL_ED448_H_
#define WOLFSSL_ED448_H_

#ifdef __cplusplus
extern "C" {
#endif

WOLFSSL_API
int wolfSSL_ED448_generate_key(unsigned char *priv, unsigned int *privSz,
                               unsigned char *pub, unsigned int *pubSz);
WOLFSSL_API
int wolfSSL_ED448_sign(const unsigned char *msg, unsigned int msgSz,
                       const unsigned char *priv, unsigned int privSz,
                       unsigned char *sig, unsigned int *sigSz);
WOLFSSL_API
int wolfSSL_ED448_verify(const unsigned char *msg, unsigned int msgSz,
                         const unsigned char *pub, unsigned int pubSz,
                         const unsigned char *sig, unsigned int sigSz);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* header */
