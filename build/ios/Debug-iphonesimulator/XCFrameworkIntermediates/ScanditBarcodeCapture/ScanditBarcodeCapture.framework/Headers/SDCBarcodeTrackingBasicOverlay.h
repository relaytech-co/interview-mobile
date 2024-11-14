/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>

@class SDCBarcodeTracking;
@class SDCBrush;
@class SDCTrackedBarcode;
@class SDCBarcodeTrackingBasicOverlay;
@class SDCDataCaptureView;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.10.0
 *
 * The style of the SDCBarcodeTrackingBasicOverlay
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeTrackingBasicOverlayStyle) {
/**
     * Added in version 6.10.0
     *
     * Legacy style from versions before 6.10.
     *
     * Deprecated since version 6.26: This style is deprecated and will be removed in the future.
     */
    SDCBarcodeTrackingBasicOverlayStyleLegacy NS_SWIFT_NAME(legacy) DEPRECATED_MSG_ATTRIBUTE("This style will be removed in the future"),
/**
     * Added in version 6.10.0
     *
     * Style that draws the highlights as a rectangular frame and adds an animation for when a code newly appears.
     */
    SDCBarcodeTrackingBasicOverlayStyleFrame NS_SWIFT_NAME(frame),
/**
     * Added in version 6.10.0
     *
     * Style that draws the highlights as a dot and adds an animation for when a code newly appears.
     */
    SDCBarcodeTrackingBasicOverlayStyleDot NS_SWIFT_NAME(dot)
} NS_SWIFT_NAME(BarcodeTrackingBasicOverlayStyle);

/**
 * Added in version 6.10.0
 *
 * Returns the string representation of the overlay style.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeTrackingBasicOverlayStyle(SDCBarcodeTrackingBasicOverlayStyle overlayStyle)
    NS_SWIFT_NAME(getter:SDCBarcodeTrackingBasicOverlayStyle.jsonString(self:));
/**
 * Added in version 6.10.0
 *
 * Creates the overlay style from its string representation
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCBarcodeTrackingBasicOverlayStyleFromJSONString(NSString *_Nonnull JSONString,
                                                                  SDCBarcodeTrackingBasicOverlayStyle *_Nonnull overlayStyle) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.0.0
 */
NS_SWIFT_NAME(BarcodeTrackingBasicOverlayDelegate)
@protocol SDCBarcodeTrackingBasicOverlayDelegate <NSObject>

/**
 * Added in version 6.0.0
 *
 * Callback method that can be used to set a SDCBrush for a tracked barcode. It is called when a new tracked barcode appears. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the tracked barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeTrackingBasicOverlay:didTapTrackedBarcode: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeTrackingBasicOverlay:(nonnull SDCBarcodeTrackingBasicOverlay *)overlay
                            brushForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.0.0
 *
 * Callback method that can be used to define an action that should be performed once a tracked barcode is tapped. Called from the main thread.
 *
 * If you are adding a UIGestureRecognizer to the data capture view, ensure that the cancelsTouchesInView property is set to NO as otherwise tap gestures will be cancelled instead of successfully completing.
 */
- (void)barcodeTrackingBasicOverlay:(nonnull SDCBarcodeTrackingBasicOverlay *)overlay
               didTapTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

/**
 * Added in version 6.0.0
 *
 * An overlay for SDCDataCaptureView that shows a simple augmentation over each tracked barcode.
 *
 * To display the augmentations, this overlay must be attached to a SDCDataCaptureView. This may be done either by creating it with overlayWithBarcodeTracking:forDataCaptureView: with a non-null view parameter or by passing this overlay to SDCDataCaptureView.addOverlay:.
 *
 * A user of this class may configure the appearance of the augmentations by implementing  SDCBarcodeTrackingBasicOverlayDelegate or by calling setBrush:forTrackedBarcode:.
 *
 * For additional information about using this overlay, refer to MatrixScan Get Started guide.
 */
NS_SWIFT_NAME(BarcodeTrackingBasicOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingBasicOverlay : NSObject <SDCDataCaptureOverlay>

/**
 * Added in version 6.0.0
 *
 * The delegate which is called whenever a new TrackedBarcode is newly tracked or newly recognized.
 *
 * @remark Using this delegate requires the MatrixScan AR add-on.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeTrackingBasicOverlayDelegate> delegate;
/**
 * Added in version 6.4.0
 *
 * The default brush applied to recognized tracked barcodes.
 *
 * Deprecated since version 6.10.1: The defaultBrush of the overlay depends on the style used, there is no unique default brush. Use defaultBrushForStyle: instead.
 */
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultBrush DEPRECATED_MSG_ATTRIBUTE("Use defaultBrushForStyle: instead.");
/**
 * Added in version 6.0.0
 *
 * The default brush applied to recognized tracked barcodes. This is the brush used if SDCBarcodeTrackingBasicOverlayDelegate is not implemented.
 * Setting this brush to nil hides all tracked barcodes, unless setBrush:forTrackedBarcode: is called.
 *
 * Deprecated since version 6.4.0: Replaced by brush.
 */
@property (nonatomic, strong, nullable)
    SDCBrush *defaultBrush DEPRECATED_MSG_ATTRIBUTE("Use brush instead");
/**
 * Added in version 6.4.0
 *
 * The brush applied to recognized tracked barcodes if SDCBarcodeTrackingBasicOverlayDelegate is not implemented. By default the value is set to defaultBrush.
 * Setting this brush to nil hides all tracked barcodes, unless setBrush:forTrackedBarcode: is called.
 */
@property (nonatomic, strong, nullable) SDCBrush *brush;
/**
 * Added in version 6.10.0
 *
 * The overlay style. Defaults to Legacy.
 */
@property (nonatomic, readonly) SDCBarcodeTrackingBasicOverlayStyle style;
/**
 * Added in version 6.0.0
 *
 * When set to YES, this overlay will visualize the active scan area used for BarcodeTracking. This is useful to check margins defined on the SDCDataCaptureView are set correctly. This property is meant for debugging during development and is not intended for use in production.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking basic overlay for the barcode tracking instance. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking;
/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking basic overlay for the barcode tracking instance. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                        forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeTracking:view:));
;

/**
 * Added in version 6.10.0
 *
 * Constructs a new barcode tracking basic overlay for the barcode tracking instance with the specified style. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                                 withStyle:(SDCBarcodeTrackingBasicOverlayStyle)style;
/**
 * Added in version 6.10.0
 *
 * Constructs a new barcode tracking basic overlay for the barcode tracking instance with the specified style. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                        forDataCaptureView:(nullable SDCDataCaptureView *)view
                                 withStyle:(SDCBarcodeTrackingBasicOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeTracking:view:style:));

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking basic overlay with the provided JSON serialization.
 *
 * For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (nullable instancetype)barcodeTrackingBasicOverlayFromJSONString:(nonnull NSString *)JSONString
                                                              mode:(nonnull SDCBarcodeTracking *)mode
                                                             error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:barcodeTracking:));

/**
 * Added in version 6.10.1
 *
 * Returns the default brush for the given style.
 */
+ (nonnull SDCBrush *)defaultBrushForStyle:(SDCBarcodeTrackingBasicOverlayStyle)style
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
 * The method can be called to change the visualization style of a tracked barcode. This method is thread-safe, it can be called from any thread.
 * If the brush is nil, then no visualization will be drawn for the tracked barcode. Additionally, tapping on the barcode will have no effect - the action defined by SDCBarcodeTrackingBasicOverlayDelegate.barcodeTrackingBasicOverlay:didTapTrackedBarcode: callback will not be performed.
 *
 * @remark Using this function requires the MatrixScan AR add-on.
 */
- (void)setBrush:(nullable SDCBrush *)brush
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.0.0
 *
 * Clears all currently displayed visualizations for the tracked barcodes.
 *
 * This only applies to the currently tracked barcodes, the visualizations for the new ones will still appear.
 */
- (void)clearTrackedBarcodeBrushes;

@end

NS_ASSUME_NONNULL_END
