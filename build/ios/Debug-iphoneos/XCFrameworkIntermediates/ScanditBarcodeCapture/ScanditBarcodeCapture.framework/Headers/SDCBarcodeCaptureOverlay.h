/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>

@class SDCBarcodeCapture;
@class SDCBrush;
@class SDCDataCaptureView;
@protocol SDCViewfinder;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.10.0
 *
 * The style of the SDCBarcodeCaptureOverlay.
 *
 * Deprecated since version 6.26: This enum is deprecated and will be removed in the future.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeCaptureOverlayStyle) {
/**
     * Added in version 6.10.0
     *
     * Legacy style from versions before 6.10.
     */
    SDCBarcodeCaptureOverlayStyleLegacy NS_SWIFT_NAME(legacy) DEPRECATED_MSG_ATTRIBUTE("This style will be removed in the future"),
/**
     * Added in version 6.10.0
     *
     * Style that draws the highlights as a rectangular frame and adds an animation for when a code is scanned.
     */
    SDCBarcodeCaptureOverlayStyleFrame NS_SWIFT_NAME(frame)
} NS_SWIFT_NAME(BarcodeCaptureOverlayStyle);

/**
 * Added in version 6.10.0
 *
 * Returns the string representation of the overlay style.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeCaptureOverlayStyle(SDCBarcodeCaptureOverlayStyle overlayStyle)
    NS_SWIFT_NAME(getter:SDCBarcodeCaptureOverlayStyle.jsonString(self:));
/**
 * Added in version 6.10.0
 *
 * Creates the overlay style from its string representation
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCBarcodeCaptureOverlayStyleFromJSONString(NSString *_Nonnull JSONString,
                                                            SDCBarcodeCaptureOverlayStyle *_Nonnull overlayStyle) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.0.0
 *
 * Overlay for the SDCBarcodeCapture capture mode that displays recognized barcodes on top of a data capture view.
 *
 * The appearance of the visualized barcodes can be configured or turned off completely through the brush property.
 */
NS_SWIFT_NAME(BarcodeCaptureOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCaptureOverlay : NSObject <SDCDataCaptureOverlay>

/**
 * Added in version 6.0.0
 *
 * Returns the default brush used by the overlay.
 *
 * Deprecated since version 6.10.0: The defaultBrush of the overlay depends on the style used, there is no unique default brush. Use defaultBrushForStyle: instead.
 */
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultBrush DEPRECATED_MSG_ATTRIBUTE("Use defaultBrushForStyle: instead.");
/**
 * Added in version 6.0.0
 *
 * The brush used for visualizing a recognized barcode in the UI. To turn off drawing of locations, set the brush to use both a transparent fill and stroke color. By default, the brush has a transparent fill color, a “Scandit”-blue stroke color, and a stroke width of 1.
 */
@property (nonatomic, strong, nonnull) SDCBrush *brush;
/**
 * Added in version 6.0.0
 *
 * Whether to show scan area guides on top of the preview. This property is useful during development to visualize the current scan areas on screen. It is not meant to be used for production. By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;
/**
 * Added in version 6.0.0
 *
 * Set the viewfinder. By default, the viewfinder is nil. Set this to an instance of SDCViewfinder if you want to draw a viewfinder.
 */
@property (nonatomic, strong, nullable) id<SDCViewfinder> viewfinder;
/**
 * Added in version 6.10.0
 *
 * The overlay style. Defaults to Legacy.
 */
@property (nonatomic, readonly) SDCBarcodeCaptureOverlayStyle style;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode capture overlay for the provided barcode capture instance. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture;
/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode capture overlay for the provided barcode capture instance. When passing a non-nil view instance, the overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture
                       forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeCapture:view:));

/**
 * Added in version 6.10.0
 *
 * Constructs a new barcode capture overlay for the provided barcode capture instance and style. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture
                                withStyle:(SDCBarcodeCaptureOverlayStyle)style;
/**
 * Added in version 6.10.0
 *
 * Constructs a new barcode capture overlay for the provided barcode capture instance and style. When passing a non-nil view instance, the overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture
                       forDataCaptureView:(nullable SDCDataCaptureView *)view
                                withStyle:(SDCBarcodeCaptureOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeCapture:view:style:));

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode capture overlay with the provided JSON serialization.
 *
 * For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (nullable instancetype)barcodeCaptureOverlayFromJSONString:(nonnull NSString *)JSONString
                                                        mode:(nonnull SDCBarcodeCapture *)mode
                                                       error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:barcodeCapture:));

/**
 * Added in version 6.10.1
 *
 * Returns the default brush for the given style.
 */
+ (nonnull SDCBrush *)defaultBrushForStyle:(SDCBarcodeCaptureOverlayStyle)style
    NS_SWIFT_NAME(defaultBrush(forStyle:));

/**
 * Added in version 6.0.0
 *
 * Updates the overlay according to a JSON serialization.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.0.0
 *
 * Set barcode capture overlay property to the provided value. Use this method to set properties that are not yet part of a stable API. Properties set through this method may or may not be used or change in a future release.
 */
- (void)setValue:(nullable id)value forProperty:(nonnull NSString *)property;

@end

NS_ASSUME_NONNULL_END
