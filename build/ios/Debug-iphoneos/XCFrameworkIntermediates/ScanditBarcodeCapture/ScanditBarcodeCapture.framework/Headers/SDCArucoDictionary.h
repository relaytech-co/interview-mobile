/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

#import <ScanditBarcodeCapture/SDCArucoDictionaryPreset.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCArucoMarker;

/**
 * Added in version 6.19.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(ArucoDictionary)
@interface SDCArucoDictionary : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.19.0
 *
 * Constructs an SDCArucoDictionary using a preset.
 */
+ (instancetype)arucoDictionaryWithPreset:(SDCArucoDictionaryPreset)preset;

/**
 * Added in version 6.19.0
 *
 * Constructs an SDCArucoDictionary using custom data.
 *
 *   • markerSize is the length of the side of the barcode. For a 5 by 5 marker it will be 5.
 */
+ (nullable instancetype)arucoDictionaryWithMarkerSize:(NSUInteger)markerSize
                                               markers:(NSArray<SDCArucoMarker *> *)markers;

@end

NS_ASSUME_NONNULL_END
