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

#include "net/ng_ipv6.h"

#include "../tests-ipv6.h"


static void set_up(void)
{
    ;
}


static void tear_down(void)
{
    ;
}


/*
 * Tests for function "ng_ipv6_init"
 */

/**
 * Deferred!
 * @pre: ...
 * @post: ....
 * @todo:
 *   - Provide specification of function behaviour, pre- and postconditions.
 *   - Provide (in)valid values for function parameters.
 */
static void test_ipv6_demux__stub1(void)
{
    const char *errstr = "!Test insufficient.!";
    kernel_pid_t iface = KERNEL_PID_UNDEF;
    ng_pktsnip_t  *pkt = NULL;
    uint8_t         nh = 0;

    iface = ng_ipv6_init();
    ng_ipv6_demux(iface, pkt, nh);

    TEST_ASSERT_MESSAGE(NULL == pkt,
                        errstr);
}


Test *ipv6_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_ipv6_demux__stub1)
    };

    EMB_UNIT_TESTCALLER(ipv6_tests, set_up, tear_down, fixtures);

    return (Test *)&ipv6_tests;
}
/** @} */
