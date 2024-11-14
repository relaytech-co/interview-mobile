import 'package:flutter/material.dart';

/// Simple pattern usually for [Scaffold]s where the [Scaffold.body] is supposed
/// to be a scroll, but has a fixed (persistent) element at the [bottom] of it.
abstract interface class RPersistentBottomBody implements Widget {
  const factory RPersistentBottomBody.column({
    Key? key,
    required Widget body,
    required Widget bottom,
    MainAxisSize mainAxisSize,
    MainAxisAlignment mainAxisAlignment,
    CrossAxisAlignment crossAxisAlignment,
  }) = _ColumnBottomBody;

  const factory RPersistentBottomBody.stack({
    Key? key,
    required Widget body,
    required Widget bottom,
    AlignmentDirectional alignment,
    TextDirection? textDirection,
    StackFit fit,
    Clip clipBehavior,
  }) = _StackBottomBody;
}

class _ColumnBottomBody extends StatelessWidget implements RPersistentBottomBody {
  const _ColumnBottomBody({
    super.key,
    required this.body,
    required this.bottom,
    this.mainAxisSize = MainAxisSize.max,
    this.mainAxisAlignment = MainAxisAlignment.start,
    this.crossAxisAlignment = CrossAxisAlignment.start,
  });

  final Widget body;
  final Widget bottom;

  final MainAxisSize mainAxisSize;
  final MainAxisAlignment mainAxisAlignment;
  final CrossAxisAlignment crossAxisAlignment;

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisSize: mainAxisSize,
      mainAxisAlignment: mainAxisAlignment,
      crossAxisAlignment: crossAxisAlignment,
      children: [
        Expanded(child: body),
        bottom,
      ],
    );
  }
}

class _StackBottomBody extends StatelessWidget implements RPersistentBottomBody {
  const _StackBottomBody({
    super.key,
    required this.body,
    required this.bottom,
    this.alignment = AlignmentDirectional.topStart,
    this.textDirection,
    this.fit = StackFit.loose,
    this.clipBehavior = Clip.hardEdge,
  });

  final Widget body;
  final Widget bottom;

  final AlignmentDirectional alignment;
  final TextDirection? textDirection;
  final StackFit fit;
  final Clip clipBehavior;

  @override
  Widget build(BuildContext context) {
    return Stack(
      alignment: alignment,
      textDirection: textDirection,
      fit: fit,
      clipBehavior: clipBehavior,
      children: [
        Positioned.fill(child: body),
        Positioned(left: 0, right: 0, bottom: 0, child: bottom),
      ],
    );
  }
}
