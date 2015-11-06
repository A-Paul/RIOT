/*
 * Copyright (C) 2014-2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_arduino-due
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the Arduino Due board
 *
 * @author      Hauke Petersen  <hauke.petersen@fu-berlin.de>
 * @author      Peter Kietzmann <peter.kietzmann@haw-hamburg.de>
 * @author      Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 */

#ifndef PERIPH_CONF_H_
#define PERIPH_CONF_H_

#include "periph_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Timer peripheral configuration
 * @{
 */
#define TIMER_NUMOF         (3U)
#define TIMER_0_EN          1
#define TIMER_1_EN          1
#define TIMER_2_EN          1

/* Timer 0 configuration */
#define TIMER_0_DEV         TC0
#define TIMER_0_CHANNELS    6
#define TIMER_0_MAX_VALUE   (0xffffffff)
#define TIMER_0_ISR1        isr_tc0
#define TIMER_0_ISR2        isr_tc1

/* Timer 1 configuration */
#define TIMER_1_DEV         TC1
#define TIMER_1_CHANNELS    6
#define TIMER_1_MAX_VALUE   (0xffffffff)
#define TIMER_1_ISR1        isr_tc3
#define TIMER_1_ISR2        isr_tc4

/* Timer 2 configuration */
#define TIMER_2_DEV         TC2
#define TIMER_2_CHANNELS    6
#define TIMER_2_MAX_VALUE   (0xffffffff)
#define TIMER_2_ISR1        isr_tc6
#define TIMER_2_ISR2        isr_tc7
/** @} */

/**
 * @name UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    /* device, rx port, tx port, rx pin, tx pin, mux, PMC bit, IRGn line */
    {(Uart *)UART,   PIOA, PIOA,  8,  9, GPIO_MUX_A, ID_UART,   UART_IRQn},
    {(Uart *)USART0, PIOA, PIOA, 10, 11, GPIO_MUX_A, ID_USART0, USART0_IRQn},
    {(Uart *)USART1, PIOA, PIOA, 12, 13, GPIO_MUX_A, ID_USART1, USART1_IRQn},
    {(Uart *)USART3, PIOD, PIOD,  4,  5, GPIO_MUX_B, ID_USART3, USART3_IRQn}
};

/* define interrupt vectors */
#define UART_0_ISR          isr_uart
#define UART_1_ISR          isr_usart0
#define UART_2_ISR          isr_usart1
#define UART_3_ISR          isr_usart3

#define UART_NUMOF          (sizeof(uart_config) / sizeof(uart_config[0]))
/** @} */

/**
 * @name Random Number Generator configuration
 * @{
 */
#define RANDOM_NUMOF        (1U)
/** @} */

/**
* @name SPI configuration
* @{
*/
#define SPI_NUMOF           (1U)
#define SPI_0_EN            1

/* SPI 0 device config */
#define SPI_0_DEV           SPI0
#define SPI_0_CLKEN()       (PMC->PMC_PCER0 |= (1 << ID_SPI0));
#define SPI_0_CLKDIS()      (PMC->PMC_PCER0 &= ~(1 << ID_SPI0));
#define SPI_0_IRQ           SPI0_IRQn
#define SPI_0_IRQ_HANDLER   isr_spi0
#define SPI_0_IRQ_PRIO      1

/* SPI 0 pin configuration */
#define SPI_0_MISO_PIN      PIO_PA25A_SPI0_MISO
#define SPI_0_MOSI_PIN      PIO_PA26A_SPI0_MOSI
#define SPI_0_SCK_PIN       PIO_PA27A_SPI0_SPCK
#define SPI_0_MISO_PORT     PIOA
#define SPI_0_MOSI_PORT     PIOA
#define SPI_0_SCK_PORT      PIOA
#define SPI_0_MISO_PORT_CLKEN()  (PMC->PMC_PCER0 |= (1 << ID_PIOA));
#define SPI_0_MOSI_PORT_CLKEN()  (PMC->PMC_PCER0 |= (1 << ID_PIOA));
#define SPI_0_SCK_PORT_CLKEN()   (PMC->PMC_PCER0 |= (1 << ID_PIOA));
/** @} */

/**
 * @name GPIO configuration
 * @{
 */
#define GPIO_0_EN           1
#define GPIO_1_EN           1
#define GPIO_2_EN           1
#define GPIO_3_EN           1
#define GPIO_4_EN           1
#define GPIO_5_EN           1
#define GPIO_6_EN           1
#define GPIO_7_EN           1
#define GPIO_8_EN           1
#define GPIO_9_EN           1
#define GPIO_10_EN          1
#define GPIO_11_EN          1
#define GPIO_12_EN          1
#define GPIO_13_EN          1
#define GPIO_14_EN          1
#define GPIO_15_EN          1
#define GPIO_16_EN          1
#define GPIO_17_EN          1
#define GPIO_18_EN          1
#define GPIO_19_EN          1
#define GPIO_20_EN          1
#define GPIO_21_EN          1
#define GPIO_22_EN          1
#define GPIO_23_EN          1
#define GPIO_24_EN          1
#define GPIO_25_EN          1
#define GPIO_26_EN          1
#define GPIO_27_EN          1
#define GPIO_28_EN          1
#define GPIO_29_EN          1
#define GPIO_30_EN          1
#define GPIO_31_EN          1

/* interrupt priority */
#define GPIO_IRQ_PRIO       1

/* GPIO channel 0 config */
#define GPIO_0_DEV          PIOA
#define GPIO_0_PIN          PIO_PA14
#define GPIO_0_IRQ          PIOA_IRQn
#define GPIO_A14_MAP        0
/* GPIO channel 1 config */
#define GPIO_1_DEV          PIOD
#define GPIO_1_PIN          PIO_PD0
#define GPIO_1_IRQ          PIOD_IRQn
#define GPIO_D0_MAP         1
/* GPIO channel 2 config */
#define GPIO_2_DEV          PIOD
#define GPIO_2_PIN          PIO_PD2
#define GPIO_2_IRQ          PIOD_IRQn
#define GPIO_D2_MAP         2
/* GPIO channel 3 config */
#define GPIO_3_DEV          PIOD
#define GPIO_3_PIN          PIO_PD6
#define GPIO_3_IRQ          PIOD_IRQn
#define GPIO_D6_MAP         3
/* GPIO channel 4 config */
#define GPIO_4_DEV          PIOA
#define GPIO_4_PIN          PIO_PA7
#define GPIO_4_IRQ          PIOA_IRQn
#define GPIO_A7_MAP         4
/* GPIO channel 5 config */
#define GPIO_5_DEV          PIOC
#define GPIO_5_PIN          PIO_PC1
#define GPIO_5_IRQ          PIOC_IRQn
#define GPIO_C1_MAP         5
/* GPIO channel 6 config */
#define GPIO_6_DEV          PIOC
#define GPIO_6_PIN          PIO_PC3
#define GPIO_6_IRQ          PIOC_IRQn
#define GPIO_C3_MAP         6
/* GPIO channel 7 config */
#define GPIO_7_DEV          PIOC
#define GPIO_7_PIN          PIO_PC5
#define GPIO_7_IRQ          PIOC_IRQn
#define GPIO_C5_MAP         7
/* GPIO channel 8 config */
#define GPIO_8_DEV          PIOC
#define GPIO_8_PIN          PIO_PC7
#define GPIO_8_IRQ          PIOC_IRQn
#define GPIO_C7_MAP         8
/* GPIO channel 9 config */
#define GPIO_9_DEV          PIOC
#define GPIO_9_PIN          PIO_PC9
#define GPIO_9_IRQ          PIOC_IRQn
#define GPIO_C9_MAP         9
/* GPIO channel 10 config */
#define GPIO_10_DEV         PIOA
#define GPIO_10_PIN         PIO_PA20
#define GPIO_10_IRQ         PIOA_IRQn
#define GPIO_A20_MAP        10
/* GPIO channel 11 config */
#define GPIO_11_DEV         PIOC
#define GPIO_11_PIN         PIO_PC18
#define GPIO_11_IRQ         PIOC_IRQn
#define GPIO_C18_MAP        11
/* GPIO channel 12 config */
#define GPIO_12_DEV         PIOC
#define GPIO_12_PIN         PIO_PC16
#define GPIO_12_IRQ         PIOC_IRQn
#define GPIO_C16_MAP        12
/* GPIO channel 13 config */
#define GPIO_13_DEV         PIOC
#define GPIO_13_PIN         PIO_PC14
#define GPIO_13_IRQ         PIOC_IRQn
#define GPIO_C14_MAP        13
/* GPIO channel 14 config */
#define GPIO_14_DEV         PIOC
#define GPIO_14_PIN         PIO_PC12
#define GPIO_14_IRQ         PIOC_IRQn
#define GPIO_C12_MAP        14
/* GPIO channel 15 config */
#define GPIO_15_DEV         PIOB
#define GPIO_15_PIN         PIO_PB14
#define GPIO_15_IRQ         PIOB_IRQn
#define GPIO_B14_MAP        15
/* GPIO channel 16 config */
#define GPIO_16_DEV         PIOB
#define GPIO_16_PIN         PIO_PB26
#define GPIO_16_IRQ         PIOB_IRQn
#define GPIO_B26_MAP        16
/* GPIO channel 17 config */
#define GPIO_17_DEV         PIOA
#define GPIO_17_PIN         PIO_PA15
#define GPIO_17_IRQ         PIOA_IRQn
#define GPIO_A15_MAP        17
/* GPIO channel 18 config */
#define GPIO_18_DEV         PIOD
#define GPIO_18_PIN         PIO_PD1
#define GPIO_18_IRQ         PIOD_IRQn
#define GPIO_D1_MAP         18
/* GPIO channel 19 config */
#define GPIO_19_DEV         PIOD
#define GPIO_19_PIN         PIO_PD3
#define GPIO_19_IRQ         PIOD_IRQn
#define GPIO_D3_MAP         19
/* GPIO channel 20 config */
#define GPIO_20_DEV         PIOD
#define GPIO_20_PIN         PIO_PD9
#define GPIO_20_IRQ         PIOD_IRQn
#define GPIO_D9_MAP         20
/* GPIO channel 21 config */
#define GPIO_21_DEV         PIOD
#define GPIO_21_PIN         PIO_PD10
#define GPIO_21_IRQ         PIOD_IRQn
#define GPIO_D10_MAP        21
/* GPIO channel 22 config */
#define GPIO_22_DEV         PIOC
#define GPIO_22_PIN         PIO_PC2
#define GPIO_22_IRQ         PIOC_IRQn
#define GPIO_C2_MAP         22
/* GPIO channel 23 config */
#define GPIO_23_DEV         PIOC
#define GPIO_23_PIN         PIO_PC4
#define GPIO_23_IRQ         PIOC_IRQn
#define GPIO_C4_MAP         23
/* GPIO channel 24 config */
#define GPIO_24_DEV         PIOC
#define GPIO_24_PIN         PIO_PC6
#define GPIO_24_IRQ         PIOC_IRQn
#define GPIO_C6_MAP         24
/* GPIO channel 25 config */
#define GPIO_25_DEV         PIOC
#define GPIO_25_PIN         PIO_PC8
#define GPIO_25_IRQ         PIOC_IRQn
#define GPIO_C8_MAP         25
/* GPIO channel 26 config */
#define GPIO_26_DEV         PIOA
#define GPIO_26_PIN         PIO_PA19
#define GPIO_26_IRQ         PIOA_IRQn
#define GPIO_A19_MAP        26
/* GPIO channel 27 config */
#define GPIO_27_DEV         PIOC
#define GPIO_27_PIN         PIO_PC19
#define GPIO_27_IRQ         PIOC_IRQn
#define GPIO_C19_MAP        27
/* GPIO channel 28 config */
#define GPIO_28_DEV         PIOC
#define GPIO_28_PIN         PIO_PC17
#define GPIO_28_IRQ         PIOC_IRQn
#define GPIO_C17_MAP        28
/* GPIO channel 29 config */
#define GPIO_29_DEV         PIOC
#define GPIO_29_PIN         PIO_PC15
#define GPIO_29_IRQ         PIOC_IRQn
#define GPIO_C15_MAP        29
/* GPIO channel 30 config */
#define GPIO_30_DEV         PIOC
#define GPIO_30_PIN         PIO_PC13
#define GPIO_30_IRQ         PIOC_IRQn
#define GPIO_C13_MAP        30
/* GPIO channel 31 config */
#define GPIO_31_DEV         PIOB
#define GPIO_31_PIN         PIO_PB21
#define GPIO_31_IRQ         PIOB_IRQn
#define GPIO_B21_MAP        31
/** @} */

/**
 * @name PWM configuration
 * @{
 */
#define PWM_NUMOF           (1U)
#define PWM_0_EN            (1)
#define PWM_MAX_VALUE       (0xffff)
#define PWM_MAX_CHANNELS    (4U)

/* PWM_0 configuration      Modified for NdW-2015 */
#define PWM_0_DEV           PWM
#define PWM_0_PID           ID_PWM
#define PWM_0_CHANNELS      (3U)
#define PWM_0_DEV_CH0       (&(PWM_0_DEV->PWM_CH_NUM[5]))
#define PWM_0_ENA_CH0       PWM_ENA_CHID5
#define PWM_0_PORT_CH0      PIOC
#define PWM_0_PIN_CH0       PIO_PC22B_PWML5
#define PWM_0_DEV_CH1       (&(PWM_0_DEV->PWM_CH_NUM[6]))
#define PWM_0_ENA_CH1       PWM_ENA_CHID6
#define PWM_0_PORT_CH1      PIOC
#define PWM_0_PIN_CH1       PIO_PC23B_PWML6
#define PWM_0_DEV_CH2       (&(PWM_0_DEV->PWM_CH_NUM[7]))
#define PWM_0_ENA_CH2       PWM_ENA_CHID7
#define PWM_0_PORT_CH2      PIOC
#define PWM_0_PIN_CH2       PIO_PC24B_PWML7
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H_ */
/** @} */
