/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

#import <ScanditBarcodeCapture/SDCBarcodePickViewHighlightStyle.h>
#import <ScanditBarcodeCapture/SDCBarcodePickState.h>

@class SDCBrush;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.19.0
 *
 * A style that will draw rectangles on top of barcodes.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickViewHighlightStyleRectangular)
@interface SDCBarcodePickViewHighlightStyleRectangular : NSObject <SDCBarcodePickViewHighlightStyle>

/**
 * Added in version 6.19.0
 *
 * Returns the JSON representation of this SDCBarcodePickViewHighlightStyleRectangular.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

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

/**
 * Added in version 6.19.0
 *
 * Gets the brush used for the passed pick state.
 */
- (SDCBrush *)brushForState:(SDCBarcodePickState)state;
/**
 * Added in version 6.19.0
 *
 * Use this method to configure the brush used for the specific pick state.
 */
- (void)setBrush:(SDCBrush *)brush forState:(SDCBarcodePickState)state;

/**
 * Added in version 6.24.0
 *
 * Gets the brush used when items in the passed pick state are selected. If nil, selected items are drawn with the same brush as non-selected items in the same state. Default is nil for all states.
 */
- (nullable SDCBrush *)selectedBrushForState:(SDCBarcodePickState)state;
/**
 * Added in version 6.24.0
 *
 * Use this method to configure the brush used when items in the specific pick state are selected. Pass nil to draw selected items with the same brush as non-selected items in the same state.
 */
- (void)setSelectedBrush:(nullable SDCBrush *)brush forState:(SDCBarcodePickState)state;

@end

NS_ASSUME_NONNULL_END
