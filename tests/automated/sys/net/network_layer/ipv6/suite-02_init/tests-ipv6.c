/*
 * Copyright (C) 2015 Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @{
 *
 * @file
 */
#include <errno.h>
#include <stdint.h>

#include "embUnit/embUnit.h"

#include "kernel_types.h"
#include "byteorder.h"

#include "net/ng_ipv6.h"

#include "unittests-constants.h"
#include "../tests-ipv6.h"


static void set_up(void)
{
  ;
}


static void tear_down(void)
{
    ;
}


/*!
 * Tests recognition for error condition 2.
 * Deferred!
 *
 * \pre: No IPV6 thread has been initialized and MAXTHREADS threads already
 *       exist.
 * \post: No IPV6 thread has been initialized.
 *
 * \todo
 *   - Remove thread from former test.
 *   - Controlled creation of precondition.
 */
static void test_ipv6_init__maxthr(void)
{
    const char *errstr = "!Test insufficient.!";
    kernel_pid_t retval = KERNEL_PID_UNDEF;

    retval = ng_ipv6_init();

    TEST_ASSERT_MESSAGE(-EOVERFLOW == retval,
                        errstr);
}


Test *tests_ipv6_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
                          new_TestFixture(test_ipv6_init__maxthr),
    };

    EMB_UNIT_TESTCALLER(ipv6_tests, set_up, tear_down, fixtures);

    return (Test *)&ipv6_tests;
}

void tests_ipv6(void)
{
    TESTS_RUN(tests_ipv6_tests());
}
/** @} */
