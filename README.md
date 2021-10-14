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

### Current Software Package / Driver Support

|MCU|Software / Driver|
|:--|:--|
|Synergy S7G2|SSP 1.7.0|
|RA6M3|FSP 0.8.0|
|RX65N|TSIP 1.10|
|RX72N|TSIP 1.13|

### Available Example Projects

wolfSSL maintains example projects for the following supported Renesas
platforms. These examples are located in the ```wolfssl/IDE/Renesas```
directory.

|Microcontroller|Platform|Example Project|
|:--|:--|:--|
|Synergy S7G2|DK-S7G2|[IDE/Renesas/e2studio/DK-S7G2](./wolfssl-4.8.1-commercial/IDE/Renesas/e2studio/DK-S7G2)|
|RA6M3|EK-RA6M3|[IDE/Renesas/e2studio/RA6M3](./wolfssl-4.8.1-commercial/IDE/Renesas/e2studio/RA6M3)|
|RX65N|GR-ROSE|[IDE/Renesas/e2studio/GR-ROSE](./wolfssl-4.8.1-commercial/IDE/Renesas/e2studio/GR-ROSE)|
|RX72N|RX72NEnvisionKit|[IDE/Renesas/e2studio/RX72NEnvisionKit](./wolfssl-4.8.1-commercial/IDE/Renesas/e2studio/RX72NEnvisionKit)|

### Further Resources

#### wolfSSL Website
[wolfSSL Renesas Support](https://www.wolfssl.com/docs/renesas/) \
[wolfSSL TSIP Support](https://www.wolfssl.com/docs/wolfssl-renesas-tsip/)

#### Renesas Website

**MCU Resources**\
[Renesas RX MCUs](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rx-32-bit-performance-efficiency-mcus) \
[Renesas RA MCUs](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus) \
[Renesas Synergy MCUs](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/renesas-synergy-platform-mcus)

**Driver and Module Resources**\
[Renesas Trusted Secure IP Driver (TSIP)](https://www.renesas.com/us/en/software-tool/trusted-secure-ip-driver) \
[Renesas Secure Cryptographic Module (SCE) HAL Module Guide](https://www.renesas.com/us/en/document/apn/sce-hal-module-guide-application-project)

## Support

For support inquiries and questions, please email support@wolfssl.com.

