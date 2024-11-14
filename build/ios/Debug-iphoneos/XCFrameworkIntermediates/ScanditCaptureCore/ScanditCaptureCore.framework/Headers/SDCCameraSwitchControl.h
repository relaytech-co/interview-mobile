/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCControl.h>
#import <ScanditCaptureCore/SDCBase.h>

@class UIImage;
@class SDCCamera;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.10.0
 *
 * Control that allows to switch between a primary and a secondary camera.
 *
 * You can add this control to a view by calling SDCDataCaptureView.addControl:.
 *
 * Adding a camera switch control to a view sets the primary camera as the view’s context frame source.
 */
NS_SWIFT_NAME(CameraSwitchControl)
SDC_EXPORTED_SYMBOL
@interface SDCCameraSwitchControl : NSObject <SDCControl>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.10.0
 *
 * The button image displayed when the primary camera is selected.
 */
@property (nonatomic, strong, nonnull) UIImage *primaryCameraImage;
/**
 * Added in version 6.10.0
 *
 * The button image displayed when the primary camera is selected and pressed.
 */
@property (nonatomic, strong, nonnull) UIImage *primaryCameraPressedImage;
/**
 * Added in version 6.10.0
 *
 * The button image displayed when the secondary camera is selected.
 */
@property (nonatomic, strong, nonnull) UIImage *secondaryCameraImage;
/**
 * Added in version 6.10.0
 *
 * The button image displayed when the secondary camera is selected and pressed.
 */
@property (nonatomic, strong, nonnull) UIImage *secondaryCameraPressedImage;

/**
 * Added in version 6.14.0
 *
 * Accessibility label text used for the button when the world facing camera is selected.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityLabelWhenWorldFacing;
/**
 * Added in version 6.14.0
 *
 * Accessibility hint text used for the button when the world facing camera is selected.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityHintWhenWorldFacing;
/**
 * Added in version 6.14.0
 *
 * Accessibility label text used for the button when the user facing camera is selected.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityLabelWhenUserFacing;
/**
 * Added in version 6.14.0
 *
 * Accessibility hint text used for the button when the user facing camera is selected.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityHintWhenUserFacing;

/**
 * Added in version 6.10.0
 *
 * The default button image used by the control for the primary camera. Can be used to reset to the original image.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultPrimaryCameraImage;
/**
 * Added in version 6.10.0
 *
 * The default button image used by the control for the primary camera while being pressed. Can be used to reset to the original image.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultPrimaryCameraPressedImage;
/**
 * Added in version 6.10.0
 *
 * The default button image used by the control for the secondary camera. Can be used to reset to the original image.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultSecondaryCameraImage;
/**
 * Added in version 6.10.0
 *
 * The default button image used by the control for the secondary camera while being pressed. Can be used to reset to the original image.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultSecondaryCameraPressedImage;

/**
 * Added in version 6.10.0
 *
 * The primary camera. Calling SDCDataCaptureView.addControl: sets this camera as the view’s context frame source.
 */
@property (nonatomic, strong, nonnull, readonly) SDCCamera *primaryCamera;
/**
 * Added in version 6.10.0
 *
 * The secondary camera.
 */
@property (nonatomic, strong, nonnull, readonly) SDCCamera *secondaryCamera;

/**
 * Added in version 6.10.0
 *
 * Initializes a CameraSwitchControl with two cameras.
 */
- (nonnull instancetype)initWithPrimaryCamera:(nonnull SDCCamera *)primaryCamera
                              secondaryCamera:(nonnull SDCCamera *)secondaryCamera;

/**
 * Added in version 6.10.0
 *
 * Constructs a new camera switch control with the provided JSON serialization.
 */
+ (nullable instancetype)cameraSwitchControlFromJSONString:(nonnull NSString *)JSONString
                                                     error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.10.0
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
