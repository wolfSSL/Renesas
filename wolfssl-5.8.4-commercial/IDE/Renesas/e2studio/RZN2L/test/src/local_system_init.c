/* local_system_init.c
 *
 * Custom configuration for wolfCrypt/wolfSSL.
 * Enabled via WOLFSSL_USER_SETTINGS.
 *
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#include "bsp_api.h"

void local_system_init (void);

BSP_TARGET_ARM void local_system_init (void)
{
#if 1
    /* This software loops are only needed when debugging. */
    __asm volatile (
        "    mov   r0, #0                         \n"
        "    movw  r1, #0xf07f                    \n"
        "    movt  r1, #0x2fa                     \n"
        "software_loop:                           \n"
        "    adds  r0, #1                         \n"
        "    cmp   r0, r1                         \n"
        "    bne   software_loop                  \n"
        ::: "memory");
#endif
    __asm volatile (
        "set_vbar:                           \n"
        "    LDR   r0, =__Vectors            \n"
        "    MCR   p15, #0, r0, c12, c0, #0  \n" /* Write r0 to VBAR */
        ::: "memory");

    __asm volatile (
        "jump_stack_init:                      \n"
        "    ldr r0, =stack_init               \n"
        "    blx r0                            \n" /* Jump to stack_init */
        );
}
