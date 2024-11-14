/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditBarcodeCapture/SDCBarcodeCountStatusProviderCallback.h>
#import <ScanditBarcodeCapture/SDCTrackedBarcode.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * When enabling status mode, an instance of this protocol must be provided.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountStatusProvider)
@protocol SDCBarcodeCountStatusProvider <NSObject>

@required

/**
 * Added in version 6.17.0
 *
 * This method will be called when the status for a group of barcodes is required. The implementation must call the callback to provide the status list.
 */
- (void)statusRequestedForBarcodes:(NSArray<SDCTrackedBarcode *> *)barcodes
                          callback:(SDCBarcodeCountStatusProviderCallback *)callback;

@end

NS_ASSUME_NONNULL_END
