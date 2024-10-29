/* port/ti/ti_ccm.c
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_TI_CCM_H
#define WOLF_CRYPT_TI_CCM_H

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/types.h>

#if defined(WOLFSSL_TI_CRYPT) ||  defined(WOLFSSL_TI_HASH)

int wolfSSL_TI_CCMInit(void) ;

#ifndef SINGLE_THREADED
void wolfSSL_TI_lockCCM(void) ;
void wolfSSL_TI_unlockCCM(void) ;
#else
#define wolfSSL_TI_lockCCM() WC_DO_NOTHING
#define wolfSSL_TI_unlockCCM() WC_DO_NOTHING
#endif

#endif

#endif

