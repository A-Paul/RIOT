/*
 * Copyright (C) 2015 Philipp Rosenkranz <philipp.rosenkranz@fu-berlin.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef UNITTESTS_CONSTANTS_H_
#define UNITTESTS_CONSTANTS_H_
#include "embUnit/embUnit.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Some randomly generated but still deterministic values for testing */
#ifndef TEST_STRING4
#define TEST_STRING4 "J&(d"
#endif
#ifndef TEST_STRING8
#define TEST_STRING8 "d)M Fvgh"
#endif
#ifndef TEST_STRING12
#define TEST_STRING12 "50U'HLKC3_ft"
#endif
#ifndef TEST_STRING16
#define TEST_STRING16 "nvxuO*6o3C=a6g7]"
#endif
#ifndef TEST_STRING64
#define TEST_STRING64 "&]x2}L3e>Jj8\"NM}Ngd?)5V5-%:-EZD?V{fda{[JTkN):1}/*5t8Q1>CZu/$s.ML"
#endif
#ifndef TEST_INT8
#define TEST_INT8 (-69)
#endif
#ifndef TEST_INT16
#define TEST_INT16 (-12229)
#endif
#ifndef TEST_INT32
#define TEST_INT32 (-1894529023L)
#endif
#ifndef TEST_INT64
#define TEST_INT64 (-4562349816927799244LL)
#endif
#ifndef TEST_UINT8
#define TEST_UINT8 (95U)
#endif
#ifndef TEST_UINT16
#define TEST_UINT16 (10098U)
#endif
#ifndef TEST_UINT32
#define TEST_UINT32 (2831907245LU)
#endif
#ifndef TEST_UINT64
#define TEST_UINT64 (13500266397057512199LLU)
#endif

#if defined(CPU_CC430) || defined(CPU_MSP430FXYZ) || defined(CPU_ATMEGA2560)
#define TEST_INT TEST_INT16
#else
#define TEST_INT TEST_INT32
#endif


/*
 * ng_ipv6_addr.h
 */

/*
 * ng_ipv6_hdr.h
 */
/* Until refs in ng_ipv6_hdr.c are refactored */
#define DEFAULT_TEST_SRC TEST_ADDR6_1
  
#define TEST_ADDR6_1    { {					    \
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, \
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f \
        } \
    }

/* Until refs in ng_ipv6_hdr.c are refactored */
#define DEFAULT_TEST_DST TEST_ADDR6_2
  
#define TEST_ADDR6_2    { { \
            0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, \
            0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f \
        } \
    }
  
  
/*
 * ng_ipv6_nc.h
 */

/*
 * ng_ipv6_netif.h
 */


#ifdef __cplusplus
}
#endif

#endif /* UNITTESTS_CONSTANTS_H_ */
/** @} */
