/* StandardTypes.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifdef WOLFSSL_AUTOSAR

#ifndef WOLFSSL_STANDARDTYPES_H
#define WOLFSSL_STANDARDTYPES_H
#include <wolfssl/wolfcrypt/types.h>

/* remap primitives */
typedef byte   uint8;
typedef byte   boolean;
typedef word16 uint16;
typedef word32 uint32;
typedef word64 uint64;

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

/* return types */
typedef enum Std_ReturnType {
    E_OK = 0x00,
    E_NOT_OK = 0x01,
    E_SMALL_BUFFER = 0x02,
    E_ENTROPY_EXHAUSTION = 0x03,
    E_KEY_READ_FAIL = 0x04,
    E_KEY_NOT_AVAILABLE = 0x05,
    E_KEY_NOT_VALID = 0x06,
    E_JOB_CANCELED = 0x07,
    E_KEY_EMPTY = 0x08
} Std_ReturnType;


typedef struct Std_VersionInfoType {
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;
#endif /* WOLFSSL_AUTOSAR */

#endif /* WOLFSSL_STANDARDTYPES_H */

