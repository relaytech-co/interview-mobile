/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCAnchor.h>

@class SDCBarcodeFind;
@class SDCBarcodeFindItem;
@class SDCBarcodeFindView;
@class SDCBarcodeFindViewSettings;
@class SDCDataCaptureContext;
@class SDCCameraSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.18.0
 */
NS_SWIFT_NAME(BarcodeFindViewUIDelegate)
@protocol SDCBarcodeFindViewUIDelegate <NSObject>

@optional

/**
 * Added in version 6.18.0
 *
 * Callback method that can be used to define an action that should be performed when the finish button is tapped from the view.
 * The foundItems parameter contains all the items found since the start of the searching process.
 * Called from the main thread.
 */
- (void)barcodeFindView:(nonnull SDCBarcodeFindView *)view
     didTapFinishButton:(NSSet<SDCBarcodeFindItem *> *)foundItems;

@end

/**
 * Added in version 6.18.0
 *
 * SDCBarcodeFind comes with a ready-to-use search UI that uses augmented reality overlays to highlight items that match predefined criteria.
 * The BarcodeFindView integrates with any app in just a few lines of code.
 */
NS_SWIFT_NAME(BarcodeFindView)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindView : UIView

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
/**
 * Added in version 6.18.0
 *
 * Constructs a new BarcodeFind view and adds it to the provided parentView. The provided settings will be used to set the default behaviour and look of the view.
 *
 * @code
 * barcodeFindView = BarcodeFindView(parentView: view, // For example the view controller's view property.
 *                                      context: context,
 *                                  barcodeFind: barcodeFind,
 *                                     settings: viewSettings)
 * @endcode
 */
- (instancetype)initWithParentView:(nonnull UIView *)parentView
                           context:(nonnull SDCDataCaptureContext *)context
                       barcodeFind:(nonnull SDCBarcodeFind *)barcodeFind
                          settings:(nonnull SDCBarcodeFindViewSettings *)settings;
/**
 * Added in version 6.18.0
 *
 * Constructs a new BarcodeFind view and adds it to the provided parentView.
 *
 * The provided settings will be used to set the default behaviour and look of the view.
 *
 * If camera settings are not provided (nil is passed as an argument) the recommended camera settings for Barcode Find will be used. If camera settings are provided these will be used instead.
 *
 * The topLayoutAnchor parameter specifies the top vertical anchor the BarcodeFind view should use to arrange its UI elements. The camera feed preview is not affected by this parameter. It can be used, for example, if you have a custom translucent navigation header and want the camera feed to show underneath, but don’t want the header to overlap other BarcodeFind UI elements (such as the progress bar). The default value is self.safeAreaLayoutGuide.topAnchor.
 */
- (instancetype)initWithParentView:(nonnull UIView *)parentView
                   topLayoutAnchor:(nullable NSLayoutYAxisAnchor *)topLayoutAnchor
                           context:(nonnull SDCDataCaptureContext *)context
                       barcodeFind:(nonnull SDCBarcodeFind *)barcodeFind
                          settings:(nonnull SDCBarcodeFindViewSettings *)settings
                    cameraSettings:(nullable SDCCameraSettings *)cameraSettings;

/**
 * Added in version 6.18.0
 *
 * Sets the delegate which is called whenever the finish button is tapped from the view.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeFindViewUIDelegate> UIDelegate;
/**
 * Added in version 6.18.0
 *
 * Indicates whether guidance should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowUserGuidanceView;
/**
 * Added in version 6.18.0
 *
 * Indicates whether hints should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowHints;
/**
 * Added in version 6.18.0
 *
 * Indicates whether the item carousel should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowCarousel;
/**
 * Added in version 6.18.0
 *
 * Indicates whether the pause button should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowPauseButton;
/**
 * Added in version 6.18.0
 *
 * Indicates whether the finish button should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowFinishButton;
/**
 * Added in version 6.18.0
 *
 * Indicates whether the progress bar should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowProgressBar;
/**
 * Added in version 6.20.0
 *
 * Indicates whether the torch control button should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowTorchControl;
/**
 * Added in version 6.28.0
 *
 * Indicates whether the zoom control should be shown to the user, allowing them to switch between the normal and ultra-wide lenses.
 *
 * Default is NO.
 *
 * @remark The zoom control requires a device with an ultra-wide camera. On devices without an ultra-wide camera, setting this property to YES has no effect.
 */
@property (nonatomic, assign, readwrite) BOOL shouldShowZoomControl;
/**
 * Added in version 6.20.0
 *
 * Updates the position of the torch control button.
 *
 * Only SDCAnchorTopLeft, SDCAnchorTopCenter, SDCAnchorTopRight and SDCAnchorBottomLeft are supported.
 *
 * Any other value will default to SDCAnchorTopLeft.
 */
@property (nonatomic, assign, readwrite) SDCAnchor torchControlPosition;
/**
 * Added in version 6.18.0
 *
 * Overrides the default text displayed in the button for collapsing the item carousel.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForCollapseCardsButton;
/**
 * Added in version 6.18.0
 *
 * Overrides the default text displayed in the green confirmation view shown when all items have been found.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForAllItemsFoundSuccessfullyHint;
/**
 * Added in version 6.18.0
 *
 * Overrides the default text for the “Point at barcodes to search” hint.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForPointAtBarcodesToSearchHint;
/**
 * Added in version 6.18.0
 *
 * Overrides the default text for the “Move closer” hint.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForMoveCloserToBarcodesHint;
/**
 * Added in version 6.18.0
 *
 * Overrides the default text for “Tap shutter to pause” hint.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForTapShutterToPauseScreenHint;
/**
 * Added in version 6.18.0
 *
 * Overrides the default text for “Tap shutter to resume” hint.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForTapShutterToResumeSearchHint;
/**
 * Added in version 6.24.0
 *
 * Overrides the default text displayed in the confirmation view shown when the item list has been updated.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForItemListUpdatedHint;
/**
 * Added in version 6.24.0
 *
 * Overrides the default text displayed in the confirmation view shown when the item list has been updated and search is paused.
 *
 * Default is nil.
 */
@property (nonatomic, copy, nullable, readwrite) NSString *textForItemListUpdatedWhenPausedHint;

/**
 * Added in version 6.18.0
 *
 * Starts the searching process. You can call this method if you want to trigger the searching process without any user interaction.
 */
- (void)startSearching;
/**
 * Added in version 6.18.0
 *
 * Pauses the searching process. You can call this method if you want to trigger pausing the searching process without any user interaction.
 */
- (void)pauseSearching;
/**
 * Added in version 6.18.0
 *
 * Method to call for preparing the mode for searching. For instance, it can be called when the view controller containing BarcodeFindView is presented (i.e., UIViewController’s viewWillAppear).
 */
- (void)prepareSearching;
/**
 * Added in version 6.18.0
 *
 * Method to call for stopping the mode. For instance, it can be called when the view controller containing BarcodeFindView is about to disappear (i.e., UIViewController’s viewWillDisappear).
 */
- (void)stopSearching;

@end

NS_ASSUME_NONNULL_END
