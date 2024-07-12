/* sctp-client-dtls.c
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


/* wolfssl */
#ifndef WOLFSSL_USER_SETTINGS
    #include <wolfssl/options.h>
#endif
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/ssl.h>

#if defined(WOLFSSL_SCTP) && defined(WOLFSSL_DTLS) && !defined(WOLFSSL_NO_TLS12)
/* sctp */
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

/* std */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define cacert "./certs/ca-cert.pem"

static int err_sys(const char* msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
#endif /* WOLFSSL_SCTP && WOLFSSL_DTLS && !WOLFSSL_NO_TLS12 */

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
#if defined(WOLFSSL_SCTP) && defined(WOLFSSL_DTLS) && !defined(WOLFSSL_NO_TLS12)
    int sd = socket(PF_INET, SOCK_STREAM, IPPROTO_SCTP);

    if (sd < 0)
        err_sys("sctp socket error");

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(12345);

    int ret = connect(sd, (struct sockaddr*)&sa, sizeof(sa));
    if (ret < 0)
        err_sys("sctp connect error");

    const char* response = "hello there";
    char buffer[80];

    WOLFSSL_CTX* ctx = wolfSSL_CTX_new(wolfDTLSv1_2_client_method());
    if (ctx == NULL)
        err_sys("ctx new dtls client failed");

    ret = wolfSSL_CTX_dtls_set_sctp(ctx);
    if (ret != WOLFSSL_SUCCESS)
        err_sys("set sctp mode failed");

    ret = wolfSSL_CTX_load_verify_locations(ctx, cacert, NULL);
    if (ret != WOLFSSL_SUCCESS)
        err_sys("ca cert error");

    WOLFSSL* ssl = wolfSSL_new(ctx);
    if (ssl == NULL)
        err_sys("ssl new dtls client failed");

    wolfSSL_set_fd(ssl, sd);

    ret = wolfSSL_connect(ssl);
    if (ret != WOLFSSL_SUCCESS)
        err_sys("ssl connect failed");

    printf("TLS version is %s\n", wolfSSL_get_version(ssl));
    printf("Cipher Suite is %s\n",
           wolfSSL_CIPHER_get_name(wolfSSL_get_current_cipher(ssl)));

    wolfSSL_write(ssl, response, (int)strlen(response));
    int got = wolfSSL_read(ssl, buffer, sizeof(buffer));
    if (got > 0) {
        buffer[got] = 0;
        printf("server said: %s\n", buffer);
    }

    unsigned char bigBuf[4096];
    unsigned int i;

    for (i = 0; i < (int)sizeof(bigBuf); i++)
        bigBuf[i] = (unsigned char)(i & 0xFF);
    wolfSSL_write(ssl, bigBuf, sizeof(bigBuf));
    memset(bigBuf, 0, sizeof(bigBuf));

    wolfSSL_read(ssl, bigBuf, sizeof(bigBuf));
    for (i = 0; i < sizeof(bigBuf); i++) {
        if (bigBuf[i] != (unsigned char)(i & 0xFF)) {
            fprintf(stderr, "big message check fail\n");
            break;
        }
    }

    wolfSSL_shutdown(ssl);
    wolfSSL_free(ssl);
    wolfSSL_CTX_free(ctx);

    close(sd);
#endif /* WOLFSSL_SCTP && WOLFSSL_DTLS && !WOLFSSL_NO_TLS12 */

    return 0;
}
