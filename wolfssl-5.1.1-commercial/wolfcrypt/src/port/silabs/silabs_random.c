/* silabs_random.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Generic SILABS Entropy random */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>

#if defined(WOLFSSL_SILABS_SE_ACCEL)

#include <sl_se_manager.h>
#include <sl_se_manager_entropy.h>

#include <wolfssl/wolfcrypt/port/silabs/silabs_random.h>

int silabs_GenerateRand(byte* output, word32 sz)
{
    sl_se_command_context_t cmd_ctx = SL_SE_COMMAND_CONTEXT_INIT;
    sl_status_t status = sl_se_init();

    if (status == SL_STATUS_OK)
        status = sl_se_get_random(&cmd_ctx, output,  sz);

    return (status != SL_STATUS_OK);
}

#endif /* WOLFSSL_SILABS_SE_ACCEL */
