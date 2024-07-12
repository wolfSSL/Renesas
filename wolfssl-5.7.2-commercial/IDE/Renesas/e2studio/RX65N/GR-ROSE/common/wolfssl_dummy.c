/* wolfssl_dummy.c
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfssl/wolfcrypt/wc_port.h>

#define YEAR 2023
#define MON  6

static int tick = 0;

time_t time(time_t *t)
{
    (void)t;
    return ((YEAR-1970)*365+30*MON)*24*60*60 + tick++;
}

#include <ctype.h>
int strncasecmp(const char *s1, const char * s2, unsigned int sz)
{
    for( ; sz>0; sz--)
        if(toupper(s1++) != toupper(s2++))
        return 1;
    return 0;
}

#if !defined(WOLFSSL_RENESAS_TSIP)
/* dummy return true when char is alphanumeric character */
int isascii(const char *s)
{
    return isalnum(s);
}
#endif

