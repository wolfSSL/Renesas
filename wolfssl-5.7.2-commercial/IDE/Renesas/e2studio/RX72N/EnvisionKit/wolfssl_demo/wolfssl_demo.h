/* wolfssl_demo.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_DEMO_H_
#define WOLFSSL_DEMO_H_


/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/* Include logging header files and define logging macros in the following order:
 * 1. Include the header file "logging_levels.h".
 * 2. Define the LIBRARY_LOG_NAME and LIBRARY_LOG_LEVEL macros depending on
 * the logging configuration for DEMO.
 * 3. Include the header file "logging_stack.h", if logging is enabled for DEMO.
 */

#include "logging_levels.h"

/* Logging configuration for the Demo. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "WOLFSSL_Demo"
#endif

#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_INFO
#endif
#include "logging_stack.h"
#include "wolfssl/ssl.h"

/* Enable wolfcrypt test demo */
/*#define CRYPT_TEST */

/* Enable benchmark demo      */
/*#define BENCHMARK*/

/* Enable TLS client demo     */
/* cannot enable with other definition */
#define TLS_CLIENT

/* use multi-thread example */
/* #define TLS_MULTITHREAD_TEST */
#if defined(TLS_MULTITHREAD_TEST) && defined(WOLFSSL_TLS13)
    #error "MULTITHREAD_TEST is only available when not set WOLFSSL_TLS13 \
           because it is not verified yet."
#endif

#if defined(TLS_MULTITHREAD_TEST)
 #define THREAD_STACK_SIZE (5 * 1024)
#endif

typedef struct tagTestInfo
{
     int  id;
     int  port;
     char name[32];
     const char* cipher;
     WOLFSSL_CTX* ctx;
     wolfSSL_Logging_cb log_f;
#if defined(TLS_MULTITHREAD_TEST)
     SemaphoreHandle_t xBinarySemaphore;
#endif
} TestInfo;


#endif /* WOLFSSL_DEMO_H_ */
