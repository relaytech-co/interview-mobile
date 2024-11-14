import 'package:flutter/material.dart';

/// Swaps the visibility of a progress indicator or [child] whether
/// it is [loading].
///
/// This will also attempt to maintain the layout and size to avoid jumps
/// between builds
class RVisibilityProgressIndicator extends StatelessWidget {
  const RVisibilityProgressIndicator({
    super.key,
    this.enabled = true,
    this.loading = false,
    this.color,
    this.indicatorSize,
    this.alignment = Alignment.center,
    this.child,
  });

  final bool loading;
  final bool enabled;
  final Color? color;
  final double? indicatorSize;
  final AlignmentGeometry alignment;
  final Widget? child;

  @override
  Widget build(BuildContext context) {
    if (!loading) return child ?? const SizedBox.shrink();

    return Stack(
      alignment: alignment,
      children: [
        if (child != null)
          Visibility.maintain(
            visible: false,
            child: child!,
          ),
        VsProgressIndicator(
          enabled: enabled,
          color: color,
          indicatorSize: indicatorSize,
        ),
      ],
    );
  }
}

class VsProgressIndicator extends StatelessWidget {
  const VsProgressIndicator({
    super.key,
    this.enabled = true,
    this.color,
    this.indicatorSize,
  });

  final bool enabled;

  final Color? color;
  final double? indicatorSize;

  @override
  Widget build(BuildContext context) {
    final theme = Theme.of(context);
    final iconTheme = IconTheme.of(context);
    final effectiveColor = color ?? (enabled ? iconTheme.color : theme.disabledColor);
    final effectiveIndicatorSize = indicatorSize ?? theme.iconTheme.size ?? 28.0;

    return SizedBox(
      width: effectiveIndicatorSize,
      height: effectiveIndicatorSize,
      child: CircularProgressIndicator(
        strokeWidth: 4.0,
        valueColor: AlwaysStoppedAnimation(effectiveColor),
      ),
    );
  }
}
