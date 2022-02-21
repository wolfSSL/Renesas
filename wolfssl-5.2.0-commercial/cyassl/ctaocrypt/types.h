/* types.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef CTAO_CRYPT_TYPES_H
#define CTAO_CRYPT_TYPES_H

#include <cyassl/ctaocrypt/wc_port.h>
#include <cyassl/ctaocrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h>

/* compatibility macros */
#define CYASSL_WORD_SIZE    WOLFSSL_WORD_SIZE
#define CYASSL_BIT_SIZE     WOLFSSL_BIT_SIZE
#define CYASSL_MAX_16BIT    WOLFSSL_MAX_16BIT
#define CYASSL_MAX_ERROR_SZ WOLFSSL_MAX_ERROR_SZ
#define cyassl_word         wolfssl_word

#endif /* CTAO_CRYPT_TYPES_H */

