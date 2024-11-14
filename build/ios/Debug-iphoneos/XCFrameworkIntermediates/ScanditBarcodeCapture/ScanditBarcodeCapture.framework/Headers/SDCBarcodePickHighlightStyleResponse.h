/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditBarcodeCapture/SDCBarcodePickState.h>

@class SDCBrush;
@class SDCBarcodePickStatusIconStyle;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.22.0
 *
 * Create this object to respond to highlight style queries.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickHighlightStyleResponse)
@interface SDCBarcodePickHighlightStyleResponse : NSObject

/**
 * Added in version 6.22.0
 *
 * Returns the JSON representation of the response.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.22.0
 *
 * Builds a response using its JSON representation.
 */
+ (nullable instancetype)responseWithJSONString:(NSString *)JSONString;

/**
 * Added in version 6.23.0
 *
 * Constructs a new instance with the passed brush and icon.
 */
- (instancetype)initWithBrush:(nullable SDCBrush *)brush
                         icon:(nullable UIImage *)icon
              statusIconStyle:(nullable SDCBarcodePickStatusIconStyle *)statusIconStyle;
/**
 * Added in version 6.24.0
 *
 * Constructs a new instance with the passed brushes and icons.
 */
- (instancetype)initWithBrush:(nullable SDCBrush *)brush
                selectedBrush:(nullable SDCBrush *)selectedBrush
                         icon:(nullable UIImage *)icon
                 selectedIcon:(nullable UIImage *)selectedIcon
              statusIconStyle:(nullable SDCBarcodePickStatusIconStyle *)statusIconStyle;

@end

NS_ASSUME_NONNULL_END
