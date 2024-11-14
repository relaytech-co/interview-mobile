import 'package:flutter/material.dart';
import 'package:utils/utils.dart';

/// A [Column] that automatically inserts [spacing] between the elements in
/// [children].
class SpacedColumn extends Column {
  SpacedColumn({
    super.key,
    super.mainAxisAlignment,
    super.mainAxisSize,
    super.crossAxisAlignment,
    super.textDirection,
    super.verticalDirection,
    super.textBaseline,
    this.spacing = 0.0,
    List<Widget> children = const [],
  }) : super(
          children: children.insertBetween(SizedBox(height: spacing)).toList(),
        );

  /// The space between each element in [children], on the main axis.
  ///
  /// Default is 0.
  final double spacing;
}

/// A [Row] that automatically inserts [spacing] between the elements in
/// [children].
class SpacedRow extends Row {
  SpacedRow({
    super.key,
    super.mainAxisAlignment,
    super.mainAxisSize,
    super.crossAxisAlignment,
    super.textDirection,
    super.verticalDirection,
    super.textBaseline,
    this.spacing = 0.0,
    List<Widget> children = const [],
  }) : super(
          children: children.insertBetween(SizedBox(width: spacing)).toList(),
        );

  /// The space between each element in [children], on the main axis.
  ///
  /// Default is 0.
  final double spacing;
}
