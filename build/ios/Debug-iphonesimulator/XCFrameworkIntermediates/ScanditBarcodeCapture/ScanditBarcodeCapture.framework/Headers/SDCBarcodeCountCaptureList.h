/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodeCountCaptureList;
@class SDCBarcodeCountCaptureListSession;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * The BarcodeCountCaptureList delegate is the main way for hooking into SDCBarcodeCountCaptureList. It provides a callback that is invoked when the state of target barcodes changes.
 */
NS_SWIFT_NAME(BarcodeCountCaptureListListener)
@protocol SDCBarcodeCountCaptureListListener <NSObject>

@required

/**
 * Added in version 6.15.0
 *
 * Called after a frame processed by SDCBarcodeCountCaptureList has caused the list to be updated.
 */
- (void)captureList:(SDCBarcodeCountCaptureList *)captureList
    didUpdateSession:(SDCBarcodeCountCaptureListSession *)session;

@optional

/**
 * Added in version 6.15.0
 *
 * Called when the listener starts observing the SDCBarcodeCountCaptureList instance.
 */
- (void)didStartObservingCaptureList:(SDCBarcodeCountCaptureList *)captureList;
/**
 * Added in version 6.15.0
 *
 * Called when the listener stops observing the SDCBarcodeCountCaptureList instance.
 */
- (void)didStopObservingCaptureList:(SDCBarcodeCountCaptureList *)captureList;
/**
 * Added in version 6.17.0
 *
 * Called after when all the barcodes in the SDCBarcodeCountCaptureList have been scanned.
 */
- (void)captureList:(SDCBarcodeCountCaptureList *)captureList
    didCompleteWithSession:(SDCBarcodeCountCaptureListSession *)session;

@end

@class SDCTargetBarcode;

/**
 * Added in version 6.15.0
 *
 * Component for SDCBarcodeCount that allows it to scan against a list of expected barcodes.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountCaptureList)
@interface SDCBarcodeCountCaptureList : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.15.0
 *
 * Constructs a new capture list component and sets an initial list of target barcodes to search for. This list may be null.
 */
- (instancetype)initWithListener:(id<SDCBarcodeCountCaptureListListener>)listener
                  targetBarcodes:(nullable NSSet<SDCTargetBarcode *> *)targetBarcodes;

@end
NS_ASSUME_NONNULL_END
