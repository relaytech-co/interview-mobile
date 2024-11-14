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
NS_SWIFT_NAME(BarcodeCountStatusErrorResult)
@interface SDCBarcodeCountStatusErrorResult : SDCBarcodeCountStatusResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.17.0
 *
 * Creator method that constructs a SDCBarcodeCountStatusResult representing an error when retrieving the status for the required barcodes. errorMessage will be presented to the user after successfully enabling status mode, and statusModeDisabledMessage will be displayed when exiting it.
 */
- (instancetype)initWithStatusList:(NSArray<SDCBarcodeCountStatusItem *> *)statusList
                      errorMessage:(nullable NSString *)errorMessage
         statusModeDisabledMessage:(nullable NSString *)statusModeDisabledMessage;

@end

NS_ASSUME_NONNULL_END
