/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.19.0
 *
 * Base protocol to which each product provider needs to conform to.
 *
 * @remark This interface might change in the future and should only be used through Scandit-provided implementations: [SDCBarcodePickAsyncMapperProductProvider].
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickProductProvider)
@protocol SDCBarcodePickProductProvider <NSObject>

@end
