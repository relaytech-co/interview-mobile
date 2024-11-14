/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCAnchor.h>

@class SDCBarcodeCount;
@class SDCBarcodeCountView;
@class SDCBrush;
@class SDCTrackedBarcode;
@class SDCDataCaptureContext;
@class SDCBarcodeCountToolbarSettings;
@class SDCBarcodeCountNotInListActionSettings;
@protocol SDCBarcodeFilterHighlightSettings;
@protocol SDCBarcodeCountStatusProvider;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * The style of the SDCBarcodeCountView
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeCountViewStyle) {
/**
     * Added in version 6.15.0
     *
     * Style that draws the highlights as a dot and adds an animation for when a code newly appears.
     */
    SDCBarcodeCountViewStyleDot,
/**
     * Added in version 6.15.0
     *
     * Style that draws the highlights as icons and adds an animation for when a code newly appears.
     */
    SDCBarcodeCountViewStyleIcon
} NS_SWIFT_NAME(BarcodeCountViewStyle);

/**
 * Added in version 6.15.0
 */
NS_SWIFT_NAME(BarcodeCountViewDelegate)
@protocol SDCBarcodeCountViewDelegate <NSObject>

@optional

/**
 * Added in version 6.15.0
 *
 * This method is called only when the view uses the SDCBarcodeCountViewStyleDot style.
 *
 * Callback method that can be used to set a SDCBrush for a recognized barcode. When setting a SDCBarcodeCountCaptureList to the mode, this brush will be used for recognized barcodes that are part of the target list. It is called when a new recognized barcode appears. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the recognized barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeCountView:didTapRecognizedBarcode: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeCountView:(nonnull SDCBarcodeCountView *)view
              brushForRecognizedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.15.0
 *
 * This method is called only when the view uses the SDCBarcodeCountViewStyleDot style.
 *
 * Callback method that can be used to set a SDCBrush for an unrecognized barcode. It is called when a new unrecognized barcode appears. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the unrecognized barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeCountView:didTapUnrecognizedBarcode: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeCountView:(nonnull SDCBarcodeCountView *)view
            brushForUnrecognizedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.15.0
 *
 * This method is called only when the view uses the SDCBarcodeCountViewStyleDot style.
 *
 * Callback method that can be used to set a SDCBrush for a recognized barcode that’s not part of the target SDCBarcodeCountCaptureList. It is called when a new recognized barcode that is not part of the target :type:barcode.count.BarcodeCountCaptureList appears. When SDCBarcodeCountCaptureList is not set, this method will never be called. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the recognized barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeCountView:didTapRecognizedBarcodeNotInList: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeCountView:(nonnull SDCBarcodeCountView *)view
     brushForRecognizedBarcodeNotInList:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.28.0
 *
 * This method is called only when the view uses the SDCBarcodeCountViewStyleDot style.
 *
 * Callback method that can be used to set a SDCBrush for an accepted barcode. It is called when a barcode is accepted. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the accepted barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeCountView:didTapAcceptedBarcode: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeCountView:(nonnull SDCBarcodeCountView *)view
                brushForAcceptedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.28.0
 *
 * This method is called only when the view uses the SDCBarcodeCountViewStyleDot style.
 *
 * Callback method that can be used to set a SDCBrush for a rejected barcode. It is called when a barcode is rejected. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the accepted barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeCountView:didTapRejectedBarcode: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeCountView:(nonnull SDCBarcodeCountView *)view
                brushForRejectedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.15.0
 *
 * Callback method that can be used to define an action that should be performed once a recognized barcode is tapped. When setting a SDCBarcodeCountCaptureList to the mode, this method will be called only when tapping recognized barcodes that are part of the target list. Called from the main thread.
 */
- (void)barcodeCountView:(nonnull SDCBarcodeCountView *)view
    didTapRecognizedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.15.0
 *
 * Callback method that can be used to define an action that should be performed once an unrecognized barcode is tapped. Called from the main thread.
 */
- (void)barcodeCountView:(nonnull SDCBarcodeCountView *)view
    didTapUnrecognizedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.15.0
 *
 * Callback method that can be used to define an action that should be performed once a recognized barcode that’s not part of the target SDCBarcodeCountCaptureList is tapped. When SDCBarcodeCountCaptureList is not set, this method will never be called. Called from the main thread.
 */
- (void)barcodeCountView:(nonnull SDCBarcodeCountView *)view
    didTapRecognizedBarcodeNotInList:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.15.0
 *
 * Callback method that can be used to define an action that should be performed once a filtered barcode is tapped. Called from the main thread.
 */
- (void)barcodeCountView:(nonnull SDCBarcodeCountView *)view
    didTapFilteredBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.28.0
 *
 * Callback method that can be used to define an action that should be performed once an accepted barcode is tapped. Called from the main thread.
 */
- (void)barcodeCountView:(nonnull SDCBarcodeCountView *)view
    didTapAcceptedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.28.0
 *
 * Callback method that can be used to define an action that should be performed once a rejected barcode is tapped. Called from the main thread.
 */
- (void)barcodeCountView:(nonnull SDCBarcodeCountView *)view
    didTapRejectedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

/**
 * Added in version 6.15.0
 */
NS_SWIFT_NAME(BarcodeCountViewUIDelegate)
@protocol SDCBarcodeCountViewUIDelegate <NSObject>

@optional

/**
 * Added in version 6.15.0
 *
 * Callback method that can be used to define an action that should be performed once the list button is tapped. Called from the main thread.
 */
- (void)listButtonTappedForBarcodeCountView:(nonnull SDCBarcodeCountView *)view;

/**
 * Added in version 6.15.0
 *
 * Callback method that can be used to define an action that should be performed once the exit button is tapped. Called from the main thread.
 */
- (void)exitButtonTappedForBarcodeCountView:(nonnull SDCBarcodeCountView *)view;

/**
 * Added in version 6.16.0
 *
 * Callback method that can be used to define an action that should be performed once the single scan button is tapped. Called from the main thread.
 */
- (void)singleScanButtonTappedForBarcodeCountView:(nonnull SDCBarcodeCountView *)view;

@end

/**
 * Added in version 6.15.0
 *
 * SDCBarcodeCount comes with a ready-to-use UI. Add SDCBarcodeCountView to the view hierarchy. Please note that this view should be presented full screen.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountView)
@interface SDCBarcodeCountView : UIView

/**
 * Added in version 6.15.0
 *
 * Returns the default brush to use for a recognized barcode. When setting a SDCBarcodeCountCaptureList to the mode, this brush will be used for recognized barcodes that are part of the target list. Only used when setting the view style to SDCBarcodeCountViewStyleDot.
 */
@property (class, nonatomic, nonnull, readonly) SDCBrush *defaultRecognizedBrush;
/**
 * Added in version 6.15.0
 *
 * Returns the default brush to use for an unrecognized barcode. Only used when setting the view style to SDCBarcodeCountViewStyleDot.
 */
@property (class, nonatomic, nonnull, readonly) SDCBrush *defaultUnrecognizedBrush;
/**
 * Added in version 6.15.0
 *
 * Returns the default brush to use for a recognized barcode that’s not part of the target SDCBarcodeCountCaptureList. Only used when setting the view style to SDCBarcodeCountViewStyleDot.
 */
@property (class, nonatomic, nonnull, readonly) SDCBrush *defaultNotInListBrush;
/**
 * Added in version 6.28.0
 *
 * Returns the default brush to use for accepted barcodes. Only used when setting the view style to SDCBarcodeCountViewStyleDot.
 */
@property (class, nonatomic, nonnull, readonly) SDCBrush *defaultAcceptedBrush;
/**
 * Added in version 6.28.0
 *
 * Returns the default brush to use for rejected barcodes. Only used when setting the view style to SDCBarcodeCountViewStyleDot.
 */
@property (class, nonatomic, nonnull, readonly) SDCBrush *defaultRejectedBrush;

/**
 * Added in version 6.15.0
 *
 * The delegate which is called whenever a new SDCTrackedBarcode is newly tracked or newly recognized.
 *
 * @remark Using this delegate requires the MatrixScan AR add-on.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeCountViewDelegate> delegate;
/**
 * Added in version 6.15.0
 *
 * The delegate which is called whenever the exit or list button of the view did receive a tap.
 *
 * @remark Using this delegate requires the MatrixScan AR add-on.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeCountViewUIDelegate> UIDelegate;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the current view settings for barcode filtering.
 */
@property (nonatomic, strong, nullable) id<SDCBarcodeFilterHighlightSettings> filterSettings;
/**
 * Added in version 6.15.0
 *
 * When set to YES, this view will visualize the active scan area used for BarcodeCount. This is useful to check margins defined on the SDCDataCaptureView are set correctly. This property is meant for debugging during development and is not intended for use in production.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;
/**
 * Added in version 6.15.0
 *
 * The view style. Defaults to SDCBarcodeCountViewStyleDot.
 */
@property (nonatomic, readonly) SDCBarcodeCountViewStyle style;
/**
 * Added in version 6.15.0
 *
 * The brush applied to recognized tracked barcodes if SDCBarcodeCountViewDelegate is not implemented. When setting a SDCBarcodeCountCaptureList to the mode, this brush will be used for recognized barcodes that are part of the target list.
 * Setting this brush to nil hides all tracked barcodes.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
@property (nonatomic, strong, nullable) SDCBrush *recognizedBrush;
/**
 * Added in version 6.15.0
 *
 * The brush applied to unrecognized tracked barcodes if SDCBarcodeCountViewDelegate is not implemented.
 * Setting this brush to nil hides all tracked barcodes.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
@property (nonatomic, strong, nullable) SDCBrush *unrecognizedBrush;
/**
 * Added in version 6.15.0
 *
 * The brush applied to recognized tracked barcodes that are not part of the target SDCBarcodeCountCaptureList, and only if SDCBarcodeCountViewDelegate is not implemented. When SDCBarcodeCountCaptureList is not set, this method will never be called.
 * Setting this brush to nil hides all tracked barcodes.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
@property (nonatomic, strong, nullable) SDCBrush *notInListBrush;
/**
 * Added in version 6.28.0
 *
 * The brush applied to accepted tracked barcodes if SDCBarcodeCountViewDelegate is not implemented.
 * Setting this brush to nil hides all accepted barcodes.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
@property (nonatomic, strong, nullable) SDCBrush *acceptedBrush;
/**
 * Added in version 6.28.0
 *
 * The brush applied to rejected tracked barcodes if SDCBarcodeCountViewDelegate is not implemented.
 * Setting this brush to nil hides all rejected barcodes.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
@property (nonatomic, strong, nullable) SDCBrush *rejectedBrush;
/**
 * Added in version 6.15.0
 *
 * When set to YES, a list button will be shown to the user in the lower left hand corner of the screen. When tapped, this button will freeze the mode unless shouldDisableModeOnExitButtonTapped is set to NO. This button triggers a call to SDCBarcodeCountViewUIDelegate.listButtonTappedForBarcodeCountView:.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowListButton;
/**
 * Added in version 6.15.0
 *
 * When set to YES, an exit button will be shown in the lower right hand corner of the screen. The behavior for this button is left entirely to the developer, and does nothing by default. When clicked, this button triggers a call to SDCBarcodeCountViewUIDelegate.exitButtonTappedForBarcodeCountView:.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowExitButton;
/**
 * Added in version 6.15.0
 *
 * When set to YES, a shutter button will be shown to the user centered in the bottom of the screen. This button triggers the processing of the current video feed. The same functionality can be triggered by calling SDCBarcodeCount.startScanningPhase.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowShutterButton;
/**
 * Added in version 6.15.0
 *
 * When set to YES, a floating shutter button will be visible on screen. This button can be dragged to any position and, when tapped, will trigger the processing of the current video feed.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowFloatingShutterButton;
/**
 * Added in version 6.15.0
 *
 * When set to YES, user guidance and the loading view will be shown to the user. The user guidance prompts the user to scan, and to move closer or further away from the target barcodes in order to scan them properly.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowUserGuidanceView;
/**
 * Added in version 6.15.0
 *
 * When set to YES, this view will show some messages about currently scanned barcodes.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowHints;
/**
 * Added in version 6.15.0
 *
 * When set to YES, a button will be shown above the default shutter button. This button clears all currently shown barcodes highlights. The same functionality can be triggered by calling clearHighlights.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowClearHighlightsButton;
/**
 * Added in version 6.16.0
 *
 * When set to YES, a collapsable toolbar will be visible at the top of the preview. This toolbar contains a set of convenience buttons for easy preference setting during scanning.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowToolbar;
/**
 * Added in version 6.16.0
 *
 * When set to YES, a button will be shown to the user in the lower left corner of the preview. The behavior for this button is left entirely to the developer, and does nothing by default. When clicked, this button triggers a call to SDCBarcodeCountViewUIDelegate.singleScanButtonTappedForBarcodeCountView:.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowSingleScanButton;
/**
 * Added in version 6.17.0
 *
 * When set to YES, a button will be shown to the user in the lower right corner of the preview. This button toggles “status mode”, in which the normal barcode highlights will be replaced by status indicators for each barcode. The status for each barcode must be provided via a SDCBarcodeCountStatusProvider previously set with setStatusProvider:. If no SDCBarcodeCountStatusProvider is set, clicking this button has no effect.
 *
 * By default this property is NO.
 *
 * @remark The Barcode Count status mode API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
@property (nonatomic, assign) BOOL shouldShowStatusModeButton;
/**
 * Added in version 6.17.0
 *
 * When set to YES, the mode will disable automatically when the default exit button is tapped.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldDisableModeOnExitButtonTapped;
/**
 * Added in version 6.24.0
 *
 * When set to YES, a progress bar will be shown to the user when a capture list has been set using SDCBarcodeCount.setCaptureList:, indicating how many of the barcodes in the list have been scanned.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL shouldShowListProgressBar;
/**
 * Added in version 6.25.0
 *
 * Enable this feature to be able to deselect items by tapping on the highlights.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL tapToUncountEnabled;

/**
 * Added in version 6.26.0
 *
 * Indicates whether the torch control button should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign) BOOL shouldShowTorchControl;
/**
 * Added in version 6.26.0
 *
 * Updates the position of the torch control button.
 *
 * Only SDCAnchorTopLeft, SDCAnchorTopRight, SDCAnchorBottomLeft and SDCAnchorBottomRight, are supported.
 *
 * Any other value will default to SDCAnchorTopLeft.
 */
@property (nonatomic, assign) SDCAnchor torchControlPosition;

/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility label for the list button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *listButtonAccessibilityLabel;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility label for the exit button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *exitButtonAccessibilityLabel;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility label for the shutter button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *shutterButtonAccessibilityLabel;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility label for the floating shutter button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *floatingShutterButtonAccessibilityLabel;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility label for the clear highlights button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *clearHighlightsButtonAccessibilityLabel;
/**
 * Added in version 6.16.0
 *
 * Use this property to access or modify the accessibility label for the single scan button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *singleScanButtonAccessibilityLabel;
/**
 * Added in version 6.17.0
 *
 * Use this property to access or modify the accessibility label for the single status mode button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *statusModeButtonAccessibilityLabel;

/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility hint for the list button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *listButtonAccessibilityHint;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility hint for the exit button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *exitButtonAccessibilityHint;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility hint for the shutter button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *shutterButtonAccessibilityHint;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility hint for the floating shutter button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *floatingShutterButtonAccessibilityHint;
/**
 * Added in version 6.15.0
 *
 * Use this property to access or modify the accessibility hint for the clear highlights button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *clearHighlightsButtonAccessibilityHint;
/**
 * Added in version 6.16.0
 *
 * Use this property to access or modify the accessibility hint for the single scan button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *singleScanButtonAccessibilityHint;
/**
 * Added in version 6.17.0
 *
 * Use this property to access or modify the accessibility hint for the status mode button provided by the view.
 */
@property (nonatomic, strong, nullable) NSString *statusModeButtonAccessibilityHint;

/**
 * Added in version 6.23.0
 *
 * Enables the SDCBarcodeCountView to react to clicks of the volume button.
 */
@property (nonatomic, assign) BOOL hardwareTriggerEnabled;

/**
 * Added in version 6.28.0
 *
 * Use this object to customize barcode not in list actions.
 */
@property (nonatomic, strong) SDCBarcodeCountNotInListActionSettings *barcodeNotInListActionSettings;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

/**
 * Added in version 6.15.0
 *
 * Constructs a new barcode count view.
 */
- (instancetype)initWithFrame:(CGRect)frame
                      context:(nonnull SDCDataCaptureContext *)context
                 barcodeCount:(nonnull SDCBarcodeCount *)barcodeCount;
/**
 * Added in version 6.15.0
 *
 * Constructs a new barcode count view.
 */
- (instancetype)initWithFrame:(CGRect)frame
                      context:(nonnull SDCDataCaptureContext *)context
                 barcodeCount:(nonnull SDCBarcodeCount *)barcodeCount
                        style:(SDCBarcodeCountViewStyle)style;

/**
 * Added in version 6.21.0
 *
 * Constructs a new barcode count view. topLayoutAnchor can be used to specify the top vertical anchor the SDCBarcodeCountView should use to arrange its UI elements. If nil the anchor used will be the top of the view.
 */
- (instancetype)initWithFrame:(CGRect)frame
                      context:(nonnull SDCDataCaptureContext *)context
                 barcodeCount:(nonnull SDCBarcodeCount *)barcodeCount
                        style:(SDCBarcodeCountViewStyle)style
              topLayoutAnchor:(nullable NSLayoutYAxisAnchor *)topLayoutAnchor;

/**
 * Added in version 6.15.0
 *
 * Clear all currently shown barcodes highlights. This only affects screen rendering, and all detected barcodes will still be available in the SDCBarcodeCountSession.
 */
- (void)clearHighlights;

/**
 * Added in version 6.15.0
 *
 * Sets the text of the hint displayed when one or more unrecognized barcodes are detected.
 */
- (void)setTextForUnrecognizedBarcodesDetectedHint:(nonnull NSString *)text;
/**
 * Added in version 6.17.0
 *
 * Returns the text of the hint displayed when one or more unrecognized barcodes are detected.
 */
- (NSString *)textForUnrecognizedBarcodesDetectedHint;

/**
 * Added in version 6.15.0
 *
 * Sets the text of the hint which suggests to tap the shutter button.
 */
- (void)setTextForTapShutterToScanHint:(nonnull NSString *)text;
/**
 * Added in version 6.17.0
 *
 * Returns the text of the hint which suggests to tap the shutter button.
 */
- (NSString *)textForTapShutterToScanHint;

/**
 * Added in version 6.15.0
 *
 * Sets the text of the hint displayed while scanning is in progress.
 */
- (void)setTextForScanningHint:(nonnull NSString *)text;
/**
 * Added in version 6.17.0
 *
 * Returns the text of the hint displayed while scanning is in progress.
 */
- (NSString *)textForScanningHint;

/**
 * Added in version 6.15.0
 *
 * Sets the text of the hint displayed when camera should be moved closer to rescan.
 */
- (void)setTextForMoveCloserAndRescanHint:(nonnull NSString *)text;
/**
 * Added in version 6.17.0
 *
 * Returns the text of the hint displayed when camera should be moved closer to rescan.
 */
- (NSString *)textForMoveCloserAndRescanHint;

/**
 * Added in version 6.15.0
 *
 * Sets the text of the hint displayed when camera should be further away to rescan.
 */
- (void)setTextForMoveFurtherAndRescanHint:(nonnull NSString *)text;
/**
 * Added in version 6.17.0
 *
 * Returns the text of the hint displayed when camera should be further away to rescan.
 */
- (NSString *)textForMoveFurtherAndRescanHint;

/**
 * Added in version 6.23.0
 *
 * Sets the text of the hint displayed when a barcode not in list is scanned.
 */
- (void)setTextForBarcodesNotInListDetectedHint:(nonnull NSString *)text;
/**
 * Added in version 6.23.0
 *
 * Returns the text of the hint displayed when a barcode not in list is scanned.
 */
- (NSString *)textForBarcodesNotInListDetectedHint;

/**
 * Added in version 6.15.0
 *
 * Use this method to modify the text of the exit button label provided by the view.
 */
- (void)setExitButtonText:(nonnull NSString *)text;
/**
 * Added in version 6.17.0
 *
 * Returns the text of the exit button label provided by the view.
 */
- (NSString *)exitButtonText;

/**
 * Added in version 6.15.0
 *
 * Use this method to modify the text of the clear button label provided by the view.
 */
- (void)setClearHighlightsButtonText:(nonnull NSString *)text;
/**
 * Added in version 6.17.0
 *
 * Returns the text of the clear button label provided by the view.
 */
- (NSString *)clearHighlightsButtonText;

/**
 * Added in version 6.25.0
 *
 * Sets the text of the hint displayed when the user deselects an item.
 */
- (void)setTextForTapToUncountHint:(nonnull NSString *)text;
/**
 * Added in version 6.25.0
 *
 * Returns the text of the hint displayed when the user deselects an item.
 */
- (NSString *)textForTapToUncountHint;

/**
 * Added in version 6.16.0
 *
 * Pass an instance of SDCBarcodeCountToolbarSettings to configure the text and accessibility options for the toolbar.
 */
- (void)setToolbarSettings:(SDCBarcodeCountToolbarSettings *)settings;

/**
 * Added in version 6.17.0
 *
 * Sets a SDCBarcodeCountStatusProvider for this view. This provider will be queried when the “status mode” button is clicked.
 *
 * @remark The Barcode Count status mode API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
- (void)setStatusProvider:(id<SDCBarcodeCountStatusProvider>)statusProvider;

/**
 * Added in version 6.18.0
 *
 * Set a SDCBrush to be used for a particular recognized SDCTrackedBarcode. This will override any other applicable brush for this particular barcode.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
- (void)setBrush:(nullable SDCBrush *)brush forRecognizedBarcode:(SDCTrackedBarcode *)barcode;
/**
 * Added in version 6.18.0
 *
 * Set a SDCBrush to be used for a particular unrecognized SDCTrackedBarcode. This will override any other applicable brush for this particular barcode.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
- (void)setBrush:(nullable SDCBrush *)brush forUnrecognizedBarcode:(SDCTrackedBarcode *)barcode;
/**
 * Added in version 6.18.0
 *
 * Set a SDCBrush to be used for a particular recognized SDCTrackedBarcode that doesn’t belong to the capture list. This will only be applicable when using a capture list, and will override any other applicable brush for this particular barcode.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
- (void)setBrush:(nullable SDCBrush *)brush
    forRecognizedBarcodeNotInList:(SDCTrackedBarcode *)barcode;
/**
 * Added in version 6.28.0
 *
 * Set a SDCBrush to be used for a particular accepted SDCTrackedBarcode. This will override any other applicable brush for this particular barcode.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
- (void)setBrush:(nullable SDCBrush *)brush forAcceptedBarcode:(SDCTrackedBarcode *)barcode;
/**
 * Added in version 6.28.0
 *
 * Set a SDCBrush to be used for a particular rejected SDCTrackedBarcode. This will override any other applicable brush for this particular barcode.
 *
 * Used only when the view uses the SDCBarcodeCountViewStyleDot style.
 */
- (void)setBrush:(nullable SDCBrush *)brush forRejectedBarcode:(SDCTrackedBarcode *)barcode;

/**
 * Added in version 6.18.0
 *
 * Method to call for preparing the mode for scanning. For instance, it can be called when the view controller containing BarcodeCountView is about to be presented (i.e., UIViewController’s viewWillAppear).
 *
 * @code
 * override func viewWillAppear(animated: Bool) {
 *     super.viewWillAppear(animated)
 *     barcodeCountView.prepareScanning(with: context)
 * }
 * @endcode
 */
- (void)prepareScanningWithContext:(SDCDataCaptureContext *)context;
/**
 * Added in version 6.18.0
 *
 * Method to call for stopping the mode. For instance, it can be called when the view controller containing BarcodeCountView is about to disappear (i.e., UIViewController’s viewWillDisappear).
 *
 * @code
 * override func viewWillDisappear(animated: Bool) {
 *     super.viewWillDisappear(animated)
 *     barcodeCountView.stopScanning()
 * }
 * @endcode
 */
- (void)stopScanning;

@end

/**
 * Added in version 6.17.0
 */
SDC_EXTERN NSString *_Nonnull SDCBarcodeCountViewStyleToString(SDCBarcodeCountViewStyle style)
    NS_SWIFT_NAME(getter:SDCBarcodeCountViewStyle.jsonString(self:));

/**
 * Added in version 6.18.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN SDCBarcodeCountViewStyle SDCBarcodeCountViewStyleFromString(NSString *_Nonnull value)
    DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future")
        NS_SWIFT_NAME(SDCBarcodeCountViewStyle.fromJsonString(_:));

NS_ASSUME_NONNULL_END
