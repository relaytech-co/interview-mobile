import 'package:flutter/material.dart';
import 'package:utils/utils.dart';

import 'constants.dart';

/// Aligns buttons vertically.
///
/// This pattern is typically used at the bottom edge of the screen.
class RActionBar extends StatelessWidget {
  const RActionBar({
    super.key,
    this.mainAxisSize = MainAxisSize.min,
    this.mainAxisAlignment = MainAxisAlignment.start,
    this.crossAxisAlignment = CrossAxisAlignment.stretch,
    this.verticalDirection = VerticalDirection.down,
    this.textDirection,
    this.textBaseline,
    this.clipBehavior = Clip.none,
    this.padding,
    this.decoration,
    this.primaryHeroTag = primaryButtonHeroTag,
    this.backgroundColor,
    required this.primary,
    this.secondary,
    this.tertiary,
  }) : direction = Axis.vertical;

  const RActionBar.horizontal({
    super.key,
    this.mainAxisSize = MainAxisSize.max,
    this.mainAxisAlignment = MainAxisAlignment.spaceBetween,
    this.crossAxisAlignment = CrossAxisAlignment.start,
    this.textDirection,
    this.backgroundColor,
    this.textBaseline,
    this.verticalDirection = VerticalDirection.down,
    this.clipBehavior = Clip.none,
    this.padding,
    this.decoration,
    this.primaryHeroTag = primaryButtonHeroTag,
    required this.primary,
    this.secondary,
  })  : direction = Axis.horizontal,
        // tertiary variations don't usually fit in a limited horizontal space
        tertiary = null;

  final Axis direction;

  final MainAxisSize mainAxisSize;
  final MainAxisAlignment mainAxisAlignment;
  final CrossAxisAlignment crossAxisAlignment;
  final VerticalDirection verticalDirection;
  final TextDirection? textDirection;
  final TextBaseline? textBaseline;
  final Clip clipBehavior;
  final Color? backgroundColor;
  final EdgeInsetsGeometry? padding;
  final Decoration? decoration;

  final Object? primaryHeroTag;

  final Widget primary;
  final Widget? secondary;
  final Widget? tertiary;

  @override
  Widget build(BuildContext context) {
    var primaryChild = primary;
    if (primaryHeroTag != null) {
      primaryChild = Hero(
        tag: primaryHeroTag!,
        transitionOnUserGestures: true,
        child: primary,
      );
    }

    final children = <Widget>[
      ...switch (direction) {
        Axis.vertical => [
            primaryChild,
            if (secondary != null) secondary!,
            if (tertiary != null) tertiary!,
          ],
        Axis.horizontal => [
            if (tertiary != null) tertiary!,
            if (secondary != null) secondary!,
            primaryChild,
          ].map((child) => Expanded(child: child)),
      },
    ].insertBetween(const SizedBox.square(dimension: 8)).toList();

    return Container(
      decoration: decoration ??
          BoxDecoration(
            color: backgroundColor ?? Colors.black,
          ),
      padding: padding ?? const ScreenMarginInsets.only(top: 16, bottom: 30),
      child: Flex(
        direction: direction,
        mainAxisSize: mainAxisSize,
        mainAxisAlignment: mainAxisAlignment,
        crossAxisAlignment: crossAxisAlignment,
        verticalDirection: verticalDirection,
        textDirection: textDirection,
        textBaseline: textBaseline,
        clipBehavior: clipBehavior,
        children: children,
      ),
    );
  }
}
