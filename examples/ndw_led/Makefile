# name of your application
export APPLICATION = ndw_led

# If no BOARD is found in the environment, use this default:
BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../..

QUIET ?=1

FEATURES_REQUIRED = periph_pwm

USEMODULE += xtimer

include $(RIOTBASE)/Makefile.include

