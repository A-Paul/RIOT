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
    int thr_count = 0;
    int thr_remain = 0;
    kernel_pid_t thr_id = KERNEL_PID_UNDEF;

    /* pexpect waypoint */
    puts("Start spawning\n");

    do {
        threads[thr_count] = thread_create(
                             dummy_stack[thr_count], sizeof(*dummy_stack),
                             THREAD_PRIORITY_MAIN - 1, CREATE_SLEEPING | CREATE_STACKTEST,
                             thread_func, NULL, "dummy");
        thr_id = threads[thr_count];
        ++thr_count;
    }
    while (-EOVERFLOW != thr_id);

    /* pexpect waypoint */
    if (-EOVERFLOW == thr_id) {
        puts("Thread creation successful aborted\n");
	thr_remain = thr_count - 1;
    }

    printf("Threads created: %d\n", thr_count);
    thr_count = 0;

    while (-EOVERFLOW != threads[thr_count]) {
        thread_wakeup(threads[thr_count]);
        ++thr_count;
	--thr_remain;
    }


    /* pexpect waypoint */
    if (0 == thr_remain) {
        puts("Created threads successful removed\n");
    }
    lpm_set(LPM_OFF);
    return 0;
}
