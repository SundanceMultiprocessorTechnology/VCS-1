TGTS  = FM191_test

all: $(TGTS)


ifneq ($(CROSS_COMPILE),)
  CC  = $(CROSS_COMPILE)gcc
  CXX = $(CROSS_COMPILE)g++
  AR  = $(CROSS_COMPILE)ar
  LD  = $(CROSS_COMPILE)ld
endif

CXXFLAGS += -Wall -std=c++11 -pthread
CPPFLAGS += -I../../include 

ifdef DEBUG
  CPPFLAGS += -DDEBUG
  CXXFLAGS += -g -O0
else
  CPPFLAGS += -D_NDEBUG
  CXXFLAGS += -O2
endif

LDLIBS += -L../../lib  -ludev -lFM191
LDLIBS_SSL += -L../../lib  

$(TGTS): FM191_test.cpp 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDLIBS)


# Cleanup

.PHONY: clean distclean

clean:
	rm -f $(TGTS)

distclean: clean
