/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup tests
 * @{
 *
 * @file
 * @brief       Test for low-level PWM drivers
 *
 * @author      Andreas 'Paul' Pauli <andreas.pauli@haw-hamburg.de>
 *
 * @}
 */

#include <stdio.h>

#include "cpu.h"
#include "board.h"
#include "xtimer.h"
#include "periph/pwm.h"

#define WAIT        (400000)

#define DEV         PWM_0
#define CHANNELS    PWM_0_CHANNELS
#define MODE        PWM_LEFT

#define FREQU       (400U)
#define STEPS       (3072U)
#define STEP        (STEPS/16)
#define OFFS        (STEPS/3)

int main(void)
{
    int ratio = 0;
    int res   = 0;
    int state = 0;
    int step  = STEP;


    mma8652_t accmtr_dev;
    i2c_t i2c_dev = 0;

    puts("\nRIOT PWM test");
    puts("Connect an LED or scope to PWM pins to see something");

    res = pwm_init(DEV, MODE, FREQU, STEPS);
    if (res < 0) {
        puts("Errors while initializing PWM");
        return 1;
    }

    puts("PWM initialized.");
    printf("requested: %d Hz, got %d Hz\n", FREQU, res);

    while (1) {
        printf("{R,G,B}:");
        for (int i = 0; i < CHANNELS; i++) {
            ratio = (state + i * OFFS) % STEPS;
            pwm_set(DEV, i, ratio);
            printf("|0x%04x", ratio);
        }
        puts("|");

        state += step;
        if (state < STEP || state > (STEPS - STEP)) {
            step  = -step;
            state += step;
        }

        xtimer_usleep(WAIT);
    }

    return 0;
}
