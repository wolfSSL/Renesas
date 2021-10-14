# wolfSSL Products for Renesas

This repository contains commercially licensed wolfSSL products for use on
specified Renesas platforms. This code is only properly licensed when following
the license terms in the LICENSE file included in this repository.

## wolfSSL Embedded SSL/TLS Library

wolfSSL is a lightweight, embedded SSL/TLS library that supports up to the most
current TLS 1.3 and DTLS 1.2 protocols.

### Library Version Information

This repository currently contains the following wolfSSL product versions.

|Product|Version|Notes|
|:--|:--|:--|
|wolfSSL|4.8.1 dev|Development version matching wolfSSL repo commit b2b39f01b7fb695cad33e5ffcec823cb67c16bc7. Includes TSIP 1.13 support. Stable wolfSSL version will be updated here next wolfSSL stable release.|

## wolfSSL Renesas Support

The wolfSSL and wolfCrypt libraries support several Renesas MCUs, with example
projects for either e2studio or CS+. wolfSSL inludes support for leveraging the
Renesas Trusted Secure IP Driver (TSIP) and Secure Cryptographic Engine (SCE).
Complete details can be found in each example's respective README, located
in the subdirectory linked below.

### Available Example Projects

wolfSSL maintains example projects for the following supported Renesas
platforms. These examples are located in the ```wolfssl/IDE/Renesas```
directory.

|Microcontroller|Platform|Example Project|
|:--|:--|:--|
|Synergy S7G2|DK-S7G2|[IDE/Renesas/e2studio/DK-S7G2](./wolfssl/Renesas/e2studio/DK-S7G2)|
|RA6M3|EK-RA6M3|[IDE/Renesas/e2studio/RA6M3](./wolfssl/Renesas/e2studio/RA6M3)|
|RX65N|GR-ROSE|[IDE/Renesas/e2studio/GR-ROSE](./wolfssl/Renesas/e2studio/GR-ROSE)|
|RX72N|RX72NEnvisionKit|[IDE/Renesas/e2studio/RX72NEnvisionKit](./wolfssl/Renesas/e2studio/RX72NEnvisionKit)|

## Support

For support inquiries and questions, please email support@wolfssl.com.

