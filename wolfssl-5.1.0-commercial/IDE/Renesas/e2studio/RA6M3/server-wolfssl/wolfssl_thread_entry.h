/* wolfssl_thread_entry.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef WOLFSSL_THREAD_ENTRY_H_
#define WOLFSSL_THREAD_ENTRY_H_

#include <wolfssl/certs_test.h>

extern uint8_t g_ether0_mac_address[6];

static const byte ucIPAddress[4]          = { 192, 168, 1, 241 };
static const byte ucNetMask[4]            = { 255, 255, 255, 0 };
static const byte ucGatewayAddress[4]     = { 192, 168, 1, 1 };
static const byte ucDNSServerAddress[4]   = { 192, 168, 1, 1 };

/* Server Cert and Key */
#define CERT_BUF        server_cert_der_1024
#define SIZEOF_CERT_BUF sizeof_server_cert_der_1024
#define KEY_BUF         server_key_der_1024
#define SIZEOF_KEY_BUF  sizeof_server_key_der_1024

/* Port That the wolfSSL Server connects to. */
#define DEFAULT_PORT 11111

#define FR_SOCKET_SUCCESS 0

#endif /* WOLFSSL_THREAD_ENTRY_H_ */
