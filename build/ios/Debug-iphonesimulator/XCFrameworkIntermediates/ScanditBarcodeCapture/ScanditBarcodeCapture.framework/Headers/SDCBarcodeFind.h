/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeFindTransformer.h>

@class SDCBarcodeFind;
@class SDCBarcodeFindFeedback;
@class SDCBarcodeFindItem;
@class SDCBarcodeFindSettings;
@class SDCDataCaptureContext;
@class SDCCameraSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.18.0
 *
 * Delegate protocol for BarcodeFind.
 */
NS_SWIFT_NAME(BarcodeFindListener)
@protocol SDCBarcodeFindListener <NSObject>

@optional

/**
 * Added in version 6.18.0
 *
 * Invoked whenever the search process has been started.
 *
 * This method is invoked from a recognition internal thread. To perform UI work, you must dispatch to the main thread first.
 */
- (void)barcodeFindDidStartSearch:(SDCBarcodeFind *)barcodeFind;
/**
 * Added in version 6.18.0
 *
 * Invoked whenever the search process has been paused. The foundItems parameter contains all the items found on the last processed camera frame.
 *
 * This method is invoked from a recognition internal thread. To perform UI work, you must dispatch to the main thread first.
 */
- (void)barcodeFind:(SDCBarcodeFind *)barcodeFind
     didPauseSearch:(NSSet<SDCBarcodeFindItem *> *)foundItems;
/**
 * Added in version 6.18.0
 *
 * Invoked whenever the search process has been stopped. The foundItems parameter contains all the items found since the start of the process.
 *
 * This method is invoked from a recognition internal thread. To perform UI work, you must dispatch to the main thread first.
 */
- (void)barcodeFind:(SDCBarcodeFind *)barcodeFind
      didStopSearch:(NSSet<SDCBarcodeFindItem *> *)foundItems;

@end

/**
 * Added in version 6.18.0
 *
 * Capture mode that implements BarcodeFind.
 *
 * This capture mode uses the barcode scanning and tracking capabilities. It cannot be used together with other capture modes that require the same capabilities, e.g. SDCBarcodeCapture.
 */
NS_SWIFT_NAME(BarcodeFind)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFind : NSObject

/**
 * Added in version 6.18.0
 *
 * The context this mode is attached to. When the data capture mode is not attached to a context, nil is returned.
 */
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
/**
 * Added in version 6.18.0
 *
 * Instance of SDCBarcodeFindFeedback that is used by the barcode scanner to notify users about Found events.
 *
 * The default instance of the Feedback will have both sound and vibration enabled. A default beep sound will be used for the sound.
 */
@property (nonatomic, strong, nonnull) SDCBarcodeFindFeedback *feedback;
/**
 * Added in version 6.18.0
 *
 * This flag indicates whether the BarcodeFind mode is currently processing frames to recognise barcodes.
 *
 * Changing this property from NO to YES causes the connected SDCBarcodeFindView to start its scanning flow.
 *
 * Changing this property from YES to NO causes the connected SDCBarcodeFindView to stop its scanning flow and go to idle mode.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
/**
 * Added in version 6.18.0
 *
 * Returns the recommended camera settings for use with barcode find.
 */
@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.18.0
 *
 * Construct a new BarcodeFind mode with the provided settings.
 */
- (instancetype)initWithSettings:(nonnull SDCBarcodeFindSettings *)settings;

/**
 * Added in version 6.18.0
 *
 * Asynchronously applies the new settings to the barcode scanner. If the scanner is currently running, the task will complete when the next frame is processed, and will use the new settings for that frame. If the scanner is currently not running, the task will complete as soon as the settings have been stored and won’t wait until the next frame is going to be processed.
 */
- (void)applySettings:(nonnull SDCBarcodeFindSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

/**
 * Added in version 6.18.0
 *
 * Adds the listener to this BarcodeFind instance.
 *
 * In case the same listener is already observing this instance, calling this method will not add the listener again. The listener is stored using a weak reference and must thus be retained by the caller for it to not go out of scope.
 */
- (void)addListener:(nonnull id<SDCBarcodeFindListener>)listener NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.18.0
 *
 * Removes a previously added listener from this BarcodeFind instance.
 *
 * In case the listener is not currently observing this instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCBarcodeFindListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 6.18.0
 *
 * Sets the list of items to search. This method runs asynchronously.
 */
- (void)setItemList:(nonnull NSSet<SDCBarcodeFindItem *> *)items;
/**
 * Added in version 6.21.0
 *
 * Sets a transformer for this instance of BarcodeFind.
 */
- (void)setBarcodeTransformer:(id<SDCBarcodeFindTransformer>)barcodeTransformer;
/**
 * Added in version 6.18.0
 *
 * Starts or resumes the search process.
 */
- (void)start;
/**
 * Added in version 6.18.0
 *
 * Stops the search process and clears the list of found items. If this is not called, the BarcodeFind instance will remember all found items.
 */
- (void)stop;
/**
 * Added in version 6.18.0
 *
 * Pauses the search process.
 */
- (void)pause;

@end

NS_ASSUME_NONNULL_END
