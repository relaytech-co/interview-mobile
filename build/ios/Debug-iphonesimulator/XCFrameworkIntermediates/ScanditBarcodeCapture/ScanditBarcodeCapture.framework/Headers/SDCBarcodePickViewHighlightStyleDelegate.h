/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

@class SDCBarcodePickHighlightStyleRequest;
@class SDCBarcodePickHighlightStyleResponse;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.22.0
 *
 * A delegate to be provided to a SDCBarcodePickViewHighlightStyle object that supports it. This delegate allows to retrieve asynchronously the style to be applied to a highlight.
 */
NS_SWIFT_NAME(BarcodePickViewHighlightStyleDelegate)
@protocol SDCBarcodePickViewHighlightStyleDelegate <NSObject>

/**
 * Added in version 6.22.0
 *
 * This method will be called every time a style for an item is needed.
 */
- (void)styleForRequest:(nonnull SDCBarcodePickHighlightStyleRequest *)request
      completionHandler:
          (nonnull void (^)(SDCBarcodePickHighlightStyleResponse *_Nullable))completionHandler;

@end

NS_ASSUME_NONNULL_END
