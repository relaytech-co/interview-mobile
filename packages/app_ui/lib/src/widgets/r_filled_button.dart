import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

import '../../app_ui.dart';
import 'r_progress_indicators.dart';

enum _FilledButtonVariant { filled, tonal, destructive, secondary, white, lightMode }

const Size _kDefaultMinimumSize = Size(64.0, 20.0);

class RFilledButton extends FilledButton {
  RFilledButton({
    super.key,
    void Function()? onPressed,
    void Function()? onLongPress,
    super.onHover,
    super.onFocusChange,
    // super.style,
    super.focusNode,
    super.autofocus = false,
    super.clipBehavior = Clip.none,
    super.statesController,
    bool expand = false,
    bool loading = false,
    Widget? leadingIcon,
    Widget? trailingIcon,
    required String traceName,
    bool sendAnalytics = true,
    Map<String, dynamic>? analyticsProps,
    Map<String, dynamic>? traceProps,
    EdgeInsetsGeometry? padding,
    required Widget child,
  })  : _variant = _FilledButtonVariant.filled,
        super(
          child: _ButtonChild(
            expand: expand,
            loading: loading,
            leadingIcon: leadingIcon,
            trailingIcon: trailingIcon,
            child: child,
          ),
          style: FilledButton.styleFrom(
              padding: padding,
              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
          onLongPress: Trace.wrapNullableHandler(onLongPress, '${traceName}_lp', 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
        );

  RFilledButton.tonal({
    super.key,
    required void Function()? onPressed,
    void Function()? onLongPress,
    super.onHover,
    super.onFocusChange,
    // super.style,
    super.focusNode,
    super.autofocus = false,
    super.clipBehavior = Clip.none,
    super.statesController,
    bool expand = false,
    bool loading = false,
    Widget? leadingIcon,
    Widget? trailingIcon,
    required String traceName,
    bool sendAnalytics = true,
    Map<String, dynamic>? analyticsProps,
    Map<String, dynamic>? traceProps,
    required Widget child,
    EdgeInsetsGeometry? padding,
  })  : _variant = _FilledButtonVariant.tonal,
        super(
          child: _ButtonChild(
            expand: expand,
            loading: loading,
            leadingIcon: leadingIcon,
            trailingIcon: trailingIcon,
            child: child,
          ),
          style: FilledButton.styleFrom(
              padding: padding,
              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
          onLongPress: Trace.wrapNullableHandler(onLongPress, '${traceName}_lp', 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
        );

  RFilledButton.destructive({
    super.key,
    required void Function()? onPressed,
    void Function()? onLongPress,
    super.onHover,
    super.onFocusChange,
    // super.style,
    super.focusNode,
    super.autofocus = false,
    super.clipBehavior = Clip.none,
    super.statesController,
    bool expand = false,
    bool loading = false,
    Widget? leadingIcon,
    Widget? trailingIcon,
    required String traceName,
    bool sendAnalytics = true,
    Map<String, dynamic>? analyticsProps,
    Map<String, dynamic>? traceProps,
    EdgeInsetsGeometry? padding,
    required Widget child,
  })  : _variant = _FilledButtonVariant.destructive,
        super(
          child: _ButtonChild(
            expand: expand,
            loading: loading,
            leadingIcon: leadingIcon,
            trailingIcon: trailingIcon,
            child: child,
          ),
          style: FilledButton.styleFrom(
              padding: padding,
              backgroundColor: RelayColors.error,
              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
          onLongPress: Trace.wrapNullableHandler(onLongPress, '${traceName}_lp', 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
        );

  RFilledButton.secondary({
    super.key,
    required void Function()? onPressed,
    void Function()? onLongPress,
    super.onHover,
    super.onFocusChange,
    // super.style,
    super.focusNode,
    super.autofocus = false,
    super.clipBehavior = Clip.none,
    super.statesController,
    bool expand = false,
    bool loading = false,
    Widget? leadingIcon,
    Widget? trailingIcon,
    required String traceName,
    bool sendAnalytics = true,
    Map<String, dynamic>? analyticsProps,
    EdgeInsetsGeometry? padding,
    Map<String, dynamic>? traceProps,
    required Widget child,
  })  : _variant = _FilledButtonVariant.secondary,
        super(
          child: _ButtonChild(
            expand: expand,
            loading: loading,
            leadingIcon: leadingIcon,
            trailingIcon: trailingIcon,
            child: child,
          ),
          style: FilledButton.styleFrom(
              padding: padding,
              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
          onLongPress: Trace.wrapNullableHandler(onLongPress, '${traceName}_lp', 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
        );

  RFilledButton.lightMode({
    super.key,
    required void Function()? onPressed,
    void Function()? onLongPress,
    super.onHover,
    super.onFocusChange,
    // super.style,
    super.focusNode,
    super.autofocus = false,
    super.clipBehavior = Clip.none,
    super.statesController,
    bool expand = false,
    bool loading = false,
    Widget? leadingIcon,
    Widget? trailingIcon,
    required String traceName,
    bool sendAnalytics = true,
    Map<String, dynamic>? analyticsProps,
    Map<String, dynamic>? traceProps,
    required Widget child,
    EdgeInsetsGeometry? padding,
  })  : _variant = _FilledButtonVariant.lightMode,
        super(
          child: _ButtonChild(
            expand: expand,
            loading: loading,
            leadingIcon: leadingIcon,
            trailingIcon: trailingIcon,
            child: child,
          ),
          style: FilledButton.styleFrom(
              padding: padding,
              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
          onLongPress: Trace.wrapNullableHandler(onLongPress, '${traceName}_lp', 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
        );

  RFilledButton.white({
    super.key,
    required void Function()? onPressed,
    void Function()? onLongPress,
    super.onHover,
    super.onFocusChange,
    // super.style,
    super.focusNode,
    super.autofocus = false,
    super.clipBehavior = Clip.none,
    super.statesController,
    bool expand = false,
    bool loading = false,
    Widget? leadingIcon,
    Widget? trailingIcon,
    required String traceName,
    bool sendAnalytics = true,
    Map<String, dynamic>? analyticsProps,
    Map<String, dynamic>? traceProps,
    required Widget child,
    EdgeInsetsGeometry? padding,
  })  : _variant = _FilledButtonVariant.white,
        super(
          child: _ButtonChild(
            expand: expand,
            loading: loading,
            leadingIcon: leadingIcon,
            trailingIcon: trailingIcon,
            child: child,
          ),
          style: FilledButton.styleFrom(
              padding: padding,
              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8))),
          onPressed: Trace.wrapNullableHandler(onPressed, traceName, 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
          onLongPress: Trace.wrapNullableHandler(onLongPress, '${traceName}_lp', 'btn',
              props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
        );

  final _FilledButtonVariant _variant;

  @override
  ButtonStyle defaultStyleOf(BuildContext context) {
    final theme = Theme.of(context);
    final colors = theme.colorScheme;

    final Color? foregroundColor, backgroundColor;
    switch (_variant) {
      case _FilledButtonVariant.filled:
        foregroundColor = colors.onPrimary;
        backgroundColor = colors.primary;
        break;
      case _FilledButtonVariant.tonal:
        foregroundColor = colors.onSecondaryContainer;
        backgroundColor = colors.secondaryContainer;
        break;
      case _FilledButtonVariant.secondary:
        foregroundColor = Colors.white;
        backgroundColor = colors.background;
        break;
      case _FilledButtonVariant.destructive:
        foregroundColor = Colors.black;
        backgroundColor = colors.errorContainer;
        break;
      case _FilledButtonVariant.lightMode:
        foregroundColor = Colors.white;
        backgroundColor = Colors.black;
      case _FilledButtonVariant.white:
        foregroundColor = Colors.black;
        backgroundColor = Colors.white;
    }

    return FilledButton.styleFrom(
      foregroundColor: foregroundColor,
      backgroundColor: backgroundColor,
      disabledForegroundColor: colors.onSurfaceVariant,
      disabledBackgroundColor: colors.surfaceVariant,
      shadowColor: colors.shadow,
      surfaceTintColor: Colors.transparent,
      elevation: 0,
      minimumSize: _kDefaultMinimumSize,
      // No default fixedSize
      fixedSize: null,
      maximumSize: Size.infinite,
      // No default side
      side: _FilledButtonVariant.white == _variant
          ? BorderSide(color: Color.fromARGB(255, 214, 213, 213), width: 1)
          : null,
      enabledMouseCursor: SystemMouseCursors.click,
      disabledMouseCursor: SystemMouseCursors.basic,
      visualDensity: theme.visualDensity,
      tapTargetSize: theme.materialTapTargetSize,
      animationDuration: kThemeChangeDuration,
      enableFeedback: true,
      alignment: Alignment.center,
      splashFactory: theme.splashFactory,
    );
  }

  @override
  ButtonStyle? themeStyleOf(BuildContext context) {
    return FilledButtonTheme.of(context).style;
  }
}

class _ButtonChild extends StatelessWidget {
  const _ButtonChild({
    required this.expand,
    required this.loading,
    required this.leadingIcon,
    required this.trailingIcon,
    required this.child,
  });

  final bool expand, loading;
  final Widget? leadingIcon, trailingIcon;
  final Widget? child;

  @override
  Widget build(BuildContext context) {
    const spacing = SizedBox(width: 8.0);
    final style = DefaultTextStyle.of(context).style;
    final indicatorSize = (style.fontSize ?? 24.0) * (style.height ?? 1.0);

    return RVisibilityProgressIndicator(
      loading: loading,
      indicatorSize: indicatorSize,
      child: Row(
        mainAxisSize: expand ? MainAxisSize.max : MainAxisSize.min,
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.center,
        children: <Widget>[
          if (leadingIcon != null) ...[leadingIcon!, spacing],
          if (child != null) Flexible(child: child!),
          if (trailingIcon != null) ...[spacing, trailingIcon!],
        ],
      ),
    );
  }
}
