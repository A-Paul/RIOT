/*
 * Copyright (C) 2015 Hamburg University of Applied Sciences
 *               2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     cpu_atmega_common
 * @{
 *
 * @file
 * @brief       CPU specific low-level PWM driver implementation for the atmega family.
 *
 * Jada jada.
 *
 * @author      Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 * @}
 */

/* Most constants defined in </usr/lib/avr/include/avr/iom328p.h>
 * And RIOT has an special *sigh*:
 * <$RIOTBASE/cpu/atmega_common/include/atmega_regs_common.h>
 */

#include "cpu.h"
#include "assert.h"
#include "periph/pwm.h"
#include "periph/gpio.h"

#define ENABLE_DEBUG    (1)
#include "debug.h"

/* guard file in case no PWM device is defined */
#if defined(PWM_NUMOF) && defined(PWM_CHAN_NUMOF)

static uint16_t pwm_period;
static uint8_t pwm_chan_mask;

uint32_t pwm_init(pwm_t dev, pwm_mode_t mode, uint32_t freq, uint16_t res)
{

    /* return the actual configured frequency */
    return ( CLOCK_CORECLOCK / (1 << prea) / diva / res);
}

uint8_t pwm_channels(pwm_t pwm)
{
    assert(pwm == PWM_DEV(0));
    return (uint8_t)PWM_CHAN_NUMOF;
}

/*
 * Update duty-cycle in channel with value.
 * If value is larger than resolution set by pwm_init() it is cropped.
 */
void pwm_set(pwm_t pwm, uint8_t channel, uint16_t value)
{
    assert((pwm == PWM_DEV(0)) && (channel < PWM_CHAN_NUMOF));

    /* clip and set new value */
}

void pwm_poweron(pwm_t pwm)
{
    assert(pwm == PWM_DEV(0));
}

void pwm_poweroff(pwm_t pwm)
{
    assert(pwm == PWM_DEV(0));
}

#endif /* PWM_NUMOF && PWM_CHAN_NUMOF */
