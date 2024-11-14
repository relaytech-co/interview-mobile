/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <AVFoundation/AVFoundation.h>
#import <ScanditCaptureCore/SDCFrameSource.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.12.0
 *
 * Emits frames added via addSampleBuffer:.
 *
 * This class can be used if the camera is not handled by Scandit Data Capture SDK (i.e., when using another framework handling the camera, like ARKit).
 * Register an instance of this class as the data source via SDCDataCaptureContext.frameSource and then add frames coming from the camera via addSampleBuffer:.
 *
 * @remark The only pixel format type supported is kCVPixelFormatType_420YpCbCr8BiPlanarFullRange.
 */
NS_SWIFT_NAME(SequenceFrameSource)
SDC_EXPORTED_SYMBOL
@interface SDCSequenceFrameSource : NSObject <SDCFrameSource>

/**
 * Added in version 6.12.0
 *
 * Constructs a new SDCSequenceFrameSource. It requires the position of the capture device (https://developer.apple.com/documentation/avfoundation/avcapturedeviceposition) and the lens position (https://developer.apple.com/documentation/avfoundation/avcapturedevice/1624643-lensposition).
 */
- (instancetype)initWithCaptureDevicePosition:(AVCaptureDevicePosition)captureDevicePosition
                                 lensPosition:(CGFloat)lensPosition;

/**
 * Added in version 6.12.0
 *
 * Convenience method for SDCFrameSource.switchToDesiredState:completionHandler:: it is same as calling SDCFrameSource.switchToDesiredState:completionHandler: with the second argument set to nil.
 */
- (void)switchToDesiredState:(SDCFrameSourceState)state;
/**
 * Added in version 6.12.0
 *
 * Add a sample buffer. If this frame source is SDCFrameSourceStateOn and connected to a SDCDataCaptureContext this is the next frame that will be processed.
 * Note that the only pixel format type supported is kCVPixelFormatType_420YpCbCr8BiPlanarFullRange.
 */
- (void)addSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end

NS_ASSUME_NONNULL_END
