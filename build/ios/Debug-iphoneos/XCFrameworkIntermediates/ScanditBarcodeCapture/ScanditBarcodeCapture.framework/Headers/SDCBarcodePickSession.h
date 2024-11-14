/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.23.0
 *
 * The BarcodePick session holds the current state of a running SDCBarcodePick.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickSession)
@interface SDCBarcodePickSession : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.23.0
 *
 * Returns the JSON representation of the session.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.23.0
 *
 * A set containing the data of all the barcodes that are currently tracked on screen.
 */
@property (nonatomic, strong, readonly) NSSet<NSString *> *trackedItems;
/**
 * Added in version 6.23.0
 *
 * A set containing the data of the barcodes that were scanned in the last frame.
 */
@property (nonatomic, strong, readonly) NSSet<NSString *> *addedItems;

@end

NS_ASSUME_NONNULL_END
