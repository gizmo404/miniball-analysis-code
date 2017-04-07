# Makefile for g_clx analysis
.PHONY: clean all

ROOTCFLAGS	:= $(shell root-config --cflags)
ROOTLIBS    := $(shell root-config --libs)

MBEVTS_DIR  = ../mbevts

CC       := $(shell root-config --cc)
CPP      := $(shell root-config --cxx)
CFLAGS   := -pedantic -Wall -g -O3 $(ROOTCFLAGS) -fPIC -Wno-unused-variable

all: g_clx

OBJECTS = $(MBEVTS_DIR)/mbevts.o doppler.o hists.o MBGeometry.o SpedeGeometry.o g_clx_dict.o
 
g_clx: g_clx.cc $(OBJECTS)
	$(CPP) $(CFLAGS) $(ROOTLIBS) $< $(OBJECTS) -o $@

$(MBEVTS_DIR)/mbevts.o: $(MBEVTS_DIR)/mbevts.cc $(MBEVTS_DIR)/mbevts.hh
	$(CC) $(CFLAGS) -c $< -o $@

doppler.o: doppler.cc doppler.hh
	$(CC) $(CFLAGS) -c $< -o $@

hists.o: hists.cc hists.hh
	$(CC) $(CFLAGS) -c $< -o $@

MBGeometry.o: MBGeometry.cc MBGeometry.hh
	$(CC) $(CFLAGS) -c $< -o $@

SpedeGeometry.o: SpedeGeometry.cc SpedeGeometry.hh
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MBEVTS_DIR)/*.o *.o
	rm -f g_clx_dict.cc g_clx_dict_rdict.pcm

# Root stuff
DEPENDENCIES = $(MBEVTS_DIR)/mbevts.hh doppler.hh hists.hh MBGeometry.hh SpedeGeometry.hh RootLinkDef.h

g_clx_dict.o: g_clx_dict.cc
	 $(CPP) -fPIC $(CFLAGS) $(INCLUDES) -c $<

g_clx_dict.cc: $(DEPENDENCIES)
	 rootcling -f $@ -c -I./ $(DEPENDENCIES)

