/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCSparkScanView;
@class SDCDataCaptureContext;
@class SDCSparkScan;
@class SDCSparkScanViewSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.16.0
 *
 * A deserializer to construct SDCSparkScanView from JSON.
 */
NS_SWIFT_NAME(SparkScanViewDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanViewDeserializer : NSObject

/**
 * Added in version 6.16.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)sparkScanViewDeserializer;

/**
 * Added in version 6.16.0
 *
 * Deserializes SparkScan view from JSON.
 */
- (nullable SDCSparkScanView *)viewFromJSONString:(NSString *)JSONString
                                      withContext:(SDCDataCaptureContext *)context
                                             mode:(SDCSparkScan *)mode
                                       parentView:(UIView *)parentView
                                            error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.16.0
 *
 * Updates the mode according to a JSON serialization.
 */
- (nullable SDCSparkScanView *)updateView:(SDCSparkScanView *)sparkScanView
                           fromJSONString:(NSString *)JSONString
                                    error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
