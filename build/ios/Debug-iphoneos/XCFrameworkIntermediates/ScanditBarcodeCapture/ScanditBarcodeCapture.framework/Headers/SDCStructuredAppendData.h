/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCEncodingRange;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * Structured append data associated with a barcode. returns the structured append data associated with this barcode. In structured append mode data is encoded across multiple 1D or 2D barcodes where each barcode contains only one segment of the complete data. Once all segment-containing barcodes are scanned the complete data can be read out.
 *
 * Only a few symbologies (pdf417, microPdf417, QR, DataMatrix, Aztec, DotCode, MaxiCode) can use this mode, and each has a different set of limitations, like included metadata or the maximum number of barcodes that can form a set.
 */
NS_SWIFT_NAME(StructuredAppendData)
SDC_EXPORTED_SYMBOL
@interface SDCStructuredAppendData : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.15.0
 *
 * Whether all the barcodes in this set have been scanned.
 */
@property (nonatomic, readonly) BOOL isComplete;
/**
 * Added in version 6.15.0
 *
 * The id of the barcode set.
 */
@property (nonatomic, nonnull, readonly) NSString *barcodeSetId;
/**
 * Added in version 6.15.0
 *
 * How many barcodes in the set have been scanned.
 */
@property (nonatomic, readonly) NSInteger scannedSegmentCount;
/**
 * Added in version 6.15.0
 *
 * How many barcodes belong to the set. Depending on the symbology this might not be available and reported as 0.
 */
@property (nonatomic, readonly) NSInteger totalSegmentCount;
/**
 * Added in version 6.15.0
 *
 * Array of encoding ranges. Each entry of the returned encoding array points into bytes of rawCompleteData and indicates what encoding is used for these bytes. This information can then be used to convert the bytes to unicode, or other representations. For most codes, a single encoding range covers the whole data, but certain 2d symbologies, such as SDCSymbologyQR allow to switch the encoding in the middle of the code.
 *
 * The returned encoding ranges are sorted from lowest to highest index. Each byte in rawCompleteData is contained in exactly one range, e.g. there are no holes or overlapping ranges.
 *
 * The encoding ranges array is only available when all of the barcodes/segments belonging to the set have been scanned and empty otherwise.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCEncodingRange *> *encodingRanges;
/**
 * Added in version 6.15.0
 *
 * String representation of the complete data. The complete data is only available when all of the barcodes/segments belonging to the set have been scanned.
 */
@property (nonatomic, nullable, readonly) NSString *completeData;
/**
 * Added in version 6.15.0
 *
 * The raw data contained in all of the scanned barcodes. The raw data is only available when all of the barcodes/segments belonging to the set have been scanned.
 *
 * Use this property instead of completeData if you are relying on binary-encoded data that cannot be represented as unicode strings.
 *
 * Unlike completeData which returns the data in Unicode representation, the rawCompleteData returns the data with the encoding that was used in the barcode. See encodingRanges for more information.
 */
@property (nonatomic, nullable, readonly) NSData *rawCompleteData;

@end

NS_ASSUME_NONNULL_END
