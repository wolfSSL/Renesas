/* key_data.c
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#include "key_data.h"

/*-------------------------------------------------------------------------
      RX72N supports TSIP v1.09 or later
--------------------------------------------------------------------------*/
#if defined(WOLFSSL_RENESAS_TSIP_TLS) && (WOLFSSL_RENESAS_TSIP_VER >= 109)

const st_key_block_data_t g_key_block_data =
{
    /* uint8_t encrypted_provisioning_key[R_TSIP_AES_CBC_IV_BYTE_SIZE * 2]; */
    {
    	0xDF, 0x78, 0x49, 0x28, 0xA9, 0x4C, 0x36, 0xD6, 0xC9, 0x89, 0x98, 0xDF,
    	0xFF, 0xB1, 0xCB, 0xBC, 0x9F, 0xF4, 0x34, 0xCD, 0x81, 0x53, 0x67, 0xB3,
    	0xFC, 0x85, 0xC6, 0x0B, 0xA2, 0xC8, 0xF4, 0x83
   },
    /* uint8_t iv[R_TSIP_AES_CBC_IV_BYTE_SIZE]; */
    {
    	0x01, 0x23, 0x45, 0x67, 0x89, 0x01, 0x23, 0x45, 0x67, 0x89, 0x01, 0x23,
    	0x45, 0x67, 0x89, 0x01
    },
    /* uint8_t
     * encrypted_user_rsa2048_ne_key[R_TSIP_RSA2048_NE_KEY_BYTE_SIZE + 16];
     */
    {
        0xCF, 0x64, 0xE8, 0xB7, 0xAB, 0x18, 0x50, 0xFD, 0xF5, 0x33, 0xA7, 0xA4,
        0x43, 0xA0, 0x3D, 0xCE, 0xEB, 0x7F, 0xC8, 0x1E, 0x7F, 0xE9, 0x4D, 0x6B,
        0x2E, 0xFB, 0x00, 0x14, 0x72, 0x49, 0x6F, 0xAA, 0x13, 0x58, 0xCC, 0xA2,
        0x49, 0xC7, 0x98, 0xEB, 0xBD, 0x9F, 0x10, 0x32, 0x99, 0xBA, 0x28, 0xC5,
        0xA3, 0x6A, 0x01, 0x9C, 0x97, 0x6D, 0x9B, 0xDF, 0xE9, 0xE0, 0x24, 0x18,
        0xD0, 0x59, 0x3C, 0x93, 0x96, 0x7C, 0x90, 0xCF, 0xED, 0xAE, 0xE0, 0xCE,
        0xC6, 0xBE, 0x81, 0x23, 0xE2, 0xBC, 0xE9, 0x69, 0x3B, 0x4A, 0x65, 0xA6,
        0x84, 0x02, 0xDF, 0x54, 0x24, 0x25, 0x48, 0x76, 0xEF, 0x2C, 0xB6, 0x87,
        0xC8, 0x09, 0x5E, 0x0D, 0xCA, 0xC5, 0x97, 0xCD, 0xA4, 0x44, 0xCA, 0xC9,
        0xAD, 0xA0, 0x9C, 0x54, 0x05, 0x85, 0x18, 0xA7, 0xBF, 0xD8, 0x37, 0xBD,
        0xF7, 0x73, 0x5D, 0x30, 0xFB, 0x48, 0xB1, 0xE0, 0x41, 0x92, 0x74, 0x4A,
        0x68, 0x21, 0xEC, 0xE4, 0x2C, 0x0C, 0xBC, 0x02, 0xAD, 0xA5, 0x6F, 0xDD,
        0xA6, 0xD6, 0x1C, 0x72, 0x85, 0xFD, 0x37, 0xB6, 0x2E, 0x0A, 0xD6, 0xBE,
        0x7A, 0x81, 0xD3, 0x50, 0x24, 0xBE, 0x69, 0xFD, 0x6D, 0xD6, 0xAA, 0x2E,
        0xFA, 0x00, 0x0A, 0x33, 0xEF, 0x53, 0xFC, 0xA4, 0xE7, 0xA2, 0x3E, 0xCE,
        0x24, 0x39, 0x4D, 0xCA, 0xE7, 0xAA, 0xC5, 0x82, 0x19, 0x40, 0x60, 0x0F,
        0xD3, 0x2C, 0x7D, 0x8E, 0x13, 0xEC, 0xCB, 0x38, 0xE1, 0xC9, 0x97, 0xF9,
        0x24, 0x1D, 0x7C, 0x77, 0xCD, 0x73, 0xBD, 0x76, 0xC7, 0x08, 0x49, 0x24,
        0xAE, 0x83, 0xE3, 0x99, 0x28, 0x62, 0xF9, 0x70, 0xD8, 0xB5, 0x28, 0x03,
        0x83, 0x0A, 0xE0, 0xEB, 0x1C, 0xC9, 0xE4, 0x0E, 0x31, 0xF9, 0x5A, 0x0B,
        0x3D, 0x06, 0x24, 0x49, 0x3B, 0xAE, 0xFE, 0x99, 0xAC, 0x59, 0x20, 0x6E,
        0xF4, 0xE1, 0x4B, 0x3C, 0x7B, 0x86, 0xF7, 0x48, 0xAA, 0x3A, 0x79, 0x8D,
        0x71, 0x4B, 0x7C, 0x4B, 0x5A, 0x74, 0x31, 0xB1, 0x6A, 0xA6, 0xD4, 0xC4,
        0xE1, 0x59, 0x90, 0x62, 0x09, 0xAB, 0xA4, 0x91, 0x02, 0x0A, 0x22, 0x2B
    },
    /* uint8_t encrypted_user_update_key[R_TSIP_AES256_KEY_BYTE_SIZE + 16]; */
    {
        0
    },
    /* uint8_t
     * encrypted_user_rsa2048_public_key[R_TSIP_RSA2048_NE_KEY_BYTE_SIZE + 16]
     */
    {
        0x60, 0x6B, 0x2E, 0x15, 0xAB, 0xE2, 0x51, 0x4D, 0x75, 0xEA, 0xF4, 0xE8,
        0xF5, 0x21, 0xC3, 0x31, 0xF9, 0x3C, 0x8A, 0x7D, 0x2B, 0x55, 0x7B, 0xA7,
        0xC0, 0xC5, 0xE0, 0xBC, 0x56, 0x75, 0xEB, 0xFA, 0x43, 0x6E, 0x49, 0x4F,
        0x29, 0xD6, 0xE8, 0xAC, 0xDA, 0x44, 0xDD, 0x82, 0x23, 0xEC, 0x3D, 0x0E,
        0xE2, 0xA1, 0xE7, 0xF3, 0x81, 0xB3, 0x4D, 0x81, 0x9A, 0xFB, 0xCE, 0x1A,
        0x57, 0xE7, 0x0E, 0x8B, 0xDC, 0x18, 0xD8, 0xB4, 0x97, 0xD0, 0xA9, 0x5D,
        0x81, 0xFB, 0x13, 0x10, 0x19, 0xD1, 0x0D, 0x43, 0xE6, 0x1D, 0xFC, 0x80,
        0x32, 0x97, 0x6A, 0xB2, 0xB2, 0x63, 0xD9, 0xC2, 0x09, 0x34, 0xF3, 0xA0,
        0x0C, 0xCE, 0x06, 0x6C, 0xB2, 0xB9, 0x2A, 0xDF, 0xEE, 0x68, 0x8B, 0x4E,
        0x8C, 0xBA, 0xF8, 0xA7, 0x60, 0x3C, 0xCC, 0xD4, 0x94, 0x42, 0xCC, 0x37,
        0x4B, 0xED, 0x70, 0xB1, 0x53, 0xBD, 0xE8, 0x92, 0xB9, 0x8B, 0x07, 0x27,
        0x42, 0xC2, 0x1B, 0xE1, 0x7D, 0x45, 0xBC, 0xB9, 0xB4, 0x3D, 0xD1, 0x62,
        0x44, 0x76, 0x4E, 0xFA, 0xE5, 0x00, 0x4F, 0x6B, 0xE6, 0xBB, 0x32, 0xFB,
        0xD6, 0xEC, 0x58, 0x98, 0xFB, 0x80, 0xF7, 0x0E, 0x96, 0x9B, 0xBB, 0xCF,
        0xDE, 0x31, 0x09, 0x39, 0x1A, 0x31, 0x49, 0xB8, 0x2F, 0x99, 0xEA, 0x9A,
        0xF2, 0x46, 0xDB, 0x09, 0x21, 0xB1, 0x41, 0x98, 0x38, 0x9A, 0xDD, 0xEE,
        0xA3, 0xEE, 0x02, 0xBB, 0x2D, 0x79, 0x44, 0xD0, 0x81, 0x60, 0x0E, 0xD3,
        0xFF, 0xBC, 0x98, 0x6B, 0x5A, 0x19, 0x47, 0xEB, 0x88, 0xC3, 0x25, 0x58,
        0xD8, 0x77, 0x95, 0x40, 0x76, 0xE3, 0x56, 0xCF, 0x94, 0x2D, 0xFE, 0x43,
        0x63, 0xD6, 0x8D, 0xA0, 0x1B, 0x43, 0x33, 0xEB, 0xBC, 0xE7, 0x92, 0x40,
        0xA2, 0xD5, 0x98, 0x5C, 0xF8, 0x91, 0xAF, 0x0B, 0xD2, 0x8E, 0xA8, 0x58,
        0x84, 0x7D, 0x90, 0xBD, 0x46, 0x09, 0xD1, 0x14, 0x95, 0x32, 0x8F, 0x49,
        0xC6, 0xDE, 0xB8, 0xA5, 0xC6, 0xFA, 0xB5, 0x5F, 0xA7, 0x41, 0x29, 0x68,
        0x87, 0xE9, 0xAF, 0xC8, 0x6F, 0xFE, 0x50, 0x84, 0x01, 0x2E, 0x02, 0x6A
    },
    /* uint8_t
     * encrypted_user_rsa2048_private_key[R_TSIP_RSA2048_ND_KEY_BYTE_SIZE + 16]
     */
    {
        0x60, 0x6B, 0x2E, 0x15, 0xAB, 0xE2, 0x51, 0x4D, 0x75, 0xEA, 0xF4, 0xE8,
        0xF5, 0x21, 0xC3, 0x31, 0xF9, 0x3C, 0x8A, 0x7D, 0x2B, 0x55, 0x7B, 0xA7,
        0xC0, 0xC5, 0xE0, 0xBC, 0x56, 0x75, 0xEB, 0xFA, 0x43, 0x6E, 0x49, 0x4F,
        0x29, 0xD6, 0xE8, 0xAC, 0xDA, 0x44, 0xDD, 0x82, 0x23, 0xEC, 0x3D, 0x0E,
        0xE2, 0xA1, 0xE7, 0xF3, 0x81, 0xB3, 0x4D, 0x81, 0x9A, 0xFB, 0xCE, 0x1A,
        0x57, 0xE7, 0x0E, 0x8B, 0xDC, 0x18, 0xD8, 0xB4, 0x97, 0xD0, 0xA9, 0x5D,
        0x81, 0xFB, 0x13, 0x10, 0x19, 0xD1, 0x0D, 0x43, 0xE6, 0x1D, 0xFC, 0x80,
        0x32, 0x97, 0x6A, 0xB2, 0xB2, 0x63, 0xD9, 0xC2, 0x09, 0x34, 0xF3, 0xA0,
        0x0C, 0xCE, 0x06, 0x6C, 0xB2, 0xB9, 0x2A, 0xDF, 0xEE, 0x68, 0x8B, 0x4E,
        0x8C, 0xBA, 0xF8, 0xA7, 0x60, 0x3C, 0xCC, 0xD4, 0x94, 0x42, 0xCC, 0x37,
        0x4B, 0xED, 0x70, 0xB1, 0x53, 0xBD, 0xE8, 0x92, 0xB9, 0x8B, 0x07, 0x27,
        0x42, 0xC2, 0x1B, 0xE1, 0x7D, 0x45, 0xBC, 0xB9, 0xB4, 0x3D, 0xD1, 0x62,
        0x44, 0x76, 0x4E, 0xFA, 0xE5, 0x00, 0x4F, 0x6B, 0xE6, 0xBB, 0x32, 0xFB,
        0xD6, 0xEC, 0x58, 0x98, 0xFB, 0x80, 0xF7, 0x0E, 0x96, 0x9B, 0xBB, 0xCF,
        0xDE, 0x31, 0x09, 0x39, 0x1A, 0x31, 0x49, 0xB8, 0x2F, 0x99, 0xEA, 0x9A,
        0xF2, 0x46, 0xDB, 0x09, 0x21, 0xB1, 0x41, 0x98, 0x38, 0x9A, 0xDD, 0xEE,
        0xA3, 0xEE, 0x02, 0xBB, 0x2D, 0x79, 0x44, 0xD0, 0x81, 0x60, 0x0E, 0xD3,
        0xFF, 0xBC, 0x98, 0x6B, 0x5A, 0x19, 0x47, 0xEB, 0x88, 0xC3, 0x25, 0x58,
        0xD8, 0x77, 0x95, 0x40, 0x76, 0xE3, 0x56, 0xCF, 0x94, 0x2D, 0xFE, 0x43,
        0x63, 0xD6, 0x8D, 0xA0, 0x1B, 0x43, 0x33, 0xEB, 0xBC, 0xE7, 0x92, 0x40,
        0xA2, 0xD5, 0x98, 0x5C, 0xF8, 0x91, 0xAF, 0x0B, 0xD2, 0x8E, 0xA8, 0x58,
        0x84, 0x7D, 0x90, 0xBD, 0x56, 0x1F, 0x2D, 0x1B, 0x8C, 0x17, 0x9E, 0xBA,
        0x0C, 0x61, 0xF8, 0x1B, 0xFB, 0xA4, 0x9E, 0x71, 0xA8, 0x09, 0x9E, 0xA9,
        0x0D, 0x2B, 0x18, 0x32, 0xFE, 0x56, 0x09, 0x1B, 0xD4, 0x0D, 0xEE, 0x58,
        0x40, 0x3B, 0x2D, 0x85, 0x52, 0xDA, 0x75, 0x2E, 0x8E, 0x52, 0xE1, 0x06,
        0x64, 0xA3, 0x06, 0x6B, 0x3E, 0x71, 0x45, 0x94, 0xE0, 0x12, 0x6F, 0x15,
        0x03, 0x57, 0x87, 0xBF, 0xE2, 0x05, 0xF7, 0x0D, 0xEA, 0x27, 0x9D, 0x9C,
        0xC4, 0x55, 0x7F, 0x87, 0x85, 0x87, 0x7F, 0xA7, 0xE4, 0xB4, 0xA6, 0x6F,
        0xB9, 0x18, 0x2E, 0x3C, 0xCF, 0x8E, 0x61, 0xD9, 0x13, 0x8C, 0xC4, 0xFF,
        0xA5, 0x0A, 0x86, 0xB7, 0x6D, 0x03, 0xA4, 0x48, 0xF5, 0xF4, 0xF5, 0x64,
        0xEA, 0x43, 0x54, 0xEB, 0x27, 0xEE, 0xD6, 0xD8, 0x89, 0xDB, 0x62, 0x37,
        0x73, 0x85, 0x86, 0xCA, 0x32, 0xE4, 0xA5, 0x61, 0x65, 0xA0, 0x0F, 0x59,
        0xA1, 0xB5, 0xB6, 0xE4, 0xA5, 0xDC, 0xFF, 0x81, 0x86, 0xB0, 0x84, 0x1A,
        0x4C, 0x68, 0xDA, 0xEB, 0x3D, 0x64, 0x40, 0x9D, 0x6B, 0x4B, 0x2A, 0x2B,
        0x09, 0xE5, 0xF0, 0x78, 0xC2, 0x47, 0x37, 0xCB, 0xE8, 0xD1, 0xA5, 0xD8,
        0xAA, 0x54, 0xC4, 0x23, 0xF9, 0x21, 0xF9, 0x78, 0x22, 0xB1, 0x40, 0x96,
        0xF9, 0xEB, 0xCB, 0x7A, 0x4B, 0xFF, 0x78, 0x8A, 0x7B, 0x8A, 0x09, 0xA9,
        0x94, 0x30, 0x4E, 0x20, 0xD2, 0x24, 0x1D, 0xED, 0x45, 0xA2, 0xAB, 0xFC,
        0xFD, 0x6A, 0xBE, 0xA7, 0x18, 0xD4, 0x5B, 0xE5, 0xBE, 0x83, 0x9F, 0xEC,
        0xA3, 0xBA, 0xEA, 0x62, 0x7E, 0xA0, 0xA2, 0x7C, 0x61, 0x8D, 0xF5, 0x42,
        0x50, 0x73, 0xE0, 0x66, 0x0B, 0x61, 0xD7, 0x86, 0x7C, 0x72, 0xF9, 0x86,
        0x0B, 0x8C, 0xC1, 0xB4, 0x2E, 0x9D, 0x19, 0xD1, 0xA4, 0xDC, 0x47, 0x85,
        0xB1, 0xBA, 0x16, 0x30, 0x97, 0x80, 0x98, 0x29, 0x16, 0xFA, 0xFD, 0x50,
        0xC6, 0x7F, 0x69, 0xA0, 0x16, 0xAF, 0x0A, 0x56, 0xDB, 0x1D, 0x53, 0xC4
    },
    /* uint8_t
     * encrypted_user_ecc256_public_key[R_TSIP_ECC_PUBLIC_KEY_BYTE_SIZE + 16];
     */
    {
        0x12, 0xF0, 0x90, 0x57, 0xDA, 0x92, 0xB4, 0x6A, 0xD9, 0xD3, 0x4D, 0x54,
        0x4C, 0x96, 0x8E, 0xB3, 0xAA, 0x33, 0x06, 0xC3, 0x7F, 0x4B, 0x6F, 0xFD,
        0xA9, 0x11, 0x73, 0x0F, 0x70, 0x73, 0xA0, 0xF7, 0x73, 0xE7, 0x8B, 0xDB,
        0xD4, 0x56, 0x4D, 0x7B, 0xCB, 0x79, 0x1E, 0x9B, 0x71, 0x74, 0xDF, 0x53,
        0x05, 0xA8, 0x54, 0xB2, 0x8B, 0x55, 0xE1, 0x7F, 0x3D, 0x4A, 0xC8, 0x84,
        0xB4, 0xD8, 0xBB, 0x9A, 0xDE, 0x2E, 0x42, 0x48, 0x9B, 0x12, 0x0B, 0x1B,
        0x1A, 0xDB, 0x3E, 0x0E, 0xE3, 0x07, 0xF8, 0x3B
     },
    /* uint8_t
     * encrypted_user_ecc256_private_key[R_TSIP_ECC_PRIVATE_KEY_BYTE_SIZE + 16];
     */
    {
        0x07, 0x21, 0xB3, 0x4A, 0x2D, 0xCE, 0xBE, 0x59, 0xBC, 0x8C, 0xE1, 0x84,
        0xF0, 0xE3, 0xEF, 0x07, 0xD8, 0xE4, 0x30, 0x31, 0xB7, 0xE2, 0xB0, 0xA6,
        0x6E, 0x51, 0xAE, 0xFD, 0x6B, 0x43, 0xB2, 0xFE, 0x1F, 0x16, 0x99, 0x67,
        0x7D, 0x33, 0x1F, 0xF9, 0x5B, 0x3C, 0xB1, 0xAC, 0x90, 0xE4, 0x05, 0x7F
    },

};

/* Public key type of CA root cert: 0: RSA-2048 2: ECDSA-P256*/
#if defined(USE_ECC_CERT)
const uint32_t              encrypted_user_key_type =
                                    R_TSIP_TLS_PUBLIC_KEY_TYPE_ECDSA_P256;
#else
const uint32_t              encrypted_user_key_type =
                                    R_TSIP_TLS_PUBLIC_KEY_TYPE_RSA2048;
#endif

const unsigned char ca_ecc_cert_der_sig[] =
{
	0x64, 0x38, 0x4F, 0x4E, 0x04, 0x69, 0xC9, 0xFC, 0x2C, 0x31,
	0x00, 0x85, 0x6B, 0xC9, 0xE6, 0x81, 0xFF, 0x4A, 0x98, 0x4F,
	0x02, 0x1B, 0x63, 0x01, 0x5C, 0xEE, 0xE0, 0x6C, 0x0D, 0xA0,
	0x7E, 0xC2, 0xA5, 0xFC, 0x87, 0x90, 0xB7, 0xFE, 0xA1, 0x4C,
	0x0D, 0xB9, 0x81, 0xC7, 0x68, 0x39, 0x26, 0xD3, 0x38, 0xAD,
	0x3C, 0xCC, 0x4B, 0xA5, 0x59, 0x01, 0xF1, 0x56, 0x50, 0x72,
	0x5F, 0xFF, 0x5D, 0x8C, 0x4D, 0xB9, 0xA6, 0xA1, 0x08, 0xE1,
	0xF2, 0x30, 0xA4, 0x20, 0x19, 0x08, 0x7F, 0x7E, 0x5C, 0xE7,
	0x6F, 0x7B, 0x19, 0x0D, 0xC0, 0x04, 0x9F, 0x68, 0x15, 0x52,
	0xDE, 0x8D, 0x9C, 0xA2, 0xC8, 0xE7, 0x71, 0xF2, 0x3B, 0xEE,
	0x5E, 0xB1, 0x72, 0xF5, 0x53, 0x80, 0xD8, 0x48, 0x2D, 0xF0,
	0x5B, 0xA1, 0x11, 0xFE, 0x0F, 0xCB, 0x60, 0x29, 0x2F, 0x27,
	0x44, 0x82, 0xE6, 0x24, 0x40, 0xE6, 0xF9, 0x63, 0x82, 0x82,
	0xFC, 0x3E, 0x82, 0xC0, 0xA2, 0x80, 0xF5, 0x25, 0x56, 0xB0,
	0x3A, 0x18, 0x70, 0x4C, 0x3F, 0x8A, 0xCD, 0xF5, 0x9E, 0xA9,
	0x34, 0x5D, 0x82, 0x24, 0xA3, 0xA7, 0x14, 0xC0, 0x13, 0x31,
	0x51, 0xED, 0x6F, 0x3E, 0x88, 0x2B, 0xAB, 0xE6, 0x7F, 0x2B,
	0xA7, 0x08, 0x24, 0xC5, 0x25, 0xDF, 0x16, 0x7D, 0x1E, 0x9B,
	0x7F, 0xA0, 0xDA, 0x07, 0xB0, 0x40, 0xF0, 0xCC, 0x76, 0x62,
	0xF7, 0xB1, 0x70, 0x98, 0x78, 0x94, 0x6D, 0xE4, 0x0E, 0xD4,
	0x86, 0x59, 0x9C, 0x4C, 0xBC, 0xC2, 0x6E, 0x82, 0x35, 0xF3,
	0x34, 0x2A, 0x17, 0x75, 0xA7, 0xD7, 0x5F, 0xF1, 0x45, 0x84,
	0xD5, 0x75, 0xF9, 0x3C, 0x2A, 0x82, 0xB7, 0xC0, 0x9E, 0x3E,
	0x76, 0xB2, 0xB3, 0xC2, 0xDC, 0xF4, 0xEA, 0x19, 0xC3, 0x8D,
	0xE9, 0x08, 0x8F, 0xA0, 0x2D, 0x5C, 0x48, 0x51, 0x51, 0x2B,
	0x74, 0x9E, 0xC8, 0xEB, 0x7C, 0x3C
};
const int sizeof_ca_ecc_cert_sig = sizeof(ca_ecc_cert_der_sig);

/* ./ca-cert.der.sign,  */
const unsigned char ca_cert_der_sig[] =
{
	0x2C, 0xA8, 0x2C, 0xA2, 0x95, 0x60, 0x27, 0xDA, 0xE1, 0xB9,
	0xD8, 0x74, 0x30, 0x10, 0x13, 0x5B, 0xDA, 0x9B, 0x15, 0xB7,
	0xF4, 0x65, 0x3A, 0x9C, 0x08, 0xF6, 0x2A, 0xC2, 0xF4, 0xD9,
	0x29, 0x3C, 0x27, 0xD2, 0xC6, 0x8B, 0x09, 0xB2, 0xBF, 0xEF,
	0x77, 0x7D, 0x95, 0x6B, 0xCC, 0x9E, 0x6F, 0x12, 0xDA, 0x7B,
	0x88, 0x36, 0x84, 0xB3, 0xC5, 0x9D, 0xCD, 0xEB, 0xE9, 0x87,
	0xC3, 0xB9, 0x25, 0xF2, 0x35, 0x27, 0x3D, 0x82, 0x00, 0xA9,
	0xDA, 0x16, 0x56, 0x29, 0xD1, 0xBD, 0xE5, 0x85, 0x79, 0xC9,
	0x2F, 0x95, 0x51, 0xDF, 0xD2, 0x3D, 0x83, 0x3F, 0x8C, 0xE6,
	0xB5, 0x6C, 0x86, 0x2D, 0x7B, 0x7D, 0x70, 0x02, 0xAF, 0x0C,
	0x63, 0x78, 0xB5, 0x9A, 0x39, 0xA7, 0x21, 0x8C, 0x84, 0xCB,
	0x21, 0x21, 0x9F, 0xEE, 0x3D, 0x38, 0xBC, 0xD6, 0x9B, 0x64,
	0xF0, 0x33, 0xD6, 0xE0, 0x81, 0x2E, 0x4F, 0x19, 0xBF, 0x2A,
	0x4B, 0x24, 0x0B, 0x2C, 0x39, 0xAA, 0xA6, 0x92, 0xAC, 0x00,
	0x89, 0xEB, 0xD5, 0xC2, 0x19, 0x5D, 0x33, 0xFA, 0xEE, 0xCB,
	0x99, 0x4E, 0xCE, 0x10, 0xAA, 0xFB, 0xB1, 0x3B, 0x6E, 0xEC,
	0x81, 0x01, 0xEE, 0x65, 0xE8, 0xB9, 0xC2, 0xBE, 0x05, 0x23,
	0xFE, 0x44, 0x27, 0xAA, 0x34, 0x68, 0xB3, 0x79, 0x27, 0xB8,
	0xFC, 0xCF, 0x1C, 0x31, 0x73, 0x7E, 0xFA, 0x65, 0x08, 0x91,
	0x45, 0xB6, 0xD7, 0x4D, 0x0E, 0x0D, 0x9C, 0x96, 0xDB, 0x49,
	0x98, 0xAE, 0xD6, 0xB5, 0xE7, 0x1C, 0x5E, 0xB4, 0x62, 0x52,
	0x5D, 0x82, 0x2C, 0xF2, 0x2F, 0xAE, 0xB8, 0xB4, 0x0C, 0x2A,
	0x26, 0x7E, 0xD2, 0x22, 0xE9, 0x51, 0x65, 0x75, 0x9E, 0x4F,
	0x23, 0xB9, 0x5E, 0x06, 0xD6, 0x71, 0xE6, 0x24, 0xFC, 0x89,
	0x16, 0xA1, 0xCC, 0xE2, 0x99, 0x5A, 0x98, 0xD0, 0x11, 0x8A,
	0x36, 0x26, 0xB5, 0xB4, 0xB1, 0x57
};
const int sizeof_ca_cert_sig = sizeof(ca_cert_der_sig);
/* ./client-cert.der.sign,  */
const unsigned char client_cert_der_sign[] =
{
    0x21, 0x2A, 0x81, 0xFF, 0xC2, 0x4C, 0x98, 0xFF, 0xB8, 0x99,
	0xFC, 0x14, 0x07, 0xBA, 0xBD, 0x7F, 0x58, 0x0F, 0x23, 0x49,
	0x6B, 0xFA, 0x47, 0xAC, 0xF5, 0xCF, 0x7A, 0x76, 0x89, 0x07,
	0x22, 0x2F, 0x2A, 0xC5, 0x9F, 0x6D, 0x37, 0xFC, 0x7E, 0x51,
	0x55, 0x29, 0xDA, 0xF9, 0x7E, 0x30, 0x25, 0x3F, 0x38, 0xE3,
	0x5B, 0xD8, 0xD1, 0xC4, 0xE1, 0x05, 0x14, 0x5D, 0x3A, 0x8C,
	0xFC, 0x42, 0x7D, 0x38, 0x21, 0x5B, 0x0B, 0xC8, 0x6E, 0x80,
	0x35, 0xA7, 0x0B, 0xAB, 0x9E, 0x8B, 0x7F, 0x04, 0xE5, 0x43,
	0x2E, 0xFF, 0x11, 0x67, 0x04, 0xF4, 0x52, 0x52, 0xEF, 0x6C,
	0xC6, 0x30, 0x63, 0xE0, 0xAE, 0xCB, 0xD0, 0xBC, 0x7F, 0xB7,
	0x98, 0xD4, 0x08, 0x76, 0x49, 0xFF, 0x0E, 0xAF, 0x2B, 0x3B,
	0xA0, 0xFD, 0x25, 0xD5, 0x42, 0x02, 0x0A, 0xAA, 0xC0, 0x0C,
	0x5C, 0x62, 0x04, 0xD0, 0x4A, 0xE7, 0xEA, 0x26, 0x72, 0xE1,
	0x35, 0x8D, 0x47, 0x5A, 0xE6, 0x9A, 0xD5, 0x5C, 0x31, 0x79,
	0x7A, 0xEE, 0x59, 0xAD, 0x1B, 0x04, 0x2C, 0xFF, 0x74, 0x9D,
	0xA5, 0x90, 0x21, 0xCE, 0xC2, 0x04, 0x41, 0x98, 0x14, 0x27,
	0xF8, 0x35, 0xB9, 0xF5, 0x73, 0x1D, 0xAE, 0x2F, 0x8F, 0x44,
	0x79, 0xCA, 0xE7, 0x38, 0xDD, 0x15, 0x11, 0xDB, 0xA5, 0x6D,
	0xE6, 0x7F, 0x4E, 0x73, 0xE6, 0x2E, 0x98, 0xF3, 0xDD, 0x5A,
	0x34, 0x24, 0x6B, 0xAF, 0x28, 0xDC, 0x3A, 0x10, 0x0D, 0x54,
	0x86, 0x11, 0x52, 0x0F, 0x88, 0x65, 0x03, 0xE5, 0x1C, 0x04,
	0x45, 0x6B, 0x25, 0x3E, 0x8D, 0x5B, 0xD7, 0x2E, 0x33, 0x06,
	0xAA, 0x23, 0xFE, 0x1B, 0x7B, 0xE8, 0xB9, 0xA7, 0x80, 0x3F,
	0x08, 0x89, 0x6A, 0x22, 0x3F, 0xE0, 0xB8, 0xF3, 0xA4, 0x0A,
	0xC6, 0xA5, 0x51, 0xC4, 0x1A, 0x38, 0xE3, 0xD2, 0x8A, 0x1C,
	0xF1, 0xAE, 0x89, 0xFB, 0xCE, 0x9E
};
const int sizeof_client_cert_der_sign = sizeof(client_cert_der_sign);

uint32_t s_inst1[R_TSIP_SINST_WORD_SIZE] = { 0 };
uint32_t s_inst2[R_TSIP_SINST2_WORD_SIZE]= { 0 };

#endif /* WOLFSSL_RENESAS_TSIP_TLS && (WOLFSSL_RENESAS_TSIP_VER >= 109) */