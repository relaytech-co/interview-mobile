#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.9.2 (swiftlang-5.9.2.2.56 clang-1500.1.0.2.5)
#ifndef SCANDITFRAMEWORKSBARCODE_SWIFT_H
#define SCANDITFRAMEWORKSBARCODE_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
@import ScanditBarcodeCapture;
@import ScanditCaptureCore;
@import ScanditFrameworksCore;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="ScanditFrameworksBarcode",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode20BarcodeCaptureModule")
@interface BarcodeCaptureModule : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCDataCaptureContext;
@class NSString;
@class SDCDataCaptureView;

@interface BarcodeCaptureModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
- (BOOL)dataCaptureContextWithAddMode:(NSString * _Nonnull)modeJson error:(NSError * _Nullable * _Nullable)error;
- (void)dataCaptureContextWithRemoveMode:(NSString * _Nonnull)modeJson;
- (void)dataCaptureContextAllModeRemoved;
- (void)didDisposeDataCaptureContext;
- (BOOL)dataCaptureViewWithAddOverlay:(NSString * _Nonnull)overlayJson to:(SDCDataCaptureView * _Nonnull)view error:(NSError * _Nullable * _Nullable)error;
@end

@class SDCBarcodeCaptureDeserializer;
@class SDCBarcodeCapture;
@class SDCJSONValue;
@class SDCBarcodeCaptureSettings;
@class SDCBarcodeCaptureOverlay;

@interface BarcodeCaptureModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <SDCBarcodeCaptureDeserializerDelegate>
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer * _Nonnull)deserializer didStartDeserializingMode:(SDCBarcodeCapture * _Nonnull)mode fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer * _Nonnull)deserializer didFinishDeserializingMode:(SDCBarcodeCapture * _Nonnull)mode fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer * _Nonnull)deserializer didStartDeserializingSettings:(SDCBarcodeCaptureSettings * _Nonnull)settings fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer * _Nonnull)deserializer didFinishDeserializingSettings:(SDCBarcodeCaptureSettings * _Nonnull)settings fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer * _Nonnull)deserializer didStartDeserializingOverlay:(SDCBarcodeCaptureOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer * _Nonnull)deserializer didFinishDeserializingOverlay:(SDCBarcodeCaptureOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode18BarcodeCountModule")
@interface BarcodeCountModule : NSObject <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
- (void)didDisposeDataCaptureContext;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode17BarcodeFindModule")
@interface BarcodeFindModule : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface BarcodeFindModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
- (void)didDisposeDataCaptureContext;
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode22BarcodeGeneratorModule")
@interface BarcodeGeneratorModule : NSObject <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
- (void)didDisposeDataCaptureContext;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode13BarcodeModule")
@interface BarcodeModule : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode17BarcodePickModule")
@interface BarcodePickModule : NSObject <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
- (void)didDisposeDataCaptureContext;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode22BarcodeSelectionModule")
@interface BarcodeSelectionModule : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface BarcodeSelectionModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
- (BOOL)dataCaptureContextWithAddMode:(NSString * _Nonnull)modeJson error:(NSError * _Nullable * _Nullable)error;
- (void)dataCaptureContextWithRemoveMode:(NSString * _Nonnull)modeJson;
- (void)dataCaptureContextAllModeRemoved;
- (void)didDisposeDataCaptureContext;
- (BOOL)dataCaptureViewWithAddOverlay:(NSString * _Nonnull)overlayJson to:(SDCDataCaptureView * _Nonnull)view error:(NSError * _Nullable * _Nullable)error;
@end

@class SDCBarcodeSelectionDeserializer;
@class SDCBarcodeSelection;
@class SDCBarcodeSelectionSettings;
@class SDCBarcodeSelectionBasicOverlay;

@interface BarcodeSelectionModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <SDCBarcodeSelectionDeserializerDelegate>
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer * _Nonnull)deserializer didStartDeserializingMode:(SDCBarcodeSelection * _Nonnull)mode fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer * _Nonnull)deserializer didFinishDeserializingMode:(SDCBarcodeSelection * _Nonnull)mode fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer * _Nonnull)deserializer didStartDeserializingSettings:(SDCBarcodeSelectionSettings * _Nonnull)settings fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer * _Nonnull)deserializer didFinishDeserializingSettings:(SDCBarcodeSelectionSettings * _Nonnull)settings fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer * _Nonnull)deserializer didStartDeserializingBasicOverlay:(SDCBarcodeSelectionBasicOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer * _Nonnull)deserializer didFinishDeserializingBasicOverlay:(SDCBarcodeSelectionBasicOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode21BarcodeTrackingModule")
@interface BarcodeTrackingModule : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface BarcodeTrackingModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
- (BOOL)dataCaptureContextWithAddMode:(NSString * _Nonnull)modeJson error:(NSError * _Nullable * _Nullable)error;
- (void)dataCaptureContextWithRemoveMode:(NSString * _Nonnull)modeJson;
- (void)dataCaptureContextAllModeRemoved;
- (void)didDisposeDataCaptureContext;
- (BOOL)dataCaptureViewWithAddOverlay:(NSString * _Nonnull)overlayJson to:(SDCDataCaptureView * _Nonnull)view error:(NSError * _Nullable * _Nullable)error;
@end

@class SDCBarcodeTrackingDeserializer;
@class SDCBarcodeTracking;
@class SDCBarcodeTrackingSettings;
@class SDCBarcodeTrackingBasicOverlay;
@class SDCBarcodeTrackingAdvancedOverlay;

@interface BarcodeTrackingModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <SDCBarcodeTrackingDeserializerDelegate>
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didStartDeserializingMode:(SDCBarcodeTracking * _Nonnull)mode fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didFinishDeserializingMode:(SDCBarcodeTracking * _Nonnull)mode fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didStartDeserializingSettings:(SDCBarcodeTrackingSettings * _Nonnull)settings fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didFinishDeserializingSettings:(SDCBarcodeTrackingSettings * _Nonnull)settings fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didStartDeserializingBasicOverlay:(SDCBarcodeTrackingBasicOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didFinishDeserializingBasicOverlay:(SDCBarcodeTrackingBasicOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didStartDeserializingAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer * _Nonnull)deserializer didFinishDeserializingAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay * _Nonnull)overlay fromJSONValue:(SDCJSONValue * _Nonnull)jsonValue;
@end

@class SDCBarcodeCaptureSession;
@protocol SDCFrameData;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode32FrameworksBarcodeCaptureListener")
@interface FrameworksBarcodeCaptureListener : NSObject <SDCBarcodeCaptureListener>
- (void)barcodeCapture:(SDCBarcodeCapture * _Nonnull)barcodeCapture didScanInSession:(SDCBarcodeCaptureSession * _Nonnull)session frameData:(id <SDCFrameData> _Nonnull)frameData;
- (void)barcodeCapture:(SDCBarcodeCapture * _Nonnull)barcodeCapture didUpdateSession:(SDCBarcodeCaptureSession * _Nonnull)session frameData:(id <SDCFrameData> _Nonnull)frameData;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodeCountCaptureList;
@class SDCBarcodeCountCaptureListSession;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode41FrameworksBarcodeCountCaptureListListener")
@interface FrameworksBarcodeCountCaptureListListener : NSObject <SDCBarcodeCountCaptureListListener>
- (void)captureList:(SDCBarcodeCountCaptureList * _Nonnull)captureList didUpdateSession:(SDCBarcodeCountCaptureListSession * _Nonnull)session;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodeCount;
@class SDCBarcodeCountSession;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode30FrameworksBarcodeCountListener")
@interface FrameworksBarcodeCountListener : NSObject <SDCBarcodeCountListener>
- (void)barcodeCount:(SDCBarcodeCount * _Nonnull)barcodeCount didScanInSession:(SDCBarcodeCountSession * _Nonnull)session frameData:(id <SDCFrameData> _Nonnull)frameData;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodeCountView;
@class SDCTrackedBarcode;
@class SDCBrush;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode34FrameworksBarcodeCountViewListener")
@interface FrameworksBarcodeCountViewListener : NSObject <SDCBarcodeCountViewDelegate>
- (SDCBrush * _Nullable)barcodeCountView:(SDCBarcodeCountView * _Nonnull)view brushForRecognizedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode SWIFT_WARN_UNUSED_RESULT;
- (SDCBrush * _Nullable)barcodeCountView:(SDCBarcodeCountView * _Nonnull)view brushForRecognizedBarcodeNotInList:(SDCTrackedBarcode * _Nonnull)trackedBarcode SWIFT_WARN_UNUSED_RESULT;
- (SDCBrush * _Nullable)barcodeCountView:(SDCBarcodeCountView * _Nonnull)view brushForUnrecognizedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode SWIFT_WARN_UNUSED_RESULT;
- (void)barcodeCountView:(SDCBarcodeCountView * _Nonnull)view didTapRecognizedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode;
- (void)barcodeCountView:(SDCBarcodeCountView * _Nonnull)view didTapFilteredBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode;
- (void)barcodeCountView:(SDCBarcodeCountView * _Nonnull)view didTapRecognizedBarcodeNotInList:(SDCTrackedBarcode * _Nonnull)trackedBarcode;
- (void)barcodeCountView:(SDCBarcodeCountView * _Nonnull)view didTapUnrecognizedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode36FrameworksBarcodeCountViewUIListener")
@interface FrameworksBarcodeCountViewUIListener : NSObject <SDCBarcodeCountViewUIDelegate>
- (void)exitButtonTappedForBarcodeCountView:(SDCBarcodeCountView * _Nonnull)view;
- (void)listButtonTappedForBarcodeCountView:(SDCBarcodeCountView * _Nonnull)view;
- (void)singleScanButtonTappedForBarcodeCountView:(SDCBarcodeCountView * _Nonnull)view;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodeFind;
@class SDCBarcodeFindItem;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode29FrameworksBarcodeFindListener")
@interface FrameworksBarcodeFindListener : NSObject <SDCBarcodeFindListener>
- (void)barcodeFindDidStartSearch:(SDCBarcodeFind * _Nonnull)barcodeFind;
- (void)barcodeFind:(SDCBarcodeFind * _Nonnull)barcodeFind didPauseSearch:(NSSet<SDCBarcodeFindItem *> * _Nonnull)foundItems;
- (void)barcodeFind:(SDCBarcodeFind * _Nonnull)barcodeFind didStopSearch:(NSSet<SDCBarcodeFindItem *> * _Nonnull)foundItems;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode32FrameworksBarcodeFindTransformer")
@interface FrameworksBarcodeFindTransformer : NSObject <SDCBarcodeFindTransformer>
- (NSString * _Nullable)transformBarcodeData:(NSString * _Nonnull)data SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodeFindView;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode35FrameworksBarcodeFindViewUIListener")
@interface FrameworksBarcodeFindViewUIListener : NSObject <SDCBarcodeFindViewUIDelegate>
- (void)barcodeFindView:(SDCBarcodeFindView * _Nonnull)view didTapFinishButton:(NSSet<SDCBarcodeFindItem *> * _Nonnull)foundItems;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode35FrameworksBarcodePickActionListener")
@interface FrameworksBarcodePickActionListener : NSObject <SDCBarcodePickActionListener>
- (void)didPickItemWithData:(NSString * _Nonnull)data completionHandler:(void (^ _Nonnull)(BOOL))completionHandler;
- (void)didUnpickItemWithData:(NSString * _Nonnull)data completionHandler:(void (^ _Nonnull)(BOOL))completionHandler;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodePickProductProviderCallbackItem;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode55FrameworksBarcodePickAsyncMapperProductProviderCallback")
@interface FrameworksBarcodePickAsyncMapperProductProviderCallback : NSObject <SDCBarcodePickAsyncMapperProductProviderDelegate>
- (void)mapItems:(NSArray<NSString *> * _Nonnull)items completionHandler:(void (^ _Nonnull)(NSArray<SDCBarcodePickProductProviderCallbackItem *> * _Nonnull))completionHandler;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodePick;
@class SDCBarcodePickScanningSession;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode37FrameworksBarcodePickScanningListener")
@interface FrameworksBarcodePickScanningListener : NSObject <SDCBarcodePickScanningListener>
- (void)barcodePick:(SDCBarcodePick * _Nonnull)barcodePick didCompleteScanningSession:(SDCBarcodePickScanningSession * _Nonnull)scanningSession;
- (void)barcodePick:(SDCBarcodePick * _Nonnull)barcodePick didUpdateScanningSession:(SDCBarcodePickScanningSession * _Nonnull)scanningSession;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodePickView;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode33FrameworksBarcodePickViewListener")
@interface FrameworksBarcodePickViewListener : NSObject <SDCBarcodePickViewListener>
- (void)barcodePickViewDidFreezeScanning:(SDCBarcodePickView * _Nonnull)view;
- (void)barcodePickViewDidStopScanning:(SDCBarcodePickView * _Nonnull)view;
- (void)barcodePickViewDidPauseScanning:(SDCBarcodePickView * _Nonnull)view;
- (void)barcodePickViewDidStartScanning:(SDCBarcodePickView * _Nonnull)view;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode35FrameworksBarcodePickViewUiListener")
@interface FrameworksBarcodePickViewUiListener : NSObject <SDCBarcodePickViewUIDelegate>
- (void)barcodePickViewDidTapFinishButton:(SDCBarcodePickView * _Nonnull)view;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcode;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode44FrameworksBarcodeSelectionAimedBrushProvider")
@interface FrameworksBarcodeSelectionAimedBrushProvider : NSObject <SDCBarcodeSelectionBrushProvider>
- (SDCBrush * _Nullable)brushForBarcode:(SDCBarcode * _Nonnull)barcode SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodeSelectionSession;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode34FrameworksBarcodeSelectionListener")
@interface FrameworksBarcodeSelectionListener : NSObject <SDCBarcodeSelectionListener>
- (void)barcodeSelection:(SDCBarcodeSelection * _Nonnull)barcodeSelection didUpdateSelection:(SDCBarcodeSelectionSession * _Nonnull)session frameData:(id <SDCFrameData> _Nullable)frameData;
- (void)barcodeSelection:(SDCBarcodeSelection * _Nonnull)barcodeSelection didUpdateSession:(SDCBarcodeSelectionSession * _Nonnull)session frameData:(id <SDCFrameData> _Nullable)frameData;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode46FrameworksBarcodeSelectionTrackedBrushProvider")
@interface FrameworksBarcodeSelectionTrackedBrushProvider : NSObject <SDCBarcodeSelectionBrushProvider>
- (SDCBrush * _Nullable)brushForBarcode:(SDCBarcode * _Nonnull)barcode SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class UIView;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode48FrameworksBarcodeTrackingAdvancedOverlayListener")
@interface FrameworksBarcodeTrackingAdvancedOverlayListener : NSObject <SDCBarcodeTrackingAdvancedOverlayDelegate>
- (UIView * _Nullable)barcodeTrackingAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay * _Nonnull)overlay viewForTrackedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode SWIFT_WARN_UNUSED_RESULT;
- (SDCAnchor)barcodeTrackingAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay * _Nonnull)overlay anchorForTrackedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode SWIFT_WARN_UNUSED_RESULT;
- (SDCPointWithUnit)barcodeTrackingAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay * _Nonnull)overlay offsetForTrackedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC24ScanditFrameworksBarcode45FrameworksBarcodeTrackingBasicOverlayListener")
@interface FrameworksBarcodeTrackingBasicOverlayListener : NSObject <SDCBarcodeTrackingBasicOverlayDelegate>
- (SDCBrush * _Nullable)barcodeTrackingBasicOverlay:(SDCBarcodeTrackingBasicOverlay * _Nonnull)overlay brushForTrackedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode SWIFT_WARN_UNUSED_RESULT;
- (void)barcodeTrackingBasicOverlay:(SDCBarcodeTrackingBasicOverlay * _Nonnull)overlay didTapTrackedBarcode:(SDCTrackedBarcode * _Nonnull)trackedBarcode;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCBarcodeTrackingSession;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode33FrameworksBarcodeTrackingListener")
@interface FrameworksBarcodeTrackingListener : NSObject <SDCBarcodeTrackingListener>
- (void)barcodeTracking:(SDCBarcodeTracking * _Nonnull)barcodeTracking didUpdate:(SDCBarcodeTrackingSession * _Nonnull)session frameData:(id <SDCFrameData> _Nonnull)frameData;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCSparkScanBarcodeFeedback;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode35FrameworksSparkScanFeedbackDelegate")
@interface FrameworksSparkScanFeedbackDelegate : NSObject <SDCSparkScanFeedbackDelegate>
- (SDCSparkScanBarcodeFeedback * _Nullable)feedbackForBarcode:(SDCBarcode * _Nonnull)barcode SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCSparkScan;
@class SDCSparkScanSession;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode27FrameworksSparkScanListener")
@interface FrameworksSparkScanListener : NSObject <SDCSparkScanListener>
- (void)sparkScan:(SDCSparkScan * _Nonnull)sparkScan didScanInSession:(SDCSparkScanSession * _Nonnull)session frameData:(id <SDCFrameData> _Nullable)frameData;
- (void)sparkScan:(SDCSparkScan * _Nonnull)sparkScan didUpdateSession:(SDCSparkScanSession * _Nonnull)session frameData:(id <SDCFrameData> _Nullable)frameData;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class SDCSparkScanView;

SWIFT_CLASS("_TtC24ScanditFrameworksBarcode33FrameworksSparkScanViewUIListener")
@interface FrameworksSparkScanViewUIListener : NSObject <SDCSparkScanViewUIDelegate>
- (void)fastFindButtonTappedInView:(SDCSparkScanView * _Nonnull)view;
- (void)barcodeCountButtonTappedInView:(SDCSparkScanView * _Nonnull)view;
- (void)barcodeFindButtonTappedInView:(SDCSparkScanView * _Nonnull)view;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end




SWIFT_CLASS("_TtC24ScanditFrameworksBarcode15SparkScanModule")
@interface SparkScanModule : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface SparkScanModule (SWIFT_EXTENSION(ScanditFrameworksBarcode)) <DeserializationLifeCycleObserver>
- (void)dataCaptureContextWithDeserialized:(SDCDataCaptureContext * _Nullable)context;
@end

#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif
