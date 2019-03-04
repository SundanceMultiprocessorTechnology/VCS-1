TGTS  = libFM191.a

all: $(TGTS)

ifneq ($(CROSS_COMPILE),)
  CC  = $(CROSS_COMPILE)gcc
  CXX = $(CROSS_COMPILE)g++
  AR  = $(CROSS_COMPILE)ar
  LD  = $(CROSS_COMPILE)ld
endif

CXXFLAGS += -Wall -std=c++11 -pthread
CPPFLAGS += -I../include 

ifdef DEBUG
  CPPFLAGS += -DDEBUG
  CXXFLAGS += -g -O0
else
  CPPFLAGS += -D_NDEBUG
  CXXFLAGS += -O2
endif

$(TGTS):FM191.o gpio.o spi.o uart.o
	$(AR) rvs ../lib/$@ $^

FM191:FM191.cpp gpio.o spi.o uart.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< 

gpio:gpio.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< 

spi:spi.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< 

uart:uart.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< 

# Cleanup

.PHONY: clean distclean

clean:
	rm -f $(TGTS)
	rm -f *.o
	rm -f ../lib/*.a

distclean: clean
