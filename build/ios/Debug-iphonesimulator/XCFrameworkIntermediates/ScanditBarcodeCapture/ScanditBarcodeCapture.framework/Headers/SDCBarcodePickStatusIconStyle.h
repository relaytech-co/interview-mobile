/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCBrush;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.23.0
 *
 * This holds the style data for the status icons.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickStatusIconStyle)
@interface SDCBarcodePickStatusIconStyle : NSObject

/**
 * Added in version 6.23.0
 *
 * Returns the JSON representation of the icon style.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.23.0
 *
 * Constructs a new instance using its JSON representation.
 */
+ (nullable instancetype)statusIconStyleWithJSONString:(NSString *)JSONString;

/**
 * Added in version 6.23.0
 *
 * Constructs a new instance that will display the default icon, an exclamation mark. The icon will be customized with the provided colors.
 */
+ (instancetype)statusIconStyleWithIconColor:(UIColor *)iconColor
                         iconBackgroundColor:(UIColor *)iconBackgroundColor
                                        text:(NSString *)text;

/**
 * Added in version 6.23.0
 *
 * Constructs a new instance that will display the provided icon and text.
 */
+ (instancetype)statusIconStyleWithIcon:(UIImage *)icon text:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
