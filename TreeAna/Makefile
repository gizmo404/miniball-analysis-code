# Makefile for g_clx analysis
.PHONY: clean all

ROOTCFLAGS	:= $(shell root-config --cflags)
ROOTLIBS    := $(shell root-config --libs)

CC       := $(shell root-config --cc)
CPP      := $(shell root-config --cxx)
CFLAGS   := -pedantic -Wall -Wno-long-long -g -O3 $(ROOTCFLAGS) -fPIC

all: g_clx
 
g_clx: g_clx.cc hists.hh ../mbevts/mbevts.o doppler.o MBGeometry.o SpedeGeometry.o g_clx_dict.o
	$(CPP) $(CFLAGS) $(ROOTLIBS) g_clx.cc ../mbevts/mbevts.o doppler.o MBGeometry.o SpedeGeometry.o -o $@

../mbevts/mbevts.o: ../mbevts/mbevts.cc ../mbevts/mbevts.hh
	$(CC) $(CFLAGS) -c $< -o $@

doppler.o: doppler.cc doppler.hh
	$(CC) $(CFLAGS) -c $< -o $@

MBGeometry.o: MBGeometry.cc MBGeometry.hh
	$(CC) $(CFLAGS) -c $< -o $@

SpedeGeometry.o: SpedeGeometry.cc SpedeGeometry.hh
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ../mbevts/*.o *.o *_dict.cc *_dict.h

# Root stuff
DEPENDENCIES = ../mbevts/mbevts.hh doppler.hh MBGeometry.hh SpedeGeometry.hh

g_clx_dict.o: g_clx_dict.cc
	 $(CPP) -fPIC $(CFLAGS) $(INCLUDES) -c $<

g_clx_dict.cc: $(DEPENDENCIES)
	 rootcling -f $@ -c -I./ $(DEPENDENCIES)

