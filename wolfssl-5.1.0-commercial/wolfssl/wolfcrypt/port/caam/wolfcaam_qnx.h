/* wolfcaam_qnx.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


/* This file is for interacting with the driver code */
#ifndef WOLFCAAM_QNX_H
#define WOLFCAAM_QNX_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_QNX_CAAM
#include <sys/iofunc.h>
#include <sys/neutrino.h>

#define Error int
#define Value int
#define Boolean int
#define Success 1
#define Failure 0
#define INTERRUPT_Panic()
#define MemoryMapMayNotBeEmpty -1
#define CAAM_WAITING -2
#define NoActivityReady -1
#define MemoryOperationNotPerformed -1

#define CAAM_ADDRESS unsigned int
#ifndef WOLFSSL_CAAM_BUFFER
#define WOLFSSL_CAAM_BUFFER
    typedef struct CAAM_BUFFER {
        int BufferType;
        CAAM_ADDRESS TheAddress;
        int Length;
    } CAAM_BUFFER;
#endif


/* IMX6UL */
#define CAAM_BASE 0x02140000
#define CAAM_PAGE 0x00100000

#define DataBuffer 0
#define LastBuffer 0
#define Success 1

/* unique devId for CAAM use on crypto callbacks */
#define WOLFSSL_CAAM_DEVID 7

#include <wolfssl/wolfcrypt/port/caam/wolfcaam_ecdsa.h>
#include <wolfssl/wolfcrypt/port/caam/wolfcaam_cmac.h>
#include <wolfssl/wolfcrypt/cryptocb.h>

#define ResourceNotAvailable -3
#define CAAM_WAITING -2

WOLFSSL_LOCAL int SynchronousSendRequest(int type, unsigned int args[4],
        CAAM_BUFFER *buf, int sz);
WOLFSSL_LOCAL int wc_CAAMInitInterface(void);
WOLFSSL_LOCAL void wc_CAAMFreeInterface(void);

#define CAAM_SEND_REQUEST(type, sz, arg, buf) \
        SynchronousSendRequest((type), (arg), (buf), (sz))
#define CAAM_INIT_INTERFACE wc_CAAMInitInterface
#define CAAM_FREE_INTERFACE wc_CAAMFreeInterface
#endif

#endif /* WOLFCAAM_QNX_H */
