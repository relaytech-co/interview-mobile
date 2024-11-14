/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.21.0
 *
 * Transformer protocol for Barcode Find.
 */
NS_SWIFT_NAME(BarcodeFindTransformer)
@protocol SDCBarcodeFindTransformer <NSObject>

/**
 * Added in version 6.21.0
 *
 * Invoked for each detected barcode. The implementation should return the same barcode data, which may or may not be transformed from the original, or nil if the barcode should be ignored entirely. Note that this method is executed on a background thread.
 */
- (nullable NSString *)transformBarcodeData:(NSString *)data;

@end

NS_ASSUME_NONNULL_END
