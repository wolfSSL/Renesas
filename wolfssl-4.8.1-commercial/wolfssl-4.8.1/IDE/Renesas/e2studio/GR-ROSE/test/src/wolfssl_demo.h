/* wolfssl_demo.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_DEMO_H_
#define WOLFSSL_DEMO_H_

#define FREQ 10000 /* Hz */

/* Enable wolfcrypt test */
/* can be enabled with benchmark test */
/* #define CRYPT_TEST    */

/* Enable benchmark               */
/* can be enabled with cyrpt test */
/* #define BENCHMARK*/

/* Enable TLS client     */
/* cannot enable with other definition */
/*#define TLS_CLIENT*/

/* Enable TLS server     */
/* cannot enable with other definition */
/* #define TLS_SERVER */

void wolfSSL_TLS_client_init();
void wolfSSL_TLS_client();
void wolfSSL_TLS_server_init();
void wolfSSL_TLS_server();

#endif /* WOLFSSL_DEMO_H_ */
