/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.18.0
 *
 * An object that defines the search options.
 */
NS_SWIFT_NAME(BarcodeFindItemSearchOptions)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindItemSearchOptions : NSObject

/**
 * Added in version 6.18.0
 *
 * The barcode data as a string.
 */
@property (nonatomic, copy, readonly) NSString *barcodeData;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.18.0
 */
- (instancetype)initWithBarcodeData:(NSString *)data;

@end

NS_ASSUME_NONNULL_END
