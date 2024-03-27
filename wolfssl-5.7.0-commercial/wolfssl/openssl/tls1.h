/* tls1.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFSSL_OPENSSL_TLS1_H_
#define WOLFSSL_OPENSSL_TLS1_H_

#ifndef TLS1_VERSION
#define TLS1_VERSION                    0x0301
#endif

#ifndef TLS1_1_VERSION
#define TLS1_1_VERSION                  0x0302
#endif

#ifndef TLS1_2_VERSION
#define TLS1_2_VERSION                  0x0303
#endif

#ifndef TLS1_3_VERSION
#define TLS1_3_VERSION                  0x0304
#endif

#ifndef TLS_MAX_VERSION
#define TLS_MAX_VERSION                 TLS1_3_VERSION
#endif

#ifdef WOLFSSL_QUIC
/* from rfc9001 */
#define TLSEXT_TYPE_quic_transport_parameters_draft   0xffa5
#define TLSEXT_TYPE_quic_transport_parameters         0x0039
#endif

#endif /* WOLFSSL_OPENSSL_TLS1_H_ */
