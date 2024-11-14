/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.6.0
 *
 * Enum used to specify how freezing of the frame preview should be handled. Freezing the preview helps the user select multiple codes which might be difficult to do on a live preview where the codes constantly move around a bit.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeSelectionFreezeBehavior) {
/**
     * Added in version 6.6.0
     *
     * The frame preview can only be frozen manually by double tapping anywhere on the screen.
     */
    SDCBarcodeSelectionFreezeBehaviorManual,
/**
     * Added in version 6.6.0
     *
     * The frame preview is automatically frozen when all barcodes in view are recognized. It can also be frozen manually by double tapping anywhere on the screen.
     *
     * @remark This setting is still in beta and may not yet work reliably in all situations.
     */
    SDCBarcodeSelectionFreezeBehaviorManualAndAutomatic
} NS_SWIFT_NAME(BarcodeSelectionFreezeBehavior);

/**
 * Added in version 6.10.0
 *
 * Deserialize the barcode selection freeze behavior from a JSON string.
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCBarcodeSelectionFreezeBehaviorFromJSONString(NSString *_Nonnull JSONString,
                                                                SDCBarcodeSelectionFreezeBehavior *_Nonnull freezeBehavior) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.10.0
 *
 * Serialize the barcode selection freeze behavior in a JSON string.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeSelectionFreezeBehavior(SDCBarcodeSelectionFreezeBehavior freezeBehavior) NS_SWIFT_NAME(getter:SDCBarcodeSelectionFreezeBehavior.jsonString(self:));

