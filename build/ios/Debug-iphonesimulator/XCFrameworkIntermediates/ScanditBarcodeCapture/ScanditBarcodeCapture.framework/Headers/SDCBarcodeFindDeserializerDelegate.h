/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

@class SDCBarcodeFindDeserializer;
@class SDCBarcodeFind;
@class SDCBarcodeFindSettings;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.19.0
 *
 * The delegate for the BarcodeFind deserializer.
 */
NS_SWIFT_NAME(BarcodeFindDeserializerDelegate)
@protocol SDCBarcodeFindDeserializerDelegate <NSObject>

/**
 * Added in version 6.19.0
 *
 * Called before the deserialization of BarcodeFind is started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeFindDeserializer:(SDCBarcodeFindDeserializer *)deserializer
      didStartDeserializingMode:(SDCBarcodeFind *)mode
                  fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.19.0
 *
 * Called when the deserialization of BarcodeFind is finished. This is the point to do additional deserialization.
 */
- (void)barcodeFindDeserializer:(SDCBarcodeFindDeserializer *)deserializer
     didFinishDeserializingMode:(SDCBarcodeFind *)mode
                  fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.19.0
 *
 * Called before the deserialization of the BarcodeFind settings is started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeFindDeserializer:(SDCBarcodeFindDeserializer *)deserializer
    didStartDeserializingSettings:(SDCBarcodeFindSettings *)settings
                    fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.19.0
 *
 * Called when the deserialization of the BarcodeFind settings is finished. This is the point to do additional deserialization.
 */
- (void)barcodeFindDeserializer:(SDCBarcodeFindDeserializer *)deserializer
    didFinishDeserializingSettings:(SDCBarcodeFindSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
