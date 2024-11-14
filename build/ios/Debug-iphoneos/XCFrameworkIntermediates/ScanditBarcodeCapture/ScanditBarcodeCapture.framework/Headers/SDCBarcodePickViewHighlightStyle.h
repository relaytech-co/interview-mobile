/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.19.0
 *
 * Common interface for SDCBarcodePickView styles.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickViewHighlightStyle)
@protocol SDCBarcodePickViewHighlightStyle <NSObject>

/**
 * Added in version 6.19.0
 *
 * Returns the JSON representation of this SDCBarcodePickViewHighlightStyle.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end
