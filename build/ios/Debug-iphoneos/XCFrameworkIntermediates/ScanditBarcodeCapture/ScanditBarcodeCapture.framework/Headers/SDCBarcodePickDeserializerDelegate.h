/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

@class SDCBarcodePickDeserializer;
@class SDCBarcodePick;
@class SDCBarcodePickSettings;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.19.0
 *
 * The delegate for the BarcodePick deserializer.
 */
NS_SWIFT_NAME(BarcodePickDeserializerDelegate)
@protocol SDCBarcodePickDeserializerDelegate <NSObject>

@optional

/**
 * Added in version 6.19.0
 *
 * Called before the deserialization of BarcodePick is started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodePickDeserializer:(SDCBarcodePickDeserializer *)deserializer
      didStartDeserializingMode:(SDCBarcodePick *)mode
                  fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.19.0
 *
 * Called when the deserialization of BarcodePick is finished. This is the point to do additional deserialization.
 */
- (void)barcodePickDeserializer:(SDCBarcodePickDeserializer *)deserializer
     didFinishDeserializingMode:(SDCBarcodePick *)mode
                  fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.19.0
 *
 * Called before the deserialization of the BarcodePick settings is started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodePickDeserializer:(SDCBarcodePickDeserializer *)deserializer
    didStartDeserializingSettings:(SDCBarcodePickSettings *)settings
                    fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.19.0
 *
 * Called when the deserialization of the BarcodePick settings is finished. This is the point to do additional deserialization.
 */
- (void)barcodePickDeserializer:(SDCBarcodePickDeserializer *)deserializer
    didFinishDeserializingSettings:(SDCBarcodePickSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
