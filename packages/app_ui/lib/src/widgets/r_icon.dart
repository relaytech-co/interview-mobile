import 'package:flutter/material.dart';

enum RIconType { primary, secondary, surface, disabled }

class RIcon extends StatelessWidget {
  const RIcon({
    Key? key,
    required this.icon,
    this.size = 24,
    this.color,
    this.type = RIconType.primary,
  }) : super(key: key);

  final Widget icon;
  final double size;
  final RIconType type;
  final Color? color;

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(12),
      decoration: BoxDecoration(
        color: _getColor(context),
        borderRadius: BorderRadius.circular(1000),
      ),
      child: icon,
    );
  }

  Color _getColor(BuildContext context) {
    switch (type) {
      case RIconType.primary:
        return color ?? Theme.of(context).colorScheme.primary;
      case RIconType.secondary:
        return color ?? Theme.of(context).colorScheme.secondary;
      case RIconType.surface:
        return color ?? Theme.of(context).colorScheme.surfaceVariant;
      case RIconType.disabled:
        return color ??
            Theme.of(context).colorScheme.onSurface.withOpacity(0.5);
    }
  }
}
