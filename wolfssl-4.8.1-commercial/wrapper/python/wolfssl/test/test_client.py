# -*- coding: utf-8 -*-
#
# test_client.py
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

HOST = "www.python.org"
PORT = 443
CA_CERTS = "certs/ca-digicert-ev.pem"

@pytest.fixture(
    params=["wrap_socket", "wrap_socket_with_ca",
            "wrap_socket_from_context", "ssl_socket"])
def secure_socket(request, ssl_provider, tcp_socket):
    sock = None

    if request.param == "wrap_socket":
        sock = ssl_provider.wrap_socket(tcp_socket)

    elif request.param == "wrap_socket_with_ca":
        sock = ssl_provider.wrap_socket(
            tcp_socket, cert_reqs=ssl_provider.CERT_REQUIRED, ca_certs=CA_CERTS)

    elif request.param == "wrap_socket_from_context":
        ctx = ssl_provider.SSLContext(ssl_provider.PROTOCOL_TLSv1_2)

        ctx.verify_mode = ssl_provider.CERT_REQUIRED
        ctx.load_verify_locations(CA_CERTS)

        sock = ctx.wrap_socket(tcp_socket)

    elif request.param == "ssl_socket":
        sock = ssl_provider.SSLSocket(
            tcp_socket, cert_reqs=ssl_provider.CERT_REQUIRED, ca_certs=CA_CERTS)

    if sock:
        yield sock
        sock.close()

def test_secure_connection(secure_socket):
    secure_socket.connect((HOST, PORT))

    secure_socket.write(b"GET / HTTP/1.1\n\n")
    assert secure_socket.read(4) == b"HTTP"
