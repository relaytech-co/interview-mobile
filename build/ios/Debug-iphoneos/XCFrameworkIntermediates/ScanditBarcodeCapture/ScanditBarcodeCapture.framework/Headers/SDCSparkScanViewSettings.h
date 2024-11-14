/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCCamera.h>
#import <ScanditBarcodeCapture/SDCSparkScanToastSettings.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * The capture mode type of the SDCSparkScanView.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanScanningBehavior) {
/**
     * Added in version 6.15.0
     *
     * Barcode capturing session is stopped after each scan.
     */
    SDCSparkScanScanningBehaviorSingle,
/**
     * Added in version 6.15.0
     *
     * Keeps the barcode capturing session active for longer time.
     */
    SDCSparkScanScanningBehaviorContinuous
} NS_SWIFT_NAME(SparkScanScanningBehavior);

/**
 * Added in version 6.19.0
 *
 * The scanning precision type of the SDCSparkScanView.
 *
 * Deprecated since version 6.23.0: Replaced by SDCSparkScanPreviewBehavior because accurate workflow have been simplified.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanScanningPrecision) {
/**
     * Added in version 6.19.0
     *
     * Default precision. Depending on the configured scanning mode and behavior, it results in the following behaviors:
     *
     * SDCSparkScanScanningModeDefault
     *
     * SDCSparkScanScanningModeTarget
     *
     * SDCSparkScanScanningBehaviorSingle
     *
     *   • Tapping the trigger button starts the camera and the
     * scanning process.
     *
     *   • A barcode is scanned as soon as it is visible on the
     * camera frame.
     *
     *   • After a successful scan, the scanning process is
     * stopped, and the camera is frozen on the last frame.
     *
     *   • Tapping the trigger button starts the camera and the
     * scanning process.
     *
     *   • A barcode is scanned after pointing the viewfinder at
     * it for a short time.
     *
     *   • After a successful scan, the scanning process is
     * stopped, and the camera is frozen on the last frame.
     *
     * SDCSparkScanScanningBehaviorContinuous
     *
     *   • Tapping the trigger button starts the camera and the
     * scanning process.
     *
     *   • A barcode is scanned as soon as it is visible on the
     * camera frame.
     *
     *   • Camera and scanning process keep running until the
     * user taps the trigger button, or the
     * SDCSparkScanViewSettings.continuousCaptureTimeout
     * expires.
     *
     *   • Tapping the trigger button starts the camera and the
     * scanning process.
     *
     *   • A barcode is scanned after pointing the viewfinder at
     * it for a short time.
     *
     *   • Camera and scanning process keep running until the
     * user taps the trigger button, or the
     * SDCSparkScanViewSettings.continuousCaptureTimeout
     * expires.
     */
    SDCSparkScanScanningPrecisionDefault,
/**
     * Added in version 6.19.0
     *
     * Accurate precision. Depending on the configured scanning mode and behavior, it results in the following behaviors:
     *
     * SDCSparkScanScanningModeDefault
     *
     * SDCSparkScanScanningModeTarget
     *
     * SDCSparkScanScanningBehaviorSingle
     *
     *   • Expanding the trigger button starts the camera, and
     * tapping it starts the scanning process.
     *
     *   • A barcode is scanned after pointing the viewfinder at
     * it.
     *
     *   • After a successful scan, the scanning process is
     * stopped, but the camera keeps running.
     *
     *   • Tapping the trigger button starts the camera and the
     * scanning process.
     *
     *   • A barcode is scanned after pointing the viewfinder at
     * it and tapping the trigger button.
     *
     *   • Camera and scanning process keep running until the
     * trigger button is collapsed.
     *
     * SDCSparkScanScanningBehaviorContinuous
     *
     *   • Expanding the trigger button starts the camera, and
     * tapping it starts the scanning process.
     *
     *   • A barcode is scanned after pointing the viewfinder at
     * it.
     *
     *   • Camera and scanning process keep running until the
     * user taps the trigger button, or the
     * SDCSparkScanViewSettings.continuousCaptureTimeout
     * expires.
     *
     *   • Expanding the trigger button starts the camera, and
     * tapping it starts the scanning process.
     *
     *   • A barcode is scanned after pointing the viewfinder at
     * it for a short time.
     *
     *   • Camera and scanning process keep running until the
     * user taps the trigger button, or the
     * SDCSparkScanViewSettings.continuousCaptureTimeout
     * expires.
     */
    SDCSparkScanScanningPrecisionAccurate
} NS_SWIFT_NAME(SparkScanScanningPrecision);

/**
 * Added in version 6.23.0
 *
 * The preview behavior type of the SDCSparkScanView.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanPreviewBehavior) {
/**
     * Added in version 6.23.0
     *
     * After a scan with scanning behavior SDCSparkScanScanningBehaviorSingle, or stopping scanning with scanning behavior SDCSparkScanScanningBehaviorContinuous, camera moves to standby state and preview is hidden for maximum efficiency.
     */
    SDCSparkScanPreviewBehaviorDefault,
/**
     * Added in version 6.23.0
     *
     * After a scan with scanning behavior SDCSparkScanScanningBehaviorSingle, or stopping scanning with scanning behavior SDCSparkScanScanningBehaviorContinuous, camera stays active and preview is visible for maximum precision.
     */
    SDCSparkScanPreviewBehaviorPersistent
} NS_SWIFT_NAME(SparkScanPreviewBehavior);

/**
 * Added in version 6.19.0
 *
 * Deprecated since version 6.23.0: Replaced by NSStringFromSparkScanPreviewBehavior(previewBehavior).
 */
SDC_EXTERN NSString *_Nonnull NSStringFromSparkScanScanningPrecision(SDCSparkScanScanningPrecision scanningPrecision)
DEPRECATED_MSG_ATTRIBUTE("No longer needed.") NS_SWIFT_NAME(getter:SDCSparkScanScanningPrecision.jsonString(self:));
/**
 * Added in version 6.19.0
 *
 * Deprecated since version 6.23.0: Replaced by SDCSparkScanPreviewBehaviorFromJSONString(JSONString, previewBehavior).
 */
SDC_EXTERN BOOL SDCSparkScanScanningPrecisionFromJSONString(NSString *_Nonnull JSONString, SDCSparkScanScanningPrecision *_Nonnull scanningPrecision) DEPRECATED_MSG_ATTRIBUTE("No longer needed.");
/**
 * Added in version 6.23.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromSparkScanPreviewBehavior(SDCSparkScanPreviewBehavior previewBehavior)
    DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future") NS_SWIFT_NAME(getter:SDCSparkScanPreviewBehavior.jsonString(self:));
/**
 * Added in version 6.23.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCSparkScanPreviewBehaviorFromJSONString(NSString *_Nonnull JSONString, SDCSparkScanPreviewBehavior *_Nonnull previewBehavior) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.16.0
 *
 * The base class for setting a default scanning mode to SDCSparkScanViewSettings. Can be either SDCSparkScanScanningModeTarget or SDCSparkScanScanningModeDefault.
 */
NS_SWIFT_NAME(SparkScanScanningMode)
@protocol SDCSparkScanScanningMode <NSObject>
/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
@end

/**
 * Added in version 6.16.0
 *
 * This is the standard scanning mode for SparkScan.
 */
NS_SWIFT_NAME(SparkScanScanningModeDefault)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanScanningModeDefault : NSObject <SDCSparkScanScanningMode>
/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
/**
 * Added in version 6.16.0
 *
 * The scanning mode provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanScanningBehavior scanningBehavior;
/**
 * Added in version 6.23.0
 *
 * The preview behavior provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanPreviewBehavior previewBehavior;
/**
 * Added in version 6.19.0
 *
 * The scanning precision provided in the constructor.
 *
 * Deprecated since version 6.23.0: Replaced by previewBehavior.
 */
@property (nonatomic, assign, readonly)
    SDCSparkScanScanningPrecision scanningPrecision DEPRECATED_MSG_ATTRIBUTE(
        "Use previewBehavior instead");
/**
 * Added in version 6.16.0
 *
 * Constructs a new default scanning mode with the provided capture mode and scanning precision.
 *
 * Deprecated since version 6.23.0: Replaced by initializer that accepts SDCSparkScanPreviewBehavior instead of deprecated SDCSparkScanScanningPrecision.
 */
- (instancetype)initWithScanningBehavior:(SDCSparkScanScanningBehavior)scanningBehavior
                       scanningPrecision:(SDCSparkScanScanningPrecision)scanningPrecision
    DEPRECATED_MSG_ATTRIBUTE("Use initializer with previewBehavior parameter instead");
/**
 * Added in version 6.23.0
 *
 * Constructs a new default scanning mode with the provided capture mode and preview behavior.
 */
- (instancetype)initWithScanningBehavior:(SDCSparkScanScanningBehavior)scanningBehavior
                         previewBehavior:(SDCSparkScanPreviewBehavior)previewBehavior;
@end

/**
 * Added in version 6.16.0
 *
 * Target scanning mode. This is meant and optimized to scan codes further away.
 */
NS_SWIFT_NAME(SparkScanScanningModeTarget)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanScanningModeTarget : NSObject <SDCSparkScanScanningMode>
/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
/**
 * Added in version 6.16.0
 *
 * The scanning mode provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanScanningBehavior scanningBehavior;
/**
 * Added in version 6.23.0
 *
 * The preview behavior provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanPreviewBehavior previewBehavior;
/**
 * Added in version 6.19.0
 *
 * The scanning precision provided in the constructor.
 *
 * Deprecated since version 6.23.0: Replaced by previewBehavior.
 */
@property (nonatomic, assign, readonly)
    SDCSparkScanScanningPrecision scanningPrecision DEPRECATED_MSG_ATTRIBUTE(
        "Use previewBehavior instead");
/**
 * Added in version 6.16.0
 *
 * Constructs a new target scanning mode with the provided capture mode and scanning precision.
 *
 * Deprecated since version 6.23.0: Replaced by initializer that accepts SDCSparkScanPreviewBehavior instead of deprecated SDCSparkScanScanningPrecision.
 */
- (instancetype)initWithScanningBehavior:(SDCSparkScanScanningBehavior)scanningBehavior
                       scanningPrecision:(SDCSparkScanScanningPrecision)scanningPrecision
    DEPRECATED_MSG_ATTRIBUTE("Use initializer with previewBehavior parameter instead");
/**
 * Added in version 6.23.0
 *
 * Constructs a new target scanning mode with the provided capture mode and preview behavior.
 */
- (instancetype)initWithScanningBehavior:(SDCSparkScanScanningBehavior)scanningBehavior
                         previewBehavior:(SDCSparkScanPreviewBehavior)previewBehavior;
@end

/**
 * Added in version 6.15.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromSparkScanScanningBehavior(SDCSparkScanScanningBehavior scanningBehavior)
    DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future")
    NS_SWIFT_NAME(getter:SDCSparkScanScanningBehavior.jsonString(self:));
/**
 * Added in version 6.15.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCSparkScanScanningBehaviorFromJSONString(NSString *_Nonnull JSONString, SDCSparkScanScanningBehavior *_Nonnull scanningBehavior) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.15.0
 *
 * The hand mode type of the SDCSparkScanView.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanViewHandMode) {
/**
     * Added in version 6.15.0
     *
     * Optimizes the layout for right-hand use of the SDCSparkScanView.
     */
    SDCSparkScanViewHandModeRight,
/**
     * Added in version 6.15.0
     *
     * Optimizes the layout for left-hand use of the SDCSparkScanView.
     */
    SDCSparkScanViewHandModeLeft
} NS_SWIFT_NAME(SparkScanViewHandMode);

/**
 * Added in version 6.15.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromSparkScanViewHandMode(SDCSparkScanViewHandMode handMode)
    DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future")
    NS_SWIFT_NAME(getter:SDCSparkScanViewHandMode.jsonString(self:));
/**
 * Added in version 6.15.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCSparkScanViewHandModeFromJSONString(NSString *_Nonnull JSONString, SDCSparkScanViewHandMode *_Nonnull handMode) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.15.0
 *
 * @warning Changing the values of SparkScanViewSettings instance after the creation of SDCSparkScanView does not result in applying the changed settings to the corresponding view.
 */
NS_SWIFT_NAME(SparkScanViewSettings)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanViewSettings : NSObject

/**
 * Added in version 6.15.0
 *
 * The timeout to automatically switch to idle state. When set to negative value timeout is infinite.
 *
 * Default is infinite.
 */
@property (nonatomic, assign) NSTimeInterval triggerButtonCollapseTimeout;
/**
 * Added in version 6.15.0
 *
 * The timeout to automatically stop capturing when the view is configured in SDCSparkScanScanningBehaviorContinuous capturing mode.
 *
 * Default is 60 seconds.
 *
 * Deprecated since version 6.23.0: Replaced by inactiveStateTimeout.
 */
@property (nonatomic, assign) NSTimeInterval continuousCaptureTimeout DEPRECATED_MSG_ATTRIBUTE("Use inactiveStateTimeout instead");
/**
 * Added in version 6.23.0
 *
 * The timeout to automatically stop capturing.
 *
 * Default is 10 seconds.
 */
@property (nonatomic, assign) NSTimeInterval inactiveStateTimeout;

/**
 * Added in version 6.15.0
 *
 * Sets the default torch state of the camera.
 *
 * Default is SDCTorchStateOff.
 */
@property (nonatomic, assign) SDCTorchState defaultTorchState;
/**
 * Added in version 6.24.0
 *
 * Sets the default camera position.
 *
 * Default is SDCCameraPositionWorldFacing.
 *
 * @remark This API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
@property (nonatomic, assign) SDCCameraPosition defaultCameraPosition;
/**
 * Added in version 6.16.0
 *
 * Sets the default scanning mode of the view.
 *
 * Default is SDCSparkScanScanningModeDefault.
 */
@property (nonatomic, strong) id<SDCSparkScanScanningMode> defaultScanningMode;
/**
 * Added in version 6.16.0
 *
 * Indicates whether the feedback should have sound enabled.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isSoundEnabled) BOOL soundEnabled;
/**
 * Added in version 6.16.0
 *
 * Indicates whether the feedback should have haptics enabled.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isHapticEnabled) BOOL hapticEnabled;
/**
 * Added in version 6.16.0
 *
 * Indicates whether the visual feedback on scan should be displayed.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isVisualFeedbackEnabled) BOOL visualFeedbackEnabled;
/**
 * Added in version 6.16.0
 *
 * Indicates whether to keep scanning as long as the scan button is pressed.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isHoldToScanEnabled) BOOL holdToScanEnabled;
/**
 * Added in version 6.15.0
 *
 * Sets the default hand mode of the view.
 *
 * Default is SDCSparkScanViewHandModeRight.
 */
@property (nonatomic, assign) SDCSparkScanViewHandMode defaultHandMode;
/**
 * Added in version 6.17.0
 *
 * If set to YES the scan button will not be limited vertically in its movement. This makes it possible to interact with the part of the app that might otherwise be covered by it. If the button covers the camera preview when the scanner is started, it will be moved to just under the preview.
 *
 * Default is YES.
 *
 * Deprecated since version 6.22.0: There is no drag limit anymore. Button can be repositioned all the way from the bottom to the top of the screen.
 */
@property (nonatomic, assign) BOOL ignoreDragLimits DEPRECATED_MSG_ATTRIBUTE("There is no drag limit anymore.");

/**
 * Added in version 6.16.0
 *
 * Sets whether the SDCSparkScanView should react to clicks of the volume button. Disabled by default.
 */
@property (nonatomic, assign, getter=isHardwareTriggerEnabled) BOOL hardwareTriggerEnabled;

/**
 * Added in version 6.18.0
 *
 * The zoom factor to use for the camera.
 *
 * Default is 1.
 *
 * Deprecated since version 6.23.0: Replaced by zoomFactorOut because zoom switch control is now also available in SDCSparkScanScanningModeDefault scanning mode.
 */
@property (nonatomic, assign) CGFloat targetZoomFactorOut DEPRECATED_MSG_ATTRIBUTE("Use zoomFactorOut instead");
/**
 * Added in version 6.18.0
 *
 * The zoom factor to move to when the zoom in gesture was performed or zoom switch control was tapped.
 *
 * Default is 2.
 *
 * Deprecated since version 6.23.0: Replaced by zoomFactorIn because zoom switch control is now also available in SDCSparkScanScanningModeDefault scanning mode.
 */
@property (nonatomic, assign) CGFloat targetZoomFactorIn DEPRECATED_MSG_ATTRIBUTE("Use zoomFactorIn instead");
/**
 * Added in version 6.23.0
 *
 * The zoom factor to use for the camera.
 *
 * Default is 1.
 */
@property (nonatomic, assign) CGFloat zoomFactorOut;
/**
 * Added in version 6.23.0
 *
 * The zoom factor to move to when the zoom switch control was tapped.
 *
 * Default is 2.
 */
@property (nonatomic, assign) CGFloat zoomFactorIn;

/**
 * Added in version 6.18.0
 *
 * Sets the toast settings. See SDCSparkScanToastSettings for details.
 */
@property (nonatomic, strong) SDCSparkScanToastSettings *toastSettings;

/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation of the spark scan settings.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END
