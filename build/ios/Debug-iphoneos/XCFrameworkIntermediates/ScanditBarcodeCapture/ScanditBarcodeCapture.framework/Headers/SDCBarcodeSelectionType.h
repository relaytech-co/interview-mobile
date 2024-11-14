/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.6.0
 *
 * The protocol for all barcode selection types. Possible selection types are:
 *
 *   • SDCBarcodeSelectionAimerSelection
 *
 *   • SDCBarcodeSelectionTapSelection
 */
NS_SWIFT_NAME(BarcodeSelectionType)
@protocol SDCBarcodeSelectionType <NSObject>
/**
 * Added in version 6.10.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
@end

NS_ASSUME_NONNULL_END
