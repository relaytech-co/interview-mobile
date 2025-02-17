/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

SDC_EXTERN NSString *_Nonnull const SDCBarcodeTrackingSettingsErrorDomain NS_SWIFT_NAME(BarcodeTrackingSettingsErrorDomain);

@class SDCFrameSaveTrigger;
@class SDCSymbologySettings;
@class SDCArucoDictionary;

/**
 * Added in version 6.5.0
 *
 * An enumeration of barcode tracking scenarios.
 *
 * Deprecated since version 6.26: Setting a scenario is no longer recommended, use SDCBarcodeTrackingSettings.settings instead.
 */
typedef NS_ENUM(NSUInteger, SDCBarcodeTrackingScenario) {
/**
     * Added in version 6.5.0
     *
     * Scenario A.
     */
    SDCBarcodeTrackingScenarioA NS_SWIFT_NAME(a),
/**
     * Added in version 6.5.0
     *
     * Scenario B.
     *
     * Deprecated since version 6.15: Scenario B is deprecated, use SDCBarcodeCount instead.
     */
    SDCBarcodeTrackingScenarioB NS_SWIFT_NAME(b),
} NS_SWIFT_NAME(BarcodeTrackingScenario) DEPRECATED_MSG_ATTRIBUTE("Setting a scenario is no longer recommended.");

/**
 * Added in version 6.0.0
 */
NS_SWIFT_NAME(BarcodeTrackingSettings)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingSettings : NSObject <NSCopying>

/**
 * Added in version 6.0.0
 *
 * Returns the set of enabled symbologies.
 */
@property (nonatomic, nonnull, readonly) NSSet<NSNumber *> *enabledSymbologies NS_REFINED_FOR_SWIFT;

/**
 * Added in version 6.0.0
 *
 * Creates a new barcode tracking settings instance. All symbologies are disabled. Make sure to enable the symbologies required by your app before applying the settings to SDCBarcodeTracking with SDCBarcodeTracking.applySettings:completionHandler:.
 */
+ (instancetype)settings NS_SWIFT_UNAVAILABLE("Use initializer instead");
/**
 * Added in version 6.5.0
 *
 * Creates a new barcode tracking settings instance with the provided scenario.
 *
 * Deprecated since version 6.26: Setting a scenario is no longer recommended, use settings instead.
 */
+ (instancetype)settingsWithScenario:(SDCBarcodeTrackingScenario)scenario
    NS_SWIFT_UNAVAILABLE("Use initializer instead")
        DEPRECATED_MSG_ATTRIBUTE("Setting a scenario is no longer recommended, use init instead.");

/**
 * Added in version 6.13.0
 *
 * Creates a new barcode tracking settings instance with the provided scenario.
 */
- (instancetype)initWithScenario:(SDCBarcodeTrackingScenario)scenario
    DEPRECATED_MSG_ATTRIBUTE("Setting a scenario is no longer recommended, use init instead.");

/**
 * Added in version 6.0.0
 *
 * Get SDCSymbologySettings specific for the given SDCSymbology.
 *
 * Note that modifying the returned object doesn’t automatically apply the changes to SDCBarcodeTracking. After you made changes to the symbology settings,
 *
 * call SDCBarcodeTracking.applySettings:completionHandler:
 *
 * with these SDCBarcodeTrackingSettings to apply them.
 */
- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;

/**
 * Added in version 6.0.0
 *
 * Sets property to the provided value. Use this method to set properties that are not yet part of a stable API. Properties set through this method may or may not be used or change in a future release.
 */
- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));

/**
 * Added in version 6.0.0
 *
 * Retrieves the value of a previously set property. In case the property does not exist, -1 is returned.
 */
- (nullable id)valueForProperty:(NSString *)property;

/**
 * Added in version 6.0.0
 *
 * This function provides a convenient shortcut to enabling decoding of particular symbologies without having to go through SDCSymbologySettings.
 * By default, all symbologies are turned off and symbologies need to be explicitly enabled.
 */
- (void)enableSymbologies:(nonnull NSSet<NSNumber *> *)symbologies NS_REFINED_FOR_SWIFT;

/**
 * Added in version 6.0.0
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

@end

NS_ASSUME_NONNULL_END
