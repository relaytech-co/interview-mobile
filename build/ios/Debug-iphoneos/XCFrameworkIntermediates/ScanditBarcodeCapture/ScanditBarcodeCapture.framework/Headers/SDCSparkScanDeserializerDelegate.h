/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCJSONValue;
@class SDCSparkScan;
@class SDCSparkScanDeserializer;
@class SDCSparkScanSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.16.0
 *
 * The listener for the SparkScan deserializer.
 */
NS_SWIFT_NAME(SparkScanDeserializerDelegate)
@protocol SDCSparkScanDeserializerDelegate <NSObject>

/**
 * Added in version 6.16.0
 *
 * Called before the deserialization of SparkScan started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)sparkScanDeserializer:(SDCSparkScanDeserializer *)deserializer
    didStartDeserializingMode:(SDCSparkScan *)mode
                fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.16.0
 *
 * Called when the deserialization of SparkScan finished. This is the point to do additional deserialization.
 */
- (void)sparkScanDeserializer:(SDCSparkScanDeserializer *)deserializer
    didFinishDeserializingMode:(SDCSparkScan *)mode
                 fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.16.0
 *
 * Called before the deserialization of the SparkScan settings started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)sparkScanDeserializer:(SDCSparkScanDeserializer *)deserializer
    didStartDeserializingSettings:(SDCSparkScanSettings *)settings
                    fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.16.0
 *
 * Called when the deserialization of the SparkScan settings finished. This is the point to do additional deserialization.
 */
- (void)sparkScanDeserializer:(SDCSparkScanDeserializer *)deserializer
    didFinishDeserializingSettings:(SDCSparkScanSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
