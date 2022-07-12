/* cpuid.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef WOLF_CRYPT_CPUID_H
#define WOLF_CRYPT_CPUID_H


#include <wolfssl/wolfcrypt/types.h>


#ifdef __cplusplus
    extern "C" {
#endif

#if (defined(WOLFSSL_X86_64_BUILD) || defined(USE_INTEL_SPEEDUP) || \
    defined(WOLFSSL_AESNI) || defined(WOLFSSL_SP_X86_64_ASM)) && \
    !defined(WOLFSSL_NO_ASM)
    #define HAVE_CPUID
    #define HAVE_CPUID_INTEL
#endif

#ifdef HAVE_CPUID_INTEL

    #define CPUID_AVX1   0x0001
    #define CPUID_AVX2   0x0002
    #define CPUID_RDRAND 0x0004
    #define CPUID_RDSEED 0x0008
    #define CPUID_BMI2   0x0010   /* MULX, RORX */
    #define CPUID_AESNI  0x0020
    #define CPUID_ADX    0x0040   /* ADCX, ADOX */
    #define CPUID_MOVBE  0x0080   /* Move and byte swap */

    #define IS_INTEL_AVX1(f)    ((f) & CPUID_AVX1)
    #define IS_INTEL_AVX2(f)    ((f) & CPUID_AVX2)
    #define IS_INTEL_RDRAND(f)  ((f) & CPUID_RDRAND)
    #define IS_INTEL_RDSEED(f)  ((f) & CPUID_RDSEED)
    #define IS_INTEL_BMI2(f)    ((f) & CPUID_BMI2)
    #define IS_INTEL_AESNI(f)   ((f) & CPUID_AESNI)
    #define IS_INTEL_ADX(f)     ((f) & CPUID_ADX)
    #define IS_INTEL_MOVBE(f)   ((f) & CPUID_MOVBE)

#endif

#ifdef HAVE_CPUID
    void cpuid_set_flags(void);
    word32 cpuid_get_flags(void);

    /* Public APIs to modify flags. */
    WOLFSSL_API void cpuid_select_flags(word32 flags);
    WOLFSSL_API void cpuid_set_flag(word32 flag);
    WOLFSSL_API void cpuid_clear_flag(word32 flag);

#endif

#ifdef __cplusplus
    }   /* extern "C" */
#endif


#endif /* WOLF_CRYPT_CPUID_H */
