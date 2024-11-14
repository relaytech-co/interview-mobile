/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCSparkScan;
@class SDCSparkScanSettings;
@protocol SDCSparkScanDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.16.0
 *
 * A deserializer to construct SparkScan from JSON. For most use cases it is enough to use SDCSparkScan.sparkScanFromJSONString:error: which internally uses this deserializer. Using the deserializer gives the advantage of being able to listen to the deserialization events as they happen and potentially influence them. Additionally warnings can be read from the deserializer that would otherwise not be available.
 */
NS_SWIFT_NAME(SparkScanDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanDeserializer : NSObject

/**
 * Added in version 6.16.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCSparkScanDeserializerDelegate> delegate;
/**
 * Added in version 6.16.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

/**
 * Added in version 6.16.0
 *
 * Creates a new deserializer object.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Added in version 6.16.0
 *
 * Deserializes SparkScan from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCSparkScan *)modeFromJSONString:(NSString *)JSONString
                                        error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.16.0
 *
 * Takes an existing SparkScan and updates it by deserializing new or changed properties from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCSparkScan *)updateMode:(SDCSparkScan *)sparkScan
                       fromJSONString:(NSString *)JSONString
                                error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.16.0
 *
 * Deserializes SparkScan settings from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCSparkScanSettings *)settingsFromJSONString:(NSString *)JSONString
                                                    error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.16.0
 *
 * Takes existing SparkScan settings and updates them by deserializing new or changed properties from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCSparkScanSettings *)updateSettings:(SDCSparkScanSettings *)settings
                                   fromJSONString:(NSString *)JSONString
                                            error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
