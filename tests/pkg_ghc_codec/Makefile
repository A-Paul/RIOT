include ../Makefile.tests_common

BOARD ?= native

BOARD_INSUFFICIENT_MEMORY := arduino-due arduino-duemilanove arduino-mega2560 \
                   arduino-mkr1000 arduino-mkrzero arduino-uno arduino-zero

BOARD_WHITELIST := airfy-beacon avsextrem \
                   b-l072z-lrwan1 b-l475e-iot01a bluepill cc2538dk ek-lm4f120xl \
                   feather-m0 fox frdm-k22f frdm-k64f ikea-tradfri iotlab-a8-m3 \
                   iotlab-m3 limifrog-v1 maple-mini msb-430 msb-430h msba2 msbiot \
                   mulle nrf52840dk nrf52dk nrf6310 nucleo-f207zg nucleo-f303ze \
                   nucleo-f412zg nucleo-f413zh nucleo-f429zi nucleo-f446ze \
                   nucleo-f031k6 nucleo-f042k6 nucleo-f303k8 nucleo-l031k6 \
                   nucleo-l432kc nucleo-f072rb nucleo-f091rc nucleo-f103rb nucleo-f302r8 \
                   nucleo-f303re nucleo-f334r8 nucleo-f401re nucleo-f410rb nucleo-f411re \
                   nucleo-f446re nucleo-l053r8 nucleo-l073rz nucleo-l152re nucleo-l476rg \
                   nz32-sc151 openmote-cc2538 pba-d-01-kw2x remote-pa remote-reva \
                   remote-revb samd21-xpro saml21-xpro samr21-xpro sltb001a \
                   sodaq-autonomo sodaq-explorer spark-core stm32f0discovery \
                   stm32f3discovery stm32f4discovery telosb udoo waspmote-pro \
                   wsn430-v1_3b wsn430-v1_4 yunjia-nrf51822 z1 native

GHC_ENCODER_IMPL := naive
export GHC_ENCODER_IMPL

USEPKG += ghc_codec

include $(RIOTBASE)/Makefile.include
