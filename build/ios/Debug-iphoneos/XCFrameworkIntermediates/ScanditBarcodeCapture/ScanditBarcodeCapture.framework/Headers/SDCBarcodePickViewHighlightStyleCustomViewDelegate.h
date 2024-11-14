/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

@class SDCBarcodePickHighlightStyleRequest;
@class SDCBarcodePickHighlightCustomViewResponse;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.23.0
 *
 * An object that will provide the views to the SDCBarcodePickViewHighlightStyleCustomView style.
 */
NS_SWIFT_NAME(BarcodePickViewHighlightStyleCustomViewDelegate)
@protocol SDCBarcodePickViewHighlightStyleCustomViewDelegate <NSObject>

/**
 * Added in version 6.23.0
 *
 * This method will be called every time the view for an item is needed.
 */
- (void)customViewForRequest:(nonnull SDCBarcodePickHighlightStyleRequest *)request
           completionHandler:(nonnull void (^)(SDCBarcodePickHighlightCustomViewResponse *_Nullable))completionHandler;

@end

NS_ASSUME_NONNULL_END
