/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCQuadrilateral.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.10.0
 *
 * A class used to instantiate a tracked barcode with the specified information. Can be used to create TrackedBarcode mocks for unit testing.
 */
NS_SWIFT_NAME(TrackedBarcodeInfo)
SDC_EXPORTED_SYMBOL
@interface SDCTrackedBarcodeInfo : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.10.0
 */
- (instancetype)initWithSymbology:(SDCSymbology)symbology data:(nonnull NSString *)data;

/**
 * Added in version 6.10.0
 */
- (instancetype)initWithSymbology:(SDCSymbology)symbology
                             data:(nonnull NSString *)data
                         location:(SDCQuadrilateral)location;

/**
 * Added in version 6.10.0
 */
- (instancetype)initWithSymbology:(SDCSymbology)symbology
                             data:(nonnull NSString *)data
                         location:(SDCQuadrilateral)location
                       identifier:(NSInteger)identifier;

/**
 * Added in version 6.10.0
 *
 * The symbology of the barcode.
 */
@property (nonatomic, readonly) SDCSymbology symbology;
/**
 * Added in version 6.10.0
 *
 * The data of a barcode as a unicode string.
 */
@property (nonatomic, nonnull, readonly) NSString *data;
/**
 * Added in version 6.10.0
 *
 * The location of the code. For more info see TrackedBarcode.
 */
@property (nonatomic, readonly) SDCQuadrilateral location;
/**
 * Added in version 6.10.0
 */
@property (nonatomic, readonly) NSInteger identifier;

@end

NS_ASSUME_NONNULL_END
