/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCQRCodeErrorCorrectionLevel.h>

@class SDCBarcodeGenerator;

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.21.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodeGeneratorBuilder)
@interface SDCBarcodeGeneratorBuilder : NSObject

/**
 * Added in version 6.21.0
 *
 * Sets the foreground color for the generated codes. Default is Color.BLACK.
 */
@property (nonatomic, strong, nonnull) UIColor *foregroundColor;
/**
 * Added in version 6.21.0
 *
 * Sets the background color for the generated codes. Default is Color.WHITE.
 */
@property (nonatomic, strong, nonnull) UIColor *backgroundColor;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.21.0
 *
 * Constructs a SDCBarcodeGenerator with the properties set on the builder.
 */
- (nullable SDCBarcodeGenerator *)buildWithError:(NSError *_Nullable *_Nullable)error;

@end

/**
 * Added in version 6.21.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(QRCodeBarcodeGeneratorBuilder)
@interface SDCQRCodeBarcodeGeneratorBuilder : SDCBarcodeGeneratorBuilder

/**
 * Added in version 6.21.0
 *
 * Configure how much error correction to use in the generated code.
 */
@property (nonatomic, assign) SDCQRCodeErrorCorrectionLevel errorCorrectionLevel;
/**
 * Added in version 6.21.0
 *
 * The version number for the QR code. Version number determines the size of the QR code, with a
 * larger size allowing more data to be stored. The value must be greater than 0, and if the value
 * is too small for the data being encoded, code generation will fail.
 */
@property (nonatomic, assign) NSInteger versionNumber;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

/**
 * Added in version 6.28.0
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(AztecBarcodeGeneratorBuilder)
@interface SDCAztecBarcodeGeneratorBuilder : SDCBarcodeGeneratorBuilder

/**
 * Added in version 6.28.0
 *
 * Optional parameter to configure how much error correction to use in the generated code. The value must be greater than 0.
 */
@property (nonatomic, assign) NSInteger minimumErrorCorrectionPercent;
/**
 * Added in version 6.28.0
 *
 * Optional parameter to configure how many layers, each one containing two rings of pixels, to use in the generated code. The value must be between -4 and 32. Negative values create compact codes.
 */
@property (nonatomic, assign) NSInteger layers;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
