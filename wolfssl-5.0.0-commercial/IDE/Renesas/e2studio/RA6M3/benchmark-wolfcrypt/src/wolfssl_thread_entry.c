/* wolfssl_thread_entry.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#include <wolfssl/wolfcrypt/settings.h>
#include "wolfcrypt/benchmark/benchmark.h"
#include "common/util.h"

void wolfssl_thread_entry(void *pvParameters) {
    FSP_PARAMETER_NOT_USED(pvParameters);
    initialise_monitor_handles();
    benchmark_test(0);
    while (1);
}
