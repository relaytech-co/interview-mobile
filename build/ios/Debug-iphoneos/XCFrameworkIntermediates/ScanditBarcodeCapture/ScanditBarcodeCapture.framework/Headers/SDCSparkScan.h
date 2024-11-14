/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcode;
@class SDCSparkScan;
@class SDCSparkScanFeedback;
@class SDCSparkScanLicenseInfo;
@class SDCSparkScanSession;
@class SDCSparkScanSettings;
@class SDCDataCaptureContext;
@protocol SDCFrameData;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.8.0
 *
 * Delegate protocol for traditional SparkScan.
 */
NS_SWIFT_NAME(SparkScanListener)
@protocol SDCSparkScanListener <NSObject>

@required

/**
 * Added in version 6.8.0
 *
 * Invoked whenever a code has been scanned. The newly scanned barcode can be retrieved from SDCSparkScanSession.newlyRecognizedBarcode.
 *
 * This method is invoked from a recognition internal thread. To perform UI work, you must dispatch to the main thread first. After receiving this callback, you will typically want to start processing the scanned barcodes. Keep in mind however, that any further recognition is blocked until this method completes. Therefore, if you need to perform a time-consuming operation, like querying a database or opening an URL encoded in the barcode data, consider switching to another thread.
 *
 * Sometimes, after receiving this callback, you may want to stop scanning. You can do that by disabling the SparkScan.
 *
 * SDCFrameData is nil if the camera is frozen and the selection is changed.
 */
- (void)sparkScan:(SDCSparkScan *)sparkScan
    didScanInSession:(SDCSparkScanSession *)session
           frameData:(nullable id<SDCFrameData>)frameData;

@optional

/**
 * Added in version 6.8.0
 *
 * Invoked after a frame has been processed by SparkScan and the session has been updated. In contrast to sparkScan:didScanInSession:frameData:, this method is invoked, regardless whether a code was scanned or not. If codes were recognized in this frame, this method is invoked after sparkScan:didScanInSession:frameData:.
 *
 * This method is invoked from a recognition internal thread. To perform UI work, you must dispatch to the main thread first. Further recognition is blocked until this method completes. It is thus recommended to do as little work as possible in this method.
 *
 * SDCFrameData is nil if the camera is frozen and the selection is changed.
 */
- (void)sparkScan:(SDCSparkScan *)sparkScan
    didUpdateSession:(SDCSparkScanSession *)session
           frameData:(nullable id<SDCFrameData>)frameData;

@end

/**
 * Added in version 6.8.0
 *
 * Capture mode that implements SparkScan.
 *
 * This capture mode uses the barcode scanning capability. It cannot be used together with other capture modes that require the same capabilities, e.g. SDCBarcodeCapture.
 */
NS_SWIFT_NAME(SparkScan)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScan : NSObject

/**
 * Added in version 6.8.0
 *
 * The context this mode is attached to. When the data capture mode is not attached to a context, nil is returned.
 */
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
/**
 * Added in version 6.8.0
 *
 * This flag indicates whether the SparkScan mode is currently processing frames to recognise barcodes.
 *
 * Changing this property from NO to YES causes the connected SDCSparkScanView to start its scanning flow.
 *
 * Changing this property from YES to NO causes the connected SDCSparkScanView to stop its scanning flow and go to idle mode.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
/**
 * Added in version 6.8.0
 *
 * Deprecated since version 6.23: The feedback emitted is now specified for each detected barcode. See SDCSparkScanView.feedbackDelegate.
 *
 * Instance of SDCSparkScanFeedback that is used by SparkScan to notify users about a successful scan of a barcode.
 *
 * To change the feedback emitted, the SDCSparkScanFeedback can be modified as shown below, or a new one can be assigned.
 *
 * @code
 * let sparkScan: SparkScan = ...
 * sparkScan.feedback.success = Feedback(vibration: Vibration.impactHapticFeedback, sound: Sound.default)
 * @endcode
 */
@property (nonatomic, strong, nonnull) SDCSparkScanFeedback *feedback DEPRECATED_MSG_ATTRIBUTE(
    "This property does nothing. Use SDCSparkScanFeedbackDelegate instead.");
/**
 * Added in version 6.12.0
 *
 * The object containing information about SparkScan licensing.
 *
 * @remark This value is available with a small delay. To make sure it is available, set a SDCDataCaptureContextListener and, as soon as SDCDataCaptureContextListener.context:didAddMode: is called, this license object is available.
 */
@property (nonatomic, nullable, readonly) SDCSparkScanLicenseInfo *sparkScanLicenseInfo;

+ (instancetype)new NS_UNAVAILABLE;

/**
 * Added in version 6.16.0
 *
 * Construct a new SparkScan mode with default settings.
 */
- (instancetype)init;
/**
 * Added in version 6.16.0
 *
 * Construct a new SparkScan mode with the provided settings.
 */
- (instancetype)initWithSettings:(nonnull SDCSparkScanSettings *)settings NS_DESIGNATED_INITIALIZER;
/**
 * Added in version 6.16.0
 *
 * Construct a new SparkScan mode from the provided json. Check SDCSparkScanDeserializer for more info.
 */
+ (nullable instancetype)sparkScanFromJSONString:(nonnull NSString *)JSONString
                                           error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:));
;

/**
 * Added in version 6.8.0
 *
 * Asynchronously applies the new settings to the barcode scanner. If the scanner is currently running, the task will complete when the next frame is processed, and will use the new settings for that frame. If the scanner is currently not running, the task will complete as soon as the settings have been stored and won’t wait until the next frame is going to be processed.
 */
- (void)applySettings:(nonnull SDCSparkScanSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

/**
 * Added in version 6.8.0
 *
 * Adds the listener to this SparkScan instance.
 *
 * In case the same listener is already observing this instance, calling this method will not add the listener again. The listener is stored using a weak reference and must thus be retained by the caller for it to not go out of scope.
 */
- (void)addListener:(nonnull id<SDCSparkScanListener>)listener NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.8.0
 *
 * Removes a previously added listener from this SparkScan instance.
 *
 * In case the listener is not currently observing this instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCSparkScanListener>)listener NS_SWIFT_NAME(removeListener(_:));

@end

NS_ASSUME_NONNULL_END
