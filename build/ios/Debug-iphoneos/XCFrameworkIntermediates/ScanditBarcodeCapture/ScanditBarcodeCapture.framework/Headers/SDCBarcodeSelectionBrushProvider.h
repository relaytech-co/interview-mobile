/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#include <ScanditBarcodeCapture/SDCBarcode.h>
#include <ScanditCaptureCore/SDCBrush.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * Protocol for applying custom brushes to recognized barcodes.
 */
NS_SWIFT_NAME(BarcodeSelectionBrushProvider)
@protocol SDCBarcodeSelectionBrushProvider <NSObject>

/**
 * Added in version 6.17.0
 *
 * Return the brush to apply to the given barcode. A non-nil brush returned by this method overrides any other brush set for the barcode.
 */
- (nullable SDCBrush *)brushForBarcode:(SDCBarcode *)barcode;

@end

NS_ASSUME_NONNULL_END
