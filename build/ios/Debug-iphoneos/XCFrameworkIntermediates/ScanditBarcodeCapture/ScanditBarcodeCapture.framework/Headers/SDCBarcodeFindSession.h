/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.18.0
 *
 * The BarcodeFind session holds the ongoing state of a running SDCBarcodeFind.
 */
NS_SWIFT_NAME(BarcodeFindSession)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindSession : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
