# -*- coding: utf-8 -*-
#
# conftest.py
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

# pylint: disable=missing-docstring, redefined-outer-name

import sys
import ssl
import wolfssl
import pytest

@pytest.fixture
def tcp_socket():
    import socket
    from contextlib import closing

    with closing(socket.socket(socket.AF_INET, socket.SOCK_STREAM)) as sock:
        yield sock

@pytest.fixture(
    params=[ssl, wolfssl]  if sys.version_info.major == 3 else [wolfssl],
    ids=["ssl", "wolfssl"] if sys.version_info.major == 3 else ["wolfssl"])
def ssl_provider(request):
    return request.param

@pytest.fixture
def ssl_context(ssl_provider):
    return ssl_provider.SSLContext(ssl_provider.PROTOCOL_SSLv23)
