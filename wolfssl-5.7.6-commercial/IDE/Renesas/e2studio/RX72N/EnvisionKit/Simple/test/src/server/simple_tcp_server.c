/* simple_tcp_server.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#include <stdio.h>
#include <string.h>
#include <wolfssl_simple_demo.h>
#include <stdio.h>
#include <string.h>
#include "r_t4_itcpip.h"

static int my_IORecv(char* buff, int sz, void* ctx)
{
    int ret;
    ID  cepid;

    if(ctx != NULL)
        cepid = *(ID *)ctx;
    else
        return 0;

    ret = tcp_rcv_dat(cepid, buff, sz, TMO_FEVR);
    if(ret > 0)
        return ret;
    else
        return 0;
}

static int my_IOSend(char* buff, int sz, void* ctx)
{
    int ret;
    ID  cepid;

    if(ctx != NULL)
        cepid = *(ID *)ctx;
    else
        return 0;

    ret = tcp_snd_dat(cepid, buff, sz, TMO_FEVR);
    if(ret == sz)
        return ret;
    else
        return 0;
}

void simple_tcp_server( )
{
    ID cepid = 1;
    ID repid = 1;
    ER ercd;
    int len;
    #define BUFF_SIZE 256
    char buff[BUFF_SIZE];
    T_IPV4EP dst_addr = {0, 0};

    if((ercd = tcp_acp_cep(cepid, repid, &dst_addr, TMO_FEVR)) != E_OK) {
        printf("ERROR TCP Accept: %d\n", ercd);
        goto out;
    }

    if ((len = my_IORecv(buff, sizeof(buff) - 1, (void*)&cepid)) < 0) {
        printf("ERROR: Read \n");
        goto out;
    }

    buff[len] = '\0';
    printf("Received: %s\n", buff);

    if (my_IOSend(buff, len, (void*)&cepid) != len) {
        printf("ERROR: Write\n");
    }

out:
    tcp_sht_cep(cepid);
    tcp_cls_cep(cepid, TMO_FEVR);
}
