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
 * Added in version 6.8.0
 *
 * The SparkScan session is responsible for determining the list of relevant barcodes by filtering out duplicates. This filtering of duplicates is completely time-based and does not use any information about the location of the barcode. By default, all the codes scanned in a frame are always reported. It is possible to filter out codes recently scanned by changing SDCSparkScanSettings.codeDuplicateFilter.
 *
 * When the SparkScan mode is disabled, the session’s duplicate filter is reset.
 *
 * The SparkScan session should only be accessed from within sparkScan:didScanInSession:frameData: or sparkScan:didUpdateSession:frameData: and from the thread these methods are called from. It is not safe to be accessed from anywhere else since it may be concurrently modified.
 *
 * Specifically no reference to newlyRecognizedBarcodes should be kept and traversed outside of sparkScan:didScanInSession:frameData: or sparkScan:didUpdateSession:frameData:. Instead a copy of the lists should be made to avoid concurrent modification. The individual barcodes can be referenced without copying as they are not further modified.
 */
NS_SWIFT_NAME(SparkScanSession)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanSession : NSObject

/**
 * Added in version 6.26.0
 *
 * Last newly recognized barcode in the last processed frame.
 */
@property (nonatomic, nullable, readonly) SDCBarcode *newlyRecognizedBarcode;
/**
 * Added in version 6.8.0
 *
 * List of codes that were newly recognized in the last processed frame.
 *
 * Deprecated since version 6.26.0: Prefer use of newlyRecognizedBarcode instead.
 */
@property (nonatomic, nonnull, readonly)
    NSArray<SDCBarcode *> *newlyRecognizedBarcodes DEPRECATED_MSG_ATTRIBUTE(
        "Use newlyRecognizedBarcode instead.");
/**
 * Added in version 6.8.0
 *
 * The identifier of the current frame sequence.
 *
 * As long as there is no interruption of frames coming from the camera, the frameSequenceId will stay the same. Note that every time target mode is switched on or off, this number will change.
 */
@property (nonatomic, readonly) NSInteger frameSequenceId;
/**
 * Added in version 6.8.0
 *
 * Returns the JSON representation of the SparkScan session.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.8.0
 *
 * Resets the SparkScan session, effectively clearing the history of scanned codes. This affects duplicate filtering: when calling reset every frame has the same effect as setting the SDCSparkScanSettings.codeDuplicateFilter to 0. This function should only be called inside the listeners’ callback.
 */
- (void)reset;

@end

NS_ASSUME_NONNULL_END
