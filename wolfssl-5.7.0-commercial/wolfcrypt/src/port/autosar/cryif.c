/* cryif.c
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* AutoSAR 4.4 */
/* shim layer for use of wolfSSL crypto driver */


#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/version.h>
#include <wolfssl/wolfcrypt/port/autosar/Csm.h>
#include <wolfssl/wolfcrypt/port/autosar/CryIf.h>
#include <wolfssl/wolfcrypt/port/autosar/Crypto.h>

#ifdef WOLFSSL_AUTOSAR
#ifndef NO_WOLFSSL_AUTOSAR_CRYIF

#include <wolfssl/wolfcrypt/logging.h>

/* initialization function */
void CryIf_Init(const CryIf_ConfigType* in)
{
    (void)in;
    Crypto_Init(NULL);
}


void CryIf_GetVersionInfo(Std_VersionInfoType* ver)
{
    if (ver != NULL) {
        ver->vendorID = 0; /* no vendor or module ID */
        ver->moduleID = 0;
        ver->sw_major_version = (LIBWOLFSSL_VERSION_HEX >> 24) & 0xFFF;
        ver->sw_minor_version = (LIBWOLFSSL_VERSION_HEX >> 12) & 0xFFF;
        ver->sw_patch_version = (LIBWOLFSSL_VERSION_HEX) & 0xFFF;
    }
}


/* returns E_OK on success */
Std_ReturnType CryIf_ProcessJob(uint32 id, Crypto_JobType* job)
{
    WOLFSSL_ENTER("CryIf_ProcessJob");
    if (job == NULL) {
        return E_NOT_OK;
    }

    /* only handle synchronous jobs */
    if (job->jobPrimitiveInfo->processingType != CRYPTO_PROCESSING_SYNC) {
        WOLFSSL_MSG("Crypto Interface only supporting synchronous jobs");
        return E_NOT_OK;
    }

    return Crypto_ProcessJob(id, job);
}


/* not implemented yet since async not supported */
Std_ReturnType CryIf_CancelJob(uint32 id, Crypto_JobType* job)
{
    (void)id;
    (void)job;
    WOLFSSL_STUB("CryIf_CancelJob");

    return E_NOT_OK;
}


/* return E_OK on success */
Std_ReturnType CryIf_KeyElementSet(uint32 keyId, uint32 eId, const uint8* key,
        uint32 keySz)
{
    if (key == NULL || keySz == 0) {
        /* report CRYIF_E_PARAM_POINTER to the DET */
        return E_NOT_OK;
    }

    return Crypto_KeyElementSet(keyId, eId, key, keySz);
}
#endif /* NO_WOLFSSL_AUTOSAR_CRYIF */
#endif /* WOLFSSL_AUTOSAR */

