/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCFeedback;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SparkScanFeedback)
SDC_EXPORTED_SYMBOL
DEPRECATED_MSG_ATTRIBUTE("This class is not used anymore. Use SDCSparkScanFeedbackDelegate instead")
/**
 * Added in version 6.8.0
 *
 * Deprecated since version 6.23: This class is not used anymore. Use SDCSparkScanBarcodeFeedback and SDCSparkScanView.feedbackDelegate instead.
 *
 * Determines what feedback (vibration, sound) should be emitted when scanning barcodes.
 *
 * This class allows to configure the feedback that gets emitted when a barcode is read successfully through the success property and erroneously through the error property.
 *
 * As of now, this class only allows to configure the feedback that gets emitted when a barcode is read successfully, through the success property.
 *
 * See documentation on the SDCSparkScan.feedback property for usage samples.
 */
@interface SDCSparkScanFeedback : NSObject

/**
 * Added in version 6.8.0
 *
 * Returns a SparkScan feedback with default configuration:
 *
 *   • default beep sound is loaded,
 *
 *   • beeping for the success event is enabled,
 *
 *   • vibration for the success event is enabled.
 */
@property (class, nonatomic, readonly) SDCSparkScanFeedback *defaultFeedback;

/**
 * Added in version 6.8.0
 *
 * A feedback for a success event.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *success;
/**
 * Added in version 6.16.0
 *
 * A feedback for a error event.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *error;
/**
 * Added in version 6.9.0
 *
 * Returns the JSON representation of the feedback.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.8.0
 *
 * Construct a new SparkScan feedback with the provided JSON serialization.
 */
+ (nullable instancetype)sparkScanFeedbackFromJSONString:(nonnull NSString *)JSONString
                                                   error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
