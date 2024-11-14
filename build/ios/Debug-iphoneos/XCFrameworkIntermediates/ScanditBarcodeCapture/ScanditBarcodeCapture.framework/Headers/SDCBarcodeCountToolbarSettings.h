/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.16.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountToolbarSettings)
@interface SDCBarcodeCountToolbarSettings : NSObject

/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the audio setting button when in “on” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *audioOnButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the audio setting button when in “off” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *audioOffButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility hint of the audio setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *audioButtonAccessibilityHint;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility label of the audio setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *audioButtonAccessibilityLabel;

/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the vibration setting button when in “on” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *vibrationOnButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the vibration setting button when in “off” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *vibrationOffButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility hint of the vibration setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *vibrationButtonAccessibilityHint;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility label of the vibration setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *vibrationButtonAccessibilityLabel;

/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the strap mode setting button when in “on” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *strapModeOnButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the strap mode setting button when in “off” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *strapModeOffButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility hint of the strap mode setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *strapModeButtonAccessibilityHint;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility label of the strap mode setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *strapModeButtonAccessibilityLabel;

/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the color scheme setting button when in “on” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *colorSchemeOnButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the text of the color scheme setting button when in “off” state. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *colorSchemeOffButtonText;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility hint of the color scheme setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *colorSchemeButtonAccessibilityHint;
/**
 * Added in version 6.16.0
 *
 * If populated sets the accessibility label of the color scheme setting button. Otherwise a default value will be used.
 */
@property (nonatomic, strong, nullable) NSString *colorSchemeButtonAccessibilityLabel;

@end

NS_ASSUME_NONNULL_END
