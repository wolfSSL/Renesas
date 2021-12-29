/* freertos_tcp_port.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include "bsp_api.h"
#include "FreeRTOS.h"
#include "FreeRTOS_sockets.h"
#include "FreeRTOS_IP.h"
#include <stdlib.h>

#define HOSTNAME "wolfssl_ra6m3g"

/*
 * Contains callback functions for FreeRTOS+TCP
 * The following implementations are NOT SUITABLE FOR PRODUCTION.
 * They currently serve to build the projects and are not secure.
 */

uint32_t ulApplicationGetNextSequenceNumber(uint32_t ulSourceAddress,
                                            uint16_t usSourcePort,
                                            uint32_t ulDestinationAddress,
                                            uint16_t usDestinationPort);

const char *pcApplicationHostnameHook(void) {
    return HOSTNAME;
}

uint32_t ulRand(void) {
    return (uint32_t) rand();
}

/* Disabled in RA Configuration. Re-Enable within FreeRTOS+TCP Stack Properties */
void vApplicationIPNetworkEventHook(eIPCallbackEvent_t eNetworkEvent) {
    (void) eNetworkEvent;
}

uint32_t ulApplicationGetNextSequenceNumber(uint32_t ulSourceAddress,
                                            uint16_t usSourcePort,
                                            uint32_t ulDestinationAddress,
                                            uint16_t usDestinationPort)
{
    (void) ulSourceAddress;
    (void) usSourcePort;
    (void) ulDestinationAddress;
    (void) usDestinationPort;

    return ulRand();
}
