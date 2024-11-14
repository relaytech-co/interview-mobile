/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * Represents a position in a grid.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(Coordinate2D)
@interface SDCCoordinate2D : NSObject

/**
 * Added in version 6.17.0
 *
 * X coordinate value.
 */
@property (nonatomic, assign, readonly) NSInteger x;
/**
 * Added in version 6.17.0
 *
 * Y coordinate value.
 */
@property (nonatomic, assign, readonly) NSInteger y;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.17.0
 *
 * Instantiates a Coordinate2d.
 */
- (instancetype)initWithX:(NSInteger)x y:(NSInteger)y;

@end

NS_ASSUME_NONNULL_END
