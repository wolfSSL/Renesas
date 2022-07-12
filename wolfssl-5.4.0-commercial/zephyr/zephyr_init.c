/* zephyr_init.c
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/** @file
 * @brief wolfSSL initialization
 *
 * Initialize the wolfSSL library.
 */

#include <init.h>

#include "user_settings.h"
#include "wolfssl/ssl.h"

static int _wolfssl_init(const struct device *device)
{
    ARG_UNUSED(device);

    return 0;
}

SYS_INIT(_wolfssl_init, POST_KERNEL, 0);
