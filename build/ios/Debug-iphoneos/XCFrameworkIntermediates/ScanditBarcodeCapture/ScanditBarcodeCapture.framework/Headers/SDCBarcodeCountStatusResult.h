/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.17.0
 *
 * An object used to provide a status list when calling SDCBarcodeCountStatusProviderCallback.onStatusReady:. Cannot be instantiated directly, instead must be created using one of the creator methods SDCBarcodeCountStatusSuccessResult.initWithStatusList:statusModeEnabledMessage:statusModeDisabledMessage:, SDCBarcodeCountStatusErrorResult.initWithStatusList:errorMessage:statusModeDisabledMessage: or SDCBarcodeCountStatusAbortResult.initWithErrorMessage:.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountStatusResult)
@interface SDCBarcodeCountStatusResult : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end
