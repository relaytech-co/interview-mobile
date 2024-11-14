/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.28.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeCountNotInListActionSettings)
@interface SDCBarcodeCountNotInListActionSettings : NSObject

/**
 * Added in version 6.28.0
 *
 * Use this property to enable the not in list actions. Defaults to NO.
 */
@property (nonatomic, assign) BOOL enabled;

/**
 * Added in version 6.28.0
 *
 * The text for the label associated with the accept button.
 */
@property (nonatomic, strong) NSString *acceptButtonText;
/**
 * Added in version 6.28.0
 *
 * The accept button accessibility label.
 */
@property (nonatomic, strong) NSString *acceptButtonAccessibilityLabel;
/**
 * Added in version 6.28.0
 *
 * The accept button accessibility hint.
 */
@property (nonatomic, strong) NSString *acceptButtonAccessibilityHint;

/**
 * Added in version 6.28.0
 *
 * The text for the label associated with the reject button.
 */
@property (nonatomic, strong) NSString *rejectButtonText;
/**
 * Added in version 6.28.0
 *
 * The reject button accessibility label.
 */
@property (nonatomic, strong) NSString *rejectButtonAccessibilityLabel;
/**
 * Added in version 6.28.0
 *
 * The reject button accessibility hint.
 */
@property (nonatomic, strong) NSString *rejectButtonAccessibilityHint;

/**
 * Added in version 6.28.0
 *
 * The text for the label associated with the cancel button.
 */
@property (nonatomic, strong) NSString *cancelButtonText;
/**
 * Added in version 6.28.0
 *
 * The cancel button accessibility label.
 */
@property (nonatomic, strong) NSString *cancelButtonAccessibilityLabel;
/**
 * Added in version 6.28.0
 *
 * The cancel button accessibility hint.
 */
@property (nonatomic, strong) NSString *cancelButtonAccessibilityHint;

/**
 * Added in version 6.28.0
 *
 * The text for the hint that will be shown when a barcode is accepted.
 */
@property (nonatomic, strong) NSString *barcodeAcceptedHint;
/**
 * Added in version 6.28.0
 *
 * The text for the hint that will be shown when a barcode is rejected.
 */
@property (nonatomic, strong) NSString *barcodeRejectedHint;

@end

NS_ASSUME_NONNULL_END
