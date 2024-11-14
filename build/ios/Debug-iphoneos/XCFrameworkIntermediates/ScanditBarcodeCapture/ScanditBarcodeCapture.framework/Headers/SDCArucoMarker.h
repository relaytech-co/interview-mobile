/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.19.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(ArucoMarker)
@interface SDCArucoMarker : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.19.0
 *
 * The size of the ArucoMarker.
 */
@property (nonatomic, readonly) NSInteger size;
/**
 * Added in version 6.19.0
 *
 * The data of the ArucoMarker.
 */
@property (nonatomic, nonnull, readonly) NSData *data;

/**
 * Added in version 6.19.0
 *
 * Constructs an ArUco marker definition. Used to create a custom SDCArucoDictionary.
 *
 *   • markerSize is the length of the side of the barcode. For a 5 by 5 marker it will be 5.
 *
 *   • markerData is the data used to build the marker. It needs to contain only the values 0 or 1 as 8-bit values. The order is row major. For a 5 by 5 marker it needs to contain 25 bytes.
 *
 * @code
 * let data = Data([0, 1, 0, .... 1, 1]) // Contains 25 values
 * let marker = ArucoMarker(markerSize: 5, markerData: data)
 * @endcode
 */
- (instancetype)initWithMarkerSize:(NSUInteger)markerSize markerData:(NSData *)markerData;

@end

NS_ASSUME_NONNULL_END
