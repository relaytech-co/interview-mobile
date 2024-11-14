/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

@class SDCDataCaptureContext;
@class SDCBarcodePick;
@class SDCBarcodePickView;
@class SDCBarcodePickSettings;
@class SDCBarcodePickAsyncMapperProductProvider;
@class NSLayoutYAxisAnchor;
@protocol SDCBarcodePickProductProvider;
@protocol SDCBarcodePickAsyncMapperProductProviderDelegate;
@protocol SDCBarcodePickDeserializerDelegate;
@protocol SDCBarcodePickViewHighlightStyleCustomViewDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.19.0
 *
 * A deserializer to construct barcode pick settings and mode from JSON.
 */
NS_SWIFT_NAME(BarcodePickDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodePickDeserializer : NSObject

/**
 * Added in version 6.19.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodePickDeserializerDelegate> delegate;

/**
 * Added in version 6.19.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)barcodePickDeserializer;

/**
 * Added in version 6.19.0
 *
 * Constructs a new SDCBarcodePickSettings object with the provided JSON serialization.
 */
- (nullable SDCBarcodePickSettings *)settingsFromJSONString:(NSString *)JSONString
                                                      error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.19.0
 *
 * Updates the settings according to a JSON serialization.
 */
- (nullable SDCBarcodePickSettings *)updateSettings:(SDCBarcodePickSettings *)settings
                                     fromJSONString:(NSString *)JSONString
                                              error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.19.0
 *
 * Constructs a new SDCBarcodePick object with the provided JSON serialization.
 */
- (nullable SDCBarcodePick *)modeFromJSONString:(NSString *)JSONString
                                        context:(SDCDataCaptureContext *)context
                                productProvider:(id<SDCBarcodePickProductProvider>)productProvider
                                          error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.19.0
 *
 * Updates the mode according to a JSON serialization.
 */
- (nullable SDCBarcodePick *)updateMode:(SDCBarcodePick *)mode
                         fromJSONString:(NSString *)JSONString
                                  error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.19.0
 *
 * Constructs a new async SDCBarcodePickAsyncMapperProductProvider with the provided JSON serialization.
 */
- (nullable SDCBarcodePickAsyncMapperProductProvider *)asyncMapperProductProviderFromJSONString:(NSString *)JSONString
                                                                                       delegate:(id<SDCBarcodePickAsyncMapperProductProviderDelegate>)delegate
                                                                                          error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.19.0
 *
 * Constructs a new SDCBarcodePickView object with the provided JSON serialization.
 */
- (nullable SDCBarcodePickView *)viewFromJSONString:(NSString *)JSONString
                                            context:(SDCDataCaptureContext *)context
                                               mode:(SDCBarcodePick *)mode
                                              error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.20.0
 *
 * Constructs a new SDCBarcodePickView object with the provided JSON serialization.
 * An optional topLayoutAnchor can be specified. See SDCBarcodePickViewSettings.topLayoutAnchor.
 */
- (nullable SDCBarcodePickView *)viewFromJSONString:(NSString *)JSONString
                                            context:(SDCDataCaptureContext *)context
                                    topLayoutAnchor:(nullable NSLayoutYAxisAnchor *)topLayoutAnchor
                                               mode:(SDCBarcodePick *)mode
                                              error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.25.0
 *
 * Constructs a new SDCBarcodePickView object with the provided JSON serialization, and a SDCBarcodePickViewHighlightStyleCustomViewDelegate for the SDCBarcodePickViewHighlightStyleCustomView type.
 */
- (nullable SDCBarcodePickView *)viewFromJSONString:(NSString *)JSONString
                                            context:(SDCDataCaptureContext *)context
                                    topLayoutAnchor:(nullable NSLayoutYAxisAnchor *)topLayoutAnchor
                                               mode:(SDCBarcodePick *)mode
                   customViewHighlightStyleDelegate:(nullable id<SDCBarcodePickViewHighlightStyleCustomViewDelegate>)customViewHighlightStyleDelegate
                                              error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.19.0
 *
 * Updates the view according to a JSON serialization.
 */
- (nullable SDCBarcodePickView *)updateView:(SDCBarcodePickView *)view
                             fromJSONString:(nonnull NSString *)JSONString
                                      error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
