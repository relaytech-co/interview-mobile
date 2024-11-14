/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCBarcode;
@class SDCTrackedBarcode;
@class SDCTargetBarcode;

/**
 * Added in version 6.15.0
 *
 * The capture list session contains all the barcodes recognised so far, and how they match against the target list.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountCaptureListSession)
@interface SDCBarcodeCountCaptureListSession : NSObject

/**
 * Added in version 6.15.0
 *
 * A list of tracked barcodes that have been correctly matched to the target data provided in the list.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *correctBarcodes;
/**
 * Added in version 6.15.0
 *
 * A list of tracked barcodes that have been correctly scanned, but that don’t match any of the ones provided in the list.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *wrongBarcodes;
/**
 * Added in version 6.15.0
 *
 * A list of the barcodes in the target list that have not yet been correctly scanned. If no list was provided to SDCBarcodeCountCaptureList, this list will be empty.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCTargetBarcode *> *missingBarcodes;
/**
 * Added in version 6.28.0
 *
 * A list of tracked barcodes that have been marked as accepted.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *acceptedBarcodes;
/**
 * Added in version 6.28.0
 *
 * A list of tracked barcodes that have been marked as rejected.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *rejectedBarcodes;

/**
 * Added in version 6.16.0
 *
 * The array of additional barcodes injected with SDCBarcodeCount.setAdditionalBarcodes:.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCBarcode *> *additionalBarcodes;
/**
 * Added in version 6.17.0
 *
 * Returns the JSON representation of the barcode count capture list session.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
