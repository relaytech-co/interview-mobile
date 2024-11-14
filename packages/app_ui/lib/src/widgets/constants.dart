import 'package:flutter/material.dart';

const Object primaryButtonHeroTag = _PrimaryButtonHeroTag();

class _PrimaryButtonHeroTag {
  const _PrimaryButtonHeroTag();

  @override
  String toString() => '<default primary button tag>';
}

const double kScreenMargin = 24.0;

class ScreenMarginInsets extends EdgeInsets {
  const ScreenMarginInsets.only({
    super.left = kScreenMargin,
    super.top,
    super.right = kScreenMargin,
    super.bottom,
  }) : super.only();

  const ScreenMarginInsets.symmetric({
    super.vertical = 0.0,
  }) : super.symmetric(horizontal: kScreenMargin);
}
