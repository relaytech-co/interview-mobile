/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCAnchor.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.19.0
 *
 * Contains the default values for SDCBarcodeFindView properties.
 */
NS_SWIFT_NAME(BarcodeFindViewDefaults)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeFindViewDefaults : NSObject

/**
 * Added in version 6.19.0
 *
 * Default is YES.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowUserGuidanceView;
/**
 * Added in version 6.19.0
 *
 * Default is YES.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowHints;
/**
 * Added in version 6.19.0
 *
 * Default is YES.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowCarousel;
/**
 * Added in version 6.19.0
 *
 * Default is YES.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowPauseButton;
/**
 * Added in version 6.19.0
 *
 * Default is YES.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowFinishButton;
/**
 * Added in version 6.19.0
 *
 * Default is NO.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowProgressBar;
/**
 * Added in version 6.20.0
 *
 * Default is NO.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowTorchControl;
/**
 * Added in version 6.28.0
 *
 * Default is NO.
 */
@property (class, nonatomic, assign, readonly) BOOL defaultShouldShowZoomControl;
/**
 * Added in version 6.20.0
 *
 * Default is SDCAnchorTopLeft.
 */
@property (class, nonatomic, assign, readonly) SDCAnchor defaultTorchControlPosition;
/**
 * Added in version 6.19.0
 *
 * Default is “Collapse cards”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForCollapseCardsButton;
/**
 * Added in version 6.19.0
 *
 * Default is “All items found successfully!”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForAllItemsFoundSuccessfullyHint;
/**
 * Added in version 6.19.0
 *
 * Default is “Point at barcode and scan”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForPointAtBarcodesToSearchHint;
/**
 * Added in version 6.19.0
 *
 * Default is “Move closer to barcodes”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForMoveCloserToBarcodesHint;
/**
 * Added in version 6.19.0
 *
 * Default is “Tap shutter to pause screen”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForTapShutterToPauseScreenHint;
/**
 * Added in version 6.19.0
 *
 * Default is “Tap shutter to resume search”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForTapShutterToResumeSearchHint;
/**
 * Added in version 6.24.0
 *
 * Default is “Search list updated. Tap shutter for details.”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForItemListUpdatedHint;
/**
 * Added in version 6.24.0
 *
 * Default is “Search list updated.”.
 */
@property (class, nonatomic, readonly) NSString *defaultTextForItemListUpdatedWhenPausedHint;

@end

NS_ASSUME_NONNULL_END
