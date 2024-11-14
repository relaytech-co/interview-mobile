/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

#import <ScanditBarcodeCapture/SDCBarcodePickViewHighlightStyle.h>

@class SDCBarcodePickStatusIconSettings;
@protocol SDCBarcodePickViewHighlightStyleCustomViewDelegate;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.23.0
 *
 * A style that will allow the user to provide their own views to be displayed on top of barcodes.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickViewHighlightStyleCustomView)
@interface SDCBarcodePickViewHighlightStyleCustomView : NSObject <SDCBarcodePickViewHighlightStyle>

/**
 * Added in version 6.23.0
 *
 * Returns the JSON representation of this SDCBarcodePickViewHighlightStyleCustomView.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.23.0
 *
 * Sets a delegate that will provide the views to be displayed.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodePickViewHighlightStyleCustomViewDelegate> delegate;

/**
 * Added in version 6.23.0
 *
 * If YES the view size will be adjusted to cover the barcode. Defaults to NO.
 */
@property (nonatomic, assign) BOOL fitViewsToBarcode;
/**
 * Added in version 6.25.0
 *
 * The settings used to customize the status icons.
 */
@property (nonatomic, strong) SDCBarcodePickStatusIconSettings *statusIconSettings;

/**
 * Added in version 6.25.0
 *
 * Minimum height for the highlights. Default is 40dp.
 */
@property (nonatomic, assign) NSInteger minimumHighlightHeight;
/**
 * Added in version 6.25.0
 *
 * Minimum width for the highlights. Default is 40dp.
 */
@property (nonatomic, assign) NSInteger minimumHighlightWidth;

@end

NS_ASSUME_NONNULL_END
