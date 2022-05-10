/* psa.c
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>

#if defined(WOLFSSL_HAVE_PSA)

#include <psa/crypto.h>

#include <wolfssl/wolfcrypt/port/psa/psa.h>

#include <wolfssl/wolfcrypt/error-crypt.h>
#include <wolfssl/wolfcrypt/types.h>

#if defined(WOLFSSL_PSA_GLOBAL_LOCK)
static wolfSSL_Mutex psa_global_mutex;

void PSA_LOCK()
{
    /* ideally we should propagate the return error here. Leaving out for code
       simplicity for now. */
    wc_LockMutex(&psa_global_mutex);
}

void PSA_UNLOCK()
{
    wc_UnLockMutex(&psa_global_mutex);
}

#endif


int wc_psa_init()
{
    psa_status_t s;

#if defined(WOLFSSL_PSA_GLOBAL_LOCK)
    wc_InitMutex(&psa_global_mutex);
#endif

    PSA_LOCK();
    s = psa_crypto_init();
    PSA_UNLOCK();
    if (s != PSA_SUCCESS)
        return WC_HW_E;

    return 0;
}

#if !defined(WOLFSSL_PSA_NO_RNG)
/**
 * wc_psa_get_random() - generate @size random bytes in @out
 * @out: output buffer
 * @size: number of random bytes to generate
 *
 * return: 0 on success
 */
int wc_psa_get_random(unsigned char *out, word32 sz)
{
    psa_status_t s;

    PSA_LOCK();
    s = psa_generate_random((uint8_t*)out, sz);
    PSA_UNLOCK();
    if (s != PSA_SUCCESS)
        return WC_HW_E;

    return 0;
}
#endif

#endif /* WOLFSSL_HAVE_PSA */
