/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.19.0
 *
 * The possible states of an item.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodePickState) {
/**
     * Added in version 6.19.0
     *
     * The item should be ignored in this session.
     */
    SDCBarcodePickStateIgnore,
/**
     * Added in version 6.19.0
     *
     * The item has been picked.
     */
    SDCBarcodePickStatePicked,
/**
     * Added in version 6.19.0
     *
     * The item should be picked.
     */
    SDCBarcodePickStateToPick,
/**
     * Added in version 6.19.0
     *
     * The item has not been mapped to a product.
     */
    SDCBarcodePickStateUnknown,
} NS_SWIFT_NAME(BarcodePickState);

/**
 * Added in version 6.19.0
 */
SDC_EXTERN NSString *_Nonnull SDCBarcodePickStateToString(SDCBarcodePickState state)
    NS_SWIFT_NAME(getter:SDCBarcodePickState.jsonString(self:));

/**
 * Added in version 6.19.0
 */
SDC_EXTERN BOOL SDCBarcodePickStateFromString(NSString *_Nonnull value,
                                              SDCBarcodePickState *_Nonnull state);
