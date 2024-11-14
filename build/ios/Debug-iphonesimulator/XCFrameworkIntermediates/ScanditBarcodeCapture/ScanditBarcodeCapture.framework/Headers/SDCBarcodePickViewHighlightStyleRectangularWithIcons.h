/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

#import <ScanditBarcodeCapture/SDCBarcodePickViewHighlightStyle.h>
#import <ScanditBarcodeCapture/SDCBarcodePickState.h>
#import <ScanditBarcodeCapture/SDCBarcodePickIconStyle.h>

@class SDCBrush;
@class UIImage;
@class SDCBarcodePickStatusIconSettings;
@protocol SDCBarcodePickViewHighlightStyleDelegate;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.19.0
 *
 * A style that will draw rectangles on top of barcodes, the highlights can also have icons drawn on top.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickViewHighlightStyleRectangularWithIcons)
@interface SDCBarcodePickViewHighlightStyleRectangularWithIcons
    : NSObject <SDCBarcodePickViewHighlightStyle>

/**
 * Added in version 6.22.0
 *
 * Set a delegate to override asynchronously the style of the highlights depending on each item’s code and state.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodePickViewHighlightStyleDelegate> delegate;
/**
 * Added in version 6.19.0
 *
 * The selected icons style. Defaults to SDCBarcodePickIconStylePreset1
 */
@property (nonatomic, assign, readonly) SDCBarcodePickIconStyle iconStyle;
/**
 * Added in version 6.19.0
 *
 * Returns the JSON representation of this SDCBarcodePickViewHighlightStyleRectangularWithIcons.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
/**
 * Added in version 6.22.0
 *
 * If enabled the delegate responses will be cached, otherwise the style will be asked every time. Defaults to YES.
 */
@property (nonatomic, assign) BOOL styleResponseCacheEnabled;
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

/**
 * Added in version 6.22.0
 *
 * Creates a new instance using the specified icon style.
 */
- (instancetype)initWithIconStyle:(SDCBarcodePickIconStyle)iconStyle;

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

/**
 * Added in version 6.22.0
 *
 * Use this method to configure the icon used for the specific pick state.
 *
 * @remark The icon is shown with a size of 18x18 dp.
 */
- (void)setIcon:(nullable UIImage *)icon forState:(SDCBarcodePickState)state;

/**
 * Added in version 6.24.0
 *
 * Use this method to configure the icon used when items in the specific pick state are selected. If nil, selected items use the same icon as non-selected items in the same state. Default is nil for all states.
 */
- (void)setSelectedIcon:(nullable UIImage *)icon forState:(SDCBarcodePickState)state;

@end

NS_ASSUME_NONNULL_END
