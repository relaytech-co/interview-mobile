import 'package:flutter/material.dart';

import 'flex.dart';

abstract class _DecorationSkeleton extends StatelessWidget {
  const _DecorationSkeleton({
    super.key,
    this.decorationPosition = DecorationPosition.background,
    this.width,
    this.height,
    this.size,
    this.widthFactor,
    this.heightFactor,
    this.alignment = Alignment.center,
    this.sizeFactor,
    this.padding,
    this.margin,
    this.image,
    this.border,
    this.borderRadius,
    this.boxShadow,
    this.gradient,
    this.backgroundBlendMode,
  });

  Decoration get decoration;

  final DecorationPosition decorationPosition;
  final double? width;
  final double? height;
  final Size? size;
  final double? widthFactor;
  final double? heightFactor;
  final AlignmentGeometry alignment;
  final Size? sizeFactor;
  final EdgeInsetsGeometry? padding;
  final EdgeInsetsGeometry? margin;
  final DecorationImage? image;
  final BoxBorder? border;
  final BorderRadiusGeometry? borderRadius;
  final List<BoxShadow>? boxShadow;
  final Gradient? gradient;
  final BlendMode? backgroundBlendMode;

  @override
  Widget build(BuildContext context) {
    Widget child = DecoratedBox(
      position: decorationPosition,
      decoration: decoration,
      child: SizedBox.fromSize(size: padding?.collapsedSize ?? Size.zero),
    );

    if (widthFactor != null || heightFactor != null || sizeFactor != null) {
      child = FractionallySizedBox(
        alignment: alignment,
        widthFactor: widthFactor ?? sizeFactor?.width,
        heightFactor: heightFactor ?? sizeFactor?.height,
        child: child,
      );
    }
    if (width != null || height != null || size != null || padding != null) {
      child = SizedBox(
        width: _sumIfNotEmpty(width ?? size?.width, padding?.horizontal),
        height: _sumIfNotEmpty(height ?? size?.height, padding?.vertical),
        child: child,
      );
    }
    if (margin != null) {
      child = Padding(padding: margin!, child: child);
    }
    return child;
  }
}

/// A boxed (i.e. rectangle) decoration skeleton used for [Shimmer] layouts.
///
/// This skeleton by itself doesn't have any gradients applied to it. Build
/// your layout with multiple Skeletons and add a final gradient on top of
/// them for better performance (usually is used to wrap a whole screen).
class BoxSkeleton extends _DecorationSkeleton {
  const BoxSkeleton({
    super.key,
    this.shape = BoxShape.rectangle,
    super.decorationPosition = DecorationPosition.background,
    super.width,
    super.height,
    super.size,
    super.widthFactor,
    super.heightFactor,
    super.sizeFactor,
    super.alignment = Alignment.center,
    super.padding,
    super.margin,
    super.image,
    super.border,
    super.borderRadius,
    super.boxShadow,
    super.gradient,
    super.backgroundBlendMode,
  });

  const BoxSkeleton.circle({
    super.key,
    required double size,
    super.decorationPosition = DecorationPosition.background,
    super.padding,
    super.margin,
    super.image,
    super.border,
    super.borderRadius,
    super.boxShadow,
    super.gradient,
    super.backgroundBlendMode,
  })  : shape = BoxShape.circle,
        super(
          width: size,
          height: size,
          size: null,
          widthFactor: null,
          heightFactor: null,
          sizeFactor: null,
          alignment: Alignment.center,
        );

  final BoxShape shape;

  @override
  Decoration get decoration {
    return BoxDecoration(
      color: Colors.black,
      image: image,
      border: border,
      borderRadius: borderRadius,
      boxShadow: boxShadow,
      gradient: gradient,
      backgroundBlendMode: backgroundBlendMode,
      shape: shape,
    );
  }
}

/// A shape decoration skeleton used for [Shimmer] layouts.
///
/// This skeleton by itself doesn't have any gradients applied to it. Build
/// your layout with multiple Skeletons and add a final gradient on top of
/// them for better performance (usually is used to wrap a whole screen).
class ShapeSkeleton extends _DecorationSkeleton {
  const ShapeSkeleton({
    super.key,
    required this.shape,
    super.decorationPosition = DecorationPosition.background,
    super.width,
    super.height,
    super.size,
    super.widthFactor,
    super.heightFactor,
    super.alignment = Alignment.center,
    super.sizeFactor,
    super.padding,
    super.margin,
    super.image,
    super.border,
    super.borderRadius,
    super.boxShadow,
    super.gradient,
    super.backgroundBlendMode,
  });

  final ShapeBorder shape;

  @override
  Decoration get decoration {
    return ShapeDecoration(
      shape: shape,
      color: Colors.black,
      gradient: null,
      image: null,
      shadows: null,
    );
  }
}

/// A skeleton used for [Shimmer] layouts to be replaced by text sections
///
/// This skeleton by itself doesn't have any gradients applied to it. Build
/// your layout with multiple Skeletons and add a final gradient on top of
/// them for better performance (usually is used to wrap a whole screen).
class TextSkeleton extends StatelessWidget {
  const TextSkeleton({
    super.key,
    this.width,
    this.widthFactor,
    this.height,
    this.spacing,
    this.alignment = Alignment.center,
    this.padding,
    this.margin,
    this.style,
    this.borderRadius,
    this.lines = 1,
  }) : assert(lines >= 1);

  final double? width;
  final double? widthFactor;
  final double? height;
  final double? spacing;
  final AlignmentGeometry alignment;
  final EdgeInsetsGeometry? padding;
  final EdgeInsetsGeometry? margin;
  final BorderRadiusGeometry? borderRadius;
  final int lines;

  /// Determines which [TextStyle] to use from the current [TextTheme].
  /// If null, fallbacks to [DefaultTextStyle].
  final TextStyle? Function(TextTheme textTheme)? style;

  static double heightFromStyle(
    TextStyle? style, {
    double fallback = 16.0,
    double textScaleFactor = 1.0,
  }) {
    var result = fallback;
    if (style != null && style.fontSize != null) {
      result = style.fontSize! * (style.height ?? 1.0);
    }
    return result * textScaleFactor;
  }

  @override
  Widget build(BuildContext context) {
    final theme = Theme.of(context);
    final textScaleFactor = MediaQuery.textScalerOf(context);
    final defaultTextStyle = DefaultTextStyle.of(context);
    final currentStyle = style?.call(theme.textTheme) ?? defaultTextStyle.style;
    final barHeight = height ??
        heightFromStyle(
          currentStyle,
          textScaleFactor: textScaleFactor.scale(currentStyle.fontSize ?? 16.0),
        );

    Widget child = BoxSkeleton(
      width: width,
      widthFactor: widthFactor,
      alignment: alignment,
      height: barHeight,
      padding: padding,
      margin: margin,
      borderRadius: borderRadius,
    );

    final lineShapes = List<Widget>.filled(
      lines - 1,
      BoxSkeleton(
        width: width,
        widthFactor: 1.0,
        alignment: alignment,
        height: barHeight,
        padding: padding,
        margin: margin,
        borderRadius: borderRadius,
      ),
    );

    final crossAxisAlignment = switch (defaultTextStyle.textAlign) {
      TextAlign.center => CrossAxisAlignment.center,
      TextAlign.end || TextAlign.right => CrossAxisAlignment.end,
      TextAlign.start || TextAlign.left || _ => CrossAxisAlignment.start,
    };

    if (lines > 1) {
      child = SpacedColumn(
        mainAxisSize: MainAxisSize.min,
        mainAxisAlignment: MainAxisAlignment.start,
        crossAxisAlignment: crossAxisAlignment,
        spacing: 4.0,
        children: lineShapes.followedBy([child]).toList(),
      );
    }

    return child;
  }
}

/// A skeleton used for [Shimmer] layouts that will be replaced by an Icon
///
/// This skeleton by itself doesn't have any gradients applied to it. Build
/// your layout with multiple Skeletons and add a final gradient on top of
/// them for better performance (usually is used to wrap a whole screen).
class IconSkeleton extends StatelessWidget {
  const IconSkeleton({
    super.key,
    this.shape = BoxShape.circle,
    this.width,
    this.height,
    this.size,
    this.widthFactor,
    this.heightFactor,
    this.sizeFactor,
    this.alignment = Alignment.center,
    this.padding,
    this.margin,
    this.image,
    this.border,
    this.borderRadius,
    this.boxShadow,
    this.gradient,
    this.backgroundBlendMode,
  });

  final BoxShape shape;
  final double? width;
  final double? height;
  final Size? size;
  final double? widthFactor;
  final double? heightFactor;
  final Size? sizeFactor;
  final AlignmentGeometry alignment;
  final EdgeInsetsGeometry? padding;
  final EdgeInsetsGeometry? margin;
  final DecorationImage? image;
  final BoxBorder? border;
  final BorderRadiusGeometry? borderRadius;
  final List<BoxShadow>? boxShadow;
  final Gradient? gradient;
  final BlendMode? backgroundBlendMode;

  @override
  Widget build(BuildContext context) {
    final iconTheme = IconTheme.of(context);

    return BoxSkeleton(
      shape: shape,
      width: width,
      height: height,
      size: size ?? Size.square(iconTheme.size ?? 24.0),
      widthFactor: widthFactor,
      heightFactor: heightFactor,
      sizeFactor: sizeFactor,
      alignment: alignment,
      padding: padding,
      margin: margin,
      image: image,
      border: border,
      borderRadius: borderRadius,
      boxShadow: boxShadow,
      gradient: gradient,
      backgroundBlendMode: backgroundBlendMode,
    );
  }
}

double? _sumIfNotEmpty(double? lhs, double? rhs) {
  if (lhs == null) return rhs;
  if (rhs == null) return lhs;
  return lhs + rhs;
}
