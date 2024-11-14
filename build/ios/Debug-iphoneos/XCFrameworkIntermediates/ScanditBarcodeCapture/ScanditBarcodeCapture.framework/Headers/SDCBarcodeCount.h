/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureMode.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCBarcodeCount;
@class SDCBarcodeCountFeedback;
@class SDCBarcodeCountSession;
@class SDCBarcodeCountSettings;
@class SDCCameraSettings;
@class SDCDataCaptureContext;
@class SDCBarcodeCountCaptureList;
@class SDCBarcode;
@protocol SDCFrameData;

/**
 * Added in version 6.14.0
 *
 * The BarcodeCount delegate is the main way for hooking into BarcodeCount. It provides a callback that is invoked when the state of tracked barcodes changes.
 */
NS_SWIFT_NAME(BarcodeCountListener)
@protocol SDCBarcodeCountListener <NSObject>

@required

/**
 * Added in version 6.15.0
 *
 * Invoked once scanning phase is over.
 */
- (void)barcodeCount:(nonnull SDCBarcodeCount *)barcodeCount
    didScanInSession:(nonnull SDCBarcodeCountSession *)session
           frameData:(nonnull id<SDCFrameData>)frameData;

@optional
- (void)barcodeCount:(nonnull SDCBarcodeCount *)barcodeCount
    didUpdateSession:(nonnull SDCBarcodeCountSession *)session
           frameData:(nonnull id<SDCFrameData>)frameData;
/**
 * Added in version 6.14.0
 *
 * Called when the listener starts observing the BarcodeCount instance.
 */
- (void)didStartObservingBarcodeCount:(nonnull SDCBarcodeCount *)barcodeCount;
/**
 * Added in version 6.14.0
 *
 * Called when the listener stops observing the BarcodeCount instance.
 */
- (void)didStopObservingBarcodeCount:(nonnull SDCBarcodeCount *)barcodeCount;

@end

/**
 * Added in version 6.14.0
 *
 * Barcode Count is a data capture mode that implements MatrixScan Count in use cases that include a counting workflow such as receiving, inventory count, and stock taking. MatrixScan Count is an out-of-the-box scan and count solution that enables faster and more accurate counting of multiple items at once.
 *
 * Learn more on how to use Barcode Count in our Get Started guide.
 *
 * This capture mode uses the barcode scanning and tracking capabilities. It cannot be used together with other capture modes that require the same capabilities, e.g. SDCBarcodeCapture.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCount)
@interface SDCBarcodeCount : NSObject <SDCDataCaptureMode>

/**
 * Added in version 6.14.0
 *
 * Returns the recommended camera settings for use with barcode count.
 */
@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;
/**
 * Added in version 6.14.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.context.
 */
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
/**
 * Added in version 6.14.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.enabled.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
/**
 * Added in version 6.14.0
 *
 * Instance of SDCBarcodeCountFeedback that is used by the barcode scanner to notify users about Success and Failure events.
 *
 * The default instance of the Feedback will have both sound and vibration enabled. A default beep sound will be used for the sound.
 */
@property (nonatomic, strong, nonnull) SDCBarcodeCountFeedback *feedback;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.14.0
 *
 * Constructs a new barcode count mode with the provided context and settings. When the context is not nil, the capture mode is automatically added to the context.
 */
+ (instancetype)barcodeCountWithContext:(nullable SDCDataCaptureContext *)context
                               settings:(nonnull SDCBarcodeCountSettings *)settings;

/**
 * Added in version 6.14.0
 *
 * Asynchronously applies the new settings to the barcode scanner, then calls whenDone. If the scanner is currently running, the task will complete when the next frame is processed, and will use the new settings for that frame. If the scanner is currently not running, the task will complete as soon as the settings have been stored and won’t wait until the next frame is going to be processed.
 */
- (void)applySettings:(nonnull SDCBarcodeCountSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

/**
 * Added in version 6.14.0
 *
 * Adds the listener to observe this barcode capture instance.
 *
 * If the listener is already observing the barcode count instance, calling this method has no effect.
 */
- (void)addListener:(nonnull id<SDCBarcodeCountListener>)listener NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.14.0
 *
 * Removes a previously added listener from this barcode count instance.
 *
 * If the listener is not currently observing the barcode count instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCBarcodeCountListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 6.14.0
 *
 * Starts the capture session. If the enabled is false, this call has no effect.
 */
- (void)startScanningPhase;
/**
 * Added in version 6.15.0
 *
 * Disables this mode and switches off the current SDCFrameSource.
 */
- (void)endScanningPhase;
/**
 * Added in version 6.14.0
 *
 * Resets the session, effectively clearing the history of tracked and unscanned barcodes.
 */
- (void)reset;

/**
 * Added in version 6.15.0
 *
 * Enables “Scanning against a list” mode, which provides additional functionality when looking for a specific set of Barcodes.
 */
- (void)setCaptureList:(nullable SDCBarcodeCountCaptureList *)captureList;

/**
 * Added in version 6.16.0
 *
 * Use this method to inject barcodes that will be used as partial scanning result. SDCBarcodeCountView will consider these barcodes when updating the UI.
 * Note that, if scanning against a list where multiple instances of the same barcode are expected, each entry in this list will only count as 1 towards the expected total. In order to specify that several instances of a barcode were scanned in previous sessions, this list should include one entry per each of those instances.
 */
- (void)setAdditionalBarcodes:(NSArray<SDCBarcode *> *)additionalBarcodes;
/**
 * Added in version 6.16.0
 *
 * Clears the additional barcodes.
 */
- (void)clearAdditionalBarcodes;

@end

NS_ASSUME_NONNULL_END
