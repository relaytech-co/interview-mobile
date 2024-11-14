/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.21.0
 *
 * The BarcodePick scanning session holds the ongoing state of a running SDCBarcodePick.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickScanningSession)
@interface SDCBarcodePickScanningSession : NSObject

/**
 * Added in version 6.22.0
 *
 * Returns the JSON representation of the session.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.21.0
 *
 * Set of barcodes represented by their data that are picked.
 */
@property (nonatomic, strong, readonly) NSSet<NSString *> *pickedItems;
/**
 * Added in version 6.21.0
 *
 * Set of barcodes represented by their data that are scanned.
 */
@property (nonatomic, strong, readonly) NSSet<NSString *> *scannedItems;

@end

NS_ASSUME_NONNULL_END
