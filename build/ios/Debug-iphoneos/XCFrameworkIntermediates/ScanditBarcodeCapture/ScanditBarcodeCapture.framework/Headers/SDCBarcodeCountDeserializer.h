/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodeCount;
@class SDCBarcodeCountSettings;
@class SDCDataCaptureContext;
@class SDCBarcodeCount;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.16.0
 *
 * A deserializer to construct barcode count settings from JSON.
 */
NS_SWIFT_NAME(BarcodeCountDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCountDeserializer : NSObject

/**
 * Added in version 6.16.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)barcodeCountDeserializer;

/**
 * Added in version 6.17.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

/**
 * Added in version 6.16.0
 *
 * Constructs a new barcode count settings object with the provided JSON serialization.
 */
- (nullable SDCBarcodeCountSettings *)settingsFromJSONString:(NSString *)JSONString
                                                       error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.16.0
 *
 * Updates the settings according to a JSON serialization.
 */
- (nullable SDCBarcodeCountSettings *)updateSettings:(SDCBarcodeCountSettings *)settings
                                      fromJSONString:(NSString *)JSONString
                                               error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.17.0
 *
 * Constructs a new barcode count object with the provided JSON serialization.
 */
- (nullable SDCBarcodeCount *)modeFromJSONString:(NSString *)JSONString
                                         context:(SDCDataCaptureContext *)context
                                           error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.17.0
 *
 * Updates the mode according to a JSON serialization.
 */
- (nullable SDCBarcodeCount *)updateMode:(SDCBarcodeCount *)mode
                          fromJSONString:(NSString *)JSONString
                                   error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.18.0
 *
 * Updates the mode according to a JSON serialization, sets the mode to use the SDCDataCaptureContext instance passed as parameter.
 */
- (nullable SDCBarcodeCount *)updateMode:(SDCBarcodeCount *)mode
                          fromJSONString:(NSString *)JSONString
                                 context:(SDCDataCaptureContext *)context
                                   error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
