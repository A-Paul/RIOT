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
 * @author  Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 * @}
 */

#include <errno.h>
#include <stdio.h>
#include "thread.h"
#include "lpm.h"

/* One stack for all threads. DON'T TRY THIS AT HOME!! */
char dummy_stack[THREAD_STACKSIZE_DEFAULT];

void *thread_func(void *arg)
{
    return arg;
}

int main(void)
{
    kernel_pid_t thr_id = KERNEL_PID_UNDEF;
    puts("Start spawning\n");
    do {
        thr_id = thread_create(
                     dummy_stack, sizeof(dummy_stack),
                     THREAD_PRIORITY_MAIN - 1, CREATE_SLEEPING | CREATE_STACKTEST,
                     thread_func, NULL, "dummy");
    }
    while (-EOVERFLOW != thr_id);

    if (-EOVERFLOW == thr_id) {
        puts("Thread creation successful aborted\n");
    }
    lpm_set(LPM_OFF);
    return 0;
}
