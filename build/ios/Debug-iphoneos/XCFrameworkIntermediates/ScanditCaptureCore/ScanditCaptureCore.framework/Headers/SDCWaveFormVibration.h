/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCVibration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * A wave form vibration, to be emitted for example when a code has been successfully scanned.
 */
NS_SWIFT_NAME(WaveFormVibration)
SDC_EXPORTED_SYMBOL
@interface SDCWaveFormVibration : SDCVibration

/**
 * Added in version 6.17.0
 *
 * Returns the timings of the WaveFormVibration.
 */
@property (nonatomic, nonnull, readonly) NSArray<NSNumber *> *timings NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.17.0
 *
 * Returns the amplitudes of the WaveFormVibration.
 */
@property (nonatomic, nullable, readonly) NSArray<NSNumber *> *amplitudes NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.17.0
 *
 * Returns the JSON representation of the vibration.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.17.0
 *
 * Creates a new WaveFormVibration object with timings.
 */
- (instancetype)initWithTimings:(nonnull NSArray<NSNumber *> *)timings NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.17.0
 *
 * Creates a new WaveFormVibration object with timings and amplitudes.
 */
- (instancetype)initWithTimings:(nonnull NSArray<NSNumber *> *)timings
                     amplitudes:(nullable NSArray<NSNumber *> *)amplitudes NS_REFINED_FOR_SWIFT;

@end

NS_ASSUME_NONNULL_END
