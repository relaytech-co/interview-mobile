/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCBrush.h>
#import <ScanditBarcodeCapture/SDCBarcodeFilterHighlightType.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeFilterHighlightSettings)
@protocol SDCBarcodeFilterHighlightSettings <NSObject>

/**
 * Added in version 6.15.0
 *
 * Returns the SDCBrush applied to filtered barcodes when highlightType is set to SDCBarcodeFilterHighlightTypeBrush.
 */
@property (nonatomic, nullable, readonly) SDCBrush *brush;
/**
 * Added in version 6.15.0
 *
 * Returns the type of highlight that will be applied to filtered barcodes.
 */
@property (nonatomic, readonly) SDCBarcodeFilterHighlightType highlightType;

@end

NS_ASSUME_NONNULL_END
