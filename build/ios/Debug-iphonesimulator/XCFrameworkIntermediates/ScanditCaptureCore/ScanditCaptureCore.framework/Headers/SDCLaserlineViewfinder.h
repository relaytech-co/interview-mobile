/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCViewfinder.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class UIColor;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.8.0
 *
 * The style of the SDCLaserlineViewfinder.
 *
 * Deprecated since version 6.26: This enum is deprecated and will be removed in the future.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCLaserlineViewfinderStyle) {
/**
     * Added in version 6.8.0
     *
     * The legacy style from versions before 6.8.
     */
    SDCLaserlineViewfinderStyleLegacy,
/**
     * Added in version 6.8.0
     *
     * New style from version 6.8 onwards with an animation.
     */
    SDCLaserlineViewfinderStyleAnimated,
} NS_SWIFT_NAME(LaserlineViewfinderStyle)
    DEPRECATED_MSG_ATTRIBUTE("The LaserlineViewfinderStyle enum will be removed in the future");

/**
 * Added in version 6.8.0
 *
 * Serialize the viewfinder style in a JSON string.
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromLaserlineViewfinderStyle(SDCLaserlineViewfinderStyle style) DEPRECATED_MSG_ATTRIBUTE("The LaserlineViewfinderStyle enum will be removed in the future") NS_SWIFT_NAME(getter:SDCLaserlineViewfinderStyle.jsonString(self:));
/**
 * Added in version 6.8.0
 *
 * Deserialize the viewfinder style from a JSON string.
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCLaserlineViewfinderStyleFromJSONString(NSString *_Nonnull JSONString,
                                                          SDCLaserlineViewfinderStyle *_Nonnull style) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

NS_SWIFT_NAME(LaserlineViewfinder)
SDC_EXPORTED_SYMBOL
DEPRECATED_MSG_ATTRIBUTE("The LaserlineViewfinder will be removed in the future")
/**
 * Added in version 6.0.0
 *
 * A horizontal laser line with a Scandit logo underneath. Toggles color depending on the capture mode enabled property. The laserline is centered on the data capture view’s point of interest.
 *
 * To use this viewfinder, create a new instance and assign it to the overlay, e.g. the barcode capture overlay via the SDCBarcodeCaptureOverlay.viewfinder property.
 *
 * Deprecated since version 6.26: This Viewfinder is deprecated and will be removed in the future.
 */
@interface SDCLaserlineViewfinder : NSObject <SDCViewfinder>

/**
 * Added in version 6.0.0
 *
 * Constructs a new laserline viewfinder with SDCLaserlineViewfinderStyleLegacy.
 *
 * Deprecated since version 6.14.0: Use viewfinderWithStyle: instead.
 */
+ (nonnull instancetype)viewfinder DEPRECATED_MSG_ATTRIBUTE("Use viewfinderWithStyle: instead.");
/**
 * Added in version 6.8.0
 *
 * Returns a new laserline viewfinder in the style provided.
 */
+ (nonnull instancetype)viewfinderWithStyle:(SDCLaserlineViewfinderStyle)style;

/**
 * Added in version 6.0.0
 *
 * The width of the laser line. The laser line is centered on the point of interest of the view.  When specifying the width with relative units, the width is measured relative to the view’s width minus the horizontal scan area margins.
 */
@property (nonatomic, assign) SDCFloatWithUnit width;
/**
 * Added in version 6.0.0
 *
 * The color to be used when recognition is enabled/active.
 */
@property (nonatomic, strong, nonnull) UIColor *enabledColor;
/**
 * Added in version 6.0.0
 *
 * The color to be used when recognition is disabled/inactive.
 */
@property (nonatomic, strong, nonnull) UIColor *disabledColor;
/**
 * Added in version 6.8.0
 *
 * The style of the viewfinder.
 */
@property (nonatomic, readonly) SDCLaserlineViewfinderStyle style;

@end

NS_ASSUME_NONNULL_END
