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
 * An object that contains additional info about the product.
 */
NS_SWIFT_NAME(BarcodeFindItemContent)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindItemContent : NSObject

/**
 * Added in version 6.18.0
 *
 * Optional item name.
 */
@property (nonatomic, copy, nullable, readonly) NSString *info;
/**
 * Added in version 6.18.0
 *
 * Optional item details.
 */
@property (nonatomic, copy, nullable, readonly) NSString *additionalInfo;
/**
 * Added in version 6.18.0
 *
 * Optional item image.
 */
@property (nonatomic, strong, nullable, readonly) UIImage *image;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.18.0
 */
- (instancetype)initWithInfo:(nullable NSString *)info
              additionalInfo:(nullable NSString *)additionalInfo
                       image:(nullable UIImage *)image;

@end

NS_ASSUME_NONNULL_END
