/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCBarcodeSelectionDeserializer;
@class SDCBarcodeSelection;
@class SDCBarcodeSelectionSettings;
@class SDCBarcodeSelectionBasicOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.10.0
 *
 * The listener for the barcode selection deserializer.
 */
NS_SWIFT_NAME(BarcodeSelectionDeserializerDelegate)
@protocol SDCBarcodeSelectionDeserializerDelegate <NSObject>

/**
 * Added in version 6.10.0
 *
 * Called before the deserialization of barcode selection started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
           didStartDeserializingMode:(SDCBarcodeSelection *)mode
                       fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.10.0
 *
 * Called when the deserialization of barcode selection finished. This is the point to do additional deserialization.
 */
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
          didFinishDeserializingMode:(SDCBarcodeSelection *)mode
                       fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.10.0
 *
 * Called before the deserialization of the barcode selection settings started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
       didStartDeserializingSettings:(SDCBarcodeSelectionSettings *)settings
                       fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.10.0
 *
 * Called when the deserialization of the barcode selection settings finished. This is the point to do additional deserialization.
 */
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
      didFinishDeserializingSettings:(SDCBarcodeSelectionSettings *)settings
                       fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.10.0
 *
 * Called before the deserialization of the barcode selection basic overlay started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
    didStartDeserializingBasicOverlay:(SDCBarcodeSelectionBasicOverlay *)overlay
                        fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.10.0
 *
 * Called when the deserialization of the barcode selection basic overlay finished. This is the point to do additional deserialization.
 */
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
    didFinishDeserializingBasicOverlay:(SDCBarcodeSelectionBasicOverlay *)overlay
                         fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
