/* logging.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


/* submitted by eof */


#ifndef CYASSL_LOGGING_H
#define CYASSL_LOGGING_H

/* for fips compatibility @wc_fips */
#include <wolfssl/wolfcrypt/logging.h>
#define CYASSL_LEAVE WOLFSSL_LEAVE
#define CYASSL_ERROR WOLFSSL_ERROR
#define CYASSL_ENTER WOLFSSL_ENTER
#define CYASSL_MSG   WOLFSSL_MSG
/* check old macros possibly declared */
#if defined(DEBUG_CYASSL) && !defined(DEBUG_WOLFSSL)
    #define DEBUG_WOLFSSL
#endif

#endif /* CYASSL_LOGGING_H */

