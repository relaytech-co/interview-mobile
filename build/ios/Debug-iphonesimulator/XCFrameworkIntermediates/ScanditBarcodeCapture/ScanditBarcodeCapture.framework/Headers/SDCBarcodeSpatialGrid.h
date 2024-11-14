/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcode;
@class SDCCoordinate2D;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * Object that is returned by SDCBarcodeCountSession.spatialMap. Represents the result of mapping the barcodes in a grid.
 * Depending on the scanned barcodes the grid could be incomplete so for some coordinates the returned barcode could be nil.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeSpatialGrid)
@interface SDCBarcodeSpatialGrid : NSObject

/**
 * Added in version 6.17.0
 *
 * Returns the number of rows in the grid.
 */
@property (nonatomic, assign, readonly) NSInteger rows;
/**
 * Added in version 6.17.0
 *
 * Returns the number of columns in the grid.
 */
@property (nonatomic, assign, readonly) NSInteger columns;
/**
 * Added in version 6.19.0
 *
 * Returns the JSON representation of the spatial grid.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.17.0
 *
 * Returns the barcode at the specified coordinates. If there is no barcode nil is returned.
 */
- (nullable SDCBarcode *)barcodeAtRow:(NSUInteger)row column:(NSUInteger)column;
/**
 * Added in version 6.17.0
 *
 * Returns an array of Barcodes corresponding to the selected row.
 *
 * Missing barcodes in the row will be represented by NSNull.
 */
- (NSArray<SDCBarcode *> *)rowAtIndex:(NSUInteger)index;
/**
 * Added in version 6.17.0
 *
 * Returns an array of barcodes corresponding to the selected column.
 *
 * Missing barcodes in the column will be represented by NSNull.
 */
- (NSArray<SDCBarcode *> *)columnAtIndex:(NSUInteger)index;
/**
 * Added in version 6.17.0
 *
 * Returns the list of coordinates for a specific barcode.
 */
- (NSArray<SDCCoordinate2D *> *)coordinatesForBarcode:(SDCBarcode *)barcode;

@end

NS_ASSUME_NONNULL_END
