# Makefile for mbgtk GUI
.PHONY: clean all

ROOTCFLAGS	:= $(shell root-config --cflags)
ROOTLIBS    := $(shell root-config --libs)

LIB_DIR     := ../lib
G_CLX_DIR   := ../TreeAna

CC       := $(shell root-config --cc)
CPP      := $(shell root-config --cxx)
CFLAGS   := $(shell pkg-config --cflags gtkmm-3.0) $(ROOTCFLAGS) -Wall -fPIC -Wno-unused-variable -g

LIBS     := $(shell pkg-config --libs gtkmm-3.0) $(ROOTLIBS) -L$(LIB_DIR) -lTreeAna

INCLUDES := -I$(G_CLX_DIR)

all: mbgtk

OBJECTS = Sorter.o

Sorter.o: Sorter.cc
	$(CPP) $(CFLAGS) $(INCLUDES) -c $< -o $@

mbgtk: mbgtk.cc $(OBJECTS)
	$(CPP) $(CFLAGS) $(LIBS) $(INCLUDES) $< $(OBJECTS) -o $@

clean:
	rm -f *.o
