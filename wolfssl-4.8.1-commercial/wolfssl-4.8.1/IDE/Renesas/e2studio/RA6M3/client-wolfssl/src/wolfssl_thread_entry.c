/* wolfssl_thread_entry.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* wolfSSL */
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/ssl.h>
#include <wolfssl/wolfio.h>
#include "wolfssl_thread_entry.h"

/* FreeRTOS */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"

/* Project Specific */
#include "common/util.h"
#include <stdio.h>

void wolfssl_thread_entry(void *pvParameters) {
    FSP_PARAMETER_NOT_USED(pvParameters);

    /* FreeRTOS+TCP Objects */
    BaseType_t fr_status;
    socklen_t xSize = sizeof(struct freertos_sockaddr);
    xSocket_t xClientSocket = NULL;
    struct freertos_sockaddr xRemoteAddress;

    /* Return status */
    int ret = WOLFSSL_FAILURE;

    /* Message to send and buffer for receive. */
    const char msg[] = "Hello from wolfSSL client.";
    char buff[256];

    /* wolfSSL objects */
    WOLFSSL_CTX *ctx = NULL;
    WOLFSSL *ssl = NULL;

    /* Output to Renesas Debug Virtual Console */
    initialise_monitor_handles();
#ifdef DEBUG_WOLFSSL
    wolfSSL_Debugging_ON();
#endif

    /* FreeRTOS+TCP Ethernet and IP Setup */
    fr_status = FreeRTOS_IPInit(ucIPAddress,
                                ucNetMask,
                                ucGatewayAddress,
                                ucDNSServerAddress,
                                g_ether0_mac_address);
    if (pdPASS != fr_status) {
        printf("Error [%ld]: FreeRTOS_IPInit.\n",fr_status);
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* Client Socket Setup */
    xRemoteAddress.sin_port = FreeRTOS_htons(DEFAULT_PORT);
    xRemoteAddress.sin_addr = FreeRTOS_inet_addr(SERVER_IP);

    /* Create a FreeRTOS TCP Socket and connect */
    xClientSocket = FreeRTOS_socket(FREERTOS_AF_INET,
                                    FREERTOS_SOCK_STREAM,
                                    FREERTOS_IPPROTO_TCP);
    configASSERT(xClientSocket != FREERTOS_INVALID_SOCKET);
    FreeRTOS_bind(xClientSocket, &xRemoteAddress, sizeof(xSize));

    /* Client Socket Connect */
    ret = FreeRTOS_connect(xClientSocket,
                           &xRemoteAddress,
                           sizeof(xRemoteAddress));
    if (ret != FR_SOCKET_SUCCESS) {
        printf("Error [%d]: FreeRTOS_connect.\n",ret);
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* TLS Connection Setup */
    /* Initialize wolfSSL */
    wolfSSL_Init();

    /* Create and initialize WOLFSSL_CTX */
    ctx = wolfSSL_CTX_new(wolfSSLv23_client_method_ex((void *)NULL));
    if (ctx == NULL) {
        printf("Error: wolfSSL_CTX_new.\n");
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* Load client certificates into WOLFSSL_CTX */
    ret = wolfSSL_CTX_load_verify_buffer(ctx, CERT, SIZEOF_CERT,
                                         WOLFSSL_FILETYPE_ASN1);
    if (ret != WOLFSSL_SUCCESS) {
        printf("Error [%d]: wolfSSL_CTX_load_verify_buffer.\n",ret);
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* Create a WOLFSSL object */
    ssl = wolfSSL_new(ctx);
    if (ssl == NULL) {
        printf("Error: wolfSSL_new.\n");
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* Attach wolfSSL to the socket */
    ret = wolfSSL_set_fd(ssl, (int) xClientSocket);
    if (ret != WOLFSSL_SUCCESS) {
        printf("Error [%d]: wolfSSL_set_fd.\n",ret);
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* Connect to wolfSSL on the server side */
    ret = wolfSSL_connect(ssl);
    if (ret != WOLFSSL_SUCCESS) {
        ret = wolfSSL_get_error(ssl, ret);
        printf("Error [%d]: wolfSSL_connect.\n",ret);
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* Send the message to the server */
    ret = wolfSSL_write(ssl, msg, (int) XSTRLEN(msg));
    if (ret < 0) {
        printf("Error: wolfSSL_write.\n");
        util_inf_loop(xClientSocket, ctx, ssl);
    }

    /* Read the server data into buff array */
    XMEMSET(buff, 0, sizeof(buff));
    ret = wolfSSL_read(ssl, buff, sizeof(buff) - 1);

    /* Shutdown TLS connection */
    wolfSSL_shutdown(ssl);

    /* Cleanup */
    util_inf_loop(xClientSocket, ctx, ssl);
}
