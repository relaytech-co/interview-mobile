/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditBarcodeCapture/SDCBarcodePickState.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.22.0
 *
 * This class encapsulates a style request for an highlight. It provides the item data, the product identifier if already mapped and the state.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickHighlightStyleRequest)
@interface SDCBarcodePickHighlightStyleRequest : NSObject

/**
 * Added in version 6.22.0
 *
 * The barcode data.
 */
@property (nonatomic, strong, readonly) NSString *itemData;
/**
 * Added in version 6.22.0
 *
 * The item data that was provided during the mapping, if available.
 */
@property (nonatomic, strong, nullable, readonly) NSString *productIdentifier;
/**
 * Added in version 6.22.0
 *
 * The state of the the scanned item.
 */
@property (nonatomic, assign, readonly) SDCBarcodePickState state;

/**
 * Added in version 6.22.0
 *
 * Returns the JSON representation of the request.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
