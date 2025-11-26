/* app_print.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "hal_data.h"

static char         g_uart_buf[256];        ///< uart tx buffer
extern volatile uint32_t g_tx_complete;
void uart_printf( const char *format, ... );

void uart_printf( const char *format, ... )
{
    va_list  va;
    uint32_t bytes;
    uint32_t offset, len, skip;
    char  chara;
    const char ch = '\r';
    char* p;

    va_start( va, format );
    bytes =  (uint32_t)vsprintf(g_uart_buf, format, va);
    va_end( va );

    if (bytes > 0) {
        p = &g_uart_buf[0];
        offset = 0;
        skip = 0;

        do {
            len = 0;
            skip = 0;
            for (;offset < bytes; offset++, len++) {
                chara = g_uart_buf[offset];
                if ('\n' == chara) {
                    skip = 1;
                    len += 1;
                    break;
                }
                if ('\r' == chara && (offset + 1) < bytes &&
                        '\n' == g_uart_buf[offset + 1]){
                    skip = 2;
                    len += 2;
                    break;
                }
            }
            /* write buffer without LF */
            R_SCI_UART_Write(&g_uart0_ctrl, (uint8_t*)p, len);
            while(!g_tx_complete);
            g_tx_complete = 0;
            if (skip > 0) {
                R_SCI_UART_Write(&g_uart0_ctrl, (uint8_t*)&ch, 1);
                while(!g_tx_complete);
            }
            p += (len + skip);
            offset += skip;
        } while(offset < bytes);
    }


    g_tx_complete = 0;
}
