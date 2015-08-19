APPLICATION = ipv6
#include ../Makefile.tests_common
BOARD ?= native
RIOTBASE ?= $(CURDIR)/../../../../../../..
QUIET ?= 1

USEMODULE += embunit

USEMODULE += ng_ipv6

USEMODULE += ng_icmpv6
USEMODULE += ng_ndp

USEMODULE += ng_nettest

DISABLE_MODULE = auto_init

CFLAGS += -DTEST_SUITES

#include $(RIOTBASE)/Makefile.base
include $(RIOTBASE)/Makefile.include
