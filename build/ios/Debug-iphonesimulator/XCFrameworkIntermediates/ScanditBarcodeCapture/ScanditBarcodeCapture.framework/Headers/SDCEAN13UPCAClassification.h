/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * Helper class to distinguish between UPC-A and EAN13 barcodes. Normally they are both returned as an SDCSymbologyEAN13UPCA because UPC-A codes are a subset of EAN-13 instead of an entirely separate symbology.
 */
NS_SWIFT_NAME(EAN13UPCAClassification)
SDC_EXPORTED_SYMBOL
@interface SDCEAN13UPCAClassification : NSObject

/**
 * Added in version 6.15.0
 *
 * Returns true if barcode is UPC-A.
 */
+ (BOOL)isUPCA:(nonnull SDCBarcode *)barcode;
/**
 * Added in version 6.15.0
 *
 * Returns true if barcode is EAN 13.
 */
+ (BOOL)isEAN13:(nonnull SDCBarcode *)barcode;

@end

NS_ASSUME_NONNULL_END
