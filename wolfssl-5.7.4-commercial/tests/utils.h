/* utils.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>
#include <tests/unit.h>

#ifndef NO_FILESYSTEM

#ifdef _MSC_VER
#include <direct.h>
#endif

#define TMP_DIR_PREFIX "tmpDir-"
/* len is length of tmpDir name, assuming
 * len does not include null terminating character */
char* create_tmp_dir(char *tmpDir, int len)
{
    if (len < (int)XSTR_SIZEOF(TMP_DIR_PREFIX))
        return NULL;

    XMEMCPY(tmpDir, TMP_DIR_PREFIX, XSTR_SIZEOF(TMP_DIR_PREFIX));

    if (mymktemp(tmpDir, len, len - (int)XSTR_SIZEOF(TMP_DIR_PREFIX)) == NULL)
        return NULL;

#ifdef _MSC_VER
    if (_mkdir(tmpDir) != 0)
        return NULL;
#elif defined(__MINGW32__)
    if (mkdir(tmpDir) != 0)
        return NULL;
#else
    if (mkdir(tmpDir, 0700) != 0)
        return NULL;
#endif

    return tmpDir;
}

int rem_dir(const char* dirName)
{
#ifdef _MSC_VER
    if (_rmdir(dirName) != 0)
        return -1;
#else
    if (rmdir(dirName) != 0)
        return -1;
#endif
    return 0;
}

int rem_file(const char* fileName)
{
#ifdef _MSC_VER
    if (_unlink(fileName) != 0)
        return -1;
#else
    if (unlink(fileName) != 0)
        return -1;
#endif
    return 0;
}

int copy_file(const char* in, const char* out)
{
    byte buf[100];
    XFILE inFile = XBADFILE;
    XFILE outFile = XBADFILE;
    size_t sz;
    int ret = -1;

    inFile = XFOPEN(in, "rb");
    if (inFile == XBADFILE)
        goto cleanup;

    outFile = XFOPEN(out, "wb");
    if (outFile == XBADFILE)
        goto cleanup;

    while ((sz = XFREAD(buf, 1, sizeof(buf), inFile)) != 0) {
        if (XFERROR(inFile))
            goto cleanup;
        if (XFWRITE(buf, 1, sz, outFile) != sz)
            goto cleanup;
        if (XFEOF(inFile))
            break;
    }

    ret = 0;
cleanup:
    if (inFile != XBADFILE)
        XFCLOSE(inFile);
    if (outFile != XBADFILE)
        XFCLOSE(outFile);
    return ret;
}

#if defined(__MACH__) || defined(__FreeBSD__)
int link_file(const char* in, const char* out)
{
    return link(in, out);
}
#endif
#endif /* !NO_FILESYSTEM */

#define TEST_MEMIO_BUF_SZ (64 * 1024)
struct test_memio_ctx
{
    byte c_buff[TEST_MEMIO_BUF_SZ];
    int c_len;
    const char* c_ciphers;
    byte s_buff[TEST_MEMIO_BUF_SZ];
    int s_len;
    const char* s_ciphers;
};
int test_memio_do_handshake(WOLFSSL *ssl_c, WOLFSSL *ssl_s,
    int max_rounds, int *rounds);
int test_memio_setup(struct test_memio_ctx *ctx,
    WOLFSSL_CTX **ctx_c, WOLFSSL_CTX **ctx_s, WOLFSSL **ssl_c, WOLFSSL **ssl_s,
    method_provider method_c, method_provider method_s);
int test_memio_setup_ex(struct test_memio_ctx *ctx,
    WOLFSSL_CTX **ctx_c, WOLFSSL_CTX **ctx_s, WOLFSSL **ssl_c, WOLFSSL **ssl_s,
    method_provider method_c, method_provider method_s,
    byte *caCert, int caCertSz, byte *serverCert, int serverCertSz,
    byte *serverKey, int serverKeySz);

#if !defined(SINGLE_THREADED) && defined(WOLFSSL_COND)
void signal_ready(tcp_ready* ready)
{
    THREAD_CHECK_RET(wolfSSL_CondStart(&ready->cond));
    ready->ready = 1;
    THREAD_CHECK_RET(wolfSSL_CondSignal(&ready->cond));
    THREAD_CHECK_RET(wolfSSL_CondEnd(&ready->cond));
}
#endif

void wait_tcp_ready(func_args* args)
{
#if !defined(SINGLE_THREADED) && defined(WOLFSSL_COND)
    tcp_ready* ready = args->signal;
    THREAD_CHECK_RET(wolfSSL_CondStart(&ready->cond));
    if (!ready->ready) {
        THREAD_CHECK_RET(wolfSSL_CondWait(&ready->cond));
    }
    ready->ready = 0; /* reset */
    THREAD_CHECK_RET(wolfSSL_CondEnd(&ready->cond));
#else
    /* no threading wait or single threaded */
    (void)args;
#endif
}

#ifndef SINGLE_THREADED
/* Start a thread.
 *
 * @param [in]  fun     Function to execute in thread.
 * @param [in]  args    Object to send to function in thread.
 * @param [out] thread  Handle to thread.
 */
void start_thread(THREAD_CB fun, func_args* args, THREAD_TYPE* thread)
{
    THREAD_CHECK_RET(wolfSSL_NewThread(thread, fun, args));
}


/* Join thread to wait for completion.
 *
 * @param [in] thread  Handle to thread.
 */
void join_thread(THREAD_TYPE thread)
{
    THREAD_CHECK_RET(wolfSSL_JoinThread(thread));
}
#endif /* SINGLE_THREADED */

/* These correspond to WOLFSSL_SSLV3...WOLFSSL_DTLSV1_3 */
const char* tls_desc[] = {
    "SSLv3", "TLSv1.0", "TLSv1.1", "TLSv1.2", "TLSv1.3",
    "DTLSv1.0", "DTLSv1.2", "DTLSv1.3"
};
