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

#include "periph/i2c.h"
#include "mma8652.h"

#define WAIT        (400000)

#define DEV         PWM_0
#define CHANNELS    PWM_0_CHANNELS
#define MODE        PWM_LEFT

#define FREQU       (400U)
#define STEPS       (0xffff)

int main(void)
{
    //int ratio = 0;
    int res   = 0;
    int state = 0;
    int step  = STEP;


    mma8652_t accmtr_dev;
    i2c_t i2c_dev = 0;

    int16_t acc_x = 0;
    int16_t acc_y = 0;
    int16_t acc_z = 0;
    uint8_t acc_s = 0;


    puts("\nRIOT PWM test");
    puts("Connect an LED or scope to PWM pins to see something");

    res = pwm_init(DEV, MODE, FREQU, STEPS);
    if (res < 0) {
        puts("Errors while initializing PWM");
        return 1;
    }

    mma8652_init(&accmtr_dev, i2c_dev,
                 MMA8652_I2C_ADDRESS,
                 MMA8652_DATARATE_1HZ25,
                 MMA8652_FS_RANGE_4G);

    if (0 == mma8652_test(&accmtr_dev) &&
        0 == mma8652_set_active(&accmtr_dev)) {
        puts("Accelerometer O.K.");
    }

    puts("PWM initialized.");
    printf("requested: %d Hz, got %d Hz\n", FREQU, res);

    while (1) {

        if (0 < mma8652_is_ready(&accmtr_dev)) {
            puts("Ready");
        }
        mma8652_read(&accmtr_dev, &acc_x, &acc_y, &acc_z, &acc_s);
        printf("XYZ:%04d,%04d,%04d,%03d\n", acc_x, acc_y, acc_z, acc_s);

        pwm_set(DEV, 0, (acc_x << 3) + 0x7fff);
        pwm_set(DEV, 0, (acc_y << 3) + 0x7fff);
        pwm_set(DEV, 0, (acc_z << 3) + 0x7fff);

        xtimer_usleep(WAIT);
    }

    return 0;
}
