/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIColor.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.14.0
 *
 * Overlay that draws a color across the full view. The overlay fill color can be configured through the color property.
 */
NS_SWIFT_NAME(ColorFillOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCColorFillOverlay : NSObject <SDCDataCaptureOverlay>

/**
 * Added in version 6.14.0
 *
 * The fill color for this core capture overlay.
 */
@property (nonatomic, strong, nonnull) UIColor *color;

/**
 * Added in version 6.14.0
 *
 * Creates a new SDCColorFillOverlay instance with transparent color.
 */
- (instancetype)init;
/**
 * Added in version 6.14.0
 *
 * Creates a new SDCColorFillOverlay instance with the specified color.
 */
- (instancetype)initWithColor:(nonnull UIColor *)color;

@end

NS_ASSUME_NONNULL_END
