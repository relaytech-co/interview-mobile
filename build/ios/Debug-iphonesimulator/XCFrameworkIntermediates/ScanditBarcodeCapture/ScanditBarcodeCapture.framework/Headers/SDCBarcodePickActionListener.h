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
 * Will be notified when an action is performed by the user.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickActionListener)
@protocol SDCBarcodePickActionListener <NSObject>

@required

/**
 * Added in version 6.19.0
 *
 * This method will be called when the user taps on a code that is not picked.
 */
- (void)didPickItemWithData:(nonnull NSString *)data
          completionHandler:(nonnull void (^)(BOOL))completionHandler;

/**
 * Added in version 6.19.0
 *
 * This method will be called when the user taps on a code that is already picked.
 */
- (void)didUnpickItemWithData:(nonnull NSString *)data
            completionHandler:(nonnull void (^)(BOOL))completionHandler;

@end

NS_ASSUME_NONNULL_END
