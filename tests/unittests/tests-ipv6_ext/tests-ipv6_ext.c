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

#include "byteorder.h"

/*
#include "net/ng_ipv6.h"
*/
#include "net/ng_netif.h"  /* Generator for kernel_pid_t */
#include "net/ng_pktbuf.h" /* Generator for ng_pktsnip_t */
#include "net/ng_ipv6/ext.h"

#include "unittests-constants.h"
#include "tests-ipv6_ext.h"

const kernel_pid_t pid;

static void set_up(void)
{
    ;
}

/* Deferred:
 * Pre:  ...
 * Post: ...
 * TODO:
 *   - Source for initialized interface.
 *     (kernel_pid_t: take from "tests-netif/tests-netif.c:set_up()")
 *   - Description for (in)valid input values.
 *   - Description of function behaviour, pre- and post conditions.
 */
static void test_ipv6_ext_demux__stub1(void)
{

    /* Needed function arguments */
    kernel_pid_t iface = 0;
    ng_pktsnip_t *pkt = NULL;
    uint8_t nh = 0;

    TEST_ASSERT_MESSAGE(ng_ipv6_ext_demux(*iface, pkt, nh),
                        "!Test insufficient.!");
}

/* Deferred:
 * Pre:  ...
 * Post: ...
 * TODO:
 *   - source for initialized interface.
 *   - Description for (in)valid input values.
 *   - Description of function behaviour, pre- and post conditions.
 */
static void test_ipv6_ext_get_next__stub1(void)
{
    ng_ipv6_ext_t *ext = NULL;
    ng_ipv6_ext_t *res = NULL;

    TEST_ASSERT_MESSAGE(res == ng_ipv6_ext_get_next(ext),
                        "!Test insufficient.!");
}

/* Deferred:
 * Pre:  ...
 * Post: ...
 * TODO:
 *   - source for initialized interface.
 *   - Description for (in)valid input values.
 *   - Description of function behaviour, pre- and post conditions.
 */
static void test_ipv6_ext_build__stub1(void)
{
    /* Needed function arguments */
    /* TODO */
    ng_pktsnip_t *ipv6 = NULL;
    ng_pktsnip_t *next = NULL;
    ng_pktsnip_t  *res = NULL;
    uint8_t nh   = 0;
    size_t  size = 0;

    TEST_ASSERT_MESSAGE(res == ng_ipv6_ext_build(ipv6, next, nh, size),
                        "!Test insufficient.!");
}

Test *tests_ipv6_ext_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_ipv6_ext_demux__stub1),
        new_TestFixture(test_ipv6_ext_get_next__stub1),
        new_TestFixture(test_ipv6_ext_build__stub1)
    };

    EMB_UNIT_TESTCALLER(ipv6_ext_tests, NULL, NULL, fixtures);

    return (Test *)&ipv6_ext_tests;
}

void tests_ipv6_ext(void)
{
    TESTS_RUN(tests_ipv6_ext_tests());
}
/** @} */
