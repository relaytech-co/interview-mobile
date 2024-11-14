/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.24.0
 *
 * Allows to enable the new Smart algorithm that intelligently identifies and scans the intended barcode without requiring precise aiming, eliminating the need to constantly look at the screen and reducing errors.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCScanIntention) {
/**
     * Added in version 6.24.0
     *
     * Ensures the standard performance with no smart algorithms.
     */
    SDCScanIntentionManual,
/**
     * Added in version 6.24.0
     *
     * Enables the automatic algorithm that intelligently identifies and then scans the barcode that the user intends to capture, reducing errors.
     */
    SDCScanIntentionSmart
} NS_SWIFT_NAME(ScanIntention);
