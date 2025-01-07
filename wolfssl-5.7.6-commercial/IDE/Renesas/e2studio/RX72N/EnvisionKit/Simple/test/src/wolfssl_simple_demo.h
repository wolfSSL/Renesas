/* wolfssl_simple_demo.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_SIMPLE_DEMO_H_
#define WOLFSSL_SIMPLE_DEMO_H_

#define FREQ 10000 /* Hz */

/* Enable wolfcrypt test */
/* can be enabled with benchmark test */
#define CRYPT_TEST

/* Enable benchmark               */
/* can be enabled with cyrpt test */
/*#define BENCHMARK*/

/* Enable TLS client     */
/* cannot enable with other definition */
/* simplest tcp client*/
/*#define SIMPLE_TCP_CLIENT */
/* software TLS client */
/* #define SIMPLE_TLS_CLIENT */
/* use TSIP Acceleration */
/*#define SIMPLE_TLS_TSIP_CLIENT*/

/* simplest tcp server */
/*#define SIMPLE_TCP_SERVER*/
/* simple TLS server */
/* #define SIMPLE_TLS_SERVER */

void wolfSSL_TLS_client_init();
void wolfSSL_TLS_client();
void simple_tcp_client();
void wolfSSL_TLS_server_init();
void wolfSSL_TLS_server();
void simple_tcp_server();

#if defined(SIMPLE_TCP_CLIENT) || defined(SIMPLE_TLS_CLIENT) || \
    defined(SIMPLE_TCP_SERVER) || defined(SIMPLE_TLS_SERVER)
 #define min(x,y) ((x)<(y)?(x):(y))
 int isascii(const char *s);
#endif

#endif /* WOLFSSL_SIMPLE_DEMO_H_ */
