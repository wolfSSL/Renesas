# -*- coding: utf-8 -*-
#
# test_methods.py
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

# pylint: disable=missing-docstring, redefined-outer-name, import-error

import pytest
from wolfssl._methods import (WolfSSLMethod, PROTOCOL_SSLv3, PROTOCOL_SSLv23,
                              PROTOCOL_TLS, PROTOCOL_TLSv1, PROTOCOL_TLSv1_1,
                              PROTOCOL_TLSv1_2)
from wolfssl._ffi import ffi as _ffi

@pytest.fixture(
    params=[-1, PROTOCOL_SSLv3, PROTOCOL_TLSv1, PROTOCOL_TLSv1_1],
    ids=["invalid", "SSLv3", "TLSv1", "TLSv1_1"])
def unsupported_method(request):
    yield request.param

@pytest.fixture(
    params=[PROTOCOL_SSLv23, PROTOCOL_TLS, PROTOCOL_TLSv1_2],
    ids=["SSLv23", "TLS", "TLSv1_2"])
def supported_method(request):
    yield request.param


def test_unsupported_method(unsupported_method):
    with pytest.raises(ValueError):
        WolfSSLMethod(unsupported_method, False)

    with pytest.raises(ValueError):
        WolfSSLMethod(unsupported_method, True)

def test_supported_method(supported_method):
    client = WolfSSLMethod(supported_method, False)
    server = WolfSSLMethod(supported_method, True)

    assert isinstance(client, WolfSSLMethod)
    assert isinstance(server, WolfSSLMethod)
    assert client.native_object != _ffi.NULL
    assert server.native_object != _ffi.NULL
