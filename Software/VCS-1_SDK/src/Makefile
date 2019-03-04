#
# ==================================================================
# file Makefile						       
# author Pedro Machado <pedro.m@sundance.com>			               
# version 0.1								
# copyright 2018, Sundance Multiprocessor Technology Ltd. (c) GPLv3                 
# EMC2-Zxxx-FM191 Makefile               
# ==================================================================
#
PAHO_C_LIB_DIR ?= /usr/local/lib
PAHO_C_INC_DIR ?= /usr/local/include

TGTS  = emc2-fm191

all: $(TGTS)


ifneq ($(CROSS_COMPILE),)
  CC  = $(CROSS_COMPILE)gcc
  CXX = $(CROSS_COMPILE)g++
  AR  = $(CROSS_COMPILE)ar
  LD  = $(CROSS_COMPILE)ld
endif

CXXFLAGS += -Wall -std=c++11
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

SOURCES:= FM191.cpp
HEADERS:= FM191.hpp

emc2-fm191: emc2-fm191.cpp
	$(clean)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SOURCES) $(HEADERS) $< $(LDLIBS)


# Cleanup

.PHONY: clean distclean

clean:
	rm -f $(TGTS)

distclean: clean
