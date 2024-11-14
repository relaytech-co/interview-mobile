/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCDataCaptureContext;
@class SDCBarcodeGeneratorBuilder;
@class SDCQRCodeBarcodeGeneratorBuilder;
@class SDCAztecBarcodeGeneratorBuilder;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.21.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeGenerator)
@interface SDCBarcodeGenerator : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.21.0
 *
 * Create a Code 39 Barcode Generator builder for the provided context.
 */
+ (SDCBarcodeGeneratorBuilder *)code39BarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;
/**
 * Added in version 6.21.0
 *
 * Create a Code 128 Barcode Generator builder for the provided context.
 */
+ (SDCBarcodeGeneratorBuilder *)code128BarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;
/**
 * Added in version 6.21.0
 *
 * Create an EAN13 Barcode Generator builder for the provided context.
 *
 * @remark EAN13 codes are composed of 13 symbols. If 12 symbols are provided, it is assumed that the checksum is missing and it is generated and appended to the end.
 */
+ (SDCBarcodeGeneratorBuilder *)ean13BarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;
/**
 * Added in version 6.22.0
 *
 * Create a UPCA Barcode Generator builder for the provided context.
 */
+ (SDCBarcodeGeneratorBuilder *)upcaBarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;
/**
 * Added in version 6.21.0
 *
 * Create an Interleaved Two-of-Five Barcode Generator builder for the provided context.
 */
+ (SDCBarcodeGeneratorBuilder *)interleavedTwoOfFiveBarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;
/**
 * Added in version 6.21.0
 *
 * Create a QRCode Barcode Generator builder for the provided context.
 */
+ (SDCQRCodeBarcodeGeneratorBuilder *)QRCodeBarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;
/**
 * Added in version 6.21.0
 *
 * Create a DataMatrix Barcode Generator builder for the provided context.
 */
+ (SDCBarcodeGeneratorBuilder *)dataMatrixBarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;
/**
 * Added in version 6.28.0
 *
 * Create an Aztec Barcode Generator builder for the provided context.
 */
+ (SDCAztecBarcodeGeneratorBuilder *)aztecBarcodeGeneratorBuilderWithContext:
    (SDCDataCaptureContext *)context;

/**
 * Added in version 6.21.0
 *
 * Generate a code of the given width for the supplied data. If the data is not compatible
 * with the generator’s symbology, an exception is thrown.
 *
 * imageWidth specifies the width of the image in pixels.
 *
 * @remark The resulting UIImage will use the same scale as the device screen.
 */
- (nullable UIImage *)generateWithString:(NSString *)string
                              imageWidth:(CGFloat)width
                                   error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.21.0
 *
 * Generate a code of the given width for the supplied text. If the text is not compatible
 * with the generator’s symbology, an exception is thrown.
 *
 * imageWidth specifies the width of the image in pixels.
 *
 * @remark The resulting UIImage will use the same scale as the device screen.
 */
- (nullable UIImage *)generateWithData:(NSData *)data
                            imageWidth:(CGFloat)width
                                 error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
