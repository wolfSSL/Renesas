# -*- coding: utf-8 -*-
#
# _memory.py
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

# pylint: disable=missing-docstring

try:
    from wolfssl._ffi import ffi as _ffi
    from wolfssl._ffi import lib as _lib
except ImportError:
    pass

_DYNAMIC_TYPE_METHOD = 11

def _native_free(native_object, dynamic_type):
    _lib.wolfSSL_Free(native_object, _ffi.NULL, dynamic_type)
