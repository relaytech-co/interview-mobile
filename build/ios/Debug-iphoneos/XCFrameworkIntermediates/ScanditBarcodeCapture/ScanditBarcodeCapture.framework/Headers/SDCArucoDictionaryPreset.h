/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * Added in version 6.19.0
 *
 * Lists presets that can be used to create a SDCArucoDictionary
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCArucoDictionaryPreset) {
/**
     * Added in version 6.19.0
     *
     * Dictionary that contains 50 markers of size 5.
     */
    SDCArucoDictionaryPreset_5X5_50 NS_SWIFT_NAME(preset_5X5_50),
/**
     * Added in version 6.19.0
     *
     * Dictionary that contains 100 markers of size 5.
     */
    SDCArucoDictionaryPreset_5X5_100 NS_SWIFT_NAME(preset_5X5_100),
/**
     * Added in version 6.19.0
     *
     * Dictionary that contains 250 markers of size 5.
     */
    SDCArucoDictionaryPreset_5X5_250 NS_SWIFT_NAME(preset_5X5_250),
/**
     * Added in version 6.19.0
     *
     * Dictionary that contains 1000 markers of size 5.
     */
    SDCArucoDictionaryPreset_5X5_1000 NS_SWIFT_NAME(preset_5X5_1000), 
/**
     * Added in version 6.19.0
     *
     * Dictionary that contains 1023 markers of size 5.
     */
    SDCArucoDictionaryPreset_5X5_1023 NS_SWIFT_NAME(preset_5X5_1023),
/**
     * Added in version 6.19.0
     *
     * Dictionary that contains 250 markers of size 6.
     */
    SDCArucoDictionaryPreset_6X6_250 NS_SWIFT_NAME(preset_6X6_250),
/**
     * Added in version 6.19.0
     *
     * Dictionary that contains 250 markers of size 4.
     */
    SDCArucoDictionaryPreset_4X4_250 NS_SWIFT_NAME(preset_4X4_250)
} NS_SWIFT_NAME(ArucoDictionaryPreset);

