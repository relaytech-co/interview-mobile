/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeCountStatus.h>

@class SDCTrackedBarcode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * A class that stores a SDCTrackedBarcode alongside its associated status.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountStatusItem)
@interface SDCBarcodeCountStatusItem : NSObject

/**
 * Added in version 6.17.0
 *
 * The status associated to the barcode.
 */
@property (nonatomic, assign, readonly) SDCBarcodeCountStatus status;
/**
 * Added in version 6.17.0
 *
 * The tracked barcode.
 */
@property (nonatomic, strong, readonly) SDCTrackedBarcode *barcode;

/**
 * Added in version 6.17.0
 *
 * Constructs a new barcode count status item.
 */
- (instancetype)initWithBarcode:(SDCTrackedBarcode *)barcode status:(SDCBarcodeCountStatus)status;

@end

NS_ASSUME_NONNULL_END
