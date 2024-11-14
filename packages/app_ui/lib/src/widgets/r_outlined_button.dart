import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

import '../../app_ui.dart';

class ROutlinedButton extends StatelessWidget {
  ROutlinedButton({
    super.key,
    required this.onPressed,
    this.onLongPress,
    this.onHover,
    this.onFocusChange,
    //  this.style,
    this.focusNode,
    this.autofocus = false,
    this.clipBehavior = Clip.none,
    this.statesController,
    required this.traceName,
    this.sendAnalytics = true,
    this.isExpanded = false,
    this.analyticsProps,
    this.foregroundColor,
    this.backgroundColor,
    this.padding,
    this.traceProps,
    required this.label,
    this.child,
  })  : this.icon = null,
        this.style = OutlinedButton.styleFrom(
            padding: padding,
            foregroundColor: foregroundColor ?? Colors.white,
            backgroundColor: backgroundColor ?? Colors.transparent,
            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
        super();

  ROutlinedButton.icon({
    super.key,
    required this.onPressed,
    this.onLongPress,
    this.focusNode,
    this.autofocus = false,
    this.clipBehavior = Clip.none,
    this.statesController,
    required this.traceName,
    this.sendAnalytics = true,
    this.analyticsProps,
    this.traceProps,
    this.foregroundColor,
    this.backgroundColor,
    this.isExpanded = false,
    this.padding,
    required Widget icon,
    this.child,
    required this.label,
  })  : this.onHover = null,
        this.onFocusChange = null,
        this.style = OutlinedButton.styleFrom(
            foregroundColor: foregroundColor ?? Colors.white,
            backgroundColor: backgroundColor ?? Colors.transparent,
            padding: padding,
            minimumSize: const Size(0, 0),
            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
        this.icon = icon,
        super();

  ROutlinedButton.muted({
    super.key,
    required this.onPressed,
    this.onLongPress,
    this.focusNode,
    this.autofocus = false,
    this.clipBehavior = Clip.none,
    this.statesController,
    required this.traceName,
    this.padding,
    this.sendAnalytics = true,
    this.analyticsProps,
    this.traceProps,
    this.icon,
    this.foregroundColor,
    this.backgroundColor,
    this.isExpanded = false,
    this.child,
    required this.label,
  })  : this.onHover = null,
        this.onFocusChange = null,
        this.style = OutlinedButton.styleFrom(
            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8)),
            foregroundColor: foregroundColor ?? Colors.white,
            backgroundColor: backgroundColor ?? RelayColors.trueGray.shade800,
            padding: padding,
            // overlayColor: Colors.transparent,
            side: const BorderSide(color: Colors.grey)),
        super();

  final void Function()? onPressed;
  final void Function()? onLongPress;
  final void Function(bool)? onHover;
  final void Function(bool)? onFocusChange;
  final EdgeInsets? padding;
  final ButtonStyle? style;
  final FocusNode? focusNode;
  final Color? foregroundColor;
  final Color? backgroundColor;
  final bool autofocus;
  final Clip clipBehavior;
  final MaterialStatesController? statesController;
  final Widget? child;
  final String traceName;
  final bool sendAnalytics;
  final Map<String, dynamic>? analyticsProps;
  final Map<String, dynamic>? traceProps;
  final Widget? icon;
  final String? label;
  final bool isExpanded;

  @override
  Widget build(BuildContext context) {
    final child1 = Row(
      mainAxisAlignment: MainAxisAlignment.center,
      mainAxisSize: isExpanded ? MainAxisSize.max : MainAxisSize.min,
      children: [
        if (icon != null) icon!,
        if (icon != null && label != null) const Spacer1(),
        if (label != null) Text(label!)
      ],
    );

    return OutlinedButton(
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
      child: child ?? child1,
    );
  }
}
