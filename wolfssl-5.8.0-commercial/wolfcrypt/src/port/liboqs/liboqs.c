/* liboqs.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfssl/wolfcrypt/libwolfssl_sources.h>

/*

DESCRIPTION
This library provides the support interfaces to the liboqs library providing
implementations for Post-Quantum cryptography algorithms.

*/

#include <wolfssl/wolfcrypt/port/liboqs/liboqs.h>

#if defined(HAVE_LIBOQS)

/* RNG for liboqs */
static WC_RNG liboqsDefaultRNG;
static WC_RNG* liboqsCurrentRNG;

static wolfSSL_Mutex liboqsRNGMutex;

static int liboqs_init = 0;


static void wolfSSL_liboqsGetRandomData(uint8_t* buffer, size_t numOfBytes)
{
    int ret;
    word32 numOfBytes_word32;

    while (numOfBytes > 0) {
        numOfBytes_word32 = (word32)numOfBytes;
        numOfBytes -= numOfBytes_word32;
        ret = wc_RNG_GenerateBlock(liboqsCurrentRNG, buffer,
                                   numOfBytes_word32);
        if (ret != 0) {
            /* ToDo: liboqs exits program if RNG fails,
             * not sure what to do here
             */
            WOLFSSL_MSG_EX(
                "wc_RNG_GenerateBlock(..., %u) failed with ret %d "
                "in wolfSSL_liboqsGetRandomData().", numOfBytes_word32, ret
                );
            abort();
        }
    }
}

int wolfSSL_liboqsInit(void)
{
    int ret = 0;

    if (liboqs_init == 0) {
        ret = wc_InitMutex(&liboqsRNGMutex);
        if (ret != 0) {
            return ret;
        }
        ret = wc_LockMutex(&liboqsRNGMutex);
        if (ret != 0) {
            return ret;
        }
        ret = wc_InitRng(&liboqsDefaultRNG);
        if (ret == 0) {
            OQS_init();
            liboqs_init = 1;
        }
        liboqsCurrentRNG = &liboqsDefaultRNG;
        wc_UnLockMutex(&liboqsRNGMutex);

        OQS_randombytes_custom_algorithm(wolfSSL_liboqsGetRandomData);
    }

    return ret;
}

void wolfSSL_liboqsClose(void)
{
    wc_FreeRng(&liboqsDefaultRNG);
}

int wolfSSL_liboqsRngMutexLock(WC_RNG* rng)
{
    int ret = wolfSSL_liboqsInit();
    if (ret == 0) {
        ret = wc_LockMutex(&liboqsRNGMutex);
    }
    if (ret == 0 && rng != NULL) {
        /* Update the pointer with the RNG to use. This is safe as we locked the mutex */
        liboqsCurrentRNG = rng;
    }
    return ret;
}

int wolfSSL_liboqsRngMutexUnlock(void)
{
    liboqsCurrentRNG = &liboqsDefaultRNG;

    if (liboqs_init) {
        return wc_UnLockMutex(&liboqsRNGMutex);
    }
    else {
        return BAD_MUTEX_E;
    }
}

#endif /* HAVE_LIBOQS */
