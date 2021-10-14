# -*- coding: utf-8 -*-
#
# test_context.py
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

# pylint: disable=missing-docstring, invalid-name, import-error
# pylint: disable=redefined-outer-name

import pytest

with open("certs/ca-cert.pem") as ca:
    _CADATA = ca.read()

def test_context_creation(ssl_context):
    assert ssl_context != None

def test_verify_mode(ssl_provider, ssl_context):
    with pytest.raises(ValueError):
        ssl_context.verify_mode = -1

    assert ssl_context.verify_mode == ssl_provider.CERT_NONE

    ssl_context.verify_mode = ssl_provider.CERT_REQUIRED
    assert ssl_context.verify_mode == ssl_provider.CERT_REQUIRED

def test_set_ciphers(ssl_context):
    ssl_context.set_ciphers("DHE-RSA-AES256-SHA256")

    with pytest.raises(Exception):
        ssl_context.set_ciphers("foo")

def test_load_cert_chain_raises(ssl_context):
    with pytest.raises(TypeError):
        ssl_context.load_cert_chain(None)

def test_load_cert_chain(ssl_context):
    ssl_context.load_cert_chain("certs/client-cert.pem",
                                "certs/client-key.pem")

def test_load_verify_locations_raises(ssl_context):
    with pytest.raises(TypeError):
        ssl_context.load_verify_locations(None)

def test_load_verify_locations_with_cafile(ssl_context):
    ssl_context.load_verify_locations(cafile="certs/ca-cert.pem")

def test_load_verify_locations_with_cadata(ssl_provider, ssl_context):
    ssl_context.load_verify_locations(cadata=_CADATA)
