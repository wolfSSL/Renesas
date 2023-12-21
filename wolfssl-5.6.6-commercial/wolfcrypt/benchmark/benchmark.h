/* wolfcrypt/benchmark/benchmark.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFCRYPT_BENCHMARK_H
#define WOLFCRYPT_BENCHMARK_H


#ifdef __cplusplus
    extern "C" {
#endif

#include <wolfssl/wolfcrypt/types.h> /* Needed for 'byte' typedef */

/* run all benchmark entry */
#ifdef HAVE_STACK_SIZE
THREAD_RETURN WOLFSSL_THREAD benchmark_test(void* args);
#else
int benchmark_test(void *args);
#endif
#ifndef NO_MAIN_DRIVER
int wolfcrypt_benchmark_main(int argc, char** argv);
#endif

/* individual benchmarks */
int  benchmark_init(void);
int  benchmark_free(void);
void benchmark_configure(word32 block_size);

void bench_des(int useDeviceID);
void bench_arc4(int useDeviceID);
void bench_chacha(void);
void bench_chacha20_poly1305_aead(void);
void bench_aescbc(int useDeviceID);
void bench_aesgcm(int useDeviceID);
void bench_gmac(int useDeviceID);
void bench_aesccm(int useDeviceID);
void bench_aesecb(int useDeviceID);
void bench_aesxts(void);
void bench_aesctr(int useDeviceID);
void bench_aescfb(void);
void bench_aesofb(void);
void bench_aessiv(void);
void bench_poly1305(void);
void bench_camellia(void);
void bench_sm4_cbc(void);
void bench_sm4_gcm(void);
void bench_sm4_ccm(void);
void bench_md5(int useDeviceID);
void bench_sha(int useDeviceID);
void bench_sha224(int useDeviceID);
void bench_sha256(int useDeviceID);
void bench_sha384(int useDeviceID);
void bench_sha512(int useDeviceID);
#if !defined(WOLFSSL_NOSHA512_224) && \
   (!defined(HAVE_FIPS) || FIPS_VERSION_GE(5, 3)) && !defined(HAVE_SELFTEST)
void bench_sha512_224(int useDeviceID);
#endif
#if !defined(WOLFSSL_NOSHA512_256) && \
   (!defined(HAVE_FIPS) || FIPS_VERSION_GE(5, 3)) && !defined(HAVE_SELFTEST)
void bench_sha512_256(int useDeviceID);
#endif
void bench_sha3_224(int useDeviceID);
void bench_sha3_256(int useDeviceID);
void bench_sha3_384(int useDeviceID);
void bench_sha3_512(int useDeviceID);
void bench_shake128(int useDeviceID);
void bench_shake256(int useDeviceID);
void bench_sm3(int useDeviceID);
void bench_ripemd(void);
void bench_cmac(int useDeviceID);
void bench_scrypt(void);
void bench_hmac_md5(int useDeviceID);
void bench_hmac_sha(int useDeviceID);
void bench_hmac_sha224(int useDeviceID);
void bench_hmac_sha256(int useDeviceID);
void bench_hmac_sha384(int useDeviceID);
void bench_hmac_sha512(int useDeviceID);
void bench_siphash(void);
void bench_srtpkdf(void);
void bench_rsaKeyGen(int useDeviceID);
void bench_rsaKeyGen_size(int useDeviceID, word32 keySz);
void bench_rsa(int useDeviceID);
void bench_rsa_key(int useDeviceID, word32 keySz);
void bench_dh(int useDeviceID);
void bench_kyber(int type);
void bench_lms(void);
void bench_xmss(void);
void bench_ecc_curve(int curveId);
void bench_eccMakeKey(int useDeviceID, int curveId);
void bench_ecc(int useDeviceID, int curveId);
void bench_eccEncrypt(int curveId);
void bench_sm2(int useDeviceID);
void bench_curve25519KeyGen(int useDeviceID);
void bench_curve25519KeyAgree(int useDeviceID);
void bench_ed25519KeyGen(void);
void bench_ed25519KeySign(void);
void bench_curve448KeyGen(void);
void bench_curve448KeyAgree(void);
void bench_ed448KeyGen(void);
void bench_ed448KeySign(void);
void bench_eccsiKeyGen(void);
void bench_eccsiPairGen(void);
void bench_eccsiValidate(void);
void bench_eccsi(void);
void bench_sakkeKeyGen(void);
void bench_sakkeRskGen(void);
void bench_sakkeValidate(void);
void bench_sakke(void);
void bench_rng(void);
void bench_blake2b(void);
void bench_blake2s(void);
void bench_pbkdf2(void);
void bench_falconKeySign(byte level);
void bench_dilithiumKeySign(byte level);
void bench_sphincsKeySign(byte level, byte optim);

void bench_stats_print(void);


#ifdef __cplusplus
    }  /* extern "C" */
#endif


#endif /* WOLFCRYPT_BENCHMARK_H */

