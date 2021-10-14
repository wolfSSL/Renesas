/* sctp-server.c
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
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    sa.sin_port = htons(12345);

    int ret = bind(sd, (struct sockaddr*)&sa, sizeof(sa));
    if (ret < 0)
        perror("sctp bind error");

    listen(sd, 3);

    int client_sd = accept(sd, NULL, NULL);
    if (client_sd < 0)
        perror("sctp accept error");

    const char* response = "hi there";
    char buffer[80];

    int got = (int)recv(client_sd, buffer, sizeof(buffer), 0);
    if (got > 0) {
        buffer[got] = 0;
        printf("client said: %s\n", buffer);
    }
    send(client_sd, response, strlen(response), 0);


    close(sd);
#endif /* WOLFSSL_SCTP */
    return 0;
}
