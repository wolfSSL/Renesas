/* wolf_main.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include "user_settings.h"
#include "wolfssl/ssl.h"
#include <stdio.h>
#include <stdint.h>

#include "wolf_demo.h"

static WOLFSSL_CTX *wolfSSL_sv_ctx;
static WOLFSSL_CTX *wolfSSL_cl_ctx;

static long tick;
static void timeTick(void *pdata)
{
    tick++;
}

#define FREQ 10000 /* Hz */

double current_time(int reset)
{
      if(reset) tick = 0 ;
      return ((double)tick/FREQ) ;	
}

#define ARG_SZ 256
static char argBuff[ARG_SZ];
static int get_arg(func_args *args)
{
    int i;
    char *arg = argBuff;
    args->argc = 0;
    
    for(i=0; i<ARG_SZ; i++) {
        *arg = getchar();
        
	switch(*arg){
	case '\n':
	     *arg = '\0';
	     return args->argc;
	case ' ':
	     *arg++ = '\0';
	     while(*arg++ == ' '); /* Skip space */
	     args->argv[++args->argc] = arg;
	     break;
	default:
	     arg++;
	}
    }
    return args->argc ;
}

void wolfSSL_init()
{
    uint32_t channel;
    R_CMT_CreatePeriodic(FREQ, &timeTick, &channel);

    wolfSSL_sv_ctx = wolfSSL_TLS_server_init();
    wolfSSL_cl_ctx = wolfSSL_TLS_client_init();
    wolfSSL_main();
}

void wolfSSL_main()
{
    int c;
    func_args args = {0};
    
    printf("wolfSSL Demo\nt: test, b: benchmark, s: server, or c <IP addr> <Port>: client\n$ ");
    c = getchar();
    
    switch(c) {
    case 't':
        get_arg(&args);
        printf("Start wolfCrypt Test\n");
        wolfcrypt_test(&args);
        printf("End wolfCrypt Test\n");
	break;
	
    case 'b':
        get_arg(&args);
        printf("Start wolfCrypt Benchmark\n");
        benchmark_test(NULL);
        printf("End wolfCrypt Benchmark\n");
	break;
	
    case 'c':
        if(get_arg(&args) < 0)
            break;
	printf("Start TLS Client(%s, %s)\n", args.argv[1], args.argv[2]);
	wolfSSL_TLS_client(wolfSSL_cl_ctx, &args);
        printf("End TLS Client\n");
	break;
	
    case 's':
        if(get_arg(&args) < 0)
            break;
	printf("Start TLS Server\n");
	wolfSSL_TLS_server(wolfSSL_sv_ctx, &args);
        printf("End TLS Server\n");
	break;

    default:
    	printf("Command Error\n");
    }
}
