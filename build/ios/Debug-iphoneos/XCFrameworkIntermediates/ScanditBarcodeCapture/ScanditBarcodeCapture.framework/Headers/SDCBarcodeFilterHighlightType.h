/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.15.0
 *
 * The type of highlight applied to the filtered barcodes.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeFilterHighlightType) {
/**
     * Added in version 6.15.0
     *
     * A quadrilateral filled with a solid color will be drawn over filtered barcodes.
     */
    SDCBarcodeFilterHighlightTypeBrush
};

/**
 * Added in version 6.18.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN NSString *_Nonnull SDCBarcodeFilterHighlightTypeToString(SDCBarcodeFilterHighlightType type)
    DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future")
    NS_SWIFT_NAME(getter:SDCBarcodeFilterHighlightType.jsonString(self:));

/**
 * Added in version 6.18.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN SDCBarcodeFilterHighlightType SDCBarcodeFilterHighlightTypeFromString(NSString *_Nonnull value)
    DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future")
    NS_SWIFT_NAME(SDCBarcodeFilterHighlightType.fromJsonString(_:));

