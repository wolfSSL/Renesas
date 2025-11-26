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

static int tick = 0;
#define YEAR  ( \
    ((__DATE__)[7]  - '0') * 1000 + \
    ((__DATE__)[8]  - '0') * 100  + \
    ((__DATE__)[9]  - '0') * 10   + \
    ((__DATE__)[10] - '0') * 1      \
)

#define MONTH ( \
    __DATE__[2] == 'n' ? (__DATE__[1] == 'a' ? 1 : 6) \
  : __DATE__[2] == 'b' ? 2 \
  : __DATE__[2] == 'r' ? (__DATE__[0] == 'M' ? 3 : 4) \
  : __DATE__[2] == 'y' ? 5 \
  : __DATE__[2] == 'l' ? 7 \
  : __DATE__[2] == 'g' ? 8 \
  : __DATE__[2] == 'p' ? 9 \
  : __DATE__[2] == 't' ? 10 \
  : __DATE__[2] == 'v' ? 11 \
  : 12 \
	)

time_t time(time_t *t)
{
    (void)t;
    return ((YEAR-1970)*365+30*MONTH)*24*60*60 + tick++;
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

