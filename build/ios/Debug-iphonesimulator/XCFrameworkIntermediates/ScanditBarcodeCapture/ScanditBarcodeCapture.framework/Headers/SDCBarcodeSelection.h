/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureMode.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCDataCaptureContext;
@class SDCCameraSettings;
@class SDCBarcode;
@class SDCBarcodeSelectionSettings;
@class SDCBarcodeSelectionSession;
@class SDCBarcodeSelectionFeedback;
@class SDCBarcodeSelection;
@class SDCBarcodeSelectionLicenseInfo;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.6.0
 *
 * The BarcodeSelection delegate is the main way for hooking into BarcodeSelection. It provides a callback that is invoked when the state of selected barcodes changes.
 */
NS_SWIFT_NAME(BarcodeSelectionListener)
@protocol SDCBarcodeSelectionListener <NSObject>

@required

/**
 * Added in version 6.6.0
 *
 * Invoked whenever a barcode is selected or a previously selected barcode is unselected.
 *
 * SDCFrameData is nil if the camera is frozen and the selection is changed.
 */
- (void)barcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
      didUpdateSelection:(nonnull SDCBarcodeSelectionSession *)session
               frameData:(nullable id<SDCFrameData>)frameData;

@optional

/**
 * Added in version 6.6.0
 *
 * Invoked after a frame has been processed by barcode selection and the session has been updated. In contrast to barcodeSelection:didUpdateSelection:frameData:, this method is invoked, regardless whether a code was selected or not.
 *
 * SDCFrameData is nil if the camera is frozen and the selection is changed.
 */
- (void)barcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
        didUpdateSession:(nonnull SDCBarcodeSelectionSession *)session
               frameData:(nullable id<SDCFrameData>)frameData;

/**
 * Added in version 6.6.0
 *
 * Called when the listener starts observing the BarcodeSelection instance.
 */
- (void)didStartObservingBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection;

/**
 * Added in version 6.6.0
 *
 * Called when the listener stops observing the BarcodeSelection instance.
 */
- (void)didStopObservingBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection;

@end

/**
 * Added in version 6.6.0
 *
 * Data capture mode that implements barcode selection.
 *
 * Learn more on how to use Barcode Selection in our Get Started guide.
 *
 * This capture mode uses the barcode scanning and tracking capabilities. It cannot be used together with other capture modes that require the same capabilities, e.g. SDCBarcodeCapture.
 */
NS_SWIFT_NAME(BarcodeSelection)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelection : NSObject <SDCDataCaptureMode>

/**
 * Added in version 6.6.0
 *
 * Returns the recommended camera settings for use with barcode selection.
 */
@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;
/**
 * Added in version 6.6.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.context.
 */
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
/**
 * Added in version 6.6.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.enabled.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
/**
 * Added in version 6.6.0
 *
 * The point of interest overwriting the point of interest of the data capture view.
 * By default, this overwriting point of interest is not set and the one from the data capture view is used.
 *
 * Use SDCPointWithUnitNull (FloatWithUnit.null in Swift) to unset the point of interest.
 */
@property (nonatomic, assign) SDCPointWithUnit pointOfInterest;
/**
 * Added in version 6.6.0
 *
 * Instance of SDCBarcodeSelectionFeedback that is used by barcode selection to notify users about the selection of a barcode.
 *
 * The default instance of the Feedback will have the sound enabled but no vibration. A default click tone will be used for the sound.
 *
 * To change the feedback emitted, the SDCBarcodeSelectionFeedback can be modified as shown below, or a new one can be assigned.
 *
 * @code
 * let barcodeSelection: BarcodeSelection = ...
 * barcodeSelection.feedback.selection = Feedback(vibration: nil, sound: Sound.default)
 * @endcode
 */
@property (nonatomic, strong, nonnull) SDCBarcodeSelectionFeedback *feedback;

/**
 * Added in version 6.12.0
 *
 * The object containing information about barcode selection licensing.
 *
 * @remark This value is available with a small delay. To make sure it is available, set a SDCDataCaptureContextListener and, as soon as SDCDataCaptureContextListener.context:didAddMode: is called, this license object is available.
 */
@property (nonatomic, nullable, readonly) SDCBarcodeSelectionLicenseInfo *barcodeSelectionLicenseInfo;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.6.0
 *
 * Constructs a new barcode selection mode with the provided context and settings. When the context is not nil, the capture mode is automatically added to the context.
 */
+ (instancetype)barcodeSelectionWithContext:(nullable SDCDataCaptureContext *)context
                                   settings:(nonnull SDCBarcodeSelectionSettings *)settings
    NS_SWIFT_NAME(init(context:settings:));
;

/**
 * Added in version 6.10.0
 *
 * Construct a new barcode selection mode with the provided JSON serialization. The capture mode is automatically added to the context.
 */
+ (nullable instancetype)barcodeSelectionFromJSONString:(nonnull NSString *)JSONString
                                                context:(nonnull SDCDataCaptureContext *)context
                                                  error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:context:));

/**
 * Added in version 6.6.0
 *
 * Asynchronously applies the new settings to the barcode selection. If the barcode selection is currently running, the task will complete when the next frame is processed, and will use the new settings for that frame. If the barcode selection is currently not running, the task will complete as soon as the settings have been stored and won’t wait until the next frame is going to be processed.
 */
- (void)applySettings:(nonnull SDCBarcodeSelectionSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

/**
 * Added in version 6.6.0
 *
 * Adds the listener to this barcode selection instance.
 *
 * In case the same listener is already observing this instance, calling this method will not add the listener again. The listener is stored using a weak reference and must thus be retained by the caller for it to not go out of scope.
 */
- (void)addListener:(nonnull id<SDCBarcodeSelectionListener>)listener
    NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.6.0
 *
 * Removes a previously added listener from this barcode selection instance.
 *
 * In case the listener is not currently observing this instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCBarcodeSelectionListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 6.12.0
 *
 * Select all the unselected barcodes that are being tracked in current the barcode selection session. This action is dispatched asynchronously and may happen on the next frame.
 */
- (void)selectUnselectedBarcodes;

/**
 * Added in version 6.12.0
 *
 * Freeze the camera.
 */
- (void)freezeCamera;
/**
 * Added in version 6.6.0
 *
 * Unfreeze the camera.
 */
- (void)unfreezeCamera;
/**
 * Added in version 6.16.0
 *
 * Select the barcode being aimed at. Only use this with manual aimer selection.
 */
- (void)selectAimedBarcode;

/**
 * Added in version 6.6.0
 *
 * Asynchronously resets the barcode selection session, effectively clearing the history of selected codes.
 */
- (void)reset;

/**
 * Added in version 6.17.0
 *
 * Enables or disables the selection of a barcode.
 */
- (void)setSelectBarcode:(nonnull SDCBarcode *)barcode enabled:(BOOL)enabled;
/**
 * Added in version 6.17.0
 *
 * Enables or disables the selection of the barcode represented by the given JSON string.
 */
- (void)setSelectBarcodeFromJsonString:(nonnull NSString *)jsonString enabled:(BOOL)enabled;

/**
 * Added in version 6.10.0
 *
 * Updates the mode according to a JSON serialization.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.17.0
 *
 * Remove the barcodes from the list of selected barcodes.
 */
- (void)unselectBarcodes:(NSArray<SDCBarcode *> *)barcodes;
/**
 * Added in version 6.17.0
 *
 * Remove the barcodes contained in the given JSON string from the list of selected barcodes.
 * The parameter json must be the JSON serialization of an object containing the barcodes inside an array named barcodes.
 * For example:
 *
 * @code
 * {
 *   "barcodes": [
 *     {
 *         "data":"9783598215056",
 *         "rawData":"OTc4MzU5ODIxNTA1Ng==",
 *         "symbolCount":12,
 *         "symbology":"ean13Upca"
 *     }
 *   ]
 * }
 * @endcode
 */
- (void)unselectBarcodesFromJsonString:(NSString *)json;
/**
 * Added in version 6.17.0
 *
 * Increments the count of how many times the given barcodes have been selected.
 */
- (void)increaseCountForBarcodes:(NSArray<SDCBarcode *> *)barcodes;
/**
 * Added in version 6.17.0
 *
 * Increments the count of how many times the given barcodes have been selected.
 * The parameter json must be the JSON serialization of an object containing the barcodes inside an array named barcodes.
 * For example:
 *
 * @code
 * {
 *   "barcodes": [
 *     {
 *         "data":"9783598215056",
 *         "rawData":"OTc4MzU5ODIxNTA1Ng==",
 *         "symbolCount":12,
 *         "symbology":"ean13Upca"
 *     }
 *   ]
 * }
 * @endcode
 */
- (void)increaseCountForBarcodesFromJsonString:(NSString *)json;

@end

NS_ASSUME_NONNULL_END
