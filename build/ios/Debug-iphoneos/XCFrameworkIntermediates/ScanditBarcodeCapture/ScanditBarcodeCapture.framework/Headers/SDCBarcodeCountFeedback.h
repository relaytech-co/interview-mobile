/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCFeedback;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.14.0
 *
 * Determines what feedback (vibration, sound) should be emitted when barcodes are scanned.
 *
 * The feedback is specified for each BarcodeCount instance separately and can be changed
 * through the feedback property by either modifying an existing instance of this class, or by assigning a new one.
 *
 * As of now, this class allows to configure the feedback that gets emitted when barcodes are read successfully, through the success property, and
 * a feedback that gets emitted when barcodes are not read successfully, through the failure property.
 *
 * See documentation on the SDCBarcodeCount.feedback property for usage samples.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountFeedback)
@interface SDCBarcodeCountFeedback : NSObject

/**
 * Added in version 6.14.0
 *
 * Returns a barcode count feedback with default configuration:
 *
 *   • default beep sound is loaded,
 *
 *   • beeping for the success event is enabled,
 *
 *   • vibration for the success event is enabled,
 *
 *   • beeping for the unrecognized event is enabled,
 *
 *   • vibration for the unrecognized event is enabled,
 *
 *   • beeping for the failure event is enabled,
 *
 *   • vibration for the failure event is enabled.
 */
@property (class, nonatomic, readonly) SDCBarcodeCountFeedback *defaultFeedback;

/**
 * Added in version 6.14.0
 *
 * A feedback for a success event.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *success;
/**
 * Added in version 6.17.0
 *
 * A feedback for an event with unrecognized barcodes.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *unrecognized;
/**
 * Added in version 6.14.0
 *
 * A feedback for a failure event.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *failure;

/**
 * Added in version 6.17.0
 *
 * Returns the JSON representation of the feedback.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.14.0
 *
 * Empty constructor. Constructs a new feedback that will not emit any sound, nor vibration.
 */
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
