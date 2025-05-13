/* libwolfssl_sources.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* In wolfSSL library sources, #include this file before any other #includes, to
 * assure BUILDING_WOLFSSL is defined.
 *
 * This file also includes the common headers needed by all sources.
 */

#ifndef LIBWOLFSSL_SOURCES_H
#define LIBWOLFSSL_SOURCES_H

#if defined(TEST_LIBWOLFSSL_SOURCES_INCLUSION_SEQUENCE) && \
    defined(WOLF_CRYPT_SETTINGS_H) &&                      \
    !defined(LIBWOLFSSL_SOURCES_ASM_H)
    #error settings.h included before libwolfssl_sources.h.
#endif

#ifndef BUILDING_WOLFSSL
    #define BUILDING_WOLFSSL
#endif

#if defined(HAVE_CONFIG_H) && !defined(WC_CONFIG_H_INCLUDED)
    #include <config.h>
    #define WC_CONFIG_H_INCLUDED
#endif

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/error-crypt.h>
#include <wolfssl/wolfcrypt/logging.h>

#endif /* LIBWOLFSSL_SOURCES_H */
