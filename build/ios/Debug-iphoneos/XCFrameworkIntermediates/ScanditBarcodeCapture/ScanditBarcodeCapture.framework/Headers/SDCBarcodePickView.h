/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCDataCaptureContext;
@class SDCBarcodePick;
@class SDCBarcodePickViewSettings;
@class SDCCameraSettings;
@class SDCBarcodePickView;

@protocol SDCBarcodePickActionListener;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.20.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickViewUIDelegate)
@protocol SDCBarcodePickViewUIDelegate <NSObject>

@optional

/**
 * Added in version 6.20.0
 *
 * Callback method that can be used to define an action that should be performed when the finish button is tapped from the view.
 * Called from the main thread.
 */
- (void)barcodePickViewDidTapFinishButton:(SDCBarcodePickView *)view;

@end

/**
 * Added in version 6.20.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickViewListener)
@protocol SDCBarcodePickViewListener <NSObject>

@optional

/**
 * Added in version 6.20.0
 *
 * Callback method invoked when the view starts scanning.
 * Called from the main thread.
 */
- (void)barcodePickViewDidStartScanning:(SDCBarcodePickView *)view;
/**
 * Added in version 6.20.0
 *
 * Callback method invoked the scanning is freezed.
 * Called from the main thread.
 */
- (void)barcodePickViewDidFreezeScanning:(SDCBarcodePickView *)view;
/**
 * Added in version 6.20.0
 *
 * Callback method invoked when the scanning is paused.
 * Called from the main thread.
 */
- (void)barcodePickViewDidPauseScanning:(SDCBarcodePickView *)view;
/**
 * Added in version 6.20.0
 *
 * Callback method invoked when the scanning is stopped.
 * Called from the main thread.
 */
- (void)barcodePickViewDidStopScanning:(SDCBarcodePickView *)view;

@end

/**
 * Added in version 6.19.0
 *
 * BarcodePickView.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickView)
@interface SDCBarcodePickView : UIView

/**
 * Added in version 6.20.0
 *
 * Sets the delegate which is called whenever the finish button is tapped from the view.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodePickViewUIDelegate> UIDelegate;

/**
 * Added in version 6.19.0
 *
 * Initializes a BarcodePickView
 */
- (instancetype)initWithFrame:(CGRect)frame
                      context:(SDCDataCaptureContext *)context
                  barcodePick:(SDCBarcodePick *)barcodePick
                     settings:(SDCBarcodePickViewSettings *)viewSettings;

/**
 * Added in version 6.19.0
 *
 * Initializes a BarcodePickView
 */
- (instancetype)initWithFrame:(CGRect)frame
                      context:(SDCDataCaptureContext *)context
                  barcodePick:(SDCBarcodePick *)barcodePick
                     settings:(SDCBarcodePickViewSettings *)viewSettings
               cameraSettings:(nullable SDCCameraSettings *)cameraSettings;

/**
 * Added in version 6.20.0
 *
 * Add a SDCBarcodePickViewListener to the mode. User actions will be notified to the listener.
 */
- (void)addListener:(nonnull id<SDCBarcodePickViewListener>)listener NS_SWIFT_NAME(addListener(_:));

/**
 * Added in version 6.20.0
 *
 * Removes a SDCBarcodePickViewListener.
 */
- (void)removeListener:(nonnull id<SDCBarcodePickViewListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 6.19.0
 *
 * Add a SDCBarcodePickActionListener to the mode. User actions will be notified to the listener.
 */
- (void)addActionListener:(nonnull id<SDCBarcodePickActionListener>)listener
    NS_SWIFT_NAME(addActionListener(_:));
/**
 * Added in version 6.19.0
 *
 * Removes a SDCBarcodePickActionListener.
 */
- (void)removeActionListener:(nonnull id<SDCBarcodePickActionListener>)listener
    NS_SWIFT_NAME(removeActionListener(_:));

/**
 * Added in version 6.19.0
 *
 * Starts the camera and the scanning process. Can be stopped by calling pause.
 *
 * For instance, it can be called when the view controller containing the view is presented (i.e., UIViewController’s viewWillAppear).
 */
- (void)start;
/**
 * Added in version 6.20.0
 *
 * Freezes the camera and the highlights position to make the selection easier. The scanning can be started again using start.
 */
- (void)freeze;
/**
 * Added in version 6.19.0
 *
 * Pauses the camera and the scanning process. It can be started again using start.
 */
- (void)pause;
/**
 * Added in version 6.19.0
 *
 * Stops the camera and the scanning process. After this call the view should not be used anymore.
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
