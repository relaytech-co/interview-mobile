/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodeCountView;
@class SDCBarcodeCount;
@class SDCDataCaptureContext;

@class SDCBrush;

@class NSLayoutYAxisAnchor;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.17.0
 *
 * A deserializer to construct barcode count views from JSON.
 */
NS_SWIFT_NAME(BarcodeCountViewDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCountViewDeserializer : NSObject

/**
 * Added in version 6.17.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)barcodeCountViewDeserializer;

/**
 * Added in version 6.17.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

/**
 * Added in version 6.17.0
 *
 * Constructs a new barcode count view with the provided JSON serialization.
 */
- (nullable SDCBarcodeCountView *)viewFromJSONString:(NSString *)JSONString
                                        barcodeCount:(SDCBarcodeCount *)mode
                                             context:(SDCDataCaptureContext *)context
                                               error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.24.0
 *
 * Constructs a new barcode count view with the provided JSON serialization.
 * An optional topLayoutAnchor can be specified.
 */
- (nullable SDCBarcodeCountView *)viewFromJSONString:(NSString *)JSONString
                                        barcodeCount:(SDCBarcodeCount *)mode
                                     topLayoutAnchor:(nullable NSLayoutYAxisAnchor *)topLayoutAnchor
                                             context:(SDCDataCaptureContext *)context
                                               error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.17.0
 *
 * Updates the view according to a JSON serialization.
 */
- (nullable SDCBarcodeCountView *)updateView:(SDCBarcodeCountView *)view
                              fromJSONString:(NSString *)JSONString
                                       error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.18.0
 *
 * Updates the view according to a JSON serialization, sets the view to use the SDCDataCaptureContext instance passed as parameter.
 */
- (nullable SDCBarcodeCountView *)updateView:(SDCBarcodeCountView *)view
                              fromJSONString:(NSString *)JSONString
                                     context:(SDCDataCaptureContext *)context
                                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
