/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodePickStatusIconStyle;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.23.0
 *
 * Create this object to respond to SDCBarcodePickViewHighlightStyleCustomView queries.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickHighlightCustomViewResponse)
@interface SDCBarcodePickHighlightCustomViewResponse : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.23.0
 *
 * Creates a new instance with the provided view. A SDCBarcodePickStatusIconStyle instance can also be provided to display a status icon.
 *
 * @remark Requires a special license key to support rendering any kind of images since this feature is available only in limited countries. Please contact support@scandit.com for details
 */
- (instancetype)initWithView:(UIView *)view
             statusIconStyle:(nullable SDCBarcodePickStatusIconStyle *)statusIconStyle;

@end

NS_ASSUME_NONNULL_END
