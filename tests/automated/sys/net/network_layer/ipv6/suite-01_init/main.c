/*
 * Copyright (C) 2015 Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     tests-ipv6
 * @{
 *
 * @file
 * @brief       Test application for ng_ipv6 network
 *
 * @author      Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 * @}
 */

#include <stdio.h>

#include "net/ng_nettest.h"
#include "embUnit.h"
#include "msg.h"

#include "../tests-ipv6.h"


#define MAIN_MSG_QUEUE_SIZE (1) /* UDP does not fragment so this should suffice */

int main(void)
{

    /* Preparing minimal runtime environment for modules using netapi. */

//    if (ng_nettest_init() < 0) {
    if (0) {
        puts("Error initializing nettest thread");
        return 1;
    }


    /* This is what ist tested in the test.
     * if (udp_netapi_tests_init() < 0) {
     *   return 1;
     * }
     */

    /* Not needed in init test.
     * msg_init_queue(msg_queue, MAIN_MSG_QUEUE_SIZE);
     */

    TESTS_START();
    TESTS_RUN(ipv6_tests());
    TESTS_END();

    return 0;
}
