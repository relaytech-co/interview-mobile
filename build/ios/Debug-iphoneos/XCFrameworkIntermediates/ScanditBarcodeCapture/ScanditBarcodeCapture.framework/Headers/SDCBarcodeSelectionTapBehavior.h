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
 * Enum used to specify what happens when the user taps a barcode.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeSelectionTapBehavior) {
/**
     * Added in version 6.6.0
     *
     * Tapping an unselected barcode selects it. Tapping an already selected barcode will unselect it.
     */
    SDCBarcodeSelectionTapBehaviorToggleSelection,
/**
     * Added in version 6.6.0
     *
     * Tapping an unselected barcode selects it. Tapping on an already selected barcode will increment the count returned by SDCBarcodeSelectionSession.countForBarcode:.
     */
    SDCBarcodeSelectionTapBehaviorRepeatSelection
} NS_SWIFT_NAME(BarcodeSelectionTapBehavior);

/**
 * Added in version 6.10.0
 *
 * Deserialize the barcode selection tap behavior from a JSON string.
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCBarcodeSelectionTapBehaviorFromJSONString(NSString *_Nonnull JSONString,
                                                             SDCBarcodeSelectionTapBehavior *_Nonnull tapBehavior) DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");

/**
 * Added in version 6.10.0
 *
 * Serialize the barcode selection tap behavior in a JSON string.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeSelectionTapBehavior(SDCBarcodeSelectionTapBehavior tapBehavior) NS_SWIFT_NAME(getter:SDCBarcodeSelectionTapBehavior.jsonString(self:));

