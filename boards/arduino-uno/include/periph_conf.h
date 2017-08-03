/*
 * Copyright (C) 2014 Freie Universität Berlin, Hinnerk van Bruinehsen
 *               2016 Laurent Navet <laurent.navet@gmail.com>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_arduino-uno
 * @{
 *
 * @file
 * @brief       Configuration of MCU periphery for Arduino UNO boards
 *
 * @author      Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include "cpu.h"
#include "periph_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name    Clock configuration
 * @{
 */
#define CLOCK_CORECLOCK     (16000000L)
/** @} */

/**
 * @name    Timer configuration
 *
 * The timer driver only supports the 16-bit timer (Timer1)
 * so this is the only one we can use here.
 * @{
 */
#define TIMER_NUMOF         (2U)

#define TIMER_0             MEGA_TIMER1
#define TIMER_0_MASK        &TIMSK1
#define TIMER_0_FLAG        &TIFR1
#define TIMER_0_ISRA        TIMER1_COMPA_vect
#define TIMER_0_ISRB        TIMER1_COMPB_vect
/** @} */

/**
 * @name    UART configuration
 *
 * The UART devices have fixed pin mappings, so all we need to do, is to specify
 * which devices we would like to use and their corresponding RX interrupts. See
 * the reference manual for the fixed pin mapping.
 *
 * @{
 */
#define UART_NUMOF          (1U)

#define UART_0              MEGA_UART0
#define UART_0_ISR          USART_RX_vect
/** @} */

/**
 * @name    SPI configuration
 *
 * The fixed pins for arduino uno and duemilanove are:
 * MOSI - PB3 (Arduino pin 11)
 * MISO - PB4 (Arduino pin 12)
 * SCK  - PB5 (Arduino pin 13)
 * SS   - PB2 (Arduino pin 10) -> this pin is configured as output, but not used
 *
 * @{
 */
#define SPI_NUMOF           1           /* set to 0 to disable SPI */
/** @} */

/* Taken and adapted from arduino-zero */
/**
 * @name PWM configuration
 * @{
 */
#define PWM_0_EN            1
#define PWM_1_EN            0
#define PWM_2_EN            0
#define PWM_MAX_CHANNELS    2
/* for compatibility with test application */ /*???*/
#define PWM_0_CHANNELS      PWM_MAX_CHANNELS
#define PWM_1_CHANNELS      PWM_MAX_CHANNELS
#define PWM_1_CHANNELS      PWM_MAX_CHANNELS

/* PWM device configuration */
static const pwm_conf_t pwm_config[] = {
#if PWM_0_EN
  {},
#endif
#if PWM_1_EN
  {},
#endif
#if PWM_2_EN
  {},
#endif
};

/* number of devices that are actually defined */
#define PWM_NUMOF           (1U)
/** @} */

#define MEGA_PRR            PRR         /* Power Reduction Register is PRR */
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
