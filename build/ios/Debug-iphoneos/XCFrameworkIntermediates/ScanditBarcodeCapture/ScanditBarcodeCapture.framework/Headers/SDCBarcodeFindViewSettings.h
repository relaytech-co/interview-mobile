/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.18.0
 */
NS_SWIFT_NAME(BarcodeFindViewSettings)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindViewSettings : NSObject

/**
 * Added in version 6.18.0
 *
 * The color for the overlay of an item that is in the list of items to find.
 *
 * Default is #2EC1CE.
 */
@property (nonatomic, strong) UIColor *inListItemColor;
/**
 * Added in version 6.18.0
 *
 * The color for the overlay of an item that is not n the list of items to find.
 *
 * Default is #FFFFFF.
 */
@property (nonatomic, strong) UIColor *notInListItemColor;
/**
 * Added in version 6.18.0
 *
 * Indicates whether audio feedback should be enabled.
 *
 * Default is YES.
 */
@property (nonatomic, assign) BOOL soundEnabled;
/**
 * Added in version 6.18.0
 *
 * Indicates whether haptic feedback should be enabled.
 *
 * Default is YES.
 */
@property (nonatomic, assign) BOOL hapticEnabled;
/**
 * Added in version 6.23.0
 *
 * Sets whether the SDCBarcodeFindView should react to clicks of the volume button. Disabled by default.
 */
@property (nonatomic, assign) BOOL hardwareTriggerEnabled;
/**
 * Added in version 6.19.0
 *
 * Returns the JSON representation of the view settings.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END
