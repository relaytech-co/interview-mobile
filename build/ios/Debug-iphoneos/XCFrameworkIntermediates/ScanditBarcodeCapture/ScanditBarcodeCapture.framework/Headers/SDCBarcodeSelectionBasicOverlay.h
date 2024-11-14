/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionBrushProvider.h>

@class SDCBarcodeSelection;
@class SDCBrush;
@class SDCBarcode;
@class SDCDataCaptureView;
@protocol SDCViewfinder;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.10.0
 *
 * The style of the SDCBarcodeSelectionBasicOverlay.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeSelectionBasicOverlayStyle) {
/**
     * Added in version 6.10.0
     *
     * Style that draws the highlights as a rectangular frame and adds an animation for when a code newly appears.
     */
    SDCBarcodeSelectionBasicOverlayStyleFrame NS_SWIFT_NAME(frame),
/**
     * Added in version 6.10.0
     *
     * Style that draws the highlights as a dot and adds an animation for when a code newly appears.
     */
    SDCBarcodeSelectionBasicOverlayStyleDot NS_SWIFT_NAME(dot)
} NS_SWIFT_NAME(BarcodeSelectionBasicOverlayStyle);

/**
 * Added in version 6.10.0
 *
 * Returns the string representation of the overlay style.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeSelectionBasicOverlayStyle(SDCBarcodeSelectionBasicOverlayStyle overlayStyle)
    NS_SWIFT_NAME(getter:SDCBarcodeSelectionBasicOverlayStyle.jsonString(self:));
/**
 * Added in version 6.10.0
 *
 * Creates the overlay style from its string representation
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCBarcodeSelectionBasicOverlayStyleFromJSONString(NSString *_Nonnull JSONString,
                                                                   SDCBarcodeSelectionBasicOverlayStyle *_Nonnull overlayStyle) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.6.0
 *
 * An overlay for SDCDataCaptureView that shows a simple augmentation over each selected barcode.
 *
 * To display the augmentations, this overlay must be attached to a SDCDataCaptureView. This may be done either by creating it with overlayWithBarcodeSelection:forDataCaptureView: with a non-null view parameter or by passing this overlay to SDCDataCaptureView.addOverlay:.
 *
 * A user of this class may configure the appearance of the augmentations by configuring the brush properties.
 */
NS_SWIFT_NAME(BarcodeSelectionBasicOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionBasicOverlay : UIView <SDCDataCaptureOverlay>

/**
 * Added in version 6.6.0
 *
 * The default brush applied to recognized tracked barcodes.
 *
 * Deprecated since version 6.10.1: The defaultTrackedBrush of the overlay depends on the style used, there is no unique default brush. Use defaultTrackedBrushForStyle: instead.
 */
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultTrackedBrush DEPRECATED_MSG_ATTRIBUTE(
        "Use defaultTrackedBrushForStyle: instead.");
/**
 * Added in version 6.6.0
 *
 * The default brush applied to aimed barcodes.
 *
 * Deprecated since version 6.10.1: The defaultAimedBrush of the overlay depends on the style used, there is no unique default brush. Use defaultAimedBrushForStyle: instead.
 */
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultAimedBrush DEPRECATED_MSG_ATTRIBUTE("Use defaultAimedBrushForStyle: instead.");
/**
 * Added in version 6.6.0
 *
 * The default brush applied to barcodes currently being selected.
 */
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultSelectingBrush DEPRECATED_MSG_ATTRIBUTE(
        "Use defaultSelectingBrushForStyle: instead.");
/**
 * Added in version 6.6.0
 *
 * The default brush applied to selected barcodes.
 */
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultSelectedBrush DEPRECATED_MSG_ATTRIBUTE(
        "Use defaultSelectedBrushForStyle: instead.");

/**
 * Added in version 6.6.0
 *
 * The brush applied to recognized tracked barcodes, by default the value is set to defaultTrackedBrush.
 * Setting this brush to SDCBrush.transparentBrush hides all tracked barcodes.
 */
@property (nonatomic, strong, nonnull) SDCBrush *trackedBrush;
/**
 * Added in version 6.6.0
 *
 * The brush applied to the barcode that is currently being aimed at.
 *
 * By default the value is set to defaultAimedBrush.
 */
@property (nonatomic, strong, nonnull) SDCBrush *aimedBrush;
/**
 * Added in version 6.6.0
 *
 * The brush applied to the barcodes for the short moment when they are being selected.
 *
 * By default the value is set to defaultSelectingBrush.
 */
@property (nonatomic, strong, nonnull) SDCBrush *selectingBrush;
/**
 * Added in version 6.6.0
 *
 * The brush applied to selected barcodes, by default the value is set to defaultSelectedBrush.
 * Setting this brush to SDCBrush.transparentBrush hides all selected barcodes.
 */
@property (nonatomic, strong, nonnull) SDCBrush *selectedBrush;

/**
 * Added in version 6.12.0
 *
 * The overlay’s background color when in frozen state. This color will be on top of the video preview but below the highlights. Semitransparent black by default.
 */
@property (nonatomic, strong, nonnull) UIColor *frozenBackgroundColor;

/**
 * Added in version 6.6.0
 *
 * When set to YES, this overlay will visualize some hints explaining how to use barcode selection.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowHints;
/**
 * Added in version 6.6.0
 *
 * When set to YES, this overlay will visualize the active scan area used for BarcodeSelection. This is useful to check margins defined on the SDCDataCaptureView are set correctly. This property is meant for debugging during development and is not intended for use in production.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;
/**
 * Added in version 6.6.0
 *
 * The viewfinder of the overlay. The viewfinder is only visible when the selection type is SDCBarcodeSelectionAimerSelection.
 */
@property (nonatomic, strong, nonnull, readonly) id<SDCViewfinder> viewfinder;

/**
 * Added in version 6.10.0
 *
 * The overlay style. Defaults to Frame.
 */
@property (nonatomic, readonly) SDCBarcodeSelectionBasicOverlayStyle style;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

/**
 * Added in version 6.6.0
 *
 * Constructs a new barcode selection basic overlay for the barcode selection instance. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
    NS_SWIFT_NAME(init(barcodeSelection:));
/**
 * Added in version 6.10.0
 *
 * Constructs a new barcode selection basic overlay for the barcode selection instance with the specified style. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
                                  withStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeSelection:style:));
/**
 * Added in version 6.6.0
 *
 * Constructs a new barcode selection basic overlay for the barcode selection instance. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
                         forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeSelection:view:));
/**
 * Added in version 6.10.0
 *
 * Constructs a new barcode selection basic overlay for the barcode selection instance with the specified style. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
                         forDataCaptureView:(nullable SDCDataCaptureView *)view
                                  withStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeSelection:view:style:));

/**
 * Added in version 6.10.1
 *
 * Returns the default tracked brush for the given style.
 */
+ (nonnull SDCBrush *)defaultTrackedBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultTrackedBrush(forStyle:));
/**
 * Added in version 6.10.1
 *
 * Returns the default aimed brush for the given style.
 */
+ (nonnull SDCBrush *)defaultAimedBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultAimedBrush(forStyle:));
/**
 * Added in version 6.10.1
 *
 * Returns the default selecting brush for the given style.
 */
+ (nonnull SDCBrush *)defaultSelectingBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultSelectingBrush(forStyle:));
/**
 * Added in version 6.10.1
 *
 * Returns the default selected brush for the given style.
 */
+ (nonnull SDCBrush *)defaultSelectedBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultSelectedBrush(forStyle:));

/**
 * Added in version 6.14.0
 *
 * Constructs a new barcode selection basic overlay with the provided JSON serialization.
 *
 * For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (nullable instancetype)barcodeSelectionBasicOverlayFromJSONString:(nonnull NSString *)JSONString
                                                              mode:(nonnull SDCBarcodeSelection *)mode
                                                             error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:barcodeSelection:));

/**
 * Added in version 6.6.0
 *
 * Clears all currently displayed visualizations for the on screen barcodes.
 *
 * This only applies to the currently displayed barcodes, the visualizations for the new ones will still appear.
 */
- (void)clearSelectedBarcodeBrushes;

/**
 * Added in version 6.14.0
 *
 * Sets the text of the hint which suggests to use double tap gesture to freeze capture view.
 */
- (void)setTextForSelectOrDoubleTapToFreezeHint:(nonnull NSString *)text;
/**
 * Added in version 6.14.0
 *
 * Sets the text of the hint which suggests to use tap gesture to select barcodes.
 */
- (void)setTextForTapToSelectHint:(nonnull NSString *)text;
/**
 * Added in version 6.14.0
 *
 * Sets the text of the hint which suggests to use double tap gesture to unfreeze capture view.
 */
- (void)setTextForDoubleTapToUnfreezeHint:(nonnull NSString *)text;
/**
 * Added in version 6.14.0
 *
 * Sets the text of the hint which suggests to use tap gesture anywhere on the screen to select.
 */
- (void)setTextForTapAnywhereToSelectHint:(nonnull NSString *)text;
/**
 * Added in version 6.18.0
 *
 * Sets the text of the hint which suggests to aim at a barcode to scan it.
 */
- (void)setTextForAimToSelectAutoHint:(nonnull NSString *)text;

/**
 * Added in version 6.17.0
 *
 * Sets the brush provider for aimed barcode.
 */
- (void)setAimedBarcodeBrushProvider:(nullable id<SDCBarcodeSelectionBrushProvider>)brushProvider;
/**
 * Added in version 6.17.0
 *
 * Sets the brush provider for tracked barcode.
 */
- (void)setTrackedBarcodeBrushProvider:(nullable id<SDCBarcodeSelectionBrushProvider>)brushProvider;

/**
 * Added in version 6.14.0
 *
 * Updates the overlay according to a JSON serialization.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
