/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCControl.h>
#import <ScanditCaptureCore/SDCBase.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

@class SDCZoomSwitchControl;

/**
 * Added in version 6.18.0
 *
 * Listener for observing the zoom changes. This listener is typically used when you want to react to zoom control being tapped to update UI elements or similar.
 */
NS_SWIFT_NAME(ZoomSwitchControlListener)
@protocol SDCZoomSwitchControlListener <NSObject>
/**
 * Added in version 6.18.0
 *
 * Called when a zoom in action triggered.
 */
- (void)zoomControlDidZoomIn:(SDCZoomSwitchControl *)zoomControl;
/**
 * Added in version 6.18.0
 *
 * Called when a zoom out action triggered.
 */
- (void)zoomControlDidZoomOut:(SDCZoomSwitchControl *)zoomControl;
@end

/**
 * Added in version 6.10.0
 *
 * Control that allows to switch between two camera zoom levels defined by SDCCameraSettings.zoomFactor and SDCCameraSettings.zoomGestureZoomFactor.
 *
 * You can add this control to a view by calling SDCDataCaptureView.addControl:.
 */
NS_SWIFT_NAME(ZoomSwitchControl)
SDC_EXPORTED_SYMBOL
@interface SDCZoomSwitchControl : NSObject <SDCControl>

/**
 * Added in version 6.10.0
 *
 * The button image displayed when the zoom level is set to 1x.
 */
@property (nonatomic, strong, nonnull) UIImage *zoomedOutImage;
/**
 * Added in version 6.10.0
 *
 * The button image displayed when the zoom level is set to 1x and the button is pressed.
 */
@property (nonatomic, strong, nonnull) UIImage *zoomedOutPressedImage;
/**
 * Added in version 6.10.0
 *
 * The button image displayed when the zoom level is set to 2x.
 */
@property (nonatomic, strong, nonnull) UIImage *zoomedInImage;
/**
 * Added in version 6.10.0
 *
 * The button image displayed when the zoom level is set to 2x and pressed.
 */
@property (nonatomic, strong, nonnull) UIImage *zoomedInPressedImage;

/**
 * Added in version 6.10.0
 *
 * The default button image displayed when the zoom level is set to 1x.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedOutImage;
/**
 * Added in version 6.10.0
 *
 * The default button image displayed when the zoom level is set to 1x and the button is pressed.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedOutPressedImage;
/**
 * Added in version 6.10.0
 *
 * The default button image displayed when the zoom level is set to 2x.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedInImage;
/**
 * Added in version 6.10.0
 *
 * The default button image displayed when the zoom level is set to 2x and pressed.
 */
@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedInPressedImage;

/**
 * Added in version 6.10.0
 *
 * Constructs a new zoom switch control with the provided JSON serialization.
 */
+ (nullable instancetype)zoomSwitchControlFromJSONString:(nonnull NSString *)JSONString
                                                   error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.10.0
 *
 * Updates the control according to a JSON serialization.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.18.0
 *
 * Adds the listener to this control.
 */
- (void)addListener:(nonnull id<SDCZoomSwitchControlListener>)listener;
/**
 * Added in version 6.18.0
 *
 * Removes a previously added listener from this control.
 */
- (void)removeListener:(nonnull id<SDCZoomSwitchControlListener>)listener;

@end

NS_ASSUME_NONNULL_END
