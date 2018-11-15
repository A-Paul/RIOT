/*
 * Copyright (C) 2015-2018 Hamburg University of Applied Sciences
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */
/**
 * @file
 * @brief       Check if the ghc tests build.
 *
 * @author      Andreas "Paul" Pauli <andreas.pauli@haw-hamburg.de>
 *
 */

#include <stdio.h>

#include <ghc.h>
#include <ghc_codec.h>

int main(void)
{
    puts("SUCCESS: GHC tests compiled!");
    return 0;
}
