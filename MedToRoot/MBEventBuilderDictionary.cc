// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME MBEventBuilderDictionary

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "BuiltEvent.hh"
#include "Datas.hh"
#include "EventBuffer.hh"
#include "EventBuilder.hh"
#include "GlobalSettings.hh"
#include "Modules.hh"
#include "SubEvents.hh"
#include "UnpackedEvent.hh"
#include "Calibration.hh"
#include "ParticleRange.hh"
#include "../mbevts/mbevts.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_GlobalSettings(void *p = 0);
   static void *newArray_GlobalSettings(Long_t size, void *p);
   static void delete_GlobalSettings(void *p);
   static void deleteArray_GlobalSettings(void *p);
   static void destruct_GlobalSettings(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GlobalSettings*)
   {
      ::GlobalSettings *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::GlobalSettings >(0);
      static ::ROOT::TGenericClassInfo 
         instance("GlobalSettings", ::GlobalSettings::Class_Version(), "GlobalSettings.hh", 19,
                  typeid(::GlobalSettings), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::GlobalSettings::Dictionary, isa_proxy, 4,
                  sizeof(::GlobalSettings) );
      instance.SetNew(&new_GlobalSettings);
      instance.SetNewArray(&newArray_GlobalSettings);
      instance.SetDelete(&delete_GlobalSettings);
      instance.SetDeleteArray(&deleteArray_GlobalSettings);
      instance.SetDestructor(&destruct_GlobalSettings);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GlobalSettings*)
   {
      return GenerateInitInstanceLocal((::GlobalSettings*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::GlobalSettings*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_DgfSubEvent(void *p = 0);
   static void *newArray_DgfSubEvent(Long_t size, void *p);
   static void delete_DgfSubEvent(void *p);
   static void deleteArray_DgfSubEvent(void *p);
   static void destruct_DgfSubEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DgfSubEvent*)
   {
      ::DgfSubEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::DgfSubEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("DgfSubEvent", ::DgfSubEvent::Class_Version(), "SubEvents.hh", 16,
                  typeid(::DgfSubEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::DgfSubEvent::Dictionary, isa_proxy, 4,
                  sizeof(::DgfSubEvent) );
      instance.SetNew(&new_DgfSubEvent);
      instance.SetNewArray(&newArray_DgfSubEvent);
      instance.SetDelete(&delete_DgfSubEvent);
      instance.SetDeleteArray(&deleteArray_DgfSubEvent);
      instance.SetDestructor(&destruct_DgfSubEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DgfSubEvent*)
   {
      return GenerateInitInstanceLocal((::DgfSubEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DgfSubEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_AdcSubEvent(void *p = 0);
   static void *newArray_AdcSubEvent(Long_t size, void *p);
   static void delete_AdcSubEvent(void *p);
   static void deleteArray_AdcSubEvent(void *p);
   static void destruct_AdcSubEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AdcSubEvent*)
   {
      ::AdcSubEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::AdcSubEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("AdcSubEvent", ::AdcSubEvent::Class_Version(), "SubEvents.hh", 161,
                  typeid(::AdcSubEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::AdcSubEvent::Dictionary, isa_proxy, 4,
                  sizeof(::AdcSubEvent) );
      instance.SetNew(&new_AdcSubEvent);
      instance.SetNewArray(&newArray_AdcSubEvent);
      instance.SetDelete(&delete_AdcSubEvent);
      instance.SetDeleteArray(&deleteArray_AdcSubEvent);
      instance.SetDestructor(&destruct_AdcSubEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AdcSubEvent*)
   {
      return GenerateInitInstanceLocal((::AdcSubEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AdcSubEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PatternUnitSubEvent(void *p = 0);
   static void *newArray_PatternUnitSubEvent(Long_t size, void *p);
   static void delete_PatternUnitSubEvent(void *p);
   static void deleteArray_PatternUnitSubEvent(void *p);
   static void destruct_PatternUnitSubEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PatternUnitSubEvent*)
   {
      ::PatternUnitSubEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PatternUnitSubEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PatternUnitSubEvent", ::PatternUnitSubEvent::Class_Version(), "SubEvents.hh", 256,
                  typeid(::PatternUnitSubEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PatternUnitSubEvent::Dictionary, isa_proxy, 4,
                  sizeof(::PatternUnitSubEvent) );
      instance.SetNew(&new_PatternUnitSubEvent);
      instance.SetNewArray(&newArray_PatternUnitSubEvent);
      instance.SetDelete(&delete_PatternUnitSubEvent);
      instance.SetDeleteArray(&deleteArray_PatternUnitSubEvent);
      instance.SetDestructor(&destruct_PatternUnitSubEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PatternUnitSubEvent*)
   {
      return GenerateInitInstanceLocal((::PatternUnitSubEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::PatternUnitSubEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ScalerSubEvent(void *p = 0);
   static void *newArray_ScalerSubEvent(Long_t size, void *p);
   static void delete_ScalerSubEvent(void *p);
   static void deleteArray_ScalerSubEvent(void *p);
   static void destruct_ScalerSubEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ScalerSubEvent*)
   {
      ::ScalerSubEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ScalerSubEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ScalerSubEvent", ::ScalerSubEvent::Class_Version(), "SubEvents.hh", 293,
                  typeid(::ScalerSubEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::ScalerSubEvent::Dictionary, isa_proxy, 4,
                  sizeof(::ScalerSubEvent) );
      instance.SetNew(&new_ScalerSubEvent);
      instance.SetNewArray(&newArray_ScalerSubEvent);
      instance.SetDelete(&delete_ScalerSubEvent);
      instance.SetDeleteArray(&deleteArray_ScalerSubEvent);
      instance.SetDestructor(&destruct_ScalerSubEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ScalerSubEvent*)
   {
      return GenerateInitInstanceLocal((::ScalerSubEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ScalerSubEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_DgfScalerSubEvent(void *p = 0);
   static void *newArray_DgfScalerSubEvent(Long_t size, void *p);
   static void delete_DgfScalerSubEvent(void *p);
   static void deleteArray_DgfScalerSubEvent(void *p);
   static void destruct_DgfScalerSubEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DgfScalerSubEvent*)
   {
      ::DgfScalerSubEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::DgfScalerSubEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("DgfScalerSubEvent", ::DgfScalerSubEvent::Class_Version(), "SubEvents.hh", 349,
                  typeid(::DgfScalerSubEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::DgfScalerSubEvent::Dictionary, isa_proxy, 4,
                  sizeof(::DgfScalerSubEvent) );
      instance.SetNew(&new_DgfScalerSubEvent);
      instance.SetNewArray(&newArray_DgfScalerSubEvent);
      instance.SetDelete(&delete_DgfScalerSubEvent);
      instance.SetDeleteArray(&deleteArray_DgfScalerSubEvent);
      instance.SetDestructor(&destruct_DgfScalerSubEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DgfScalerSubEvent*)
   {
      return GenerateInitInstanceLocal((::DgfScalerSubEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DgfScalerSubEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_BraggChamberSubEvent(void *p = 0);
   static void *newArray_BraggChamberSubEvent(Long_t size, void *p);
   static void delete_BraggChamberSubEvent(void *p);
   static void deleteArray_BraggChamberSubEvent(void *p);
   static void destruct_BraggChamberSubEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BraggChamberSubEvent*)
   {
      ::BraggChamberSubEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::BraggChamberSubEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("BraggChamberSubEvent", ::BraggChamberSubEvent::Class_Version(), "SubEvents.hh", 570,
                  typeid(::BraggChamberSubEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::BraggChamberSubEvent::Dictionary, isa_proxy, 4,
                  sizeof(::BraggChamberSubEvent) );
      instance.SetNew(&new_BraggChamberSubEvent);
      instance.SetNewArray(&newArray_BraggChamberSubEvent);
      instance.SetDelete(&delete_BraggChamberSubEvent);
      instance.SetDeleteArray(&deleteArray_BraggChamberSubEvent);
      instance.SetDestructor(&destruct_BraggChamberSubEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BraggChamberSubEvent*)
   {
      return GenerateInitInstanceLocal((::BraggChamberSubEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::BraggChamberSubEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_AdcData(void *p = 0);
   static void *newArray_AdcData(Long_t size, void *p);
   static void delete_AdcData(void *p);
   static void deleteArray_AdcData(void *p);
   static void destruct_AdcData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AdcData*)
   {
      ::AdcData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::AdcData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("AdcData", ::AdcData::Class_Version(), "Datas.hh", 10,
                  typeid(::AdcData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::AdcData::Dictionary, isa_proxy, 4,
                  sizeof(::AdcData) );
      instance.SetNew(&new_AdcData);
      instance.SetNewArray(&newArray_AdcData);
      instance.SetDelete(&delete_AdcData);
      instance.SetDeleteArray(&deleteArray_AdcData);
      instance.SetDestructor(&destruct_AdcData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AdcData*)
   {
      return GenerateInitInstanceLocal((::AdcData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AdcData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_DgfData(void *p = 0);
   static void *newArray_DgfData(Long_t size, void *p);
   static void delete_DgfData(void *p);
   static void deleteArray_DgfData(void *p);
   static void destruct_DgfData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DgfData*)
   {
      ::DgfData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::DgfData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("DgfData", ::DgfData::Class_Version(), "Datas.hh", 60,
                  typeid(::DgfData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::DgfData::Dictionary, isa_proxy, 4,
                  sizeof(::DgfData) );
      instance.SetNew(&new_DgfData);
      instance.SetNewArray(&newArray_DgfData);
      instance.SetDelete(&delete_DgfData);
      instance.SetDeleteArray(&deleteArray_DgfData);
      instance.SetDestructor(&destruct_DgfData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DgfData*)
   {
      return GenerateInitInstanceLocal((::DgfData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DgfData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_BuiltEvent(void *p = 0);
   static void *newArray_BuiltEvent(Long_t size, void *p);
   static void delete_BuiltEvent(void *p);
   static void deleteArray_BuiltEvent(void *p);
   static void destruct_BuiltEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BuiltEvent*)
   {
      ::BuiltEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::BuiltEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("BuiltEvent", ::BuiltEvent::Class_Version(), "BuiltEvent.hh", 14,
                  typeid(::BuiltEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::BuiltEvent::Dictionary, isa_proxy, 4,
                  sizeof(::BuiltEvent) );
      instance.SetNew(&new_BuiltEvent);
      instance.SetNewArray(&newArray_BuiltEvent);
      instance.SetDelete(&delete_BuiltEvent);
      instance.SetDeleteArray(&deleteArray_BuiltEvent);
      instance.SetDestructor(&destruct_BuiltEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BuiltEvent*)
   {
      return GenerateInitInstanceLocal((::BuiltEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::BuiltEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_DgfModule(void *p = 0);
   static void *newArray_DgfModule(Long_t size, void *p);
   static void delete_DgfModule(void *p);
   static void deleteArray_DgfModule(void *p);
   static void destruct_DgfModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DgfModule*)
   {
      ::DgfModule *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::DgfModule >(0);
      static ::ROOT::TGenericClassInfo 
         instance("DgfModule", ::DgfModule::Class_Version(), "Modules.hh", 10,
                  typeid(::DgfModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::DgfModule::Dictionary, isa_proxy, 4,
                  sizeof(::DgfModule) );
      instance.SetNew(&new_DgfModule);
      instance.SetNewArray(&newArray_DgfModule);
      instance.SetDelete(&delete_DgfModule);
      instance.SetDeleteArray(&deleteArray_DgfModule);
      instance.SetDestructor(&destruct_DgfModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DgfModule*)
   {
      return GenerateInitInstanceLocal((::DgfModule*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DgfModule*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_AdcModule(void *p = 0);
   static void *newArray_AdcModule(Long_t size, void *p);
   static void delete_AdcModule(void *p);
   static void deleteArray_AdcModule(void *p);
   static void destruct_AdcModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AdcModule*)
   {
      ::AdcModule *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::AdcModule >(0);
      static ::ROOT::TGenericClassInfo 
         instance("AdcModule", ::AdcModule::Class_Version(), "Modules.hh", 72,
                  typeid(::AdcModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::AdcModule::Dictionary, isa_proxy, 4,
                  sizeof(::AdcModule) );
      instance.SetNew(&new_AdcModule);
      instance.SetNewArray(&newArray_AdcModule);
      instance.SetDelete(&delete_AdcModule);
      instance.SetDeleteArray(&deleteArray_AdcModule);
      instance.SetDestructor(&destruct_AdcModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AdcModule*)
   {
      return GenerateInitInstanceLocal((::AdcModule*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AdcModule*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PatternUnit(void *p = 0);
   static void *newArray_PatternUnit(Long_t size, void *p);
   static void delete_PatternUnit(void *p);
   static void deleteArray_PatternUnit(void *p);
   static void destruct_PatternUnit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PatternUnit*)
   {
      ::PatternUnit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PatternUnit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PatternUnit", ::PatternUnit::Class_Version(), "Modules.hh", 127,
                  typeid(::PatternUnit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PatternUnit::Dictionary, isa_proxy, 4,
                  sizeof(::PatternUnit) );
      instance.SetNew(&new_PatternUnit);
      instance.SetNewArray(&newArray_PatternUnit);
      instance.SetDelete(&delete_PatternUnit);
      instance.SetDeleteArray(&deleteArray_PatternUnit);
      instance.SetDestructor(&destruct_PatternUnit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PatternUnit*)
   {
      return GenerateInitInstanceLocal((::PatternUnit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::PatternUnit*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SISScaler(void *p = 0);
   static void *newArray_SISScaler(Long_t size, void *p);
   static void delete_SISScaler(void *p);
   static void deleteArray_SISScaler(void *p);
   static void destruct_SISScaler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SISScaler*)
   {
      ::SISScaler *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SISScaler >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SISScaler", ::SISScaler::Class_Version(), "Modules.hh", 182,
                  typeid(::SISScaler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SISScaler::Dictionary, isa_proxy, 4,
                  sizeof(::SISScaler) );
      instance.SetNew(&new_SISScaler);
      instance.SetNewArray(&newArray_SISScaler);
      instance.SetDelete(&delete_SISScaler);
      instance.SetDeleteArray(&deleteArray_SISScaler);
      instance.SetDestructor(&destruct_SISScaler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SISScaler*)
   {
      return GenerateInitInstanceLocal((::SISScaler*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SISScaler*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_DgfScaler(void *p = 0);
   static void *newArray_DgfScaler(Long_t size, void *p);
   static void delete_DgfScaler(void *p);
   static void deleteArray_DgfScaler(void *p);
   static void destruct_DgfScaler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DgfScaler*)
   {
      ::DgfScaler *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::DgfScaler >(0);
      static ::ROOT::TGenericClassInfo 
         instance("DgfScaler", ::DgfScaler::Class_Version(), "Modules.hh", 231,
                  typeid(::DgfScaler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::DgfScaler::Dictionary, isa_proxy, 4,
                  sizeof(::DgfScaler) );
      instance.SetNew(&new_DgfScaler);
      instance.SetNewArray(&newArray_DgfScaler);
      instance.SetDelete(&delete_DgfScaler);
      instance.SetDeleteArray(&deleteArray_DgfScaler);
      instance.SetDestructor(&destruct_DgfScaler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DgfScaler*)
   {
      return GenerateInitInstanceLocal((::DgfScaler*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::DgfScaler*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_BraggChamber(void *p = 0);
   static void *newArray_BraggChamber(Long_t size, void *p);
   static void delete_BraggChamber(void *p);
   static void deleteArray_BraggChamber(void *p);
   static void destruct_BraggChamber(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BraggChamber*)
   {
      ::BraggChamber *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::BraggChamber >(0);
      static ::ROOT::TGenericClassInfo 
         instance("BraggChamber", ::BraggChamber::Class_Version(), "Modules.hh", 272,
                  typeid(::BraggChamber), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::BraggChamber::Dictionary, isa_proxy, 4,
                  sizeof(::BraggChamber) );
      instance.SetNew(&new_BraggChamber);
      instance.SetNewArray(&newArray_BraggChamber);
      instance.SetDelete(&delete_BraggChamber);
      instance.SetDeleteArray(&deleteArray_BraggChamber);
      instance.SetDestructor(&destruct_BraggChamber);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BraggChamber*)
   {
      return GenerateInitInstanceLocal((::BraggChamber*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::BraggChamber*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_EventBuffer(void *p = 0);
   static void *newArray_EventBuffer(Long_t size, void *p);
   static void delete_EventBuffer(void *p);
   static void deleteArray_EventBuffer(void *p);
   static void destruct_EventBuffer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EventBuffer*)
   {
      ::EventBuffer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EventBuffer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EventBuffer", ::EventBuffer::Class_Version(), "EventBuffer.hh", 16,
                  typeid(::EventBuffer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::EventBuffer::Dictionary, isa_proxy, 4,
                  sizeof(::EventBuffer) );
      instance.SetNew(&new_EventBuffer);
      instance.SetNewArray(&newArray_EventBuffer);
      instance.SetDelete(&delete_EventBuffer);
      instance.SetDeleteArray(&deleteArray_EventBuffer);
      instance.SetDestructor(&destruct_EventBuffer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EventBuffer*)
   {
      return GenerateInitInstanceLocal((::EventBuffer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EventBuffer*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_UnpackedEvent(void *p = 0);
   static void *newArray_UnpackedEvent(Long_t size, void *p);
   static void delete_UnpackedEvent(void *p);
   static void deleteArray_UnpackedEvent(void *p);
   static void destruct_UnpackedEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::UnpackedEvent*)
   {
      ::UnpackedEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::UnpackedEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("UnpackedEvent", ::UnpackedEvent::Class_Version(), "UnpackedEvent.hh", 65,
                  typeid(::UnpackedEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::UnpackedEvent::Dictionary, isa_proxy, 4,
                  sizeof(::UnpackedEvent) );
      instance.SetNew(&new_UnpackedEvent);
      instance.SetNewArray(&newArray_UnpackedEvent);
      instance.SetDelete(&delete_UnpackedEvent);
      instance.SetDeleteArray(&deleteArray_UnpackedEvent);
      instance.SetDestructor(&destruct_UnpackedEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::UnpackedEvent*)
   {
      return GenerateInitInstanceLocal((::UnpackedEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::UnpackedEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_EventBuilder(void *p = 0);
   static void *newArray_EventBuilder(Long_t size, void *p);
   static void delete_EventBuilder(void *p);
   static void deleteArray_EventBuilder(void *p);
   static void destruct_EventBuilder(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EventBuilder*)
   {
      ::EventBuilder *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EventBuilder >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EventBuilder", ::EventBuilder::Class_Version(), "EventBuilder.hh", 18,
                  typeid(::EventBuilder), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::EventBuilder::Dictionary, isa_proxy, 4,
                  sizeof(::EventBuilder) );
      instance.SetNew(&new_EventBuilder);
      instance.SetNewArray(&newArray_EventBuilder);
      instance.SetDelete(&delete_EventBuilder);
      instance.SetDeleteArray(&deleteArray_EventBuilder);
      instance.SetDestructor(&destruct_EventBuilder);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EventBuilder*)
   {
      return GenerateInitInstanceLocal((::EventBuilder*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EventBuilder*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Calibration(void *p = 0);
   static void *newArray_Calibration(Long_t size, void *p);
   static void delete_Calibration(void *p);
   static void deleteArray_Calibration(void *p);
   static void destruct_Calibration(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Calibration*)
   {
      ::Calibration *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Calibration >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Calibration", ::Calibration::Class_Version(), "Calibration.hh", 19,
                  typeid(::Calibration), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Calibration::Dictionary, isa_proxy, 4,
                  sizeof(::Calibration) );
      instance.SetNew(&new_Calibration);
      instance.SetNewArray(&newArray_Calibration);
      instance.SetDelete(&delete_Calibration);
      instance.SetDeleteArray(&deleteArray_Calibration);
      instance.SetDestructor(&destruct_Calibration);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Calibration*)
   {
      return GenerateInitInstanceLocal((::Calibration*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Calibration*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_mbevts(void *p = 0);
   static void *newArray_mbevts(Long_t size, void *p);
   static void delete_mbevts(void *p);
   static void deleteArray_mbevts(void *p);
   static void destruct_mbevts(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mbevts*)
   {
      ::mbevts *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::mbevts >(0);
      static ::ROOT::TGenericClassInfo 
         instance("mbevts", ::mbevts::Class_Version(), "../mbevts/mbevts.hh", 9,
                  typeid(::mbevts), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::mbevts::Dictionary, isa_proxy, 4,
                  sizeof(::mbevts) );
      instance.SetNew(&new_mbevts);
      instance.SetNewArray(&newArray_mbevts);
      instance.SetDelete(&delete_mbevts);
      instance.SetDeleteArray(&deleteArray_mbevts);
      instance.SetDestructor(&destruct_mbevts);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mbevts*)
   {
      return GenerateInitInstanceLocal((::mbevts*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::mbevts*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr GlobalSettings::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *GlobalSettings::Class_Name()
{
   return "GlobalSettings";
}

//______________________________________________________________________________
const char *GlobalSettings::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GlobalSettings*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int GlobalSettings::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GlobalSettings*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GlobalSettings::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GlobalSettings*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GlobalSettings::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GlobalSettings*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr DgfSubEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *DgfSubEvent::Class_Name()
{
   return "DgfSubEvent";
}

//______________________________________________________________________________
const char *DgfSubEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfSubEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int DgfSubEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfSubEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DgfSubEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfSubEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DgfSubEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfSubEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr AdcSubEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *AdcSubEvent::Class_Name()
{
   return "AdcSubEvent";
}

//______________________________________________________________________________
const char *AdcSubEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AdcSubEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AdcSubEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AdcSubEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *AdcSubEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AdcSubEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *AdcSubEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AdcSubEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PatternUnitSubEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PatternUnitSubEvent::Class_Name()
{
   return "PatternUnitSubEvent";
}

//______________________________________________________________________________
const char *PatternUnitSubEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PatternUnitSubEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PatternUnitSubEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PatternUnitSubEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PatternUnitSubEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PatternUnitSubEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PatternUnitSubEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PatternUnitSubEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ScalerSubEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ScalerSubEvent::Class_Name()
{
   return "ScalerSubEvent";
}

//______________________________________________________________________________
const char *ScalerSubEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ScalerSubEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ScalerSubEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ScalerSubEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ScalerSubEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ScalerSubEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ScalerSubEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ScalerSubEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr DgfScalerSubEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *DgfScalerSubEvent::Class_Name()
{
   return "DgfScalerSubEvent";
}

//______________________________________________________________________________
const char *DgfScalerSubEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfScalerSubEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int DgfScalerSubEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfScalerSubEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DgfScalerSubEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfScalerSubEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DgfScalerSubEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfScalerSubEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr BraggChamberSubEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BraggChamberSubEvent::Class_Name()
{
   return "BraggChamberSubEvent";
}

//______________________________________________________________________________
const char *BraggChamberSubEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BraggChamberSubEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BraggChamberSubEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BraggChamberSubEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BraggChamberSubEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BraggChamberSubEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BraggChamberSubEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BraggChamberSubEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr AdcData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *AdcData::Class_Name()
{
   return "AdcData";
}

//______________________________________________________________________________
const char *AdcData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AdcData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AdcData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AdcData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *AdcData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AdcData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *AdcData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AdcData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr DgfData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *DgfData::Class_Name()
{
   return "DgfData";
}

//______________________________________________________________________________
const char *DgfData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int DgfData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DgfData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DgfData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr BuiltEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BuiltEvent::Class_Name()
{
   return "BuiltEvent";
}

//______________________________________________________________________________
const char *BuiltEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BuiltEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BuiltEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BuiltEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BuiltEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BuiltEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BuiltEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BuiltEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr DgfModule::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *DgfModule::Class_Name()
{
   return "DgfModule";
}

//______________________________________________________________________________
const char *DgfModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfModule*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int DgfModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfModule*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DgfModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfModule*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DgfModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfModule*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr AdcModule::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *AdcModule::Class_Name()
{
   return "AdcModule";
}

//______________________________________________________________________________
const char *AdcModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AdcModule*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AdcModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AdcModule*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *AdcModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AdcModule*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *AdcModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AdcModule*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PatternUnit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PatternUnit::Class_Name()
{
   return "PatternUnit";
}

//______________________________________________________________________________
const char *PatternUnit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PatternUnit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PatternUnit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PatternUnit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PatternUnit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PatternUnit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PatternUnit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PatternUnit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SISScaler::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SISScaler::Class_Name()
{
   return "SISScaler";
}

//______________________________________________________________________________
const char *SISScaler::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SISScaler*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SISScaler::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SISScaler*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SISScaler::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SISScaler*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SISScaler::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SISScaler*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr DgfScaler::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *DgfScaler::Class_Name()
{
   return "DgfScaler";
}

//______________________________________________________________________________
const char *DgfScaler::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfScaler*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int DgfScaler::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::DgfScaler*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DgfScaler::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfScaler*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DgfScaler::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::DgfScaler*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr BraggChamber::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BraggChamber::Class_Name()
{
   return "BraggChamber";
}

//______________________________________________________________________________
const char *BraggChamber::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BraggChamber*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BraggChamber::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BraggChamber*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BraggChamber::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BraggChamber*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BraggChamber::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BraggChamber*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr EventBuffer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EventBuffer::Class_Name()
{
   return "EventBuffer";
}

//______________________________________________________________________________
const char *EventBuffer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventBuffer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EventBuffer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventBuffer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventBuffer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventBuffer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventBuffer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventBuffer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr UnpackedEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *UnpackedEvent::Class_Name()
{
   return "UnpackedEvent";
}

//______________________________________________________________________________
const char *UnpackedEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UnpackedEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int UnpackedEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UnpackedEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UnpackedEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UnpackedEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UnpackedEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UnpackedEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr EventBuilder::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EventBuilder::Class_Name()
{
   return "EventBuilder";
}

//______________________________________________________________________________
const char *EventBuilder::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventBuilder*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EventBuilder::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventBuilder*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventBuilder::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventBuilder*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventBuilder::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventBuilder*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Calibration::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Calibration::Class_Name()
{
   return "Calibration";
}

//______________________________________________________________________________
const char *Calibration::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Calibration*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Calibration::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Calibration*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Calibration::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Calibration*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Calibration::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Calibration*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr mbevts::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *mbevts::Class_Name()
{
   return "mbevts";
}

//______________________________________________________________________________
const char *mbevts::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::mbevts*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int mbevts::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::mbevts*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *mbevts::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::mbevts*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *mbevts::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::mbevts*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void GlobalSettings::Streamer(TBuffer &R__b)
{
   // Stream an object of class GlobalSettings.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(GlobalSettings::Class(),this);
   } else {
      R__b.WriteClassBuffer(GlobalSettings::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_GlobalSettings(void *p) {
      return  p ? new(p) ::GlobalSettings : new ::GlobalSettings;
   }
   static void *newArray_GlobalSettings(Long_t nElements, void *p) {
      return p ? new(p) ::GlobalSettings[nElements] : new ::GlobalSettings[nElements];
   }
   // Wrapper around operator delete
   static void delete_GlobalSettings(void *p) {
      delete ((::GlobalSettings*)p);
   }
   static void deleteArray_GlobalSettings(void *p) {
      delete [] ((::GlobalSettings*)p);
   }
   static void destruct_GlobalSettings(void *p) {
      typedef ::GlobalSettings current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::GlobalSettings

//______________________________________________________________________________
void DgfSubEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class DgfSubEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(DgfSubEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(DgfSubEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_DgfSubEvent(void *p) {
      return  p ? new(p) ::DgfSubEvent : new ::DgfSubEvent;
   }
   static void *newArray_DgfSubEvent(Long_t nElements, void *p) {
      return p ? new(p) ::DgfSubEvent[nElements] : new ::DgfSubEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_DgfSubEvent(void *p) {
      delete ((::DgfSubEvent*)p);
   }
   static void deleteArray_DgfSubEvent(void *p) {
      delete [] ((::DgfSubEvent*)p);
   }
   static void destruct_DgfSubEvent(void *p) {
      typedef ::DgfSubEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DgfSubEvent

//______________________________________________________________________________
void AdcSubEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class AdcSubEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(AdcSubEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(AdcSubEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_AdcSubEvent(void *p) {
      return  p ? new(p) ::AdcSubEvent : new ::AdcSubEvent;
   }
   static void *newArray_AdcSubEvent(Long_t nElements, void *p) {
      return p ? new(p) ::AdcSubEvent[nElements] : new ::AdcSubEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_AdcSubEvent(void *p) {
      delete ((::AdcSubEvent*)p);
   }
   static void deleteArray_AdcSubEvent(void *p) {
      delete [] ((::AdcSubEvent*)p);
   }
   static void destruct_AdcSubEvent(void *p) {
      typedef ::AdcSubEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AdcSubEvent

//______________________________________________________________________________
void PatternUnitSubEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class PatternUnitSubEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PatternUnitSubEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(PatternUnitSubEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PatternUnitSubEvent(void *p) {
      return  p ? new(p) ::PatternUnitSubEvent : new ::PatternUnitSubEvent;
   }
   static void *newArray_PatternUnitSubEvent(Long_t nElements, void *p) {
      return p ? new(p) ::PatternUnitSubEvent[nElements] : new ::PatternUnitSubEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_PatternUnitSubEvent(void *p) {
      delete ((::PatternUnitSubEvent*)p);
   }
   static void deleteArray_PatternUnitSubEvent(void *p) {
      delete [] ((::PatternUnitSubEvent*)p);
   }
   static void destruct_PatternUnitSubEvent(void *p) {
      typedef ::PatternUnitSubEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PatternUnitSubEvent

//______________________________________________________________________________
void ScalerSubEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class ScalerSubEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ScalerSubEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(ScalerSubEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ScalerSubEvent(void *p) {
      return  p ? new(p) ::ScalerSubEvent : new ::ScalerSubEvent;
   }
   static void *newArray_ScalerSubEvent(Long_t nElements, void *p) {
      return p ? new(p) ::ScalerSubEvent[nElements] : new ::ScalerSubEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_ScalerSubEvent(void *p) {
      delete ((::ScalerSubEvent*)p);
   }
   static void deleteArray_ScalerSubEvent(void *p) {
      delete [] ((::ScalerSubEvent*)p);
   }
   static void destruct_ScalerSubEvent(void *p) {
      typedef ::ScalerSubEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ScalerSubEvent

//______________________________________________________________________________
void DgfScalerSubEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class DgfScalerSubEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(DgfScalerSubEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(DgfScalerSubEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_DgfScalerSubEvent(void *p) {
      return  p ? new(p) ::DgfScalerSubEvent : new ::DgfScalerSubEvent;
   }
   static void *newArray_DgfScalerSubEvent(Long_t nElements, void *p) {
      return p ? new(p) ::DgfScalerSubEvent[nElements] : new ::DgfScalerSubEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_DgfScalerSubEvent(void *p) {
      delete ((::DgfScalerSubEvent*)p);
   }
   static void deleteArray_DgfScalerSubEvent(void *p) {
      delete [] ((::DgfScalerSubEvent*)p);
   }
   static void destruct_DgfScalerSubEvent(void *p) {
      typedef ::DgfScalerSubEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DgfScalerSubEvent

//______________________________________________________________________________
void BraggChamberSubEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class BraggChamberSubEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(BraggChamberSubEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(BraggChamberSubEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_BraggChamberSubEvent(void *p) {
      return  p ? new(p) ::BraggChamberSubEvent : new ::BraggChamberSubEvent;
   }
   static void *newArray_BraggChamberSubEvent(Long_t nElements, void *p) {
      return p ? new(p) ::BraggChamberSubEvent[nElements] : new ::BraggChamberSubEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_BraggChamberSubEvent(void *p) {
      delete ((::BraggChamberSubEvent*)p);
   }
   static void deleteArray_BraggChamberSubEvent(void *p) {
      delete [] ((::BraggChamberSubEvent*)p);
   }
   static void destruct_BraggChamberSubEvent(void *p) {
      typedef ::BraggChamberSubEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BraggChamberSubEvent

//______________________________________________________________________________
void AdcData::Streamer(TBuffer &R__b)
{
   // Stream an object of class AdcData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(AdcData::Class(),this);
   } else {
      R__b.WriteClassBuffer(AdcData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_AdcData(void *p) {
      return  p ? new(p) ::AdcData : new ::AdcData;
   }
   static void *newArray_AdcData(Long_t nElements, void *p) {
      return p ? new(p) ::AdcData[nElements] : new ::AdcData[nElements];
   }
   // Wrapper around operator delete
   static void delete_AdcData(void *p) {
      delete ((::AdcData*)p);
   }
   static void deleteArray_AdcData(void *p) {
      delete [] ((::AdcData*)p);
   }
   static void destruct_AdcData(void *p) {
      typedef ::AdcData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AdcData

//______________________________________________________________________________
void DgfData::Streamer(TBuffer &R__b)
{
   // Stream an object of class DgfData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(DgfData::Class(),this);
   } else {
      R__b.WriteClassBuffer(DgfData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_DgfData(void *p) {
      return  p ? new(p) ::DgfData : new ::DgfData;
   }
   static void *newArray_DgfData(Long_t nElements, void *p) {
      return p ? new(p) ::DgfData[nElements] : new ::DgfData[nElements];
   }
   // Wrapper around operator delete
   static void delete_DgfData(void *p) {
      delete ((::DgfData*)p);
   }
   static void deleteArray_DgfData(void *p) {
      delete [] ((::DgfData*)p);
   }
   static void destruct_DgfData(void *p) {
      typedef ::DgfData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DgfData

//______________________________________________________________________________
void BuiltEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class BuiltEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(BuiltEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(BuiltEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_BuiltEvent(void *p) {
      return  p ? new(p) ::BuiltEvent : new ::BuiltEvent;
   }
   static void *newArray_BuiltEvent(Long_t nElements, void *p) {
      return p ? new(p) ::BuiltEvent[nElements] : new ::BuiltEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_BuiltEvent(void *p) {
      delete ((::BuiltEvent*)p);
   }
   static void deleteArray_BuiltEvent(void *p) {
      delete [] ((::BuiltEvent*)p);
   }
   static void destruct_BuiltEvent(void *p) {
      typedef ::BuiltEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BuiltEvent

//______________________________________________________________________________
void DgfModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class DgfModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(DgfModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(DgfModule::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_DgfModule(void *p) {
      return  p ? new(p) ::DgfModule : new ::DgfModule;
   }
   static void *newArray_DgfModule(Long_t nElements, void *p) {
      return p ? new(p) ::DgfModule[nElements] : new ::DgfModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_DgfModule(void *p) {
      delete ((::DgfModule*)p);
   }
   static void deleteArray_DgfModule(void *p) {
      delete [] ((::DgfModule*)p);
   }
   static void destruct_DgfModule(void *p) {
      typedef ::DgfModule current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DgfModule

//______________________________________________________________________________
void AdcModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class AdcModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(AdcModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(AdcModule::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_AdcModule(void *p) {
      return  p ? new(p) ::AdcModule : new ::AdcModule;
   }
   static void *newArray_AdcModule(Long_t nElements, void *p) {
      return p ? new(p) ::AdcModule[nElements] : new ::AdcModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_AdcModule(void *p) {
      delete ((::AdcModule*)p);
   }
   static void deleteArray_AdcModule(void *p) {
      delete [] ((::AdcModule*)p);
   }
   static void destruct_AdcModule(void *p) {
      typedef ::AdcModule current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AdcModule

//______________________________________________________________________________
void PatternUnit::Streamer(TBuffer &R__b)
{
   // Stream an object of class PatternUnit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PatternUnit::Class(),this);
   } else {
      R__b.WriteClassBuffer(PatternUnit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PatternUnit(void *p) {
      return  p ? new(p) ::PatternUnit : new ::PatternUnit;
   }
   static void *newArray_PatternUnit(Long_t nElements, void *p) {
      return p ? new(p) ::PatternUnit[nElements] : new ::PatternUnit[nElements];
   }
   // Wrapper around operator delete
   static void delete_PatternUnit(void *p) {
      delete ((::PatternUnit*)p);
   }
   static void deleteArray_PatternUnit(void *p) {
      delete [] ((::PatternUnit*)p);
   }
   static void destruct_PatternUnit(void *p) {
      typedef ::PatternUnit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PatternUnit

//______________________________________________________________________________
void SISScaler::Streamer(TBuffer &R__b)
{
   // Stream an object of class SISScaler.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SISScaler::Class(),this);
   } else {
      R__b.WriteClassBuffer(SISScaler::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SISScaler(void *p) {
      return  p ? new(p) ::SISScaler : new ::SISScaler;
   }
   static void *newArray_SISScaler(Long_t nElements, void *p) {
      return p ? new(p) ::SISScaler[nElements] : new ::SISScaler[nElements];
   }
   // Wrapper around operator delete
   static void delete_SISScaler(void *p) {
      delete ((::SISScaler*)p);
   }
   static void deleteArray_SISScaler(void *p) {
      delete [] ((::SISScaler*)p);
   }
   static void destruct_SISScaler(void *p) {
      typedef ::SISScaler current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SISScaler

//______________________________________________________________________________
void DgfScaler::Streamer(TBuffer &R__b)
{
   // Stream an object of class DgfScaler.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(DgfScaler::Class(),this);
   } else {
      R__b.WriteClassBuffer(DgfScaler::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_DgfScaler(void *p) {
      return  p ? new(p) ::DgfScaler : new ::DgfScaler;
   }
   static void *newArray_DgfScaler(Long_t nElements, void *p) {
      return p ? new(p) ::DgfScaler[nElements] : new ::DgfScaler[nElements];
   }
   // Wrapper around operator delete
   static void delete_DgfScaler(void *p) {
      delete ((::DgfScaler*)p);
   }
   static void deleteArray_DgfScaler(void *p) {
      delete [] ((::DgfScaler*)p);
   }
   static void destruct_DgfScaler(void *p) {
      typedef ::DgfScaler current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DgfScaler

//______________________________________________________________________________
void BraggChamber::Streamer(TBuffer &R__b)
{
   // Stream an object of class BraggChamber.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(BraggChamber::Class(),this);
   } else {
      R__b.WriteClassBuffer(BraggChamber::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_BraggChamber(void *p) {
      return  p ? new(p) ::BraggChamber : new ::BraggChamber;
   }
   static void *newArray_BraggChamber(Long_t nElements, void *p) {
      return p ? new(p) ::BraggChamber[nElements] : new ::BraggChamber[nElements];
   }
   // Wrapper around operator delete
   static void delete_BraggChamber(void *p) {
      delete ((::BraggChamber*)p);
   }
   static void deleteArray_BraggChamber(void *p) {
      delete [] ((::BraggChamber*)p);
   }
   static void destruct_BraggChamber(void *p) {
      typedef ::BraggChamber current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BraggChamber

//______________________________________________________________________________
void EventBuffer::Streamer(TBuffer &R__b)
{
   // Stream an object of class EventBuffer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EventBuffer::Class(),this);
   } else {
      R__b.WriteClassBuffer(EventBuffer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_EventBuffer(void *p) {
      return  p ? new(p) ::EventBuffer : new ::EventBuffer;
   }
   static void *newArray_EventBuffer(Long_t nElements, void *p) {
      return p ? new(p) ::EventBuffer[nElements] : new ::EventBuffer[nElements];
   }
   // Wrapper around operator delete
   static void delete_EventBuffer(void *p) {
      delete ((::EventBuffer*)p);
   }
   static void deleteArray_EventBuffer(void *p) {
      delete [] ((::EventBuffer*)p);
   }
   static void destruct_EventBuffer(void *p) {
      typedef ::EventBuffer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EventBuffer

//______________________________________________________________________________
void UnpackedEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class UnpackedEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(UnpackedEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(UnpackedEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_UnpackedEvent(void *p) {
      return  p ? new(p) ::UnpackedEvent : new ::UnpackedEvent;
   }
   static void *newArray_UnpackedEvent(Long_t nElements, void *p) {
      return p ? new(p) ::UnpackedEvent[nElements] : new ::UnpackedEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_UnpackedEvent(void *p) {
      delete ((::UnpackedEvent*)p);
   }
   static void deleteArray_UnpackedEvent(void *p) {
      delete [] ((::UnpackedEvent*)p);
   }
   static void destruct_UnpackedEvent(void *p) {
      typedef ::UnpackedEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::UnpackedEvent

//______________________________________________________________________________
void EventBuilder::Streamer(TBuffer &R__b)
{
   // Stream an object of class EventBuilder.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EventBuilder::Class(),this);
   } else {
      R__b.WriteClassBuffer(EventBuilder::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_EventBuilder(void *p) {
      return  p ? new(p) ::EventBuilder : new ::EventBuilder;
   }
   static void *newArray_EventBuilder(Long_t nElements, void *p) {
      return p ? new(p) ::EventBuilder[nElements] : new ::EventBuilder[nElements];
   }
   // Wrapper around operator delete
   static void delete_EventBuilder(void *p) {
      delete ((::EventBuilder*)p);
   }
   static void deleteArray_EventBuilder(void *p) {
      delete [] ((::EventBuilder*)p);
   }
   static void destruct_EventBuilder(void *p) {
      typedef ::EventBuilder current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EventBuilder

//______________________________________________________________________________
void Calibration::Streamer(TBuffer &R__b)
{
   // Stream an object of class Calibration.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Calibration::Class(),this);
   } else {
      R__b.WriteClassBuffer(Calibration::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Calibration(void *p) {
      return  p ? new(p) ::Calibration : new ::Calibration;
   }
   static void *newArray_Calibration(Long_t nElements, void *p) {
      return p ? new(p) ::Calibration[nElements] : new ::Calibration[nElements];
   }
   // Wrapper around operator delete
   static void delete_Calibration(void *p) {
      delete ((::Calibration*)p);
   }
   static void deleteArray_Calibration(void *p) {
      delete [] ((::Calibration*)p);
   }
   static void destruct_Calibration(void *p) {
      typedef ::Calibration current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Calibration

//______________________________________________________________________________
void mbevts::Streamer(TBuffer &R__b)
{
   // Stream an object of class mbevts.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(mbevts::Class(),this);
   } else {
      R__b.WriteClassBuffer(mbevts::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_mbevts(void *p) {
      return  p ? new(p) ::mbevts : new ::mbevts;
   }
   static void *newArray_mbevts(Long_t nElements, void *p) {
      return p ? new(p) ::mbevts[nElements] : new ::mbevts[nElements];
   }
   // Wrapper around operator delete
   static void delete_mbevts(void *p) {
      delete ((::mbevts*)p);
   }
   static void deleteArray_mbevts(void *p) {
      delete [] ((::mbevts*)p);
   }
   static void destruct_mbevts(void *p) {
      typedef ::mbevts current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::mbevts

namespace ROOT {
   static TClass *vectorlEvectorlElongsPdoublegRsPgR_Dictionary();
   static void vectorlEvectorlElongsPdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlElongsPdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlElongsPdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlElongsPdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlElongsPdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlElongsPdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<long double> >*)
   {
      vector<vector<long double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<long double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<long double> >", -2, "vector", 458,
                  typeid(vector<vector<long double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlElongsPdoublegRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<long double> >) );
      instance.SetNew(&new_vectorlEvectorlElongsPdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlElongsPdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlElongsPdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlElongsPdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlElongsPdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<long double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<long double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlElongsPdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<long double> >*)0x0)->GetClass();
      vectorlEvectorlElongsPdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlElongsPdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlElongsPdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<long double> > : new vector<vector<long double> >;
   }
   static void *newArray_vectorlEvectorlElongsPdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<long double> >[nElements] : new vector<vector<long double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlElongsPdoublegRsPgR(void *p) {
      delete ((vector<vector<long double> >*)p);
   }
   static void deleteArray_vectorlEvectorlElongsPdoublegRsPgR(void *p) {
      delete [] ((vector<vector<long double> >*)p);
   }
   static void destruct_vectorlEvectorlElongsPdoublegRsPgR(void *p) {
      typedef vector<vector<long double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<long double> >

namespace ROOT {
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary();
   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<double> >*)
   {
      vector<vector<double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<double> >", -2, "vector", 458,
                  typeid(vector<vector<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEdoublegRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<double> >) );
      instance.SetNew(&new_vectorlEvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<double> >*)0x0)->GetClass();
      vectorlEvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> > : new vector<vector<double> >;
   }
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> >[nElements] : new vector<vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete ((vector<vector<double> >*)p);
   }
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete [] ((vector<vector<double> >*)p);
   }
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p) {
      typedef vector<vector<double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<double> >

namespace ROOT {
   static TClass *vectorlEunsignedsPshortgR_Dictionary();
   static void vectorlEunsignedsPshortgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPshortgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPshortgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPshortgR(void *p);
   static void deleteArray_vectorlEunsignedsPshortgR(void *p);
   static void destruct_vectorlEunsignedsPshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned short>*)
   {
      vector<unsigned short> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned short>", -2, "vector", 458,
                  typeid(vector<unsigned short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned short>) );
      instance.SetNew(&new_vectorlEunsignedsPshortgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPshortgR);
      instance.SetDelete(&delete_vectorlEunsignedsPshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPshortgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned short> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<unsigned short>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned short>*)0x0)->GetClass();
      vectorlEunsignedsPshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPshortgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned short> : new vector<unsigned short>;
   }
   static void *newArray_vectorlEunsignedsPshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned short>[nElements] : new vector<unsigned short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPshortgR(void *p) {
      delete ((vector<unsigned short>*)p);
   }
   static void deleteArray_vectorlEunsignedsPshortgR(void *p) {
      delete [] ((vector<unsigned short>*)p);
   }
   static void destruct_vectorlEunsignedsPshortgR(void *p) {
      typedef vector<unsigned short> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned short>

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 458,
                  typeid(vector<unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned int>*)0x0)->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete ((vector<unsigned int>*)p);
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] ((vector<unsigned int>*)p);
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlElongsPdoublegR_Dictionary();
   static void vectorlElongsPdoublegR_TClassManip(TClass*);
   static void *new_vectorlElongsPdoublegR(void *p = 0);
   static void *newArray_vectorlElongsPdoublegR(Long_t size, void *p);
   static void delete_vectorlElongsPdoublegR(void *p);
   static void deleteArray_vectorlElongsPdoublegR(void *p);
   static void destruct_vectorlElongsPdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<long double>*)
   {
      vector<long double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<long double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<long double>", -2, "vector", 458,
                  typeid(vector<long double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlElongsPdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<long double>) );
      instance.SetNew(&new_vectorlElongsPdoublegR);
      instance.SetNewArray(&newArray_vectorlElongsPdoublegR);
      instance.SetDelete(&delete_vectorlElongsPdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlElongsPdoublegR);
      instance.SetDestructor(&destruct_vectorlElongsPdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<long double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<long double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlElongsPdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<long double>*)0x0)->GetClass();
      vectorlElongsPdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlElongsPdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlElongsPdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<long double> : new vector<long double>;
   }
   static void *newArray_vectorlElongsPdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<long double>[nElements] : new vector<long double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlElongsPdoublegR(void *p) {
      delete ((vector<long double>*)p);
   }
   static void deleteArray_vectorlElongsPdoublegR(void *p) {
      delete [] ((vector<long double>*)p);
   }
   static void destruct_vectorlElongsPdoublegR(void *p) {
      typedef vector<long double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<long double>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 458,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 458,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlEScalerSubEventgR_Dictionary();
   static void vectorlEScalerSubEventgR_TClassManip(TClass*);
   static void *new_vectorlEScalerSubEventgR(void *p = 0);
   static void *newArray_vectorlEScalerSubEventgR(Long_t size, void *p);
   static void delete_vectorlEScalerSubEventgR(void *p);
   static void deleteArray_vectorlEScalerSubEventgR(void *p);
   static void destruct_vectorlEScalerSubEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ScalerSubEvent>*)
   {
      vector<ScalerSubEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ScalerSubEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ScalerSubEvent>", -2, "vector", 458,
                  typeid(vector<ScalerSubEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEScalerSubEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<ScalerSubEvent>) );
      instance.SetNew(&new_vectorlEScalerSubEventgR);
      instance.SetNewArray(&newArray_vectorlEScalerSubEventgR);
      instance.SetDelete(&delete_vectorlEScalerSubEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEScalerSubEventgR);
      instance.SetDestructor(&destruct_vectorlEScalerSubEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ScalerSubEvent> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ScalerSubEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEScalerSubEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ScalerSubEvent>*)0x0)->GetClass();
      vectorlEScalerSubEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEScalerSubEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEScalerSubEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<ScalerSubEvent> : new vector<ScalerSubEvent>;
   }
   static void *newArray_vectorlEScalerSubEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<ScalerSubEvent>[nElements] : new vector<ScalerSubEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEScalerSubEventgR(void *p) {
      delete ((vector<ScalerSubEvent>*)p);
   }
   static void deleteArray_vectorlEScalerSubEventgR(void *p) {
      delete [] ((vector<ScalerSubEvent>*)p);
   }
   static void destruct_vectorlEScalerSubEventgR(void *p) {
      typedef vector<ScalerSubEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ScalerSubEvent>

namespace ROOT {
   static TClass *vectorlEPatternUnitSubEventgR_Dictionary();
   static void vectorlEPatternUnitSubEventgR_TClassManip(TClass*);
   static void *new_vectorlEPatternUnitSubEventgR(void *p = 0);
   static void *newArray_vectorlEPatternUnitSubEventgR(Long_t size, void *p);
   static void delete_vectorlEPatternUnitSubEventgR(void *p);
   static void deleteArray_vectorlEPatternUnitSubEventgR(void *p);
   static void destruct_vectorlEPatternUnitSubEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PatternUnitSubEvent>*)
   {
      vector<PatternUnitSubEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PatternUnitSubEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PatternUnitSubEvent>", -2, "vector", 458,
                  typeid(vector<PatternUnitSubEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPatternUnitSubEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<PatternUnitSubEvent>) );
      instance.SetNew(&new_vectorlEPatternUnitSubEventgR);
      instance.SetNewArray(&newArray_vectorlEPatternUnitSubEventgR);
      instance.SetDelete(&delete_vectorlEPatternUnitSubEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEPatternUnitSubEventgR);
      instance.SetDestructor(&destruct_vectorlEPatternUnitSubEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PatternUnitSubEvent> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<PatternUnitSubEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPatternUnitSubEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<PatternUnitSubEvent>*)0x0)->GetClass();
      vectorlEPatternUnitSubEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPatternUnitSubEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPatternUnitSubEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PatternUnitSubEvent> : new vector<PatternUnitSubEvent>;
   }
   static void *newArray_vectorlEPatternUnitSubEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PatternUnitSubEvent>[nElements] : new vector<PatternUnitSubEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPatternUnitSubEventgR(void *p) {
      delete ((vector<PatternUnitSubEvent>*)p);
   }
   static void deleteArray_vectorlEPatternUnitSubEventgR(void *p) {
      delete [] ((vector<PatternUnitSubEvent>*)p);
   }
   static void destruct_vectorlEPatternUnitSubEventgR(void *p) {
      typedef vector<PatternUnitSubEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<PatternUnitSubEvent>

namespace ROOT {
   static TClass *vectorlEPatternUnitgR_Dictionary();
   static void vectorlEPatternUnitgR_TClassManip(TClass*);
   static void *new_vectorlEPatternUnitgR(void *p = 0);
   static void *newArray_vectorlEPatternUnitgR(Long_t size, void *p);
   static void delete_vectorlEPatternUnitgR(void *p);
   static void deleteArray_vectorlEPatternUnitgR(void *p);
   static void destruct_vectorlEPatternUnitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PatternUnit>*)
   {
      vector<PatternUnit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PatternUnit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PatternUnit>", -2, "vector", 458,
                  typeid(vector<PatternUnit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPatternUnitgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<PatternUnit>) );
      instance.SetNew(&new_vectorlEPatternUnitgR);
      instance.SetNewArray(&newArray_vectorlEPatternUnitgR);
      instance.SetDelete(&delete_vectorlEPatternUnitgR);
      instance.SetDeleteArray(&deleteArray_vectorlEPatternUnitgR);
      instance.SetDestructor(&destruct_vectorlEPatternUnitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PatternUnit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<PatternUnit>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPatternUnitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<PatternUnit>*)0x0)->GetClass();
      vectorlEPatternUnitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPatternUnitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPatternUnitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PatternUnit> : new vector<PatternUnit>;
   }
   static void *newArray_vectorlEPatternUnitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PatternUnit>[nElements] : new vector<PatternUnit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPatternUnitgR(void *p) {
      delete ((vector<PatternUnit>*)p);
   }
   static void deleteArray_vectorlEPatternUnitgR(void *p) {
      delete [] ((vector<PatternUnit>*)p);
   }
   static void destruct_vectorlEPatternUnitgR(void *p) {
      typedef vector<PatternUnit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<PatternUnit>

namespace ROOT {
   static TClass *vectorlELong64_tgR_Dictionary();
   static void vectorlELong64_tgR_TClassManip(TClass*);
   static void *new_vectorlELong64_tgR(void *p = 0);
   static void *newArray_vectorlELong64_tgR(Long_t size, void *p);
   static void delete_vectorlELong64_tgR(void *p);
   static void deleteArray_vectorlELong64_tgR(void *p);
   static void destruct_vectorlELong64_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Long64_t>*)
   {
      vector<Long64_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Long64_t>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Long64_t>", -2, "vector", 458,
                  typeid(vector<Long64_t>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlELong64_tgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Long64_t>) );
      instance.SetNew(&new_vectorlELong64_tgR);
      instance.SetNewArray(&newArray_vectorlELong64_tgR);
      instance.SetDelete(&delete_vectorlELong64_tgR);
      instance.SetDeleteArray(&deleteArray_vectorlELong64_tgR);
      instance.SetDestructor(&destruct_vectorlELong64_tgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Long64_t> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<Long64_t>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlELong64_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Long64_t>*)0x0)->GetClass();
      vectorlELong64_tgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlELong64_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlELong64_tgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Long64_t> : new vector<Long64_t>;
   }
   static void *newArray_vectorlELong64_tgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Long64_t>[nElements] : new vector<Long64_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlELong64_tgR(void *p) {
      delete ((vector<Long64_t>*)p);
   }
   static void deleteArray_vectorlELong64_tgR(void *p) {
      delete [] ((vector<Long64_t>*)p);
   }
   static void destruct_vectorlELong64_tgR(void *p) {
      typedef vector<Long64_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Long64_t>

namespace ROOT {
   static TClass *vectorlEDgfSubEventgR_Dictionary();
   static void vectorlEDgfSubEventgR_TClassManip(TClass*);
   static void *new_vectorlEDgfSubEventgR(void *p = 0);
   static void *newArray_vectorlEDgfSubEventgR(Long_t size, void *p);
   static void delete_vectorlEDgfSubEventgR(void *p);
   static void deleteArray_vectorlEDgfSubEventgR(void *p);
   static void destruct_vectorlEDgfSubEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DgfSubEvent>*)
   {
      vector<DgfSubEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DgfSubEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DgfSubEvent>", -2, "vector", 458,
                  typeid(vector<DgfSubEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEDgfSubEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<DgfSubEvent>) );
      instance.SetNew(&new_vectorlEDgfSubEventgR);
      instance.SetNewArray(&newArray_vectorlEDgfSubEventgR);
      instance.SetDelete(&delete_vectorlEDgfSubEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDgfSubEventgR);
      instance.SetDestructor(&destruct_vectorlEDgfSubEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DgfSubEvent> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DgfSubEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDgfSubEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DgfSubEvent>*)0x0)->GetClass();
      vectorlEDgfSubEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDgfSubEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDgfSubEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfSubEvent> : new vector<DgfSubEvent>;
   }
   static void *newArray_vectorlEDgfSubEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfSubEvent>[nElements] : new vector<DgfSubEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDgfSubEventgR(void *p) {
      delete ((vector<DgfSubEvent>*)p);
   }
   static void deleteArray_vectorlEDgfSubEventgR(void *p) {
      delete [] ((vector<DgfSubEvent>*)p);
   }
   static void destruct_vectorlEDgfSubEventgR(void *p) {
      typedef vector<DgfSubEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DgfSubEvent>

namespace ROOT {
   static TClass *vectorlEDgfScalerSubEventgR_Dictionary();
   static void vectorlEDgfScalerSubEventgR_TClassManip(TClass*);
   static void *new_vectorlEDgfScalerSubEventgR(void *p = 0);
   static void *newArray_vectorlEDgfScalerSubEventgR(Long_t size, void *p);
   static void delete_vectorlEDgfScalerSubEventgR(void *p);
   static void deleteArray_vectorlEDgfScalerSubEventgR(void *p);
   static void destruct_vectorlEDgfScalerSubEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DgfScalerSubEvent>*)
   {
      vector<DgfScalerSubEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DgfScalerSubEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DgfScalerSubEvent>", -2, "vector", 458,
                  typeid(vector<DgfScalerSubEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEDgfScalerSubEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<DgfScalerSubEvent>) );
      instance.SetNew(&new_vectorlEDgfScalerSubEventgR);
      instance.SetNewArray(&newArray_vectorlEDgfScalerSubEventgR);
      instance.SetDelete(&delete_vectorlEDgfScalerSubEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDgfScalerSubEventgR);
      instance.SetDestructor(&destruct_vectorlEDgfScalerSubEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DgfScalerSubEvent> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DgfScalerSubEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDgfScalerSubEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DgfScalerSubEvent>*)0x0)->GetClass();
      vectorlEDgfScalerSubEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDgfScalerSubEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDgfScalerSubEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfScalerSubEvent> : new vector<DgfScalerSubEvent>;
   }
   static void *newArray_vectorlEDgfScalerSubEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfScalerSubEvent>[nElements] : new vector<DgfScalerSubEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDgfScalerSubEventgR(void *p) {
      delete ((vector<DgfScalerSubEvent>*)p);
   }
   static void deleteArray_vectorlEDgfScalerSubEventgR(void *p) {
      delete [] ((vector<DgfScalerSubEvent>*)p);
   }
   static void destruct_vectorlEDgfScalerSubEventgR(void *p) {
      typedef vector<DgfScalerSubEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DgfScalerSubEvent>

namespace ROOT {
   static TClass *vectorlEDgfModulegR_Dictionary();
   static void vectorlEDgfModulegR_TClassManip(TClass*);
   static void *new_vectorlEDgfModulegR(void *p = 0);
   static void *newArray_vectorlEDgfModulegR(Long_t size, void *p);
   static void delete_vectorlEDgfModulegR(void *p);
   static void deleteArray_vectorlEDgfModulegR(void *p);
   static void destruct_vectorlEDgfModulegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DgfModule>*)
   {
      vector<DgfModule> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DgfModule>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DgfModule>", -2, "vector", 458,
                  typeid(vector<DgfModule>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEDgfModulegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<DgfModule>) );
      instance.SetNew(&new_vectorlEDgfModulegR);
      instance.SetNewArray(&newArray_vectorlEDgfModulegR);
      instance.SetDelete(&delete_vectorlEDgfModulegR);
      instance.SetDeleteArray(&deleteArray_vectorlEDgfModulegR);
      instance.SetDestructor(&destruct_vectorlEDgfModulegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DgfModule> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DgfModule>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDgfModulegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DgfModule>*)0x0)->GetClass();
      vectorlEDgfModulegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDgfModulegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDgfModulegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfModule> : new vector<DgfModule>;
   }
   static void *newArray_vectorlEDgfModulegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfModule>[nElements] : new vector<DgfModule>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDgfModulegR(void *p) {
      delete ((vector<DgfModule>*)p);
   }
   static void deleteArray_vectorlEDgfModulegR(void *p) {
      delete [] ((vector<DgfModule>*)p);
   }
   static void destruct_vectorlEDgfModulegR(void *p) {
      typedef vector<DgfModule> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DgfModule>

namespace ROOT {
   static TClass *vectorlEDgfDatagR_Dictionary();
   static void vectorlEDgfDatagR_TClassManip(TClass*);
   static void *new_vectorlEDgfDatagR(void *p = 0);
   static void *newArray_vectorlEDgfDatagR(Long_t size, void *p);
   static void delete_vectorlEDgfDatagR(void *p);
   static void deleteArray_vectorlEDgfDatagR(void *p);
   static void destruct_vectorlEDgfDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DgfData>*)
   {
      vector<DgfData> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DgfData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DgfData>", -2, "vector", 458,
                  typeid(vector<DgfData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEDgfDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<DgfData>) );
      instance.SetNew(&new_vectorlEDgfDatagR);
      instance.SetNewArray(&newArray_vectorlEDgfDatagR);
      instance.SetDelete(&delete_vectorlEDgfDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEDgfDatagR);
      instance.SetDestructor(&destruct_vectorlEDgfDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DgfData> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<DgfData>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDgfDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DgfData>*)0x0)->GetClass();
      vectorlEDgfDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDgfDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDgfDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfData> : new vector<DgfData>;
   }
   static void *newArray_vectorlEDgfDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DgfData>[nElements] : new vector<DgfData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDgfDatagR(void *p) {
      delete ((vector<DgfData>*)p);
   }
   static void deleteArray_vectorlEDgfDatagR(void *p) {
      delete [] ((vector<DgfData>*)p);
   }
   static void destruct_vectorlEDgfDatagR(void *p) {
      typedef vector<DgfData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DgfData>

namespace ROOT {
   static TClass *vectorlEBuiltEventgR_Dictionary();
   static void vectorlEBuiltEventgR_TClassManip(TClass*);
   static void *new_vectorlEBuiltEventgR(void *p = 0);
   static void *newArray_vectorlEBuiltEventgR(Long_t size, void *p);
   static void delete_vectorlEBuiltEventgR(void *p);
   static void deleteArray_vectorlEBuiltEventgR(void *p);
   static void destruct_vectorlEBuiltEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<BuiltEvent>*)
   {
      vector<BuiltEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<BuiltEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<BuiltEvent>", -2, "vector", 458,
                  typeid(vector<BuiltEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEBuiltEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<BuiltEvent>) );
      instance.SetNew(&new_vectorlEBuiltEventgR);
      instance.SetNewArray(&newArray_vectorlEBuiltEventgR);
      instance.SetDelete(&delete_vectorlEBuiltEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEBuiltEventgR);
      instance.SetDestructor(&destruct_vectorlEBuiltEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<BuiltEvent> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<BuiltEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEBuiltEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<BuiltEvent>*)0x0)->GetClass();
      vectorlEBuiltEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEBuiltEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEBuiltEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<BuiltEvent> : new vector<BuiltEvent>;
   }
   static void *newArray_vectorlEBuiltEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<BuiltEvent>[nElements] : new vector<BuiltEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEBuiltEventgR(void *p) {
      delete ((vector<BuiltEvent>*)p);
   }
   static void deleteArray_vectorlEBuiltEventgR(void *p) {
      delete [] ((vector<BuiltEvent>*)p);
   }
   static void destruct_vectorlEBuiltEventgR(void *p) {
      typedef vector<BuiltEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<BuiltEvent>

namespace ROOT {
   static TClass *vectorlEBraggChamberSubEventgR_Dictionary();
   static void vectorlEBraggChamberSubEventgR_TClassManip(TClass*);
   static void *new_vectorlEBraggChamberSubEventgR(void *p = 0);
   static void *newArray_vectorlEBraggChamberSubEventgR(Long_t size, void *p);
   static void delete_vectorlEBraggChamberSubEventgR(void *p);
   static void deleteArray_vectorlEBraggChamberSubEventgR(void *p);
   static void destruct_vectorlEBraggChamberSubEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<BraggChamberSubEvent>*)
   {
      vector<BraggChamberSubEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<BraggChamberSubEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<BraggChamberSubEvent>", -2, "vector", 458,
                  typeid(vector<BraggChamberSubEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEBraggChamberSubEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<BraggChamberSubEvent>) );
      instance.SetNew(&new_vectorlEBraggChamberSubEventgR);
      instance.SetNewArray(&newArray_vectorlEBraggChamberSubEventgR);
      instance.SetDelete(&delete_vectorlEBraggChamberSubEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEBraggChamberSubEventgR);
      instance.SetDestructor(&destruct_vectorlEBraggChamberSubEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<BraggChamberSubEvent> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<BraggChamberSubEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEBraggChamberSubEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<BraggChamberSubEvent>*)0x0)->GetClass();
      vectorlEBraggChamberSubEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEBraggChamberSubEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEBraggChamberSubEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<BraggChamberSubEvent> : new vector<BraggChamberSubEvent>;
   }
   static void *newArray_vectorlEBraggChamberSubEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<BraggChamberSubEvent>[nElements] : new vector<BraggChamberSubEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEBraggChamberSubEventgR(void *p) {
      delete ((vector<BraggChamberSubEvent>*)p);
   }
   static void deleteArray_vectorlEBraggChamberSubEventgR(void *p) {
      delete [] ((vector<BraggChamberSubEvent>*)p);
   }
   static void destruct_vectorlEBraggChamberSubEventgR(void *p) {
      typedef vector<BraggChamberSubEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<BraggChamberSubEvent>

namespace ROOT {
   static TClass *vectorlEAdcSubEventgR_Dictionary();
   static void vectorlEAdcSubEventgR_TClassManip(TClass*);
   static void *new_vectorlEAdcSubEventgR(void *p = 0);
   static void *newArray_vectorlEAdcSubEventgR(Long_t size, void *p);
   static void delete_vectorlEAdcSubEventgR(void *p);
   static void deleteArray_vectorlEAdcSubEventgR(void *p);
   static void destruct_vectorlEAdcSubEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<AdcSubEvent>*)
   {
      vector<AdcSubEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<AdcSubEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<AdcSubEvent>", -2, "vector", 458,
                  typeid(vector<AdcSubEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEAdcSubEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<AdcSubEvent>) );
      instance.SetNew(&new_vectorlEAdcSubEventgR);
      instance.SetNewArray(&newArray_vectorlEAdcSubEventgR);
      instance.SetDelete(&delete_vectorlEAdcSubEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEAdcSubEventgR);
      instance.SetDestructor(&destruct_vectorlEAdcSubEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<AdcSubEvent> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<AdcSubEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEAdcSubEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<AdcSubEvent>*)0x0)->GetClass();
      vectorlEAdcSubEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEAdcSubEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEAdcSubEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<AdcSubEvent> : new vector<AdcSubEvent>;
   }
   static void *newArray_vectorlEAdcSubEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<AdcSubEvent>[nElements] : new vector<AdcSubEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEAdcSubEventgR(void *p) {
      delete ((vector<AdcSubEvent>*)p);
   }
   static void deleteArray_vectorlEAdcSubEventgR(void *p) {
      delete [] ((vector<AdcSubEvent>*)p);
   }
   static void destruct_vectorlEAdcSubEventgR(void *p) {
      typedef vector<AdcSubEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<AdcSubEvent>

namespace ROOT {
   static TClass *vectorlEAdcModulegR_Dictionary();
   static void vectorlEAdcModulegR_TClassManip(TClass*);
   static void *new_vectorlEAdcModulegR(void *p = 0);
   static void *newArray_vectorlEAdcModulegR(Long_t size, void *p);
   static void delete_vectorlEAdcModulegR(void *p);
   static void deleteArray_vectorlEAdcModulegR(void *p);
   static void destruct_vectorlEAdcModulegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<AdcModule>*)
   {
      vector<AdcModule> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<AdcModule>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<AdcModule>", -2, "vector", 458,
                  typeid(vector<AdcModule>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEAdcModulegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<AdcModule>) );
      instance.SetNew(&new_vectorlEAdcModulegR);
      instance.SetNewArray(&newArray_vectorlEAdcModulegR);
      instance.SetDelete(&delete_vectorlEAdcModulegR);
      instance.SetDeleteArray(&deleteArray_vectorlEAdcModulegR);
      instance.SetDestructor(&destruct_vectorlEAdcModulegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<AdcModule> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<AdcModule>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEAdcModulegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<AdcModule>*)0x0)->GetClass();
      vectorlEAdcModulegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEAdcModulegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEAdcModulegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<AdcModule> : new vector<AdcModule>;
   }
   static void *newArray_vectorlEAdcModulegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<AdcModule>[nElements] : new vector<AdcModule>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEAdcModulegR(void *p) {
      delete ((vector<AdcModule>*)p);
   }
   static void deleteArray_vectorlEAdcModulegR(void *p) {
      delete [] ((vector<AdcModule>*)p);
   }
   static void destruct_vectorlEAdcModulegR(void *p) {
      typedef vector<AdcModule> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<AdcModule>

namespace ROOT {
   static TClass *vectorlEAdcDatagR_Dictionary();
   static void vectorlEAdcDatagR_TClassManip(TClass*);
   static void *new_vectorlEAdcDatagR(void *p = 0);
   static void *newArray_vectorlEAdcDatagR(Long_t size, void *p);
   static void delete_vectorlEAdcDatagR(void *p);
   static void deleteArray_vectorlEAdcDatagR(void *p);
   static void destruct_vectorlEAdcDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<AdcData>*)
   {
      vector<AdcData> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<AdcData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<AdcData>", -2, "vector", 458,
                  typeid(vector<AdcData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEAdcDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<AdcData>) );
      instance.SetNew(&new_vectorlEAdcDatagR);
      instance.SetNewArray(&newArray_vectorlEAdcDatagR);
      instance.SetDelete(&delete_vectorlEAdcDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEAdcDatagR);
      instance.SetDestructor(&destruct_vectorlEAdcDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<AdcData> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<AdcData>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEAdcDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<AdcData>*)0x0)->GetClass();
      vectorlEAdcDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEAdcDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEAdcDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<AdcData> : new vector<AdcData>;
   }
   static void *newArray_vectorlEAdcDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<AdcData>[nElements] : new vector<AdcData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEAdcDatagR(void *p) {
      delete ((vector<AdcData>*)p);
   }
   static void deleteArray_vectorlEAdcDatagR(void *p) {
      delete [] ((vector<AdcData>*)p);
   }
   static void destruct_vectorlEAdcDatagR(void *p) {
      typedef vector<AdcData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<AdcData>

namespace {
  void TriggerDictionaryInitialization_MBEventBuilderDictionary_Impl() {
    static const char* headers[] = {
"BuiltEvent.hh",
"Datas.hh",
"EventBuffer.hh",
"EventBuilder.hh",
"GlobalSettings.hh",
"Modules.hh",
"SubEvents.hh",
"UnpackedEvent.hh",
"Calibration.hh",
"ParticleRange.hh",
"../mbevts/mbevts.hh",
0
    };
    static const char* includePaths[] = {
"./med/inc",
"../common",
"/opt/local/libexec/root6/include/root",
"/Users/dacox/work/SPEDE/CERN_SPEDE/SPEDE-version-20170321/MedToRoot/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "MBEventBuilderDictionary dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$GlobalSettings.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  GlobalSettings;
class __attribute__((annotate("$clingAutoload$SubEvents.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  DgfSubEvent;
class __attribute__((annotate("$clingAutoload$SubEvents.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  AdcSubEvent;
class __attribute__((annotate("$clingAutoload$SubEvents.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  PatternUnitSubEvent;
class __attribute__((annotate("$clingAutoload$SubEvents.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  ScalerSubEvent;
class __attribute__((annotate("$clingAutoload$SubEvents.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  DgfScalerSubEvent;
class __attribute__((annotate("$clingAutoload$SubEvents.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  BraggChamberSubEvent;
class __attribute__((annotate("$clingAutoload$Datas.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  AdcData;
class __attribute__((annotate("$clingAutoload$Datas.hh")))  __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  DgfData;
class __attribute__((annotate("$clingAutoload$BuiltEvent.hh")))  BuiltEvent;
class __attribute__((annotate("$clingAutoload$Modules.hh")))  __attribute__((annotate("$clingAutoload$EventBuffer.hh")))  DgfModule;
class __attribute__((annotate("$clingAutoload$Modules.hh")))  __attribute__((annotate("$clingAutoload$EventBuffer.hh")))  AdcModule;
class __attribute__((annotate("$clingAutoload$Modules.hh")))  __attribute__((annotate("$clingAutoload$EventBuffer.hh")))  PatternUnit;
class __attribute__((annotate("$clingAutoload$Modules.hh")))  __attribute__((annotate("$clingAutoload$EventBuffer.hh")))  SISScaler;
class __attribute__((annotate("$clingAutoload$Modules.hh")))  __attribute__((annotate("$clingAutoload$EventBuffer.hh")))  DgfScaler;
class __attribute__((annotate("$clingAutoload$Modules.hh")))  __attribute__((annotate("$clingAutoload$EventBuffer.hh")))  BraggChamber;
class __attribute__((annotate("$clingAutoload$EventBuffer.hh")))  EventBuffer;
class __attribute__((annotate("$clingAutoload$UnpackedEvent.hh")))  __attribute__((annotate("$clingAutoload$EventBuilder.hh")))  UnpackedEvent;
class __attribute__((annotate("$clingAutoload$EventBuilder.hh")))  EventBuilder;
class __attribute__((annotate("$clingAutoload$Calibration.hh")))  Calibration;
class __attribute__((annotate("$clingAutoload$../mbevts/mbevts.hh")))  mbevts;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "MBEventBuilderDictionary dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "BuiltEvent.hh"
#include "Datas.hh"
#include "EventBuffer.hh"
#include "EventBuilder.hh"
#include "GlobalSettings.hh"
#include "Modules.hh"
#include "SubEvents.hh"
#include "UnpackedEvent.hh"
#include "Calibration.hh"
#include "ParticleRange.hh"
#include "../mbevts/mbevts.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"AdcData", payloadCode, "@",
"AdcModule", payloadCode, "@",
"AdcSubEvent", payloadCode, "@",
"BraggChamber", payloadCode, "@",
"BraggChamberSubEvent", payloadCode, "@",
"BuiltEvent", payloadCode, "@",
"Calibration", payloadCode, "@",
"DgfData", payloadCode, "@",
"DgfModule", payloadCode, "@",
"DgfScaler", payloadCode, "@",
"DgfScalerSubEvent", payloadCode, "@",
"DgfSubEvent", payloadCode, "@",
"EventBuffer", payloadCode, "@",
"EventBuilder", payloadCode, "@",
"GlobalSettings", payloadCode, "@",
"PatternUnit", payloadCode, "@",
"PatternUnitSubEvent", payloadCode, "@",
"SISScaler", payloadCode, "@",
"ScalerSubEvent", payloadCode, "@",
"UnpackedEvent", payloadCode, "@",
"mbevts", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("MBEventBuilderDictionary",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_MBEventBuilderDictionary_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_MBEventBuilderDictionary_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_MBEventBuilderDictionary() {
  TriggerDictionaryInitialization_MBEventBuilderDictionary_Impl();
}
