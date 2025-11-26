#!/usr/bin/env python
#
#  pio_install_cryptography.py
#
# Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfSSL.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com
#
# Import("env")
import subprocess
import sys

# Function to install a package
def install(package):
    subprocess.check_call([sys.executable, "-m", "pip", "install", package])

try:
    # Check if cryptography is installed
    import cryptography
except ImportError:
    # If not installed, install it
    print("cryptography package not found. Installing...")
    install("cryptography")
