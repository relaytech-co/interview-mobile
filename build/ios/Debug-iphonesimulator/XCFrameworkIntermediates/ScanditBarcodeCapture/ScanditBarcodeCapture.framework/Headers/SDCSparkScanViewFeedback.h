/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCBrush;

SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(SparkScanViewFeedback)
DEPRECATED_MSG_ATTRIBUTE("This class is not used anymore. Use SDCSparkScanFeedbackDelegate instead")
/**
 * Added in version 6.15.0
 *
 * Deprecated since version 6.23: This class is not used anymore. Use SDCSparkScanBarcodeFeedback and SDCSparkScanView.feedbackDelegate instead.
 *
 * Used to display a visual feedback when capturing barcodes.
 */
@interface SDCSparkScanViewFeedback : NSObject
@end

SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(SparkScanViewSuccessFeedback)
DEPRECATED_MSG_ATTRIBUTE("This class is not used anymore. Use SDCSparkScanFeedbackDelegate instead")
/**
 * Added in version 6.15.0
 *
 * Deprecated since version 6.23: This class is not used anymore. Use SparkScanBarcodeFeedback.Success and SDCSparkScanView.feedbackDelegate instead.
 *
 * Used to emit a success SDCSparkScanFeedback feedback when capturing barcodes.
 */
@interface SDCSparkScanViewSuccessFeedback : SDCSparkScanViewFeedback

/**
 * Added in version 6.16.0
 *
 * The color of the visual success feedback.
 */
@property (nonatomic, readonly) UIColor *visualFeedbackColor;

/**
 * Added in version 6.16.0
 *
 * Constructs a success feedback.
 */
- (instancetype)init;
/**
 * Added in version 6.16.0
 *
 * Constructs a success feedback.
 */
- (instancetype)initWithVisualFeedbackColor:(UIColor *)visualFeedbackColor;

@end

SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(SparkScanViewErrorFeedback)
DEPRECATED_MSG_ATTRIBUTE("This class is not used anymore. Use SDCSparkScanFeedbackDelegate instead")
/**
 * Added in version 6.15.0
 *
 * Deprecated since version 6.23: This class is not used anymore. Use SparkScanBarcodeFeedback.Error and SDCSparkScanView.feedbackDelegate instead.
 *
 * Used to display an error visual feedback and emit an error SDCSparkScanFeedback feedback when capturing barcodes.
 */
@interface SDCSparkScanViewErrorFeedback : SDCSparkScanViewFeedback

/**
 * Added in version 6.15.0
 *
 * The error message to display when a wrong barcode was captured.
 */
@property (nonatomic, nonnull, readonly) NSString *message;
/**
 * Added in version 6.15.0
 *
 * The time interval after which to resume the capturing process.
 */
@property (nonatomic, readonly) NSTimeInterval resumeCapturingDelay;
/**
 * Added in version 6.16.0
 *
 * The color of the visual error feedback.
 */
@property (nonatomic, readonly) UIColor *visualFeedbackColor;
/**
 * Added in version 6.18.0
 *
 * The brush used for the error feedback.
 */
@property (nonatomic, readonly) SDCBrush *brush;

/**
 * Added in version 6.15.0
 *
 * Constructs an error feedback.
 */
- (instancetype)initWithMessage:(nonnull NSString *)message
           resumeCapturingDelay:(NSTimeInterval)resumeCapturingDelay;
/**
 * Added in version 6.16.0
 *
 * Constructs an error feedback.
 */
- (instancetype)initWithMessage:(nonnull NSString *)message
           resumeCapturingDelay:(NSTimeInterval)resumeCapturingDelay
            visualFeedbackColor:(UIColor *)visualFeedbackColor;
/**
 * Added in version 6.18.0
 *
 * Constructs an error feedback.
 */
- (instancetype)initWithMessage:(nonnull NSString *)message
           resumeCapturingDelay:(NSTimeInterval)resumeCapturingDelay
                          brush:(SDCBrush *)brush;
/**
 * Added in version 6.18.0
 *
 * Constructs an error feedback.
 */
- (instancetype)initWithMessage:(nonnull NSString *)message
           resumeCapturingDelay:(NSTimeInterval)resumeCapturingDelay
            visualFeedbackColor:(nullable UIColor *)visualFeedbackColor
                          brush:(nullable SDCBrush *)brush;

@end

NS_ASSUME_NONNULL_END
