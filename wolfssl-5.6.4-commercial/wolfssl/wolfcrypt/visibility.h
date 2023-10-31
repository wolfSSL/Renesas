/* visibility.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


/* Visibility control macros */

#ifndef WOLF_CRYPT_VISIBILITY_H
#define WOLF_CRYPT_VISIBILITY_H

/* WOLFSSL_API is used for the public API symbols.
        It either imports or exports (or does nothing for static builds)

   WOLFSSL_LOCAL is used for non-API symbols (private).
*/

#if defined(BUILDING_WOLFSSL)
    #if defined(_MSC_VER) || defined(__MINGW32__) || defined(__CYGWIN__) || \
        defined(_WIN32_WCE)
        #if defined(WOLFSSL_DLL)
            #define WOLFSSL_API __declspec(dllexport)
        #else
            #define WOLFSSL_API
        #endif
        #define WOLFSSL_LOCAL
    #elif defined(HAVE_VISIBILITY) && HAVE_VISIBILITY
        #define WOLFSSL_API   __attribute__ ((visibility("default")))
        #define WOLFSSL_LOCAL __attribute__ ((visibility("hidden")))
    #elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x550)
        #define WOLFSSL_API   __global
        #define WOLFSSL_LOCAL __hidden
    #else
        #define WOLFSSL_API
        #define WOLFSSL_LOCAL
    #endif /* HAVE_VISIBILITY */
#else /* BUILDING_WOLFSSL */
    #if defined(_MSC_VER) || defined(__MINGW32__) || defined(__CYGWIN__) || \
        defined(_WIN32_WCE)
        #if defined(WOLFSSL_DLL)
            #define WOLFSSL_API __declspec(dllimport)
        #else
            #define WOLFSSL_API
        #endif
        #define WOLFSSL_LOCAL
    #else
        #define WOLFSSL_API
        #define WOLFSSL_LOCAL
    #endif
#endif /* BUILDING_WOLFSSL */

/* WOLFSSL_ABI is used for public API symbols that must not change
 * their signature. This tag is used for all APIs that are a
 * part of the fixed ABI.
 */
#define WOLFSSL_ABI

#endif /* WOLF_CRYPT_VISIBILITY_H */
