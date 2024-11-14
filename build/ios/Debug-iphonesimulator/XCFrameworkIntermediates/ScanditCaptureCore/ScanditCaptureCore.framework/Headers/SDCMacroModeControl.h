/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCControl.h>
#import <ScanditCaptureCore/SDCBase.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * Control that allows to switch between the available macro modes. The control hides itself automatically in case the active frame source doesn’t support macro mode.
 *
 * You can add this control to a view by calling SDCDataCaptureView.addControl:.
 * Please note that this control has the same default placement anchor as SDCCameraSwitchControl, so it will replace it when added to the view using the default settings.
 * If you need to place multiple controls at the same anchor, consider using SDCLinearControlGroup.
 */
NS_SWIFT_NAME(MacroModeControl)
SDC_EXPORTED_SYMBOL
@interface SDCMacroModeControl : NSObject <SDCControl>

/**
 * Added in version 6.17.0
 *
 * The button image displayed when the macro mode is auto.
 */
@property (nonatomic, strong, nonnull) UIImage *autoImage;
/**
 * Added in version 6.17.0
 *
 * The button image displayed when the macro mode is off.
 */
@property (nonatomic, strong, nonnull) UIImage *offImage;
/**
 * Added in version 6.17.0
 *
 * The button image displayed when the macro mode is on.
 */
@property (nonatomic, strong, nonnull) UIImage *onImage;

/**
 * Added in version 6.17.0
 *
 * Accessibility label text used for the control button when the macro mode is auto.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityLabelWhenAuto;
/**
 * Added in version 6.17.0
 *
 * Accessibility hint text used for the control button when the macro mode is auto.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityHintWhenAuto;
/**
 * Added in version 6.17.0
 *
 * Accessibility label text used for the control button when the macro mode is off.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityLabelWhenOff;
/**
 * Added in version 6.17.0
 *
 * Accessibility hint text used for the control button when the macro mode is off.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityHintWhenOff;
/**
 * Added in version 6.17.0
 *
 * Accessibility label text used for the control button when the macro mode is on.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityLabelWhenOn;
/**
 * Added in version 6.17.0
 *
 * Accessibility hint text used for the control button when the macro mode is on.
 */
@property (nonatomic, copy, nullable) NSString *accessibilityHintWhenOn;

/**
 * Added in version 6.17.0
 *
 * The default image used for the control button when the macro mode is auto.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultAutoImage;
/**
 * Added in version 6.17.0
 *
 * The default image used for the control button when the macro mode is off.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultOffImage;
/**
 * Added in version 6.17.0
 *
 * The default image used for the control button when the macro mode is on.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultOnImage;

/**
 * Added in version 6.17.0
 *
 * Constructs a new macro mode control with the provided JSON serialization.
 */
+ (nullable instancetype)macroModeControlFromJSONString:(nonnull NSString *)JSONString
                                                  error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.17.0
 *
 * Updates the control according to a JSON serialization.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
