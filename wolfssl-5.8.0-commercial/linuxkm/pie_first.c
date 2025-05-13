/* linuxkm/pie_first.c -- memory fenceposts for checking binary image stability
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef __PIE__
    #error pie_first.c must be compiled -fPIE.
#endif

#include <wolfssl/wolfcrypt/libwolfssl_sources.h>

#include <wolfssl/ssl.h>

int wolfCrypt_PIE_first_function(void);
int wolfCrypt_PIE_first_function(void) {
    return 0;
}

const unsigned int wolfCrypt_PIE_rodata_start[];
const unsigned int wolfCrypt_PIE_rodata_start[] =
/* random values, analogous to wolfCrypt_FIPS_ro_{start,end} */
{ 0x8208f9ca, 0x9daf4ac9 };
