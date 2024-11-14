/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeCountStatusResult.h>

@class SDCBarcodeCountStatusItem;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.17.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountStatusAbortResult)
@interface SDCBarcodeCountStatusAbortResult : SDCBarcodeCountStatusResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.17.0
 *
 * Creator method that constructs a SDCBarcodeCountStatusResult representing a critical failure when retrieving the status for the required barcodes. Will abort the status mode immediately, displaying errorMessage to the user.
 */
- (instancetype)initWithErrorMessage:(nullable NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
