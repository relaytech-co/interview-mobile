/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.25.0
 *
 * Use this class to customize the status icons in styles that support it.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickStatusIconSettings)
@interface SDCBarcodePickStatusIconSettings : NSObject

/**
 * Added in version 6.25.0
 *
 * When a status icon is displayed its size will be determined using the size of the related highlight.
 * The length of the shorter side of the highlight will be multiplied by this ratio to compute the size.
 * For example, if the ratio is 0.6 and the shorter side of the highlight is 60dp then the status icon size will be 36dp.
 *
 * Default is 0.5.
 */
@property (nonatomic, assign) CGFloat ratioToHighlightSize;
/**
 * Added in version 6.25.0
 *
 * The minimum size to use for status icons.
 *
 * Default is 20 dp.
 */
@property (nonatomic, assign) NSInteger minSize;
/**
 * Added in version 6.25.0
 *
 * The maximum size to use for status icons.
 *
 * Default is no maximum, INT_MAX.
 */
@property (nonatomic, assign) NSInteger maxSize;

@end

NS_ASSUME_NONNULL_END
