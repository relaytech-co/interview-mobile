/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * These settings are used to select barcodes that will be filtered out in the view. Any barcode that matches any of the provided settings will be covered by a colored layer.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeFilterSettings)
@interface SDCBarcodeFilterSettings : NSObject

/**
 * Added in version 6.15.0
 *
 * A map of excluded symbol counts, indexed by SDCSymbology. Each SDCSymbology will have assigned a set of all the character counts for the barcode’s NSData that will be matched.
 */
@property (nonatomic, strong)
    NSDictionary<NSNumber *, NSSet<NSNumber *> *> *excludedSymbolCounts NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.15.0
 *
 * A regular expression to be matched against NSData.
 */
@property (nonatomic, strong) NSString *excludedCodesRegex;
/**
 * Added in version 6.15.0
 *
 * A set of SDCSymbology to exclude. If an excluded SDCSymbology is not part of the set of active symbologies in the mode, this setting will have no effect on that Symbology.
 */
@property (nonatomic, strong) NSSet<NSNumber *> *excludedSymbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.15.0
 *
 * When set to YES, EAN 13 barcodes will be excluded.
 */
@property (nonatomic) BOOL excludeEAN13;
/**
 * Added in version 6.15.0
 *
 * When set to YES, UPC-A barcodes will be excluded.
 */
@property (nonatomic) BOOL excludeUPCA;

@end

NS_ASSUME_NONNULL_END
