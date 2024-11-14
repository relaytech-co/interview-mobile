import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

enum _IconButtonVariant { standard, filled, outlined }

class RIconButton extends StatelessWidget {
  RIconButton({
    Key? key,
    this.iconSize,
    this.visualDensity,
    this.padding,
    this.alignment,
    this.splashRadius,
    this.color,
    this.focusColor,
    this.hoverColor,
    this.highlightColor,
    this.splashColor,
    this.disabledColor,
    required this.onPressed,
    this.mouseCursor,
    this.focusNode,
    this.autofocus = false,
    this.tooltip,
    this.enableFeedback,
    this.constraints,
    this.style,
    this.isSelected,
    this.selectedIcon,
    required this.icon,
    required this.traceName,
    this.sendAnalytics = true,
    this.analyticsProps,
    this.traceProps,
  })  : _variant = _IconButtonVariant.standard,
        super(key: key);

  RIconButton.filled(
      {super.key,
      this.iconSize,
      this.visualDensity,
      this.padding,
      this.alignment,
      this.splashRadius,
      this.color,
      this.focusColor,
      this.hoverColor,
      this.highlightColor,
      this.splashColor,
      this.disabledColor,
      required this.onPressed,
      this.mouseCursor,
      this.focusNode,
      this.autofocus = false,
      this.tooltip,
      this.style,
      this.enableFeedback,
      this.constraints,
      this.isSelected,
      this.selectedIcon,
      required this.traceName,
      this.sendAnalytics = true,
      this.analyticsProps,
      this.traceProps,
      required this.icon})
      : _variant = _IconButtonVariant.filled,
        super();

  RIconButton.outlined(
      {super.key,
      this.iconSize,
      this.visualDensity,
      this.padding,
      this.alignment,
      this.splashRadius,
      this.color,
      this.focusColor,
      this.hoverColor,
      this.highlightColor,
      this.splashColor,
      this.disabledColor,
      required this.onPressed,
      this.mouseCursor,
      this.focusNode,
      this.autofocus = false,
      this.tooltip,
      this.enableFeedback,
      this.constraints,
      this.style,
      this.isSelected,
      this.selectedIcon,
      required this.traceName,
      this.sendAnalytics = true,
      this.analyticsProps,
      this.traceProps,
      required this.icon})
      : _variant = _IconButtonVariant.outlined,
        super();

  final double? iconSize;
  final VisualDensity? visualDensity;
  final EdgeInsetsGeometry? padding;
  final AlignmentGeometry? alignment;
  final double? splashRadius;
  final Color? color;
  final Color? focusColor;
  final Color? hoverColor;
  final Color? highlightColor;
  final Color? splashColor;
  final Color? disabledColor;
  final void Function()? onPressed;
  final MouseCursor? mouseCursor;
  final FocusNode? focusNode;
  final bool autofocus;
  final String? tooltip;
  final bool? enableFeedback;
  final BoxConstraints? constraints;
  final ButtonStyle? style;
  final bool? isSelected;
  final Widget? selectedIcon;
  final Widget icon;
  final String traceName;
  final bool sendAnalytics;
  final Map<String, dynamic>? analyticsProps;
  final Map<String, dynamic>? traceProps;

  final _IconButtonVariant _variant;

  @override
  Widget build(BuildContext context) {
    if (_variant == _IconButtonVariant.filled) {
      return IconButton.filled(
          iconSize: iconSize ?? 25,
          visualDensity: visualDensity,
          padding: padding ?? const EdgeInsets.all(15),
          alignment: alignment,
          splashRadius: splashRadius,
          color: color ?? Colors.white,
          focusColor: focusColor,
          hoverColor: hoverColor,
          highlightColor: highlightColor,
          splashColor: splashColor,
          disabledColor: disabledColor,
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps,
              traceProps: traceProps,
              sendAnalytics: sendAnalytics),
          mouseCursor: mouseCursor,
          focusNode: focusNode,
          autofocus: autofocus,
          tooltip: tooltip,
          enableFeedback: enableFeedback,
          constraints: constraints,
          style: style ??
              ButtonStyle(
                  backgroundColor:
                      MaterialStateProperty.all(Theme.of(context).canvasColor)),
          isSelected: isSelected,
          selectedIcon: selectedIcon,
          icon: icon);
    } else if (_variant == _IconButtonVariant.outlined) {
      return IconButton.outlined(
          iconSize: iconSize,
          visualDensity: visualDensity,
          padding: padding,
          alignment: alignment,
          splashRadius: splashRadius,
          color: color,
          focusColor: focusColor,
          hoverColor: hoverColor,
          highlightColor: highlightColor,
          splashColor: splashColor,
          disabledColor: disabledColor,
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps,
              traceProps: traceProps,
              sendAnalytics: sendAnalytics),
          mouseCursor: mouseCursor,
          focusNode: focusNode,
          autofocus: autofocus,
          tooltip: tooltip,
          enableFeedback: enableFeedback,
          constraints: constraints,
          style: style,
          isSelected: isSelected,
          selectedIcon: selectedIcon,
          icon: icon);
    }

    return IconButton(
      iconSize: iconSize,
      visualDensity: visualDensity,
      padding: padding,
      alignment: alignment,
      splashRadius: splashRadius,
      color: color,
      focusColor: focusColor,
      hoverColor: hoverColor,
      highlightColor: highlightColor,
      splashColor: splashColor,
      disabledColor: disabledColor,
      onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
          props: analyticsProps,
          traceProps: traceProps,
          sendAnalytics: sendAnalytics),
      mouseCursor: mouseCursor,
      focusNode: focusNode,
      autofocus: autofocus,
      tooltip: tooltip,
      enableFeedback: enableFeedback,
      constraints: constraints,
      style: style,
      isSelected: isSelected,
      selectedIcon: selectedIcon,
      icon: icon,
    );
  }
}
