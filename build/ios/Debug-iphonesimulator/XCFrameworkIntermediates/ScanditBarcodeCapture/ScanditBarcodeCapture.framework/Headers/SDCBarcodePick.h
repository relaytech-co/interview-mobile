/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCDataCaptureContext;
@class SDCBarcodePickSettings;
@class SDCBarcodePickProduct;
@class SDCCameraSettings;
@protocol SDCBarcodePickProductProvider;
@protocol SDCBarcodePickScanningListener;
@protocol SDCBarcodePickListener;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.24.0
 *
 * An enumeration of possible actions.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodePickAction) {
/**
     * Added in version 6.24.0
     *
     * No action.
     */
    SDCBarcodePickActionNone,
/**
     * Added in version 6.24.0
     *
     * Pick action.
     */
    SDCBarcodePickActionPick,
/**
     * Added in version 6.24.0
     *
     * Unpick action.
     */
    SDCBarcodePickActionUnpick
} NS_SWIFT_NAME(BarcodePickAction);

/**
 * Added in version 6.19.0
 *
 * Capture mode that implements barcode pick.
 */
NS_SWIFT_NAME(BarcodePick)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodePick : NSObject

/**
 * Added in version 6.19.0
 *
 * Returns the recommended camera settings to use with the mode.
 */
@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.19.0
 *
 * Construct a new SDCBarcodePick instance:
 *
 *   • dataCaptureContext A SDCDataCaptureContext
 *
 *   • settings An instance of SDCBarcodePickSettings used to configure the mode.
 *
 *   • productProvider The product provider responsible for retrieving and mapping products. Available product provider types: [SDCBarcodePickAsyncMapperProductProvider]
 */
+ (instancetype)barcodePickWithContext:(SDCDataCaptureContext *)context
                              settings:(SDCBarcodePickSettings *)settings
                       productProvider:(id<SDCBarcodePickProductProvider>)productProvider;

/**
 * Added in version 6.21.0
 *
 * Adds a scanning listener to this SDCBarcodePick instance.
 */
- (void)addScanningListener:(nonnull id<SDCBarcodePickScanningListener>)listener
    NS_SWIFT_NAME(addScanningListener(_:));
/**
 * Added in version 6.21.0
 *
 * Removes the scanning listener from this SDCBarcodePick instance.
 */
- (void)removeScanningListener:(nonnull id<SDCBarcodePickScanningListener>)listener
    NS_SWIFT_NAME(removeScanningListener(_:));

/**
 * Added in version 6.23.0
 *
 * Adds a listener to this SDCBarcodePick instance.
 */
- (void)addListener:(nonnull id<SDCBarcodePickListener>)listener NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.23.0
 *
 * Removes the listener from this SDCBarcodePick instance.
 */
- (void)removeListener:(nonnull id<SDCBarcodePickListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 6.24.0
 *
 * Selects the item with the given data. This causes SDCBarcodePickActionListener.didPickItemWithData:completionHandler: or SDCBarcodePickActionListener.didUnpickItemWithData:completionHandler: to be invoked, depending on the item’s current state. The completion callback specifies the type of action that will be performed.
 */
- (void)selectItemWithData:(nonnull NSString *)data
         completionHandler:(nullable void (^)(SDCBarcodePickAction))completionHandler;

/**
 * Added in version 6.24.0
 *
 * Confirms the action for the item with the given data. Same as invoking the SDCBarcodePickActionListener.didPickItemWithData:completionHandler: (if picking) or SDCBarcodePickActionListener.didUnpickItemWithData:completionHandler: (if unpicking) action callbacks passing YES. Useful as an alternative in scenarios where using such callbacks is not practical. No action is performed if the item is not currently selected.
 */
- (void)confirmActionForItemWithData:(nonnull NSString *)data;
/**
 * Added in version 6.24.0
 *
 * Cancels the action for the item with the given data. Same as invoking the SDCBarcodePickActionListener.didPickItemWithData:completionHandler: (if picking) or SDCBarcodePickActionListener.didUnpickItemWithData:completionHandler: (if unpicking) action callbacks passing NO. Useful as an alternative in scenarios where using such callbacks is not practical. No action is performed if the item is not currently selected.
 */
- (void)cancelActionForItemWithData:(nonnull NSString *)data;

@end

NS_ASSUME_NONNULL_END
