/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodeFindView;
@class SDCDataCaptureContext;
@class SDCBarcodeFind;
@class SDCBarcodeFindViewSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.19.0
 *
 * A deserializer to construct SDCBarcodeFindView instances from JSON.
 */
NS_SWIFT_NAME(BarcodeFindViewDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindViewDeserializer : NSObject

/**
 * Added in version 6.19.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)barcodeFindViewDeserializer;
/**
 * Added in version 6.19.0
 *
 * Constructs a new SDCBarcodeFindView with the provided JSON serialization.
 */
- (nullable SDCBarcodeFindView *)viewFromJSONString:(nonnull NSString *)JSONString
                                        withContext:(nonnull SDCDataCaptureContext *)context
                                               mode:(nonnull SDCBarcodeFind *)mode
                                         parentView:(nonnull UIView *)parentView
                                              error:(NSError **)error;
/**
 * Added in version 6.20.0
 *
 * Constructs a new SDCBarcodeFindView with the provided JSON serialization.
 * An optional topLayoutAnchor can be specified.
 */
- (nullable SDCBarcodeFindView *)viewFromJSONString:(nonnull NSString *)JSONString
                                        withContext:(nonnull SDCDataCaptureContext *)context
                                               mode:(nonnull SDCBarcodeFind *)mode
                                         parentView:(nonnull UIView *)parentView
                                    topLayoutAnchor:(nullable NSLayoutYAxisAnchor *)topLayoutAnchor
                                              error:(NSError **)error;
/**
 * Added in version 6.19.0
 *
 * Updates the view according to a JSON serialization.
 */
- (nullable SDCBarcodeFindView *)updateView:(nonnull SDCBarcodeFindView *)view
                             fromJSONString:(nonnull NSString *)JSONString
                                      error:(NSError **)error;
/**
 * Added in version 6.19.0
 *
 * Deserializes SDCBarcodeFindViewSettings from JSON.
 */
- (nullable SDCBarcodeFindViewSettings *)settingsFromJSONString:(NSString *)JSONString
                                                          error:
                                                              (NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
