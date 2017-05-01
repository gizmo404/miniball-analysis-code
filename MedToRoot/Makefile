.EXPORT_ALL_VARIABLES:

.PHONY: clean all

LIB_DIR    = ../lib
COMMON_DIR = ../common
MED_DIR    = ./med
MBEVTS_DIR = ../mbevts

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTINC      := $(shell root-config --incdir)

LIBS      = -lm $(ROOTLIBS) -L$(LIB_DIR) -lCommandLineInterface

AR        = ar
CC        = $(shell root-config --cc)
CPP       = $(shell root-config --cxx)

CFLAGS    = -O2 -pipe -Wall -W -Woverloaded-virtual $(ROOTCFLAGS) -fPIC

INCLUDES  = -I$(MED_DIR)/inc -I$(COMMON_DIR) -I$(MBEVTS_DIR) -I./
LFLAGS    = -O2 -g

O_FILES = BuiltEvent.o \
        Datas.o \
        EventBuffer.o \
        EventBuilder.o \
        GlobalSettings.o \
        Modules.o \
        SubEvents.o \
        UnpackedEvent.o \
        Calibration.o \
        $(MBEVTS_DIR)/mbevts.o \
        $(MED_DIR)/mbsio.o \
        $(MED_DIR)/byte_order.o \
        MBEventBuilderDictionary.o


all: $(COMMON_DIR)/libCommandLineInterface.a MBEventBuilder TreeBuilder

$(COMMON_DIR)/libCommandLineInterface.a:
	@cd $(COMMON_DIR); make

TreeBuilder: TreeBuilder.cc $(O_FILES) $(LIB_DIR)/libCommandLineInterface.a
	$(CPP) $(CFLAGS) $(INCLUDES) TreeBuilder.cc $(O_FILES) $(LIBS) -o $@
	$(AR) cru $(LIB_DIR)/libTreeBuilder.a $(O_FILES)

MBEventBuilder: MBEventBuilder.cc $(O_FILES) $(LIB_DIR)/libCommandLineInterface.a
	$(CPP) $(CFLAGS) $(INCLUDES) MBEventBuilder.cc $(O_FILES) $(LIBS) -o $@
	$(AR) cru $(LIB_DIR)/libMBEventBuilder.a $(O_FILES)

$(MED_DIR)/mbsio.o: $(MED_DIR)/src/mbsio.c $(MED_DIR)/inc/mbsio.h
	$(CC) -I$(ROOTINC) $(INCLUDES) -c $< -o $@

$(MED_DIR)/byte_order.o: $(MED_DIR)/src/byte_order.c $(MED_DIR)/inc/byte_order.h 
	$(CC) -I$(ROOTINC) $(INCLUDES) -c $< -o $@

%.o: %.cc %.hh
	$(CPP) $(CFLAGS) $(INCLUDES) -c $< -o $@


#---- Root stuff

DEPENDENCIES = BuiltEvent.hh \
			Datas.hh \
			EventBuffer.hh \
			EventBuilder.hh \
			GlobalSettings.hh \
			Modules.hh \
			SubEvents.hh \
			UnpackedEvent.hh \
			Calibration.hh \
			$(MBEVTS_DIR)/mbevts.hh \
			RootLinkDef.h

TreeBuilderDictionary.cc: $(DEPENDENCIES)
	rm -f TreeBuilderDictionary.cc TreeBuilderDictionary_rdict.pcm
	rootcling -f TreeBuilderDictionary.cc -c $(INCLUDES) $(DEPENDENCIES)

TreeBuilderDictionary.o: TreeBuilderDictionary.cc TreeBuilderDictionary_rdict.pcm
	$(CPP) -fPIC $(CFLAGS) $(INCLUDES) -c $<

MBEventBuilderDictionary.cc: $(DEPENDENCIES)
	rm -f MBEventBuilderDictionary.cc MBEventBuilderDictionary_rdict.pcm
	rootcling -f MBEventBuilderDictionary.cc -c $(INCLUDES) $(DEPENDENCIES)

MBEventBuilderDictionary.o: MBEventBuilderDictionary.cc MBEventBuilderDictionary_rdict.pcm
	$(CPP) -fPIC $(CFLAGS) $(INCLUDES) -c $<

#--------------------------------------------------
clean:
	rm -f MBEventBuilder TreeBuilder *.o $(MED_DIR)/*.o $(MBEVTS_DIR)/*.o $(LIB_DIR)/*.a
	rm -f MBEventBuilderDictionary.cc MBEventBuilderDictionary_rdict.pcm
	@cd $(COMMON_DIR); make clean

