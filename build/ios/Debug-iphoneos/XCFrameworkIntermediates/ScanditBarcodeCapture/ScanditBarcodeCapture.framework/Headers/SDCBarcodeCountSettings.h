/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

@class SDCSymbologySettings;
@class SDCBarcodeFilterSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.14.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountSettings)
@interface SDCBarcodeCountSettings : NSObject <NSCopying>

/**
 * Added in version 6.14.0
 *
 * Returns the set of enabled symbologies.
 */
@property (nonatomic, nonnull, readonly) NSSet<NSNumber *> *enabledSymbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.14.0
 *
 * Declares whether or not the barcodes to be tracked are expected to be unique. If enabled optimizations can be used to improve Barcode Count.
 *
 * @remark Do not enable this if you are expecting to scan multiple barcodes with the same content within one batch.
 */
@property (nonatomic, assign) BOOL expectsOnlyUniqueBarcodes;
/**
 * Added in version 6.15.0
 *
 * Returns the current settings for barcode filtering.
 */
@property (nonatomic, strong) SDCBarcodeFilterSettings *filterSettings;
/**
 * Added in version 6.17.0
 *
 * Use this property to enable barcode mapping.
 *
 * Default value is NO.
 *
 * @remark The Barcode Count mapping API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
@property (nonatomic, assign) BOOL mappingEnabled;
/**
 * Added in version 6.17.0
 *
 * Declares whether or not the mode will be disabled automatically when the provided capture list has been completed. If no list has been provided, this has no effect.
 *
 * Default value is YES.
 */
@property (nonatomic, assign) BOOL disableModeWhenCaptureListCompleted;
/**
 * Added in version 6.17.0
 *
 * Declares whether or not the mode will process unrecognized barcodes. If set to YES, unrecognized barcodes will be shown on screen with a warning icon, and a message will be displayed when any unrecognized barcode is found.
 *
 * By default this property is YES.
 */
@property (nonatomic, assign) BOOL enableUnrecognizedBarcodeDetection;

/**
 * Added in version 6.14.0
 *
 * Get SDCSymbologySettings specific for the given SDCSymbology.
 *
 * Note that modifying the returned object doesn’t automatically apply the changes to SDCBarcodeCount. After you made changes to the symbology settings, call SDCBarcodeCount.applySettings:completionHandler: with these SDCBarcodeCountSettings to apply them.
 */
- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;
/**
 * Added in version 6.14.0
 *
 * Sets property to the provided value. Use this method to set properties that are not yet part of a stable API. Properties set through this method may or may not be used or change in a future release.
 */
- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));
/**
 * Added in version 6.14.0
 *
 * Retrieves the value of a previously set property. In case the property does not exist, -1 is returned.
 */
- (nullable id)valueForProperty:(NSString *)property;
/**
 * Added in version 6.14.0
 *
 * This function provides a convenient shortcut to enabling decoding of particular symbologies without having to go through SDCSymbologySettings.
 * By default, all symbologies are turned off and symbologies need to be explicitly enabled.
 */
- (void)enableSymbologies:(NSSet<NSNumber *> *)symbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.14.0
 *
 * This function provides a convenient shortcut to enabling/disabling decoding of a particular symbology without having to go through SDCSymbologySettings.
 *
 * @remark Some 1d barcode symbologies allow you to encode variable-length data. By default, the Scandit Data Capture SDK only scans barcodes in a certain length range.
 *
 * If your application requires scanning of one of these symbologies, and the length is falling outside the default range, you may need to adjust the active symbol counts for the symbology in addition to enabling it.
 */
- (void)setSymbology:(SDCSymbology)symbology
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(symbology:enabled:));

@end

NS_ASSUME_NONNULL_END
