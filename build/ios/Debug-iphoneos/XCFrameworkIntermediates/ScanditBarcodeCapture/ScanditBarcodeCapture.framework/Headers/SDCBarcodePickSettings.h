/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

@class SDCSymbologySettings;
@class SDCArucoDictionary;
@class SDCBarcodeFilterSettings;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.19.0
 *
 * Contains the scanning options for an SDCBarcodePick mode.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickSettings)
@interface SDCBarcodePickSettings : NSObject <NSCopying>

/**
 * Added in version 6.19.0
 *
 * Returns the set of enabled symbologies.
 */
@property (nonatomic, nonnull, readonly) NSSet<NSNumber *> *enabledSymbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.19.0
 *
 * Get SDCSymbologySettings specific for the given SDCSymbology.
 */
- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;
/**
 * Added in version 6.19.0
 *
 * Sets property to the provided value. Use this method to set properties that are not yet part of a stable API. Properties set through this method may or may not be used or change in a future release.
 */
- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));
/**
 * Added in version 6.19.0
 *
 * Retrieves the value of a previously set property. In case the property does not exist, nil is returned.
 */
- (nullable id)valueForProperty:(NSString *)property;
/**
 * Added in version 6.19.0
 *
 * This function provides a convenient shortcut to enabling decoding of particular symbologies without having to go through SDCSymbologySettings.
 * By default, all symbologies are turned off and symbologies need to be explicitly enabled.
 */
- (void)enableSymbologies:(NSSet<NSNumber *> *)symbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.19.0
 *
 * This function provides a convenient shortcut to enabling/disabling decoding of a particular symbology without having to go through SDCSymbologySettings.
 *
 * @remark Some 1d barcode symbologies allow you to encode variable-length data. By default, the Scandit Data Capture SDK only scans barcodes in a certain length range.
 *
 * If your application requires scanning of one of these symbologies, and the length is falling outside the default range, you may need to adjust the active symbol counts for the symbology in addition to enabling it.
 */
- (void)setSymbology:(SDCSymbology)symbology
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(symbology:enabled:));

/**
 * Added in version 6.19.0
 *
 * Sets the SDCArucoDictionary to be used while scanning ArUco codes.
 * When the symbology is enabled the dictionary SDCArucoDictionaryPreset_5X5_1000 is loaded as default.
 */
- (void)setArucoDictionary:(SDCArucoDictionary *)dictionary;

/**
 * Added in version 6.19.0
 *
 * Enables or disables the audio feedback. By default YES.
 */
@property (nonatomic, assign, getter=isSoundEnabled) BOOL soundEnabled;
/**
 * Added in version 6.19.0
 *
 * Enables or disables the haptic feedback. By default YES.
 */
@property (nonatomic, assign, getter=isHapticsEnabled) BOOL hapticsEnabled;
/**
 * Added in version 6.21.0
 *
 * Enables or disables the caching of scanned barcodes to a specific product identifier. Once enabled, the request for product identifier won’t be made if scanned barcodes could be found in cache. By default YES.
 */
@property (nonatomic, assign, getter=isCachingEnabled) BOOL cachingEnabled;
/**
 * Added in version 6.24.0
 *
 * Set and access the barcode filter settings.
 */
@property (nonatomic, strong) SDCBarcodeFilterSettings *filterSettings;

@end

NS_ASSUME_NONNULL_END
