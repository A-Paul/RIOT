/*
 * Copyright (C) 2015 HAW Hamburg
 *               2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_atmega328p
 * @{
 *
 * @file
 * @brief           CPU specific definitions for internal peripheral handling
 *
 * @author          René Herthel <rene-herthel@outlook.de>
 * @author          Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author          Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 */

#ifndef PERIPH_CPU_H
#define PERIPH_CPU_H

#include <stdint.h>

#include "periph_cpu_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Define a CPU specific GPIO pin generator macro
 */
#define GPIO_PIN(x, y)          ((x << 4) | y)

/**
 * @brief   Available ports on the ATmega328p family
 */
enum {
    PORT_B = 1,       /**< port B */
    PORT_C = 2,       /**< port C */
    PORT_D = 3        /**< port D */
};

/**
 * @brief   PWM channel configuration data structure
 */
typedef struct {
//    gpio_t pin;                 /**< GPIO pin */
//    gpio_mux_t mux;             /**< pin function multiplex value */
    uint8_t chan;               /**< TCC channel to use */
} pwm_conf_chan_t;

/**
 * @brief   PWM device configuration data structure
 */
typedef struct {
//    Tcc *dev;                   /**< TCC device to use */
    pwm_conf_chan_t chan[3];    /**< channel configuration */
} pwm_conf_t;


#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CPU_H */
/** @} */
