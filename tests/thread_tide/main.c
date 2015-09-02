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
 * And remove them afterwards
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
char dummy_stack[MAXTHREADS][THREAD_STACKSIZE_DEFAULT];
kernel_pid_t threads[MAXTHREADS] = { KERNEL_PID_UNDEF };

void *thread_func(void *arg)
{
    puts(".\n");
    return arg;
}

int main(void)
{
    int count = 0;
    kernel_pid_t thr_id = KERNEL_PID_UNDEF;
    puts("Start spawning\n");
    do {
        threads[count] = thread_create(
                             dummy_stack[count], sizeof(*dummy_stack),
                             THREAD_PRIORITY_MAIN - 1, CREATE_SLEEPING | CREATE_STACKTEST,
                             thread_func, NULL, "dummy");
        thr_id = threads[count];
        ++count;
    }
    while (-EOVERFLOW != thr_id);

    if (-EOVERFLOW == thr_id) {
        puts("Thread creation successful aborted\n");
    }

    printf("Threads created: %d\n", count);
    count = 0;

    while (-EOVERFLOW != threads[count]) {
        thread_wakeup(threads[count]);
        ++count;
    }


    if (0 == count) {
        puts("Created threads successful removed\n");
    }
    lpm_set(LPM_OFF);
    return 0;
}
