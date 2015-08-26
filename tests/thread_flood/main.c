/*
 * Copyright (C) 2015 Hamburg University of Applied Sciences
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup tests
 * @{
 *
 * @file
 * @brief Thread flooding test.
 *
 * Spawns sleeping threads till the scheduler's capacity is exhausted.
 *
 * Based on 'thread_base'  Oliver Hahm <oliver.hahm@inria.fr>
 *
 * @author  Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 * @}
 */

#include <errno.h>
#include <stdio.h>
#include "thread.h"
#include "lpm.h"

char dummy_stack[THREAD_STACKSIZE_DEFAULT];

void *thread_func(void *arg)
{
    return arg;
}

int main(void)
{
    kernel_pid_t thr_id = KERNEL_PID_UNDEF;
    puts("Start spawning\n");
    while( -EOVERFLOW != thr_id) {
      thr_id = thread_create(
            dummy_stack, sizeof(dummy_stack),
            THREAD_PRIORITY_MAIN - 1, CREATE_SLEEPING | CREATE_STACKTEST,
            thread_func, NULL, "dummy");
    }
    if ( -EOVERFLOW == thr_id ) {
      puts("Thread creation successful aborted\n");
    }
    lpm_set(LPM_OFF);
    return 0;
}
