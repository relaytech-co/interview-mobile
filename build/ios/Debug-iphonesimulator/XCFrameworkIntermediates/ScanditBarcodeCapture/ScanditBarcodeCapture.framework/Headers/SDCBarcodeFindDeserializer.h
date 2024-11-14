/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodeFind;
@class SDCBarcodeFindSettings;
@protocol SDCBarcodeFindDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.19.0
 *
 * A deserializer to construct barcode find settings from JSON.
 */
NS_SWIFT_NAME(BarcodeFindDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindDeserializer : NSObject

/**
 * Added in version 6.19.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeFindDeserializerDelegate> delegate;

/**
 * Added in version 6.19.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)barcodeFindDeserializer;

/**
 * Added in version 6.19.0
 *
 * Constructs a new barcode find settings object with the provided JSON serialization.
 */
- (nullable SDCBarcodeFindSettings *)settingsFromJSONString:(NSString *)JSONString
                                                      error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.19.0
 *
 * Updates the settings according to a JSON serialization.
 */
- (nullable SDCBarcodeFindSettings *)updateSettings:(SDCBarcodeFindSettings *)settings
                                     fromJSONString:(NSString *)JSONString
                                              error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.19.0
 *
 * Constructs a new barcode find object with the provided JSON serialization.
 */
- (nullable SDCBarcodeFind *)modeFromJSONString:(NSString *)JSONString
                                          error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.19.0
 *
 * Updates the mode according to a JSON serialization.
 */
- (nullable SDCBarcodeFind *)updateMode:(SDCBarcodeFind *)mode
                         fromJSONString:(NSString *)JSONString
                                  error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
