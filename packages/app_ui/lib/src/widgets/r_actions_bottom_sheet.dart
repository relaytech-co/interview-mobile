import 'package:collection/collection.dart';
import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

import '../../app_ui.dart';

Future<T?> showAppModalBottomSheet<T>({
  required BuildContext context,
  required WidgetBuilder builder,
  Color? backgroundColor = Colors.transparent,
  double? elevation,
  ShapeBorder? shape,
  Clip? clipBehavior,
  BoxConstraints? constraints,
  Color? barrierColor,
  bool isScrollControlled = false,
  bool useRootNavigator = false,
  bool isDismissible = true,
  bool enableDrag = false,
  RouteSettings? routeSettings,
  AnimationController? transitionAnimationController,
}) {
  return showModalBottomSheet(
    context: context,
    builder: builder,
    backgroundColor: backgroundColor,
    elevation: elevation,
    shape: shape,
    clipBehavior: clipBehavior,
    constraints: constraints,
    barrierColor: barrierColor,
    isScrollControlled: true,
    useRootNavigator: useRootNavigator,
    isDismissible: isDismissible,
    enableDrag: enableDrag,
    routeSettings: routeSettings,
    transitionAnimationController: transitionAnimationController,
  );
}

class RActionsBottomSheet extends StatelessWidget {
  const RActionsBottomSheet({
    super.key,
    required this.actions,
    this.title,
    this.cancel,
    this.onClosing,
    this.animationController,
    this.enableDrag = false,
  });

  static const double _borderRadius = 16;

  /// A widget displayed on top.
  final Widget? title;

  /// A list of widgets displayed vertically in a column.
  final List<Widget> actions;

  /// A widget displayed on the bottom, separated with a spacing between
  /// the actions column.
  final Widget? cancel;

  /// Called when the bottom sheet begins to close.
  /// Works only if the close action was triggered by a drag gesture.
  final VoidCallback? onClosing;

  /// The animation controller that controls the bottom sheet's entrance
  /// and exit animations.
  final AnimationController? animationController;

  /// If true, the bottom sheet can be dragged up and down
  /// and dismissed by swiping downwards.
  final bool enableDrag;

  @override
  Widget build(BuildContext context) {
    final titleAndActions = [
      if (title != null) title!,
      ...actions,
    ];
    return SafeArea(
      child: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 15),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            ClipRRect(
              borderRadius: BorderRadius.circular(_borderRadius),
              child: Column(
                mainAxisSize: MainAxisSize.min,
                children: titleAndActions
                    .expandIndexed(
                      (index, action) => <Widget>[
                        action,
                        if (index != titleAndActions.length - 1)
                          const Divider(
                            indent: 0,
                            endIndent: 0,
                          ),
                      ],
                    )
                    .toList(),
              ),
            ),
            if (cancel != null) ...[
              const Spacer2(),
              ClipRRect(
                borderRadius: BorderRadius.circular(_borderRadius),
                child: cancel,
              ),
              const Spacer2(),
            ],
          ],
        ),

        // },
        // onClosing: () => onClosing?.call(),
      ),
    );
  }
}

/// {@template app_bottom_sheet_title}
/// Creates a bottom sheet tile for presenting a text on the top.
/// {@endtemplate}
class AppBottomSheetTitle extends StatelessWidget {
  /// {@macro app_bottom_sheet_title}
  const AppBottomSheetTitle({
    super.key,
    required this.child,
  });

  /// Creates [AppBottomSheetTitle] with a Text widget.
  AppBottomSheetTitle.text({
    Key? key,
    required String text,
    TextStyle? style,
  }) : this(
          key: key,
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 15),
            child: Text(text, textAlign: TextAlign.center, style: style //?? TextStyl.button,
                ),
          ),
        );

  /// A content displayed inside.
  final Widget child;

  @override
  Widget build(BuildContext context) {
    return ColoredBox(
      color: Theme.of(context).colorScheme.surface,
      child: ConstrainedBox(
        constraints: const BoxConstraints(minHeight: 70),
        child: Center(child: child),
      ),
    );
  }
}

/// {@template app_bottom_sheet_action}
/// Creates a bottom sheet tile for presenting an action
/// that the user can trigger.
/// {@endtemplate}
class AppBottomSheetAction extends StatelessWidget {
  /// {@macro app_bottom_sheet_action}
  const AppBottomSheetAction({
    super.key,
    required this.child,
    required this.onPressed,
    this.isDisabled = false,
  });

  /// Creates [AppBottomSheetAction] with a [Text] widget
  /// and default [TextStyle].
  AppBottomSheetAction.text({
    Key? key,
    required String text,
    required VoidCallback? onPressed,
    TextStyle? style,
    bool? isDisabled = false,
  }) : this(
          key: key,
          onPressed: isDisabled == true ? null : onPressed,
          child: Text(
            text,
            style: style ?? RelayThemeData.relayTextTheme.titleMedium,
          ),
        );

  /// Creates [AppBottomSheetAction] with a [Text] widget
  /// and uses a [TextStyle] with primary action color.
  AppBottomSheetAction.destructiveText({
    Key? key,
    required String text,
    required VoidCallback onPressed,
    bool? isDisabled,
  }) : this.text(
          key: key,
          text: text,
          onPressed: isDisabled == true ? null : onPressed,
          style: RelayThemeData.relayTextTheme.titleMedium?.copyWith(
            color: Colors.red,
          ),
        );

  /// Creates [AppBottomSheetAction] with a [Text] widget
  /// and uses a [TextStyle] with disabled color.
  AppBottomSheetAction.disabledDestructiveText({
    Key? key,
    required String text,
    required VoidCallback? onPressed,
    bool? isDisabled,
  }) : this.text(
          key: key,
          text: text,
          onPressed: isDisabled == true ? null : onPressed,
        );

  /// A content displayed inside.
  final Widget child;

  /// An action invoked on tap.
  final VoidCallback? onPressed;

  /// Action is disabled.
  final bool? isDisabled;

  @override
  Widget build(BuildContext context) {
    return Material(
      color: isDisabled == true ? Colors.grey : Theme.of(context).colorScheme.surface,
      child: InkWell(
        onTap: isDisabled == true
            ? null
            : Trace.wrapNullableHandler(onPressed, 'bottom_sheet_tap', 'ui'),
        child: ConstrainedBox(
          constraints: const BoxConstraints(minHeight: 70),
          child: Center(child: child),
        ),
      ),
    );
  }
}
