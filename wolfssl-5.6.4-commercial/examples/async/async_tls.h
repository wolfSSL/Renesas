/* async-tls.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFSSL_ASYNC_TLS_EXAMPLES_H
#define WOLFSSL_ASYNC_TLS_EXAMPLES_H

#define DEFAULT_PORT 11111
#define TEST_BUF_SZ  256

#ifdef WOLF_CRYPTO_CB
/* Example custom context for crypto callback */
typedef struct {
    int pendingCount; /* track pending tries test count */
} AsyncTlsCryptoCbCtx;
int AsyncTlsCryptoCb(int devIdArg, wc_CryptoInfo* info, void* ctx);
#endif /* WOLF_CRYPTO_CB */


int client_async_test(int argc, char** argv);
int server_async_test(int argc, char** argv);


#endif /* WOLFSSL_ASYNC_TLS_EXAMPLES_H */
