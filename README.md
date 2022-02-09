# wolfSSL Product for Renesas

This repository contains commercially licensed wolfSSL product code for use on
specified Renesas platforms. This code is only properly licensed when following
the license terms in the LICENSE file included in this repository. wolfCrypt
only usage is excluded from this license.

## wolfSSL Embedded SSL/TLS Library

wolfSSL is a lightweight, embedded SSL/TLS library that supports up to the most
current TLS 1.3 and DTLS 1.2 protocols.

### Library Version Information

This repository currently contains the following wolfSSL product versions.

|Product|Version|Notes|
|:--|:--|:--|
|wolfSSL|Post 5.1.1 dev|Development version matching wolfSSL repo commit cba262440a388ef1420f30ba99d6f0efe3a419f7. Includes RA6M3 FSP 3.5.0 and RX72N FreeRTOS example project.|

## wolfSSL Renesas Support

The wolfSSL library supports several Renesas MCUs, with example projects for
either e2studio or CS+. wolfSSL inludes support for leveraging the Renesas
Trusted Secure IP Driver (TSIP) and Secure Cryptographic Engine (SCE).
Complete details can be found in each example's respective README, located
in the subdirectory linked below.

### Current Software Package / Driver Support

|MCU|Software / Driver|
|:--|:--|
|Synergy S7G2|SSP 1.7.0|
|RA6M3|FSP 3.5.0|
|RA6M4|FSP 3.5.0|
|RX65N|TSIP 1.14|
|RX72N|TSIP 1.14|

### Available Example Projects

wolfSSL maintains example projects for the following supported Renesas
platforms. These examples are located in the ```wolfssl/IDE/Renesas```
directory.

|Microcontroller|Platform|Example Project|
|:--|:--|:--|
|Synergy S7G2|DK-S7G2|[IDE/Renesas/e2studio/DK-S7G2](./wolfssl-5.1.1-commercial/IDE/Renesas/e2studio/DK-S7G2)|
|RA6M3|EK-RA6M3|[IDE/Renesas/e2studio/RA6M3](./wolfssl-5.1.1-commercial/IDE/Renesas/e2studio/RA6M3)|
|RA6M4|EK-RA6M4|[IDE/Renesas/e2studio/RA6M4](./wolfssl-5.1.1-commercial/IDE/Renesas/e2studio/RA6M4)|
|RX65N|GR-ROSE|[IDE/Renesas/e2studio/RX65N/GR-ROSE](./wolfssl-5.1.1-commercial/IDE/Renesas/e2studio/RX65N/GR-ROSE)|
|RX65N|Renesas Starter Kit＋ for RX65N-2MB|[IDE/Renesas/e2studio/RX65N/RSK](./wolfssl-5.1.1-commercial/IDE/Renesas/e2studio/RX65N/RSK)|
|RX72N|RX72N EnvisionKit|[IDE/Renesas/e2studio/RX72N/EnvisionKit](./wolfssl-5.1.1-commercial/IDE/Renesas/e2studio/RX72N/EnvisionKit)|

## Additional wolfSSL Products to Explore

|Product|Description|
|:--|:--|
|[wolfSSH](https://www.wolfssl.com/products/wolfssh/)|Lightweight SSHv2 library
|[wolfMQTT](https://www.wolfssl.com/products/wolfmqtt/)|Lightweight MQTT client
|[wolfBoot](https://www.wolfssl.com/products/wolfboot/)|Portable secure bootloader
|[wolfSentry](https://www.wolfssl.com/products/wolfsentry/)|Embedded IDPS
|[wolfCrypt FIPS 140-2/3](https://www.wolfssl.com/license/fips/)|FIPS 140-2/3 validated crypto
|[wolfCrypt FIPS Ready](https://www.wolfssl.com/license/fips/)|FIPS crypto without a validation
|[wolfTPM](https://www.wolfssl.com/products/wolftpm/)|Portable TPM 2.0 library
|[tiny-curl](https://www.wolfssl.com/products/curl/#panel-34394-3-0-0)|Lightweight version of libcurl

## Further Resources

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

For support inquiries and questions, please email support@wolfssl.com. Feel free to reach out to info@wolfssl.jp as well.

