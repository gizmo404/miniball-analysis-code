// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME g_clx_dict

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
#include "../mbevts/mbevts.hh"
#include "doppler.hh"
#include "hists.hh"
#include "MBGeometry.hh"
#include "SpedeGeometry.hh"

// Header files passed via #pragma extra_include

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

namespace ROOT {
   static void *new_doppler(void *p = 0);
   static void *newArray_doppler(Long_t size, void *p);
   static void delete_doppler(void *p);
   static void deleteArray_doppler(void *p);
   static void destruct_doppler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::doppler*)
   {
      ::doppler *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::doppler >(0);
      static ::ROOT::TGenericClassInfo 
         instance("doppler", ::doppler::Class_Version(), "doppler.hh", 27,
                  typeid(::doppler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::doppler::Dictionary, isa_proxy, 4,
                  sizeof(::doppler) );
      instance.SetNew(&new_doppler);
      instance.SetNewArray(&newArray_doppler);
      instance.SetDelete(&delete_doppler);
      instance.SetDeleteArray(&deleteArray_doppler);
      instance.SetDestructor(&destruct_doppler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::doppler*)
   {
      return GenerateInitInstanceLocal((::doppler*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::doppler*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *hists_Dictionary();
   static void hists_TClassManip(TClass*);
   static void *new_hists(void *p = 0);
   static void *newArray_hists(Long_t size, void *p);
   static void delete_hists(void *p);
   static void deleteArray_hists(void *p);
   static void destruct_hists(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::hists*)
   {
      ::hists *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::hists));
      static ::ROOT::TGenericClassInfo 
         instance("hists", "hists.hh", 26,
                  typeid(::hists), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &hists_Dictionary, isa_proxy, 4,
                  sizeof(::hists) );
      instance.SetNew(&new_hists);
      instance.SetNewArray(&newArray_hists);
      instance.SetDelete(&delete_hists);
      instance.SetDeleteArray(&deleteArray_hists);
      instance.SetDestructor(&destruct_hists);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::hists*)
   {
      return GenerateInitInstanceLocal((::hists*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::hists*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *hists_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::hists*)0x0)->GetClass();
      hists_TClassManip(theClass);
   return theClass;
   }

   static void hists_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MBGeometry_Dictionary();
   static void MBGeometry_TClassManip(TClass*);
   static void *new_MBGeometry(void *p = 0);
   static void *newArray_MBGeometry(Long_t size, void *p);
   static void delete_MBGeometry(void *p);
   static void deleteArray_MBGeometry(void *p);
   static void destruct_MBGeometry(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MBGeometry*)
   {
      ::MBGeometry *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MBGeometry));
      static ::ROOT::TGenericClassInfo 
         instance("MBGeometry", "MBGeometry.hh", 24,
                  typeid(::MBGeometry), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MBGeometry_Dictionary, isa_proxy, 4,
                  sizeof(::MBGeometry) );
      instance.SetNew(&new_MBGeometry);
      instance.SetNewArray(&newArray_MBGeometry);
      instance.SetDelete(&delete_MBGeometry);
      instance.SetDeleteArray(&deleteArray_MBGeometry);
      instance.SetDestructor(&destruct_MBGeometry);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MBGeometry*)
   {
      return GenerateInitInstanceLocal((::MBGeometry*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MBGeometry*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MBGeometry_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MBGeometry*)0x0)->GetClass();
      MBGeometry_TClassManip(theClass);
   return theClass;
   }

   static void MBGeometry_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpedeGeometry_Dictionary();
   static void SpedeGeometry_TClassManip(TClass*);
   static void *new_SpedeGeometry(void *p = 0);
   static void *newArray_SpedeGeometry(Long_t size, void *p);
   static void delete_SpedeGeometry(void *p);
   static void deleteArray_SpedeGeometry(void *p);
   static void destruct_SpedeGeometry(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpedeGeometry*)
   {
      ::SpedeGeometry *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpedeGeometry));
      static ::ROOT::TGenericClassInfo 
         instance("SpedeGeometry", "SpedeGeometry.hh", 21,
                  typeid(::SpedeGeometry), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SpedeGeometry_Dictionary, isa_proxy, 4,
                  sizeof(::SpedeGeometry) );
      instance.SetNew(&new_SpedeGeometry);
      instance.SetNewArray(&newArray_SpedeGeometry);
      instance.SetDelete(&delete_SpedeGeometry);
      instance.SetDeleteArray(&deleteArray_SpedeGeometry);
      instance.SetDestructor(&destruct_SpedeGeometry);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpedeGeometry*)
   {
      return GenerateInitInstanceLocal((::SpedeGeometry*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpedeGeometry*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpedeGeometry_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpedeGeometry*)0x0)->GetClass();
      SpedeGeometry_TClassManip(theClass);
   return theClass;
   }

   static void SpedeGeometry_TClassManip(TClass* ){
   }

} // end of namespace ROOT

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
atomic_TClass_ptr doppler::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *doppler::Class_Name()
{
   return "doppler";
}

//______________________________________________________________________________
const char *doppler::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::doppler*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int doppler::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::doppler*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *doppler::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::doppler*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *doppler::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::doppler*)0x0)->GetClass(); }
   return fgIsA;
}

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

//______________________________________________________________________________
void doppler::Streamer(TBuffer &R__b)
{
   // Stream an object of class doppler.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(doppler::Class(),this);
   } else {
      R__b.WriteClassBuffer(doppler::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_doppler(void *p) {
      return  p ? new(p) ::doppler : new ::doppler;
   }
   static void *newArray_doppler(Long_t nElements, void *p) {
      return p ? new(p) ::doppler[nElements] : new ::doppler[nElements];
   }
   // Wrapper around operator delete
   static void delete_doppler(void *p) {
      delete ((::doppler*)p);
   }
   static void deleteArray_doppler(void *p) {
      delete [] ((::doppler*)p);
   }
   static void destruct_doppler(void *p) {
      typedef ::doppler current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::doppler

namespace ROOT {
   // Wrappers around operator new
   static void *new_hists(void *p) {
      return  p ? new(p) ::hists : new ::hists;
   }
   static void *newArray_hists(Long_t nElements, void *p) {
      return p ? new(p) ::hists[nElements] : new ::hists[nElements];
   }
   // Wrapper around operator delete
   static void delete_hists(void *p) {
      delete ((::hists*)p);
   }
   static void deleteArray_hists(void *p) {
      delete [] ((::hists*)p);
   }
   static void destruct_hists(void *p) {
      typedef ::hists current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::hists

namespace ROOT {
   // Wrappers around operator new
   static void *new_MBGeometry(void *p) {
      return  p ? new(p) ::MBGeometry : new ::MBGeometry;
   }
   static void *newArray_MBGeometry(Long_t nElements, void *p) {
      return p ? new(p) ::MBGeometry[nElements] : new ::MBGeometry[nElements];
   }
   // Wrapper around operator delete
   static void delete_MBGeometry(void *p) {
      delete ((::MBGeometry*)p);
   }
   static void deleteArray_MBGeometry(void *p) {
      delete [] ((::MBGeometry*)p);
   }
   static void destruct_MBGeometry(void *p) {
      typedef ::MBGeometry current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MBGeometry

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpedeGeometry(void *p) {
      return  p ? new(p) ::SpedeGeometry : new ::SpedeGeometry;
   }
   static void *newArray_SpedeGeometry(Long_t nElements, void *p) {
      return p ? new(p) ::SpedeGeometry[nElements] : new ::SpedeGeometry[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpedeGeometry(void *p) {
      delete ((::SpedeGeometry*)p);
   }
   static void deleteArray_SpedeGeometry(void *p) {
      delete [] ((::SpedeGeometry*)p);
   }
   static void destruct_SpedeGeometry(void *p) {
      typedef ::SpedeGeometry current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpedeGeometry

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

namespace {
  void TriggerDictionaryInitialization_g_clx_dict_Impl() {
    static const char* headers[] = {
"../mbevts/mbevts.hh",
"doppler.hh",
"hists.hh",
"MBGeometry.hh",
"SpedeGeometry.hh",
0
    };
    static const char* includePaths[] = {
"./",
"/opt/local/libexec/root6/include/root",
"/Users/dacox/work/SPEDE/CERN_SPEDE/SPEDE-version-20170321/TreeAna/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "g_clx_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$../mbevts/mbevts.hh")))  mbevts;
class __attribute__((annotate("$clingAutoload$doppler.hh")))  doppler;
class __attribute__((annotate("$clingAutoload$hists.hh")))  hists;
class __attribute__((annotate("$clingAutoload$MBGeometry.hh")))  MBGeometry;
class __attribute__((annotate("$clingAutoload$SpedeGeometry.hh")))  SpedeGeometry;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "g_clx_dict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "../mbevts/mbevts.hh"
#include "doppler.hh"
#include "hists.hh"
#include "MBGeometry.hh"
#include "SpedeGeometry.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"MBGeometry", payloadCode, "@",
"SpedeGeometry", payloadCode, "@",
"doppler", payloadCode, "@",
"hists", payloadCode, "@",
"mbevts", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("g_clx_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_g_clx_dict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_g_clx_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_g_clx_dict() {
  TriggerDictionaryInitialization_g_clx_dict_Impl();
}
