/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * A class that exposes the default values for the fields of BarcodeCountToolbarSettings.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountToolbarDefaults)
@interface SDCBarcodeCountToolbarDefaults : NSObject

/**
 * Added in version 6.17.0
 *
 * Returns the default text of the audio setting button when in “on” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *audioOnButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default text of the audio setting button when in “off” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *audioOffButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility hint of the audio setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *audioButtonAccessibilityHint;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility label of the audio setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *audioButtonAccessibilityLabel;

/**
 * Added in version 6.17.0
 *
 * Returns the default text of the vibration setting button when in “on” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *vibrationOnButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default text of the vibration setting button when in “off” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *vibrationOffButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility hint of the vibration setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *vibrationButtonAccessibilityHint;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility label of the vibration setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *vibrationButtonAccessibilityLabel;

/**
 * Added in version 6.17.0
 *
 * Returns the default text of the strap mode setting button when in “on” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *strapModeOnButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default text of the strap mode setting button when in “off” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *strapModeOffButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility hint of the strap mode setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *strapModeButtonAccessibilityHint;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility label of the strap mode setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *strapModeButtonAccessibilityLabel;

/**
 * Added in version 6.17.0
 *
 * Returns the default text of the color scheme setting button when in “on” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *colorSchemeOnButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default text of the color scheme setting button when in “off” state.
 */
@property (class, nonatomic, nonnull, readonly) NSString *colorSchemeOffButtonText;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility hint of the color scheme setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *colorSchemeButtonAccessibilityHint;
/**
 * Added in version 6.17.0
 *
 * Returns the default accessibility label of the color scheme setting button.
 */
@property (class, nonatomic, nonnull, readonly) NSString *colorSchemeButtonAccessibilityLabel;

@end

NS_ASSUME_NONNULL_END
