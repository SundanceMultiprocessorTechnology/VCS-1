
TGTS  = hdmi_out

all: $(TGTS)


ifneq ($(CROSS_COMPILE),)
  CC  = $(CROSS_COMPILE)gcc
  CXX = $(CROSS_COMPILE)g++
  AR  = $(CROSS_COMPILE)ar
  LD  = $(CROSS_COMPILE)ld
endif

CXXFLAGS += -Wall -std=c++11 -pthread
CPPFLAGS += -I.. -I./xilinx

ifdef DEBUG
  CPPFLAGS += -DDEBUG
  CXXFLAGS += -g -O0
else
  CPPFLAGS += -D_NDEBUG
  CXXFLAGS += -O2
endif

LDLIBS += -L../../lib 
LDLIBS_SSL += -L../../lib  

SOURCES:= 
HEADERS:= 

hdmi_out: hdmi_out.cpp 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SOURCES) $(HEADERS) $< $(LDLIBS)


# Cleanup

.PHONY: clean distclean

clean:
	rm -f $(TGTS)

distclean: clean
