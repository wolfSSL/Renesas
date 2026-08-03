# wolfSSL Support for Renesas Platforms

## Repository Transition Notice

wolfSSL has worked closely with the Renesas developer community for many years
to help enable secure embedded and IoT solutions across a wide range of Renesas
platforms. This repository previously provided access to commercial wolfSSL
packages for Renesas platforms.

As part of an update to our software distribution program, the commercial
wolfSSL packages that were previously available through this repository are no
longer distributed here.

We sincerely appreciate the support and engagement of the Renesas community and
remain committed to supporting developers building secure products on Renesas
devices.

## Continuing Your Integration / Licensing

The end of the bundled license is not the end of wolfSSL on Renesas. wolfSSL
remains fully committed to Renesas platform support, and obtaining a license is
straightforward.

Contact licensing@wolfssl.com to find the right license for your project.

## Future Updates and Support

wolfSSL continues to invest in security solutions for embedded and connected
devices and values its long-standing relationship with the Renesas ecosystem.

We look forward to supporting developers as they build the next generation of
secure products using Renesas technologies.

## wolfSSL Embedded SSL/TLS Library

### Supported Renesas Platforms

The [wolfSSL](https://www.wolfssl.com/products/wolfssl/) lightweight SSL/TLS
library supports up to TLS 1.3 and DTLS 1.3 on several Renesas MCUs, with
example projects for e2studio and CS+. wolfSSL includes support for leveraging
the Renesas Trusted Secure IP Driver (TSIP) and Secure Cryptographic Engine
(SCE).

|MCU|Previously Included|Software / Driver|
|:--|:--|:--|
|Synergy S7G2 (DK-S7G2)|Yes|SSP 1.7.0|
|Synergy S7G2 (SK-S7G2)|Yes|SSP 2.7.0|
|RA6M3|Yes|FSP 6.1.0|
|RA6M4|Yes|FSP 6.1.0|
|RX65N (GR-ROSE)|Yes|TSIP 1.21|
|RX65N (RSK-RX65N)|Yes|TSIP 1.21|
|RX72N|Yes|TSIP 1.21|
|RZN2L|No|FSP 2.0.0|

### Example Projects

Example projects for the following platforms were previously included in this
repository.

wolfSSL continues to maintain GPLv3-licensed example projects for these Renesas
platforms in the main wolfssl GitHub repository, linked below.

|Microcontroller|Platform|Example Project|
|:--|:--|:--|
|Synergy S7G2|DK-S7G2|[IDE/Renesas/e2studio/DK-S7G2](https://github.com/wolfSSL/wolfssl/tree/master/IDE/Renesas/e2studio/DK-S7G2)|
|RA6M3|EK-RA6M3|[IDE/Renesas/e2studio/RA6M3](https://github.com/wolfSSL/wolfssl/tree/master/IDE/Renesas/e2studio/RA6M3)|
|RA6M4|EK-RA6M4|[IDE/Renesas/e2studio/RA6M4](https://github.com/wolfSSL/wolfssl/tree/master/IDE/Renesas/e2studio/RA6M4)|
|RX65N|GR-ROSE|[IDE/Renesas/e2studio/RX65N/GR-ROSE](https://github.com/wolfSSL/wolfssl/tree/master/IDE/Renesas/e2studio/RX65N/GR-ROSE)|
|RX65N|Renesas Starter Kit＋ for RX65N-2MB|[IDE/Renesas/e2studio/RX65N/RSK](https://github.com/wolfSSL/wolfssl/tree/master/IDE/Renesas/e2studio/RX65N/RSK)|
|RX72N|RX72N EnvisionKit|[IDE/Renesas/e2studio/RX72N/EnvisionKit](https://github.com/wolfSSL/wolfssl/tree/master/IDE/Renesas/e2studio/RX72N/EnvisionKit)|
|RZN2L|RSK+RZN2L|[IDE/Renesas/e2studio/RZN2L](https://github.com/wolfSSL/wolfssl/tree/master/IDE/Renesas/e2studio/RZN2L)|

## Updated Technical Resources

Developers looking for current information on wolfSSL support for Renesas platforms can refer to the latest technical white paper:

[Download the latest white paper](https://www.wolfssl.com/docs/wolfssl-white-papers/)

## Additional wolfSSL Products to Explore

|Product|Description|
|:--|:--|
|[wolfIP](https://www.wolfssl.com/products/wolfip/)|Tiny deterministic TCP/IP stack
|[wolfSSH](https://www.wolfssl.com/products/wolfssh/)|Lightweight SSHv2 library
|[wolfMQTT](https://www.wolfssl.com/products/wolfmqtt/)|Lightweight MQTT client
|[wolfBoot](https://www.wolfssl.com/products/wolfboot/)|Portable secure bootloader
|[wolfSentry](https://www.wolfssl.com/products/wolfsentry/)|Embedded IDPS
|[wolfCrypt FIPS 140-2/3](https://www.wolfssl.com/license/fips/)|FIPS 140-2/3 validated crypto
|[wolfCrypt FIPS Ready](https://www.wolfssl.com/license/fips/)|FIPS crypto without a validation
|[wolfTPM](https://www.wolfssl.com/products/wolftpm/)|Portable TPM 2.0 library
|[tiny-curl](https://www.wolfssl.com/products/curl/#panel-34394-3-0-0)|Lightweight version of libcurl

## Further Resources

### wolfSSL Website:
[wolfSSL Renesas Support](https://www.wolfssl.com/docs/renesas/) \
[wolfSSL TSIP Support](https://www.wolfssl.com/docs/wolfssl-renesas-tsip/)

### Renesas Website:

**MCU Resources**\
[Renesas RX MCUs](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rx-32-bit-performance-efficiency-mcus) \
[Renesas RA MCUs](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus) \
[Renesas RZ MCUs](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rz-mpus) \
[Renesas Synergy MCUs](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/renesas-synergy-platform-mcus)

**Driver and Module Resources**\
[Renesas Trusted Secure IP Driver (TSIP)](https://www.renesas.com/us/en/software-tool/trusted-secure-ip-driver) \
[Renesas Secure Cryptographic Module (SCE) HAL Module Guide](https://www.renesas.com/us/en/document/apn/sce-hal-module-guide-application-project)

## Contact wolfSSL

Questions or issues? We're here to help.

Technical support: support@wolfssl.com<br/>
Japanese inquiries: info@wolfssl.jp<br/>
Licensing: licensing@wolfssl.com

