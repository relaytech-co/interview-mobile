/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcode;
@class SDCTrackedBarcode;
@class SDCBarcodeSpatialGrid;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.14.0
 *
 * The count session contains all the currently tracked barcodes and changes that were made specifically in the last processed frame.
 *
 * The count session should only be accessed from within barcodeCount:didScanInSession:frameData: to which it is provided as an argument. It is not safe to be accessed from anywhere else since it may be concurrently modified.
 *
 * Specifically no reference to recognizedBarcodes should be kept and traversed outside of barcodeCount:didScanInSession:frameData:. Instead a copy of the lists should be made to avoid concurrent modification. The individual tracked barcodes can be referenced without copying as they are not further modified.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountSession)
@interface SDCBarcodeCountSession : NSObject

/**
 * Added in version 6.14.0
 *
 * A map from identifiers to tracked barcodes. It contains all currently recognized barcodes.
 */
@property (nonatomic, nonnull, readonly)
    NSDictionary<NSNumber *, SDCTrackedBarcode *> *recognizedBarcodes NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.14.0
 *
 * The identifier of the current frame sequence.
 *
 * As long as there is no interruptions of frames coming from the camera, the frameSequenceId will stay the same.
 */
@property (nonatomic, readonly) NSInteger frameSequenceId;

/**
 * Added in version 6.16.0
 *
 * The array of additional barcodes injected with SDCBarcodeCount.setAdditionalBarcodes:.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCBarcode *> *additionalBarcodes;
/**
 * Added in version 6.17.0
 *
 * Returns the JSON representation of the barcode count session.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.14.0
 *
 * Resets the barcode count session, effectively clearing the history of recognized barcodes. This function should only be called inside the listeners’ callback.
 */
- (void)reset;

/**
 * Added in version 6.17.0
 *
 * Computes the spatial map with the current session data. If a value is returned by this method the scanning is automatically suspended.
 * Returns nil if SDCBarcodeCountSettings.mappingEnabled is NO.
 *
 * @remark The Barcode Count mapping API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
- (nullable SDCBarcodeSpatialGrid *)spatialMap;

/**
 * Added in version 6.17.0
 *
 * Computes the spatial map with the current session data, using the passed values as hints. If a value is returned by this method the scanning is automatically suspended.
 * Returns nil if SDCBarcodeCountSettings.mappingEnabled is NO.
 *
 * @remark The Barcode Count mapping API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
- (nullable SDCBarcodeSpatialGrid *)spatialMapWithExpectedNumberOfRows:(NSInteger)expectedNumberOfRows
                                               expectedNumberOfColumns:(NSInteger)expectedNumberOfColumns;

@end

NS_ASSUME_NONNULL_END
