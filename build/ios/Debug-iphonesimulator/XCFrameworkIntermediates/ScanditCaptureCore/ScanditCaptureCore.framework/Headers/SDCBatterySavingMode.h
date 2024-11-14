/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.20.0
 *
 * A feature that can help you extend the battery life of your phone when you are running low on power. It reduces some of the functions and features that consume more energy.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBatterySavingMode) {
/**
     * Added in version 6.20.0
     *
     * The battery saving mode is automatically enabled when a higher than usual consumption of the battery is detected, balancing performance and battery lifetime.
     */
    SDCBatterySavingModeAuto = 0,
/**
     * Added in version 6.20.0
     *
     * The battery saving mode is always off, ensuring the standard performance.
     */
    SDCBatterySavingModeOff = 1,
/**
     * Added in version 6.20.0
     *
     * The battery saving mode is always on, maximising the battery lifetime.
     */
    SDCBatterySavingModeOn = 2,
} NS_SWIFT_NAME(BatterySavingMode);

/**
 * Added in version 6.21.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromBatterySavingMode(SDCBatterySavingMode mode)
    NS_SWIFT_NAME(getter:SDCBatterySavingMode.jsonString(self:));
/**
 * Added in version 6.21.0
 *
 * Deprecated since version 6.26.0: This function will be removed in the future.
 */
SDC_EXTERN BOOL SDCBatterySavingModeFromJSONString(NSString *_Nonnull JSONString,
                                                   SDCBatterySavingMode *_Nonnull mode)
    DEPRECATED_MSG_ATTRIBUTE("This function will be removed in the future");
