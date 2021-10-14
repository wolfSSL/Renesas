# -*- coding: utf-8 -*-
#
# _methods.py
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

try:
    from wolfssl._ffi import ffi as _ffi
    from wolfssl._ffi import lib as _lib
except ImportError:
    pass

from wolfssl._memory import (
    _native_free, _DYNAMIC_TYPE_METHOD
)


PROTOCOL_SSLv23 = 1
PROTOCOL_SSLv3 = 2
PROTOCOL_TLS = 1
PROTOCOL_TLSv1 = 3
PROTOCOL_TLSv1_1 = 4
PROTOCOL_TLSv1_2 = 5

_PROTOCOL_LIST = [PROTOCOL_SSLv23, PROTOCOL_SSLv3, PROTOCOL_TLS,
                  PROTOCOL_TLSv1, PROTOCOL_TLSv1_1, PROTOCOL_TLSv1_2]


class WolfSSLMethod(object):
    """
    An SSLMethod holds SSL-related configuration options such as
    protocol version and communication side.
    """

    def __init__(self, protocol, server_side):
        if protocol not in _PROTOCOL_LIST:
            raise ValueError("this protocol is not supported")

        elif protocol == PROTOCOL_SSLv3:
            raise ValueError("this protocol is not supported")

        elif protocol == PROTOCOL_TLSv1:
            raise ValueError("this protocol is not supported")

        elif protocol == PROTOCOL_TLSv1_1:
            raise ValueError("this protocol is not supported")

        elif protocol == PROTOCOL_TLSv1_2:
            self.native_object =                                     \
                _lib.wolfTLSv1_2_server_method() if server_side else \
                _lib.wolfTLSv1_2_client_method()

        elif protocol in [PROTOCOL_SSLv23, PROTOCOL_TLS]:
            self.native_object =                                    \
                _lib.wolfSSLv23_server_method() if server_side else \
                _lib.wolfSSLv23_client_method()

        if self.native_object == _ffi.NULL:
            raise MemoryError("Unnable to allocate method object")


    def __del__(self):
        if getattr(self, 'native_object', _ffi.NULL) != _ffi.NULL:
            _native_free(self.native_object, _DYNAMIC_TYPE_METHOD)
