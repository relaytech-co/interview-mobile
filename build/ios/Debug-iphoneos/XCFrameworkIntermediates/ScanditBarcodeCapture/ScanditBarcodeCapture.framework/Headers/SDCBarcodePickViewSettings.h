/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCAnchor.h>

@protocol SDCBarcodePickViewHighlightStyle;
@protocol SDCBarcodeFilterHighlightSettings;
@class NSLayoutYAxisAnchor;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.19.0
 *
 * Settings used to configure SDCBarcodePickView.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickViewSettings)
@interface SDCBarcodePickViewSettings : NSObject

/**
 * Added in version 6.19.0
 *
 * The highlight style used by the view. Default is SDCBarcodePickViewHighlightStyleRectangularWithIcons.
 */
@property (nonatomic, strong) id<SDCBarcodePickViewHighlightStyle> highlightStyle;

/**
 * Added in version 6.19.0
 *
 * Enables or disables the loading dialog. Default is YES.
 */
@property (nonatomic, assign) BOOL showLoadingDialog;
/**
 * Added in version 6.19.0
 *
 * Configures the text shown by the loading dialog.
 */
@property (nonatomic, strong) NSString *loadingDialogText;

/**
 * Added in version 6.19.0
 *
 * Enables or disables the messages shown in the center of the view. Default is YES.
 */
@property (nonatomic, assign) BOOL showGuidelines;
/**
 * Added in version 6.19.0
 *
 * Configures the text shown when the mode is first launched.
 */
@property (nonatomic, strong) NSString *initialGuidelineText;
/**
 * Added in version 6.19.0
 *
 * Configures the text shown when there are no barcodes detected on screen.
 */
@property (nonatomic, strong) NSString *moveCloserGuidelineText;
/**
 * Added in version 6.24.0
 *
 * Configures the text shown to suggest the user to pause the scanning to pick items.
 */
@property (nonatomic, strong) NSString *tapShutterToPauseGuidelineText;

/**
 * Added in version 6.19.0
 *
 * Enables or disables the messages shown at the top of the view. Default is YES.
 */
@property (nonatomic, assign) BOOL showHints;
/**
 * Added in version 6.19.0
 *
 * Configures the text shown when the first item to pick is recognized and shown on screen.
 */
@property (nonatomic, strong) NSString *onFirstItemToPickFoundHintText;
/**
 * Added in version 6.19.0
 *
 * Configures the text shown when the first item pick is completed.
 */
@property (nonatomic, strong) NSString *onFirstItemPickCompletedHintText;
/**
 * Added in version 6.19.0
 *
 * Configures the text shown when the first item that was not a target is picked.
 */
@property (nonatomic, strong) NSString *onFirstUnmarkedItemPickCompletedHintText;
/**
 * Added in version 6.19.0
 *
 * Configures the text shown when the user reverses a pick.
 */
@property (nonatomic, strong) NSString *onFirstItemUnpickCompletedHintText;

/**
 * Added in version 6.23.0
 *
 * Configures the text shown when the user freezes the mode while there are status icons in view.
 */
@property (nonatomic, strong) NSString *onStatusIconShownWhilePausedHintText;

/**
 * Added in version 6.20.0
 *
 * Indicates whether the finish button should be shown to the user. Default is YES.
 */
@property (nonatomic, assign) BOOL showFinishButton;
/**
 * Added in version 6.20.0
 *
 * Indicates whether the pause button should be shown to the user. Default is YES.
 */
@property (nonatomic, assign) BOOL showPauseButton;
/**
 * Added in version 6.22.0
 *
 * Indicates whether the zoom button should be shown to the user. When clicked, it will switch between SDCCameraSettings.zoomFactor and SDCCameraSettings.zoomGestureZoomFactor, which default to 1x and 2x respectively when using SDCBarcodePick.recommendedCameraSettings. Default is NO.
 */
@property (nonatomic, assign) BOOL showZoomButton;
/**
 * Added in version 6.25.0
 *
 * Indicates the position where the zoom button will be shown to the user. If this position is shared with other controls, all of them will be shown in a row. Default is SDCAnchorBottomLeft.
 */
@property (nonatomic, assign) SDCAnchor zoomButtonPosition;
/**
 * Added in version 6.25.0
 *
 * Indicates whether the torch button should be shown to the user. Default is NO.
 */
@property (nonatomic, assign) BOOL showTorchButton;
/**
 * Added in version 6.25.0
 *
 * Indicates the position where the torch button will be shown to the user. If this position is shared with other controls, all of them will be shown in a row. Default is SDCAnchorTopLeft.
 */
@property (nonatomic, assign) SDCAnchor torchButtonPosition;

/**
 * Added in version 6.20.0
 *
 * Can be used to specify the top vertical anchor the SDCBarcodePickView should use to arrange its UI elements. Default value is nil, the anchor will be the top of the view.
 */
@property (nonatomic, strong) NSLayoutYAxisAnchor *topLayoutAnchor;

/**
 * Added in version 6.23.0
 *
 * Sets whether the SDCBarcodePickView should react to clicks of the volume button. Disabled by default.
 */
@property (nonatomic, assign) BOOL hardwareTriggerEnabled;

/**
 * Added in version 6.24.0
 *
 * Use this property to configure the appearance of the barcodes that are filtered. Default is nil, filtered barcodes won’t be visualized.
 */
@property (nonatomic, strong, nullable) id<SDCBarcodeFilterHighlightSettings> filterHighlightSettings;

@end

NS_ASSUME_NONNULL_END
