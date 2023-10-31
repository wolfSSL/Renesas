/* wolfssl_demo.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_DEMO_H_
#define WOLFSSL_DEMO_H_

#include <wolfssl/ssl.h>
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"

#define FREQ 10000 /* Hz */

/* Client connects to the server with these details. */
#define SERVER_IP    "192.168.11.65"
#define DEFAULT_PORT 11111

typedef struct tagTestInfo
{
     int  id;
     int  port;
     char name[32];
     const char* cipher;
     WOLFSSL_CTX* ctx;
} TestInfo;

/* Enable Crypt Unit Test */
/* #define UNIT_TEST */

/* Enable wolfcrypt test */
/* can be enabled with benchmark test */
#define CRYPT_TEST

/* Enable benchmark               */
/* can be enabled with cyrpt test */
/* #define BENCHMARK */

/* Enable TLS client */
/* #define TLS_CLIENT */

/* Enable TLS Server */
/* #define TLS_SERVER */

#if defined(TLS_CLIENT)
    extern WOLFSSL_CTX *client_ctx;

    /* Use RSA certificates */
    #define USE_CERT_BUFFERS_2048
    /* Use ECC certificates */
    /*#define USE_CERT_BUFFERS_256*/
#endif

#if defined(TLS_SERVER)
    extern WOLFSSL_CTX *server_ctx;

    /* Use RSA certificates */
    #define USE_CERT_BUFFERS_2048
    /* Use ECC certificates */
    /*#define USE_CERT_BUFFERS_256*/
#endif

#if defined(USE_CERT_BUFFERS_2048) && defined(USE_CERT_BUFFERS_256)
    #error please set either macro USE_CERT_BUFFERS_2048 or USE_CERT_BUFFERS_256
#endif

#define FR_SOCKET_SUCCESS 0

static void util_Cleanup(WOLFSSL_CTX *ctx, WOLFSSL *ssl) {
    printf("Cleaning up socket and wolfSSL objects.\n");
    if (ssl != NULL)
        wolfSSL_free(ssl);
    if (ctx != NULL)
        wolfSSL_CTX_free(ctx);
    wolfSSL_Cleanup();
}

static inline void util_inf_loop(WOLFSSL_CTX *ctx, WOLFSSL *ssl) {
    util_Cleanup(ctx, ssl);
    printf("Reached infinite loop.\n");
    while (1)
        ;
}

void TCPInit();
void wolfSSL_TLS_client_init();
int wolfSSL_TLS_client_do(void *pvParam);
void wolfSSL_TLS_server_init();
int wolfSSL_TLS_server_do(void *pvParam);
void wolfSSL_TLS_cleanup();

#endif /* WOLFSSL_DEMO_H_ */
