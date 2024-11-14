/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * Added in version 6.19.0
 *
 * An enumeration of the presets available to simplify configuring symbologies.
 */
typedef NS_OPTIONS(NSUInteger, SDCCapturePreset) {
/**
     * Added in version 6.19.0
     *
     * Automatically enables and optimizes symbologies most used in the Transport vertical. This includes SDCSymbologyCode128, SDCSymbologyQR, SDCSymbologyCode39, SDCSymbologyDataMatrix, SDCSymbologyEAN13UPCA, SDCSymbologyInterleavedTwoOfFive, SDCSymbologyAztec, SDCSymbologyEAN8, SDCSymbologyPDF417, SDCSymbologyUPCE.
     */
    SDCCapturePresetTransport = 1 << 0,
/**
     * Added in version 6.19.0
     *
     * Automatically enables and optimizes symbologies most used in the Logistics vertical. This includes SDCSymbologyCode128, SDCSymbologyQR, SDCSymbologyCode39, SDCSymbologyDataMatrix, SDCSymbologyEAN13UPCA, SDCSymbologyInterleavedTwoOfFive, SDCSymbologyCodabar, SDCSymbologyEAN8, SDCSymbologyPDF417, SDCSymbologyUPCE.
     */
    SDCCapturePresetLogistics = 1 << 1,
/**
     * Added in version 6.19.0
     *
     * Automatically enables and optimizes symbologies most used in the Retail vertical. This includes SDCSymbologyEAN13UPCA, SDCSymbologyCode128, SDCSymbologyQR, SDCSymbologyCode39, SDCSymbologyEAN8, SDCSymbologyDataMatrix, SDCSymbologyInterleavedTwoOfFive, SDCSymbologyUPCE, SDCSymbologyGS1Databar, SDCSymbologyGS1DatabarExpanded.
     */
    SDCCapturePresetRetail = 1 << 2,
/**
     * Added in version 6.19.0
     *
     * Automatically enables and optimizes symbologies most used in the Healthcare vertical. This includes SDCSymbologyCode128, SDCSymbologyDataMatrix, SDCSymbologyQR, SDCSymbologyEAN13UPCA, SDCSymbologyCode39, SDCSymbologyMicroPDF417, SDCSymbologyInterleavedTwoOfFive, SDCSymbologyMSIPlessey, SDCSymbologyEAN8.
     */
    SDCCapturePresetHealthcare = 1 << 3,
/**
     * Added in version 6.19.0
     *
     * Automatically enables and optimizes symbologies most used in the Manufacturing vertical. This includes SDCSymbologyCode128, SDCSymbologyDataMatrix, SDCSymbologyCode39, SDCSymbologyQR, SDCSymbologyEAN13UPCA, SDCSymbologyInterleavedTwoOfFive, SDCSymbologyPDF417, SDCSymbologyUPCE, SDCSymbologyEAN8.
     */
    SDCCapturePresetManufacturing = 1 << 4,
} NS_SWIFT_NAME(CapturePreset);
