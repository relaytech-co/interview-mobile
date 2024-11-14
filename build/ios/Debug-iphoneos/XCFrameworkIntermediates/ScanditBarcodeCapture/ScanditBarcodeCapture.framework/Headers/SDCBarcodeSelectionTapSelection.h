/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionType.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionTapBehavior.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionFreezeBehavior.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.6.0
 *
 * Tap based selection, customizable via freezeBehavior and tapBehavior.
 */
NS_SWIFT_NAME(BarcodeSelectionTapSelection)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionTapSelection : NSObject <SDCBarcodeSelectionType>

/**
 * Added in version 6.6.0
 *
 * Freeze behavior to use, defaults to SDCBarcodeSelectionFreezeBehaviorManual
 */
@property (nonatomic) SDCBarcodeSelectionFreezeBehavior freezeBehavior;
/**
 * Added in version 6.6.0
 */
@property (nonatomic) SDCBarcodeSelectionTapBehavior tapBehavior;
/**
 * Added in version 6.12.0
 *
 * Set should freeze on double tap, defaults to true.
 */
@property (nonatomic) BOOL shouldFreezeOnDoubleTap;
/**
 * Added in version 6.10.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

/**
 * Added in version 6.6.0
 *
 * Creates a new SDCBarcodeSelectionTapSelection instance.
 */
+ (instancetype)tapSelection;
/**
 * Added in version 6.6.0
 *
 * Creates a new SDCBarcodeSelectionTapSelection instance with the specified SDCBarcodeSelectionFreezeBehavior and SDCBarcodeSelectionTapBehavior.
 */
+ (instancetype)tapSelectionWithFreezeBehavior:(SDCBarcodeSelectionFreezeBehavior)freezeBehavior
                                   tapBehavior:(SDCBarcodeSelectionTapBehavior)tapBehavior
    NS_SWIFT_UNAVAILABLE("Use initializer instead");

/**
 * Added in version 6.13.0
 *
 * Creates a new SDCBarcodeSelectionTapSelection instance with the specified SDCBarcodeSelectionFreezeBehavior and SDCBarcodeSelectionTapBehavior.
 */
- (instancetype)initWithFreezeBehavior:(SDCBarcodeSelectionFreezeBehavior)freezeBehavior
                           tapBehavior:(SDCBarcodeSelectionTapBehavior)tapBehavior;

@end

NS_ASSUME_NONNULL_END
