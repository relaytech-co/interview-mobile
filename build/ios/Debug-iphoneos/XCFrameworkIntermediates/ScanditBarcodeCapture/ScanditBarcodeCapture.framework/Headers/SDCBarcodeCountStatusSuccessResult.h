/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeCountStatusResult.h>
#import <ScanditBarcodeCapture/SDCBarcodeCountStatusItem.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.17.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountStatusSuccessResult)
@interface SDCBarcodeCountStatusSuccessResult : SDCBarcodeCountStatusResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.17.0
 *
 * Creator method that constructs a SDCBarcodeCountStatusResult representing success when retrieving the status for the required barcodes. statusModeEnabledMessage will be presented to the user after successfully enabling status mode, and statusModeDisabledMessage will be displayed when exiting it.
 */
- (instancetype)initWithStatusList:(NSArray<SDCBarcodeCountStatusItem *> *)statusList
          statusModeEnabledMessage:(nullable NSString *)statusModeEnabledMessage
         statusModeDisabledMessage:(nullable NSString *)statusModeDisabledMessage;

@end

NS_ASSUME_NONNULL_END
