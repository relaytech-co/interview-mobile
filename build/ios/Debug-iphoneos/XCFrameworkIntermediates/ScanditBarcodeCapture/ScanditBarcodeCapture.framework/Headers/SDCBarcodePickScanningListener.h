/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCBarcodePickScanningSession;

/**
 * Added in version 6.21.0
 *
 * Will be notified when a scanning session is updated.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickScanningListener)
@protocol SDCBarcodePickScanningListener <NSObject>

@optional

/**
 * Added in version 6.21.0
 *
 * This method will be called whenever an item is picked or unpicked or new items scanned.
 */
- (void)barcodePick:(SDCBarcodePick *)barcodePick
    didUpdateScanningSession:(SDCBarcodePickScanningSession *)scanningSession;
/**
 * Added in version 6.21.0
 *
 * This method will be called when scanning session is completed (i.e. when SDCBarcodePickView.stop is called).
 */
- (void)barcodePick:(SDCBarcodePick *)barcodePick
    didCompleteScanningSession:(SDCBarcodePickScanningSession *)scanningSession;

@end

NS_ASSUME_NONNULL_END
