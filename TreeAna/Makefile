# Makefile for g_clx analysis
.PHONY: clean all

ROOTCFLAGS	:= $(shell root-config --cflags)
ROOTLIBS    := $(shell root-config --libs)

LIB_DIR     = ../lib
MBEVTS_DIR  = ../mbevts

LIBS        := $(ROOTLIBS) -L$(LIB_DIR)

AR          := ar
CC          := $(shell root-config --cc)
CPP         := $(shell root-config --cxx)
CFLAGS      := -pedantic -Wall -g -O3 $(ROOTCFLAGS) -fPIC -Wno-unused-variable

INCLUDES  = -I$(MBEVTS_DIR) -I./

all: TreeAna

OBJECTS = g_clx.o \
          $(MBEVTS_DIR)/mbevts.o \
          doppler.o \
          hists.o \
          MBGeometry.o \
          SpedeGeometry.o \
          TreeAnaDict.o
 
TreeAna: TreeAna.cc $(OBJECTS)
	$(CPP) $(CFLAGS) $(LIBS) $(INCLUDES) $< $(OBJECTS) -o $@
	$(AR) cru $(LIB_DIR)/libTreeAna.a $(OBJECTS)

g_clx.o: g_clx.cc g_clx.hh
	$(CPP) $(CFLAGS) -c $< -o $@

$(MBEVTS_DIR)/mbevts.o: $(MBEVTS_DIR)/mbevts.cc $(MBEVTS_DIR)/mbevts.hh
	$(CPP) $(CFLAGS) -c $< -o $@

doppler.o: doppler.cc doppler.hh
	$(CPP) $(CFLAGS) -c $< -o $@

hists.o: hists.cc hists.hh
	$(CPP) $(CFLAGS) -c $< -o $@

MBGeometry.o: MBGeometry.cc MBGeometry.hh
	$(CPP) $(CFLAGS) -c $< -o $@

SpedeGeometry.o: SpedeGeometry.cc SpedeGeometry.hh
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MBEVTS_DIR)/*.o *.o
	rm -f TreeAnaDict.cc TreeAnaDict_rdict.pcm

# Root stuff
DEPENDENCIES = g_clx.hh \
               $(MBEVTS_DIR)/mbevts.hh \
               doppler.hh \
               hists.hh \
               MBGeometry.hh \
               SpedeGeometry.hh \
               RootLinkDef.h

TreeAnaDict.o: TreeAnaDict.cc
	 $(CPP) $(CFLAGS) $(INCLUDES) -c $<

TreeAnaDict.cc: $(DEPENDENCIES)
	 rootcling -f $@ -c $(INCLUDES) $(DEPENDENCIES)

