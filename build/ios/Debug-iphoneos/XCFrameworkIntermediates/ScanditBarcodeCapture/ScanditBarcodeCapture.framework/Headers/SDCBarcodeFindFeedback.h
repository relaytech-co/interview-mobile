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
 * Added in version 6.18.0
 *
 * Determines what feedback (vibration, sound) should be emitted when barcodes are scanned.
 *
 * The feedback is specified for each BarcodeFind instance separately and can be changed
 * through the feedback property by either modifying an existing instance of this class, or by assigning a new one.
 *
 * As of now, this class allows to configure the feedback that gets emitted when barcodes are found successfully, through the found property.
 *
 * See documentation on the SDCBarcodeFind.feedback property for usage samples.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeFindFeedback)
@interface SDCBarcodeFindFeedback : NSObject

/**
 * Added in version 6.18.0
 *
 * Returns a barcode find feedback with default configuration:
 *
 *   • default beep sound is loaded,
 *
 *   • beeping for the success event is enabled,
 *
 *   • vibration for the success event is enabled.
 */
@property (class, nonatomic, readonly) SDCBarcodeFindFeedback *defaultFeedback;
/**
 * Added in version 6.18.0
 *
 * A feedback for a barcode found event.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *found;
/**
 * Added in version 6.24.0
 *
 * A feedback for the item list updated event.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *itemListUpdated;
/**
 * Added in version 6.19.0
 *
 * Returns the JSON representation of the feedback.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.19.0
 */
+ (nullable instancetype)barcodeFindFeedbackFromJSONString:(nonnull NSString *)JSONString
                                                     error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.18.0
 *
 * Empty constructor. Constructs a new feedback that will not emit any sound, nor vibration.
 */
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
