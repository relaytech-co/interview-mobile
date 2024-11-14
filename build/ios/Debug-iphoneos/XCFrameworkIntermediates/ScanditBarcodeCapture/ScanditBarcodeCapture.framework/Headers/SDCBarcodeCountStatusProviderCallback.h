/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeCountStatusResult.h>
#import <ScanditBarcodeCapture/SDCBarcodeCountStatusSuccessResult.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * When BarcodeCount queries for a status list with SDCBarcodeCountStatusProvider.statusRequestedForBarcodes:callback:, an instance of this protocol is provided to inform BarcodeCount of the result.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountStatusProviderCallback)
@interface SDCBarcodeCountStatusProviderCallback : NSObject

/**
 * Added in version 6.17.0
 *
 * This method must be called with the SDCBarcodeCountStatusResult in order to enter status mode.
 */
- (void)onStatusReady:(SDCBarcodeCountStatusResult *)result;

@end

NS_ASSUME_NONNULL_END
