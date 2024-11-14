/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>
#import <ScanditBarcodeCapture/SDCCapturePreset.h>
#import <ScanditCaptureCore/SDCBatterySavingMode.h>
#import <ScanditCaptureCore/SDCScanIntention.h>

@class SDCSymbologySettings;
@protocol SDCLocationSelection;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.8.0
 *
 * Holds all the SparkScan settings, such as enabled symbologies and location selection.
 *
 * For the settings to take effect, they must be applied to a SparkScan instance using SDCSparkScan.applySettings:completionHandler:.
 *
 * By default, all types of barcodes (symbologies) are disabled. To scan barcodes, you need to manually enable all the symbologies you want to scan in your application.
 *
 * The following lines of code show how to enable SDCSymbologyCode128 and apply the settings to SparkScan.
 *
 * @code
 * let settings = SparkScanSettings()
 * settings.set(symbology: .code128, enabled: true)
 * sparkScan.apply(settings, completionHandler: nil)
 * @endcode
 */
NS_SWIFT_NAME(SparkScanSettings)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanSettings : NSObject

/**
 * Added in version 6.8.0
 *
 * Determines the time interval in which codes with the same symbology/data are filtered out as duplicates. By default set to 1000ms. Use this property to change the interval or completely turn off duplicate filtering:
 *
 *   • Setting this property to value smaller than zero, means that the same code will not be reported again until the scanning has been stopped.
 *
 *   • Setting this property to a value of zero means that the same code will be reported every time it is found.
 *
 *   • Setting this property to a value larger than zero indicates the time that must pass between the same code to be reported again.
 */
@property (nonatomic, assign) NSTimeInterval codeDuplicateFilter;
/**
 * Added in version 6.8.0
 *
 * Returns the set of enabled symbologies.
 */
@property (nonatomic, nonnull, readonly) NSSet<NSNumber *> *enabledSymbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.20.0
 *
 * The battery saving mode to use with SparkScan. Default to SDCBatterySavingModeAuto, automatically enabling the battery saving mode when a higher than usual consumption of the battery is detected, balancing performance and battery lifetime.
 */
@property (nonatomic, assign) SDCBatterySavingMode batterySaving;
/**
 * Added in version 6.24.0
 *
 * The scan intention algorithm to use with SparkScan. Default to SDCScanIntentionSmart, enabling the automatic algorithm that intelligently identifies and then scans the barcode that the user intends to capture, reducing errors.
 */
@property (nonatomic, assign) SDCScanIntention scanIntention;
/**
 * Added in version 6.16.0
 *
 * Defines the strategy with which to select one out of many visible barcodes. By default, this property is nil and code selection is disabled.
 *
 * Deprecated since version 6.19: With the introduction of smart configurations based on the scanning mode enabled by the users, the locationSelection property is not needed anymore and has been deprecated.
 */
@property (nonatomic, strong, nonnull) id<SDCLocationSelection> locationSelection
    DEPRECATED_MSG_ATTRIBUTE("No longer needed.");
/**
 * Added in version 6.16.0
 *
 * If true, when a single barcode is tracked, it will be automatically selected. Defaults to YES.
 *
 * @remark This property works only when SparkScan is in target mode.
 *
 * Deprecated since version 6.18: With the recent improvements introduced in the target mode, selection of barcodes is easier and more reliable. Given that, this method is outdated and not needed anymore.
 */
@property (nonatomic, assign)
    BOOL singleBarcodeAutoDetection DEPRECATED_MSG_ATTRIBUTE("No longer needed.");

/**
 * Added in version 6.19.0
 *
 * Constructs new Spark Scan settings based on the provided presets, enabling relevant symbologies and optimizations. See SDCCapturePreset for more information on how to use capture presets.
 */
- (instancetype)initWithCapturePresets:(SDCCapturePreset)capturePresets;

/**
 * Added in version 6.8.0
 *
 * Get SDCSymbologySettings specific for the given SDCSymbology.
 *
 * Note that modifying the returned object doesn’t automatically apply the changes to SDCSparkScan. After you made changes to the symbology settings, call SDCSparkScan.applySettings:completionHandler: with these SDCSparkScanSettings to apply them.
 */
- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;
/**
 * Added in version 6.8.0
 *
 * Sets a property to the provided value. Use this method to set properties that are not yet part of a stable API. Properties set through this method may or may not be used or change in a future release.
 */
- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));
/**
 * Added in version 6.8.0
 *
 * Retrieves the value of a previously set property. In case the property does not exist, -1 is returned.
 */
- (nullable id)valueForProperty:(NSString *)property;
/**
 * Added in version 6.8.0
 *
 * Provides a convenient shortcut to enable decoding of particular symbologies without having to go through SDCSymbologySettings.
 * By default, all symbologies are turned off and symbologies need to be explicitly enabled.
 */
- (void)enableSymbologies:(nonnull NSSet<NSNumber *> *)symbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 6.8.0
 *
 * Provides a convenient shortcut to enable/disable decoding of a particular symbology without having to go through SDCSymbologySettings.
 *
 * Some 1d barcode symbologies allow you to encode variable-length data. By default, the Scandit Data Capture SDK only scans barcodes in a certain length range.
 *
 * If your application requires scanning of one of these symbologies, and the length is falling outside the default range, you may need to adjust the active symbol counts for the symbology in addition to enabling it.
 */
- (void)setSymbology:(SDCSymbology)symbology
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(symbology:enabled:));

@end

NS_ASSUME_NONNULL_END
