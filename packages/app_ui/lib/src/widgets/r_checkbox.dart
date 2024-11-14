import 'package:flutter/material.dart';

import '../../app_ui.dart';

class RCheckbox extends StatelessWidget {
  const RCheckbox(
      {super.key,
      required this.isSelected,
      this.size = 24,
      required this.onTap,
      this.color,
      this.analyticsProps,
      this.traceName});
  final bool isSelected;
  final Function(dynamic)? onTap;
  final String? traceName;
  final Map<String, dynamic>? analyticsProps;
  final double size;
  final Color? color;

  @override
  Widget build(BuildContext context) {
    final icon = Container(
      height: size,
      width: size,
      decoration: BoxDecoration(
          shape: BoxShape.circle,
          color: isSelected
              ? color ?? Theme.of(context).colorScheme.tertiary
              : Colors.transparent,
          border:
              Border.all(color: color ?? Theme.of(context).colorScheme.tertiary, width: 2)),
      child: isSelected
          ? Center(
              child: Icon(Icons.check_rounded,
                  color: Theme.of(context).canvasColor, size: size - 4))
          : const SizedBox.shrink(),
    );
    if (onTap == null) return icon;
    return RIconButton(
        traceName: traceName!,
        analyticsProps: analyticsProps,
        onPressed: () => onTap!(!isSelected),
        icon: Container(
          height: size,
          width: size,
          decoration: BoxDecoration(
              shape: BoxShape.circle,
              color: isSelected
                  ? color ?? Theme.of(context).colorScheme.tertiary
                  : Colors.transparent,
              border: Border.all(
                  color: color ?? Theme.of(context).colorScheme.tertiary, width: 2)),
          child: isSelected
              ? Center(
                  child: Icon(Icons.check_rounded,
                      color: Theme.of(context).canvasColor, size: size - 4))
              : const SizedBox.shrink(),
        ));
  }
}
