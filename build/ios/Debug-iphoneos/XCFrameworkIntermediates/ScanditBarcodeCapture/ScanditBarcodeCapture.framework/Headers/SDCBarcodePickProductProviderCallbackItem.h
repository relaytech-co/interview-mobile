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
 * A container class consisting of an itemData (i.e. the data of a scanned code) and a productIdentifier (i.e. the string identifier of the product of which itemData consists of)
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickProductProviderCallbackItem)
@interface SDCBarcodePickProductProviderCallbackItem : NSObject

/**
 * Added in version 6.19.0
 *
 * Returns the itemData provided on construction.
 */
@property (nonatomic, strong, readonly) NSString *itemData;
/**
 * Added in version 6.19.0
 *
 * Returns the productIdentifier provided on construction. May be nil.
 */
@property (nonatomic, strong, nullable, readonly) NSString *productIdentifier;

/**
 * Added in version 6.19.0
 *
 * Constructs a new instance containing the provided itemData and nullable productIdentifier.
 */
- (instancetype)initWithItemData:(NSString *)itemData
               productIdentifier:(nullable NSString *)productIdentifier;

@end

NS_ASSUME_NONNULL_END
