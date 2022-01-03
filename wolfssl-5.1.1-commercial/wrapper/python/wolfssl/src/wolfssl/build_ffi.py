# -*- coding: utf-8 -*-
#
# build_ffi.py
#
# Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfSSL.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com
#/
#/
#/

# pylint: disable=missing-docstring, invalid-name

from cffi import FFI

ffi = FFI()

ffi.set_source(
    "wolfssl._ffi",
    """
    #include <wolfssl/options.h>
    #include <wolfssl/ssl.h>

    void wolfSSL_Free(void *ptr, void* heap, int type);
    """,
    include_dirs=["/usr/local/include"],
    library_dirs=["/usr/local/lib"],
    libraries=["wolfssl"],
)

ffi.cdef(
    """
    typedef unsigned char byte;
    typedef unsigned int  word32;

    void  wolfSSL_Free(void*, void*, int);

    void* wolfSSLv23_server_method(void);
    void* wolfSSLv23_client_method(void);
    void* wolfTLSv1_2_server_method(void);
    void* wolfTLSv1_2_client_method(void);

    void* wolfSSL_CTX_new(void*);
    void  wolfSSL_CTX_free(void*);

    void wolfSSL_CTX_set_verify(void*, int, void*);
    int  wolfSSL_CTX_set_cipher_list(void*, const char*);
    int  wolfSSL_CTX_use_PrivateKey_file(void*, const char*, int);
    int  wolfSSL_CTX_load_verify_locations(void*, const char*, const char*);
    int  wolfSSL_CTX_load_verify_buffer(void*, const unsigned char*, long, int);
    int  wolfSSL_CTX_use_certificate_chain_file(void*, const char *);
    int  wolfSSL_CTX_UseSupportedCurve(void*, short);


    void* wolfSSL_new(void*);
    void  wolfSSL_free(void*);

    int wolfSSL_set_fd(void*, int);
    int wolfSSL_get_error(void*, int);
    int wolfSSL_negotiate(void*);
    int wolfSSL_write(void*, const void*, int);
    int wolfSSL_read(void*, void*, int);
    int wolfSSL_shutdown(void*);
    """
)

if __name__ == "__main__":
    ffi.compile(verbose=1)
