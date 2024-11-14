/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.19.0
 *
 * Represents a product to be picked.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickProduct)
@interface SDCBarcodePickProduct : NSObject

/**
 * Added in version 6.19.0
 *
 * The unique identifier for this product.
 */
@property (nonatomic, readonly) NSString *identifier;
/**
 * Added in version 6.19.0
 *
 * How many of this product need to be picked.
 */
@property (nonatomic, readonly) NSInteger quantityToPick;

/**
 * Added in version 6.19.0
 *
 * Constructs a SDCBarcodePickProduct.
 *
 *   • identifier The unique identifier for this product.
 *
 *   • quantityToPick How many of this product need to be picked.
 */
+ (instancetype)barcodePickProductWithIdentifier:(NSString *)identifier
                                  quantityToPick:(NSInteger)quantityToPick;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
