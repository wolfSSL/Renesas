/* esp32_util.c
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

#if defined(WOLFSSL_ESP32WROOM32_CRYPT) && \
  (!defined(NO_AES)        || !defined(NO_SHA) || !defined(NO_SHA256) ||\
   defined(WOLFSSL_SHA384) || defined(WOLFSSL_SHA512))

#include <wolfssl/wolfcrypt/wc_port.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

int esp_CryptHwMutexInit(wolfSSL_Mutex* mutex) {
    return wc_InitMutex(mutex);
}

int esp_CryptHwMutexLock(wolfSSL_Mutex* mutex, TickType_t xBlockTime) {
#ifdef SINGLE_THREADED
    return wc_LockMutex(mutex);
#else
    return ((xSemaphoreTake( *mutex, xBlockTime ) == pdTRUE) ? 0 : BAD_MUTEX_E);
#endif
}

int esp_CryptHwMutexUnLock(wolfSSL_Mutex* mutex) {
    return wc_UnLockMutex(mutex);
}

#endif

#ifdef WOLFSSL_ESP32WROOM32_CRYPT_DEBUG

#include "esp_timer.h"
#include "esp_log.h"

static uint64_t startTime = 0;


void wc_esp32TimerStart()
{
    startTime = esp_timer_get_time();
}

uint64_t  wc_esp32elapsedTime()
{
    /* return elapsed time since wc_esp32AesTimeStart() is called in us */
    return esp_timer_get_time() - startTime;
}

#endif /*WOLFSSL_ESP32WROOM32_CRYPT_DEBUG */
