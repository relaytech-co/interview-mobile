/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.21.0
 *
 * The level of error correction to use in generating a QR code, specifying how much the code can be damaged while remaining readable.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCQRCodeErrorCorrectionLevel) {
/**
     * Added in version 6.21.0
     *
     * “Low” (up to 7% damage)
     */
    SDCQRCodeErrorCorrectionLevelLow,
/**
     * Added in version 6.21.0
     *
     * “Medium” (up to 15% damage) (default if not set)
     */
    SDCQRCodeErrorCorrectionLevelMedium,
/**
     * Added in version 6.21.0
     *
     * “Quartile” (up to 25% damage)
     */
    SDCQRCodeErrorCorrectionLevelQuartile,
/**
     * Added in version 6.21.0
     *
     * “High” (up to 30% damage)
     */
    SDCQRCodeErrorCorrectionLevelHigh
} NS_SWIFT_NAME(QRCodeErrorCorrectionLevel);
