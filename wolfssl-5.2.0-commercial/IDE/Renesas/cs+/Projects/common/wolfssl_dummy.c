/* wolfssl_dummy.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>

#include <wolfssl/ssl.h>
#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/error-crypt.h>
#include <stdio.h>

#define YEAR 2018
#define MON  5

static int tick = 0;

time_t time(time_t *t)
{
    return ((YEAR-1970)*365+30*MON)*24*60*60 + tick++;
}

#include <ctype.h>
int strncasecmp(const char *s1, const char * s2, unsigned int sz)
{
    for( ; sz>0; sz--, s1++, s2++){
            if(toupper(*s1) < toupper(*s2)){
            return -1;
        }
        if(toupper(*s1) > toupper(*s2)){
            return 1;
        }
    }
    return 0;	
}
    
void abort(void) 
{
    while(1);
}


