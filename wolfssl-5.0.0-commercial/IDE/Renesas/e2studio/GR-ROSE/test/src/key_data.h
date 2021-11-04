/* key_data.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef KEY_DATA_H_
#define KEY_DATA_H_

#include <wolfssl/wolfcrypt/settings.h>


#if defined(WOLFSSL_RENESAS_TSIP)

    #include "r_tsip_rx_if.h"

typedef struct st_key_block_data
{
    uint8_t encrypted_provisioning_key[R_TSIP_AES_CBC_IV_BYTE_SIZE * 2];
    uint8_t iv[R_TSIP_AES_CBC_IV_BYTE_SIZE];
    uint8_t encrypted_user_rsa2048_ne_key[R_TSIP_RSA2048_NE_KEY_BYTE_SIZE + 16];
    uint8_t encrypted_user_update_key[R_TSIP_AES256_KEY_BYTE_SIZE + 16];
} st_key_block_data_t;

    #if (WOLFSSL_RENESAS_TSIP_VER >= 109)
    extern const uint32_t               encrypted_user_key_type; 
    #endif

    extern const st_key_block_data_t    g_key_block_data;
    
    
    extern const unsigned char          ca_cert_sig[];
    extern const unsigned char          ca_cert_der[];
    extern const unsigned char          client_cert_der_sign[];
    extern const int                    sizeof_ca_cert_der;


#endif /* (WOLFSSL_RENESAS_TSIP */
#endif /* KEY_DATA_H_ */

