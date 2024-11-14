/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * A barcode that’s part of a list of targets for SDCBarcodeCountCaptureList.
 */
NS_SWIFT_NAME(TargetBarcode)
SDC_EXPORTED_SYMBOL
@interface SDCTargetBarcode : NSObject

/**
 * Added in version 6.15.0
 *
 * The data of the target barcode, as a sequence of characters.
 */
@property (nonatomic, nonnull, readonly) NSString *data;
/**
 * Added in version 6.15.0
 *
 * The number of times that the target barcode is expected to be scanned.
 */
@property (nonatomic, readonly) NSInteger quantity;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.15.0
 *
 * Constructs a new target barcode to be added to a SDCBarcodeCountCaptureList.
 */
- (instancetype)initWithData:(NSString *)data quantity:(NSInteger)quantity;

@end

NS_ASSUME_NONNULL_END
