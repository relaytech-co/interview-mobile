import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

class RTextButton extends StatelessWidget {
  RTextButton({
    Key? key,
    required this.onPressed,
    this.onLongPress,
    this.onHover,
    this.onFocusChange,
    this.style,
    this.focusNode,
    this.autofocus = false,
    this.clipBehavior = Clip.none,
    this.statesController,
    required this.traceName,
    this.sendAnalytics = true,
    this.analyticsProps,
    this.traceProps,
    required this.child,
  }) : super(key: key);

  final void Function()? onPressed;
  final void Function()? onLongPress;
  final void Function(bool)? onHover;
  final void Function(bool)? onFocusChange;
  final ButtonStyle? style;
  final FocusNode? focusNode;
  final bool autofocus;
  final Clip clipBehavior;
  final MaterialStatesController? statesController;
  final Widget child;
  final String traceName;
  final bool sendAnalytics;
  final Map<String, dynamic>? analyticsProps;
  final Map<String, dynamic>? traceProps;

  @override
  Widget build(BuildContext context) {
    return TextButton(
      onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
          props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
      onLongPress: Trace.wrapNullableHandler(onLongPress, '${traceName}_lp', 'btn',
          props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
      onHover: onHover,
      onFocusChange: onFocusChange,
      style: style,
      focusNode: focusNode,
      autofocus: autofocus,
      clipBehavior: clipBehavior,
      statesController: statesController,
      child: child,
    );
  }
}
