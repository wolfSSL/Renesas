/* util.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef _UTIL_H_
#define _UTIL_H_
#include "common/user_settings.h"
#include <wolfssl/ssl.h>
#include "FreeRTOS_IP.h"
#include <stdio.h>

static void util_Cleanup(xSocket_t xSock, WOLFSSL_CTX *ctx, WOLFSSL *ssl) {
    printf("Cleaning up socket and wolfSSL objects.\n");
    if (xSock != NULL)
        FreeRTOS_closesocket(xSock);
    if (ssl != NULL)
        wolfSSL_free(ssl);
    if (ctx != NULL)
        wolfSSL_CTX_free(ctx);
    wolfSSL_Cleanup();
}

static inline void util_inf_loop(xSocket_t xClientSocket, WOLFSSL_CTX *ctx,
        WOLFSSL *ssl) {
    util_Cleanup(xClientSocket, ctx, ssl);
    printf("Reached infinite loop.\n");
    while (1)
        ;
}

#endif /* _UTIL_H */
