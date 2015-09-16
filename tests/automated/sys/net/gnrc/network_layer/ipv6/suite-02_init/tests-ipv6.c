/*
 * Copyright (C) 2015 Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup tests-ipv6
 * @{
 *
 * @file
 */
#include <errno.h>
#include <stdint.h>

#include "embUnit/embUnit.h"

#include "kernel_types.h"
#include "byteorder.h"
#include "thread.h"

#include "net/gnrc/ipv6.h"

#include "../tests-ipv6.h"

/*
 * Function representing threads, spawned in set_up().
 */
static void *thread_func(void *arg)
{
    return arg;
}

static void set_up(void)
{
    /* Guarding the loop count */
    unsigned thr_count = 0;
    /* Shared stack is only sufficient for non running threads */
    char dummy_stack[THREAD_STACKSIZE_DEFAULT];
    kernel_pid_t thr_id = KERNEL_PID_UNDEF;

    puts("Start spawning");
    do {
        thr_id = thread_create(
                     dummy_stack, sizeof(dummy_stack),
                     THREAD_PRIORITY_MAIN - 1,
                     CREATE_SLEEPING | CREATE_STACKTEST,
                     thread_func, NULL, "dummy");
        ++thr_count;
    }
    while ((-EOVERFLOW != thr_id) && (MAXTHREADS >= thr_count));
    puts("Finished spawning");
}

/*
 * Tests for function "gnrc_ipv6_init"
 */

/**
 * Tests ipv6 module thread initialisation.
 * Relying on successfull test of performed initialisation and prevention
 * of second thread creation.
 *
 * @pre: No IPV6 thread has been initialized and MAXTHREADS threads
 *       already exist.
 * @post: Function has returned expected error value, and no IPV6 thread
 *        has been initialized.
 *
 */
static void test_ipv6_init__maxthr(void)
{
    const char *errstr = "Thread creation not prevented.!";
    kernel_pid_t retval = KERNEL_PID_UNDEF;

    retval = gnrc_ipv6_init();

    TEST_ASSERT_MESSAGE(-EOVERFLOW == retval, errstr);
}

Test *ipv6_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_ipv6_init__maxthr),
    };

    EMB_UNIT_TESTCALLER(ipv6_tests, set_up, tear_down, fixtures);

    return (Test *)&ipv6_tests;
}
/** @} */
