/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCBrush;
@class SDCFeedback;

/**
 * Added in version 6.23.0
 *
 * Used to emit feedback when capturing barcodes.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(SparkScanBarcodeFeedback)
@interface SDCSparkScanBarcodeFeedback : NSObject

/**
 * Added in version 6.23.0
 *
 * Returns string representation of this object.
 */
@property (nonatomic, readonly) NSString *JSONString;

/**
 * Added in version 6.23.0
 *
 * Construct a new spark scan barcode feedback with the provided JSON serialization.
 */
+ (nullable instancetype)feedbackFromJSONString:(nonnull NSString *)JSONString
                                          error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:));

@end

/**
 * Added in version 6.23.0
 *
 * Used to display and emit a success feedback when capturing barcodes.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(SparkScanBarcodeSuccessFeedback)
@interface SDCSparkScanBarcodeSuccessFeedback : SDCSparkScanBarcodeFeedback

/**
 * Added in version 6.23.0
 *
 * The color of the visual success feedback.
 */
@property (nonatomic, readonly) UIColor *visualFeedbackColor;
/**
 * Added in version 6.23.0
 *
 * The brush used for the success feedback.
 */
@property (nonatomic, readonly) SDCBrush *brush;
/**
 * Added in version 6.23.0
 *
 * The feedback used for the success feedback.
 */
@property (nonatomic, readonly) SDCFeedback *feedback;

/**
 * Added in version 6.23.0
 *
 * Constructs a success feedback.
 */
- (instancetype)init;
/**
 * Added in version 6.23.0
 *
 * Constructs a success feedback.
 *
 * Passing nil for a nullable parameter results in using the default value.
 */
- (instancetype)initWithVisualFeedbackColor:(nullable UIColor *)visualFeedbackColor
                                   feedback:(nullable SDCFeedback *)feedback
                                      brush:(nullable SDCBrush *)brush;

@end

/**
 * Added in version 6.23.0
 *
 * Used to display and emit an error feedback when capturing barcodes.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(SparkScanBarcodeErrorFeedback)
@interface SDCSparkScanBarcodeErrorFeedback : SDCSparkScanBarcodeFeedback

/**
 * Added in version 6.23.0
 *
 * The error message to display when a wrong barcode was captured.
 */
@property (nonatomic, readonly) NSString *message;
/**
 * Added in version 6.23.0
 *
 * The time interval after which to resume the capturing process.
 */
@property (nonatomic, readonly) NSTimeInterval resumeCapturingDelay;
/**
 * Added in version 6.23.0
 *
 * The color of the visual error feedback.
 */
@property (nonatomic, readonly) UIColor *visualFeedbackColor;
/**
 * Added in version 6.23.0
 *
 * The brush used for the error feedback.
 */
@property (nonatomic, readonly) SDCBrush *brush;
/**
 * Added in version 6.23.0
 *
 * The feedback used for the error feedback.
 */
@property (nonatomic, readonly) SDCFeedback *feedback;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
/**
 * Added in version 6.23.0
 *
 * Constructs an error feedback.
 */
- (instancetype)initWithMessage:(nonnull NSString *)message
           resumeCapturingDelay:(NSTimeInterval)resumeCapturingDelay;
/**
 * Added in version 6.23.0
 *
 * Constructs an error feedback.
 *
 * Passing nil for a nullable parameter results in using the default value.
 */
- (instancetype)initWithMessage:(nonnull NSString *)message
           resumeCapturingDelay:(NSTimeInterval)resumeCapturingDelay
            visualFeedbackColor:(nullable UIColor *)visualFeedbackColor
                          brush:(nullable SDCBrush *)brush
                       feedback:(nullable SDCFeedback *)feedback;

@end

NS_ASSUME_NONNULL_END
