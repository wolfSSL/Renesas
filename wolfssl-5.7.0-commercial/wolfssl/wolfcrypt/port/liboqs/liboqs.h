/* liboqs.h
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
    \file wolfssl/wolfcrypt/port/liboqs/liboqs.h
*/
/*

DESCRIPTION
This library provides the support interfaces to the liboqs library providing
implementations for Post-Quantum cryptography algorithms.
*/

#ifndef WOLF_CRYPT_LIBOQS_H
#define WOLF_CRYPT_LIBOQS_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/random.h>


#ifdef __cplusplus
    extern "C" {
#endif

#if defined(HAVE_LIBOQS)

#include "oqs/oqs.h"
    

int wolfSSL_liboqsInit(void);

void wolfSSL_liboqsClose(void);

int wolfSSL_liboqsRngMutexLock(WC_RNG* rng);

int wolfSSL_liboqsRngMutexUnlock(void);

#endif /* HAVE_LIBOQS */

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_LIBOQS_H */
