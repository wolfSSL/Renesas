/* wolfcrypt/benchmark/benchmark.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
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

/* run all benchmark entry */
#ifdef HAVE_STACK_SIZE
THREAD_RETURN WOLFSSL_THREAD benchmark_test(void* args);
#else
int benchmark_test(void *args);
#endif

/* individual benchmarks */
int  benchmark_init(void);
int  benchmark_free(void);
void benchmark_configure(int block_size);

void bench_des(int doAsync);
void bench_arc4(int doAsync);
void bench_chacha(void);
void bench_chacha20_poly1305_aead(void);
void bench_aescbc(int doAsync);
void bench_aesgcm(int doAsync);
void bench_gmac(void);
void bench_aesccm(void);
void bench_aesecb(int doAsync);
void bench_aesxts(void);
void bench_aesctr(void);
void bench_aescfb(void);
void bench_aesofb(void);
void bench_aessiv(void);
void bench_poly1305(void);
void bench_camellia(void);
void bench_md5(int doAsync);
void bench_sha(int doAsync);
void bench_sha224(int doAsync);
void bench_sha256(int doAsync);
void bench_sha384(int doAsync);
void bench_sha512(int doAsync);
void bench_sha3_224(int doAsync);
void bench_sha3_256(int doAsync);
void bench_sha3_384(int doAsync);
void bench_sha3_512(int doAsync);
int  bench_ripemd(void);
void bench_cmac(void);
void bench_scrypt(void);
void bench_hmac_md5(int doAsync);
void bench_hmac_sha(int doAsync);
void bench_hmac_sha224(int doAsync);
void bench_hmac_sha256(int doAsync);
void bench_hmac_sha384(int doAsync);
void bench_hmac_sha512(int doAsync);
void bench_siphash(void);
void bench_rsaKeyGen(int doAsync);
void bench_rsaKeyGen_size(int doAsync, int keySz);
void bench_rsa(int doAsync);
void bench_rsa_key(int doAsync, int keySz);
void bench_dh(int doAsync);
void bench_ecc_curve(int curveId);
void bench_eccMakeKey(int doAsync, int curveId);
void bench_ecc(int doAsync, int curveId);
void bench_eccEncrypt(int curveId);
void bench_curve25519KeyGen(void);
void bench_curve25519KeyAgree(void);
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
void bench_pqcKemKeygen(word32 alg);
void bench_pqcKemEncapDecap(word32 alg);

void bench_stats_print(void);


#ifdef __cplusplus
    }  /* extern "C" */
#endif


#endif /* WOLFCRYPT_BENCHMARK_H */

