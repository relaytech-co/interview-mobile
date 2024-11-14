/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCBarcodePickSession;

/**
 * Added in version 6.23.0
 *
 * A listener that will be called every frame.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickListener)
@protocol SDCBarcodePickListener <NSObject>

@optional

/**
 * Added in version 6.23.0
 *
 * This method will be called every time a frame is processed. An updated session object is passed.
 */
- (void)barcodePick:(SDCBarcodePick *)barcodePick didUpdateSession:(SDCBarcodePickSession *)session;

@end

NS_ASSUME_NONNULL_END
