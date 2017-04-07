.EXPORT_ALL_VARIABLES:

.PHONY: clean all

LIB_DIR    = ../lib
COMMON_DIR = ../common
MED_DIR    = ./med

ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS   := $(shell root-config --libs)

LIBS    = -lm $(ROOTLIBS) -L$(LIB_DIR) -lCommandLineInterface

CC		= $(shell root-config --cc)
CPP     = $(shell root-config --cxx)

CFLAGS		= -O2 -pipe -Wall -W -Woverloaded-virtual $(ROOTCFLAGS)

INCLUDES    = -I$(MED_DIR)/inc -I$(COMMON_DIR) -I.
LFLAGS		= -O2 -g
#SOFLAGS    = -dynamiclib -single_module -undefined dynamic_lookup

O_FILES = BuiltEvent.o \
        Datas.o \
        EventBuffer.o \
        EventBuilder.o \
        GlobalSettings.o \
		ParticleRange.o \
        Modules.o \
        SubEvents.o \
        UnpackedEvent.o \
        Calibration.o \
        ../mbevts/mbevts.o \
        $(MED_DIR)/mbsio.o \
        $(MED_DIR)/byte_order.o \
        MBEventBuilderDictionary.o


all: $(COMMON_DIR)/libCommandLineInterface.a MBEventBuilder BuildEventTree 

$(COMMON_DIR)/libCommandLineInterface.a:
	@cd $(COMMON_DIR); make

BuildEventTree: BuildEventTree.cc $(O_FILES) $(LIB_DIR)/libCommandLineInterface.a
	$(CPP) $(CFLAGS) $(INCLUDES) BuildEventTree.cc $(O_FILES) $(LIBS) -o $@
	$(AR) cru $(LIB_DIR)/libBuildEventTree.a $(O_FILES)

MBEventBuilder: MBEventBuilder.cc $(O_FILES) $(LIB_DIR)/libCommandLineInterface.a
	$(CPP) $(CFLAGS) $(INCLUDES) MBEventBuilder.cc $(O_FILES) $(LIBS) -o $@
	$(AR) cru $(LIB_DIR)/libMBEventBuilder.a $(O_FILES)

$(MED_DIR)/mbsio.o: $(MED_DIR)/src/mbsio.c $(MED_DIR)/inc/mbsio.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MED_DIR)/byte_order.o: $(MED_DIR)/src/byte_order.c $(MED_DIR)/inc/byte_order.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cc %.hh
	$(CPP) $(CFLAGS) $(INCLUDES) -c $< -o $@


#---- Root stuff

DEPENDENCIES = BuiltEvent.hh Datas.hh EventBuffer.hh EventBuilder.hh GlobalSettings.hh Modules.hh SubEvents.hh UnpackedEvent.hh Calibration.hh ParticleRange.hh ../mbevts/mbevts.hh RootLinkDef.h 

BuildEventTreeDictionary.cc: $(DEPENDENCIES)
	 rm -f BuildEventTreeDictionary.cc BuildEventTreeDictionary_rdict.pcm; rootcling -f BuildEventTreeDictionary.cc -c $(INCLUDES) $(DEPENDENCIES)

BuildEventTreeDictionary.o: BuildEventTreeDictionary.cc BuildEventTreeDictionary_rdict.pcm
	 $(CPP) -fPIC $(CFLAGS) $(INCLUDES) -c $<

MBEventBuilderDictionary.cc: $(DEPENDENCIES)
	 rm -f MBEventBuilderDictionary.cc MBEventBuilderDictionary_rdict.pcm; rootcling -f MBEventBuilderDictionary.cc -c $(INCLUDES) $(DEPENDENCIES)

MBEventBuilderDictionary.o: MBEventBuilderDictionary.cc MBEventBuilderDictionary_rdict.pcm
	 $(CPP) -fPIC $(CFLAGS) $(INCLUDES) -c $<


#--------------------------------------------------
clean:
	rm  -f MBEventBuilder BuildEventTree *.o MBEventBuilderDictionary.cc MBEventBuilderDictionary_rdict.pcm
	@cd $(COMMON_DIR); make clean

