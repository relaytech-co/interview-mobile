import 'package:flutter/material.dart';

import '../../app_ui.dart';

class ActionCard extends StatelessWidget {
  const ActionCard({
    super.key,
    this.title,
    required this.parts,
    this.onPressed,
    this.onPressedSecondary,
    this.backgroundColor,
    this.foregroundColor,
    this.icon,
    this.secondaryIcon,
    this.margin = const EdgeInsets.symmetric(horizontal: 10),
    this.padding = const EdgeInsets.only(left: 10),
    this.subtitle,
    this.child,
    this.onLongPress,
  });

  final String? title;
  final String? subtitle;
  final List<String> parts;
  final VoidCallback? onPressed;
  final VoidCallback? onPressedSecondary;
  final VoidCallback? onLongPress;
  final IconData? icon;
  final IconData? secondaryIcon;
  final EdgeInsetsGeometry margin;
  final EdgeInsetsGeometry padding;
  final Color? backgroundColor;
  final Color? foregroundColor;

  /// Optional child widget to be displayed at the bottom of the card
  final Widget? child;

  String get partsFormatted =>
      parts.isEmpty ? '' : (parts.length > 1 ? (parts.join('\n')) : parts.first);

  @override
  Widget build(BuildContext context) {
    ThemeData theme = Theme.of(context);
    final secondAction = secondaryIcon != null && onPressedSecondary != null
        ? IconButton(
            onPressed: onPressedSecondary,
            icon: Icon(secondaryIcon, size: 28, color: theme.colorScheme.onBackground),
          )
        : const SizedBox.shrink();

    return InkWell(
      onLongPress: onLongPress,
      child: Container(
        width: double.infinity,
        margin: margin,
        child: Container(
          decoration: BoxDecoration(
              color: backgroundColor ?? theme.colorScheme.surface,
              borderRadius: BorderRadius.circular(10)),
          child: Padding(
            padding: padding,
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                if (title != null) ...[
                  const Spacer2(),
                  Text(title!,
                      style: theme.textTheme.bodyMedium!.copyWith(color: foregroundColor)),
                  const Spacer1(),
                ],
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    Expanded(
                      child: Column(crossAxisAlignment: CrossAxisAlignment.start, children: [
                        if (subtitle != null)
                          Text(subtitle!,
                              style: theme.textTheme.bodyMedium!.copyWith(
                                  color: foregroundColor, fontWeight: FontWeight.bold)),
                        Text(partsFormatted,
                            style:
                                theme.textTheme.bodyMedium!.copyWith(color: foregroundColor)),
                      ]),
                    ),
                    const Spacer1(),
                    Column(
                      children: [
                        secondAction,
                        IconButton(
                          onPressed: onPressed,
                          icon: Icon(icon, size: 28, color: theme.colorScheme.onBackground),
                        ),
                      ],
                    )
                  ],
                ),
                if (child != null) ...[
                  Spacer2(),
                  child!,
                ],
              ],
            ),
          ),
        ),
      ),
    );
  }
}
