/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeFindItemSearchOptions.h>
#import <ScanditBarcodeCapture/SDCBarcodeFindItemContent.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.18.0
 *
 * An object that represents an item in Barcode Find.
 */
NS_SWIFT_NAME(BarcodeFindItem)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindItem : NSObject

/**
 * Added in version 6.18.0
 *
 * The item data to search, and any other option that control the search.
 */
@property (nonatomic, strong, readonly) SDCBarcodeFindItemSearchOptions *searchOptions;
/**
 * Added in version 6.18.0
 *
 * Optional info about the item.
 */
@property (nonatomic, strong, nullable, readonly) SDCBarcodeFindItemContent *content;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.18.0
 */
- (instancetype)initWithSearchOptions:(SDCBarcodeFindItemSearchOptions *)searchOptions
                              content:(nullable SDCBarcodeFindItemContent *)content;

@end

NS_ASSUME_NONNULL_END
