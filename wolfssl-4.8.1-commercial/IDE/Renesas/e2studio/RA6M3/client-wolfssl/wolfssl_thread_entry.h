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

#include <errno.h>
#include <wolfssl/certs_test.h>

extern uint8_t g_ether0_mac_address[6];

static const byte ucIPAddress[4]          = { 192, 168, 1, 241 };
static const byte ucNetMask[4]            = { 255, 255, 255, 0 };
static const byte ucGatewayAddress[4]     = { 192, 168, 1, 1 };
static const byte ucDNSServerAddress[4]   = { 192, 168, 1, 1 };

/* Client connects to the server with these details. */
#define SERVER_IP    "192.168.1.240"
#define DEFAULT_PORT 11111
#define CERT         ca_cert_der_1024
#define SIZEOF_CERT  sizeof_ca_cert_der_1024

#define FR_SOCKET_SUCCESS 0

#endif /* WOLFSSL_THREAD_ENTRY_H_ */
