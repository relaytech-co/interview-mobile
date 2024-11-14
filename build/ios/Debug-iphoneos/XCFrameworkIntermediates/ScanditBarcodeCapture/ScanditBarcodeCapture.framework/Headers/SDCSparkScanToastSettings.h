/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.18.0
 */
NS_SWIFT_NAME(SDCSparkScanToastSettings)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanToastSettings : NSObject

/**
 * Added in version 6.18.0
 *
 * Should toasts be shown or not.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isToastEnabled) BOOL toastEnabled;
/**
 * Added in version 6.18.0
 *
 * Background color of the toast. If this property is nil, a default color will be used.
 *
 * Default is nil.
 */
@property (nonatomic, strong, nullable) UIColor *toastBackgroundColor;
/**
 * Added in version 6.18.0
 *
 * Text color of the toast. If this property is nil, a default color will be used.
 *
 * Default is nil.
 */
@property (nonatomic, strong, nullable) UIColor *toastTextColor;
/**
 * Added in version 6.18.0
 *
 * Text of the toast when target mode enabled.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *targetModeEnabledMessage;
/**
 * Added in version 6.18.0
 *
 * Text of the toast when target mode disabled.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *targetModeDisabledMessage;
/**
 * Added in version 6.18.0
 *
 * Text of the toast when SDCSparkScanScanningBehaviorContinuous capturing mode enabled.
 *
 * Default is nil. If this property is nil, a default message will be shown.
 *
 * If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *continuousModeEnabledMessage;
/**
 * Added in version 6.18.0
 *
 * Text of the toast when SDCSparkScanScanningBehaviorContinuous capturing mode disabled.
 *
 * Default is nil. If this property is nil, a default message will be shown.
 *
 * If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *continuousModeDisabledMessage;
/**
 * Added in version 6.18.0
 *
 * Text of the toast when mini preview is hidden due to a timeout to save battery.
 *
 * Default is nil. If this property is nil, a default message will be shown.
 *
 * If this property is an empty string, the toast will not be shown.
 *
 * Deprecated since version 6.23: This toast is not displayed anymore due to changes in the SparkScan toast system.
 */
@property (nonatomic, strong, nullable)
    NSString *cameraTimeoutMessage DEPRECATED_MSG_ATTRIBUTE("No longer needed.");
/**
 * Added in version 6.23.0
 *
 * Text of the toast when zooming in.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *zoomedInMessage;
/**
 * Added in version 6.23.0
 *
 * Text of the toast when zooming out.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *zoomedOutMessage;
/**
 * Added in version 6.23.0
 *
 * Text of the toast when torch is enabled.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *torchEnabledMessage;
/**
 * Added in version 6.23.0
 *
 * Text of the toast when torch is disabled.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *torchDisabledMessage;
/**
 * Added in version 6.24.0
 *
 * Text of the toast when user facing camera is enabled.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *userFacingCameraEnabledMessage;
/**
 * Added in version 6.24.0
 *
 * Text of the toast when world facing camera is enabled.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *worldFacingCameraEnabledMessage;
/**
 * Added in version 6.23.0
 *
 * Text of the toast when SDCSparkScanPreviewBehaviorPersistent capturing mode is enabled and scanning is paused.
 *
 * Default is nil. If this property is nil, a default message will be shown. If this property is an empty string, the toast will not be shown.
 */
@property (nonatomic, strong, nullable) NSString *scanPausedMessage;

/**
 * Added in version 6.18.0
 *
 * Returns the JSON representation of the toast settings.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END
