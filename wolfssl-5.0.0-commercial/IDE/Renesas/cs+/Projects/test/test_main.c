/* test_main.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include "typedefine.h"
#ifdef __cplusplus
#include <ios>                        // Remove the comment when you use ios
_SINT ios_base::Init::init_cnt;       // Remove the comment when you use ios
#endif

#include "stdio.h"

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

typedef struct func_args {
    int    argc;
    char** argv;
    int    return_code;
} func_args;

void wolfcrypt_test(func_args args);

void main(void)
{
    func_args args = { 1 };
  
    printf("Start wolfCrypt Test\n");
    wolfcrypt_test(args);
    printf("End wolfCrypt Test\n");

}

#ifdef __cplusplus
void abort(void)
{

}
#endif
