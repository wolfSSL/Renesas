/* myprintf.c
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#include "SEGGER_RTT.h"

#define SEGGER_INDEX            (0)

int myprintf(const char * sFormat, ...)
{
    int r;
    va_list ParamList;

    va_start(ParamList, sFormat);
    r = SEGGER_RTT_vprintf(0, sFormat, &ParamList);
    va_end(ParamList);
    return r;
}
