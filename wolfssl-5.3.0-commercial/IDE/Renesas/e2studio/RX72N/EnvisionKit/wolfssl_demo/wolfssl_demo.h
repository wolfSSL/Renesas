/* wolfssl_demo.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
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




/* Enable wolfcrypt test demo */
/*#define CRYPT_TEST*/

/* Enable benchmark demo      */
/*#define BENCHMARK*/

/* Enable TLS client demo     */
/* cannot enable with other definition */
#define TLS_CLIENT


#endif /* WOLFSSL_DEMO_H_ */
