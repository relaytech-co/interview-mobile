/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditBarcodeCapture/SDCBarcodeFilterHighlightSettings.h>

@class SDCBrush;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeFilterHighlightSettingsBrush)
@interface SDCBarcodeFilterHighlightSettingsBrush : NSObject <SDCBarcodeFilterHighlightSettings>

/**
 * Added in version 6.15.0
 *
 * Creates a new BarcodeFilterHighlightSettings instance with SDCBarcodeFilterHighlightTypeBrush type, with the specified brush.
 */
- (instancetype)initWithBrush:(SDCBrush *)brush;

@end

NS_ASSUME_NONNULL_END
