/* server.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFSSL_SERVER_H
#define WOLFSSL_SERVER_H


THREAD_RETURN WOLFSSL_THREAD server_test(void* args);

/* Echo bytes using buffer of blockSize until [echoData] bytes are complete. */
/* If [bechmarkThroughput] set the statistcs will be output at the end */
int ServerEchoData(WOLFSSL* ssl, int clientfd, int echoData, int blockSize,
                   size_t benchmarkThroughput);


#endif /* WOLFSSL_SERVER_H */
