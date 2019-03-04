# Makefile for the paho-mqttpp (C++) sample applications

ifdef DEVELOP
  PAHO_C_DIR ?= /cygdrive/c/Users/Pedro Machado/eclipse-workspace/emc2-vs2/paho.mqtt.c
  PAHO_C_LIB_DIR ?= $(PAHO_C_DIR)/build/output
  PAHO_C_INC_DIR ?= $(PAHO_C_DIR)/src
else
  PAHO_C_LIB_DIR ?= /usr/local/lib
  PAHO_C_INC_DIR ?= /usr/local/include
endif

TGTS  = emc2-vs1

all: $(TGTS)


ifneq ($(CROSS_COMPILE),)
  CC  = $(CROSS_COMPILE)gcc
  CXX = $(CROSS_COMPILE)g++
  AR  = $(CROSS_COMPILE)ar
  LD  = $(CROSS_COMPILE)ld
endif

CXXFLAGS += -Wall -std=c++11 -pthread
CPPFLAGS += -I.. -I$(PAHO_C_INC_DIR)

ifdef DEBUG
  CPPFLAGS += -DDEBUG
  CXXFLAGS += -g -O0
else
  CPPFLAGS += -D_NDEBUG
  CXXFLAGS += -O2
endif

LDLIBS += -L../../lib -L$(PAHO_C_LIB_DIR) -lpaho-mqttpp3 -lpaho-mqtt3a
LDLIBS_SSL += -L../../lib -L$(PAHO_C_LIB_DIR) -lpaho-mqttpp3 -lpaho-mqtt3as 

SOURCES:= FM191.cpp uart.cpp gpio.cpp spi.cpp pwm.cpp
HEADERS:= FM191.hpp uart.hpp gpio.hpp spi.hpp pwm.hpp

emc2-vs1: emc2-vs1.cpp FM191.cpp uart.cpp gpio.cpp spi.cpp pwm.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SOURCES) $(HEADERS) $< $(LDLIBS)


# Cleanup

.PHONY: clean distclean

clean:
	rm -f $(TGTS)

distclean: clean
