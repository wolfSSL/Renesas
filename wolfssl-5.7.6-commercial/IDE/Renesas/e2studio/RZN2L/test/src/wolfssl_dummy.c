/* wolfssl_dummy.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfssl/wolfcrypt/wc_port.h>

#define YEAR 2023
#define MON  9

static int tick = 0;

time_t time(time_t *t)
{
    (void)t;
    return ((YEAR-1970)*365+30*MON)*24*60*60 + tick++;
}
