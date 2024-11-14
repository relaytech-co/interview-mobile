#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "SDCBarcodeCountViewDefaults.h"
#import "SDCBarcodeCountDeserializer+Private.h"
#import "SDCBarcodeCountDeserializerDelegate.h"
#import "SDCBarcodePickSettingsDefaults.h"
#import "SDCBarcodePickViewSettingsDefaults.h"
#import "ScanditFrameworksBarcode-Bridging-Header.h"
#import "SDCSparkScanViewDefaults.h"

FOUNDATION_EXPORT double ScanditFrameworksBarcodeVersionNumber;
FOUNDATION_EXPORT const unsigned char ScanditFrameworksBarcodeVersionString[];

