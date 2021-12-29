/* sctp-client.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_USER_SETTINGS
    #include <wolfssl/options.h>
#endif
#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_SCTP

/* sctp */
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

/* std */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#endif /* WOLFSSL_SCTP */

int main()
{
#ifdef WOLFSSL_SCTP
    int sd = socket(PF_INET, SOCK_STREAM, IPPROTO_SCTP);

    if (sd < 0)
        perror("sctp socket error");

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(12345);

    int ret = connect(sd, (struct sockaddr*)&sa, sizeof(sa));
    if (ret < 0)
        perror("sctp connect error");

    const char* msg = "hello sctp";
    char buffer[80];

    send(sd, msg, strlen(msg), 0);
    int got = (int)recv(sd, buffer, sizeof(buffer), 0);
    if (got > 0) {
        buffer[got] = 0;
        printf("server said: %s\n", buffer);
    }

    close(sd);
#endif /* WOLFSSL_SCTP */
    return 0;
}
