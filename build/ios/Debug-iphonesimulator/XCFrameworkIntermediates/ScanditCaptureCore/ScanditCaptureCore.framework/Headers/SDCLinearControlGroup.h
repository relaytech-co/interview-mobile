/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCControl.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

/**
 * Added in version 6.14.0
 *
 * The orientation in which a SDCLinearControlGroup will render its child controls.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCLinearControlGroupOrientation) {
/**
     * Added in version 6.14.0
     *
     * Vertical orientation.
     */
    SDCLinearControlGroupOrientationVertical,
/**
     * Added in version 6.14.0
     *
     * Horizontal orientation.
     */
    SDCLinearControlGroupOrientationHorizontal
} NS_SWIFT_NAME(LinearControlGroupOrientation);

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.14.0
 *
 * A Control that contains multiple sub-controls allowing for spacing and orientation to be specified through initializer. This control will arrange child controls either horizontally in a single column or vertically in a single row. Use one of the initializers to build an instance of this control and add to a DataCaptureView by calling SDCDataCaptureView.addControl:.
 *
 * For example, in Swift:
 *
 * @code
 * let torchControl = TorchSwitchControl()
 * let macroModeControl = MacroModeControl()
 * let linearControlGroup = LinearControlGroup(controls:[torchControl, macroModeControl], orientation:.horizontal);
 * captureView.addControl(linearControlGroup)
 * @endcode
 *
 * or, in Objective-C:
 *
 * @code
 * SDCTorchSwitchControl *torchControl = [[SDCTorchSwitchControl alloc] init];
 * SDCMacroModeControl *macroModeControl = [[SDCMacroModeControl alloc] init];
 * SDCLinearControlGroup *linearControlGroup = [[SDCLinearControlGroup alloc] initWithControls:@[torchControl, macroModeControl] orientation:SDCLinearControlGroupOrientationHorizontal];
 * [self.captureView addControl:linearControlGroup];
 * @endcode
 *
 * @remark The controls are added from top to bottom when vertical, from left to right when horizontal.
 */
NS_SWIFT_NAME(LinearControlGroup)
SDC_EXPORTED_SYMBOL
@interface SDCLinearControlGroup : NSObject <SDCControl>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.14.0
 *
 * Get the list of controls currently in this group.
 */
@property (nonatomic, nonnull, readonly) NSArray<id<SDCControl>> *controls;
/**
 * Added in version 6.14.0
 *
 * Get the orientation for the LinearControlGroup.
 */
@property (nonatomic, readonly) SDCLinearControlGroupOrientation orientation;
/**
 * Added in version 6.14.0
 *
 * Get the spacing applied between controls inside the LinearControlGroup being built.
 */
@property (nonatomic, readonly) SDCFloatWithUnit spacing;

/**
 * Added in version 6.15.0
 *
 * Constructs a new linear control group with the provided JSON serialization.
 */
+ (nullable instancetype)linearControlGroupFromJSONString:(nonnull NSString *)JSONString
                                                    error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.14.0
 *
 * Initializes a new linear control group with controls which will be displayed inside the LinearControlGroup.
 */
- (instancetype)initWithControls:(NSArray<id<SDCControl>> *)controls;
/**
 * Added in version 6.14.0
 *
 * Initializes a new linear control group with controls which will be displayed inside the LinearControlGroup and specified orientation.
 */
- (instancetype)initWithControls:(NSArray<id<SDCControl>> *)controls
                     orientation:(SDCLinearControlGroupOrientation)orientation;
/**
 * Added in version 6.14.0
 *
 * Initializes a new linear control group with controls which will be displayed inside the LinearControlGroup and specified spacing applied between controls inside the LinearControlGroup.
 */
- (instancetype)initWithControls:(NSArray<id<SDCControl>> *)controls
                         spacing:(SDCFloatWithUnit)spacing;
/**
 * Added in version 6.14.0
 *
 * Initializes a new linear control group with controls which will be displayed inside the LinearControlGroup, specified orientation and spacing applied between controls inside the LinearControlGroup.
 */
- (instancetype)initWithControls:(NSArray<id<SDCControl>> *)controls
                     orientation:(SDCLinearControlGroupOrientation)orientation
                         spacing:(SDCFloatWithUnit)spacing NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
