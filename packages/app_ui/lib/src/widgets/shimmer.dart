// This is based on the work of the author below, it has been altered to
// our purposes.
//
// * Original author: hunghd
// * email: hunghd.yb@gmail.com
//
// A package provides an easy way to add shimmer effect to Flutter application
//
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';

// ignore_for_file: avoid_setters_without_getters

/// A linear diagonal gradient ([Alignment.topLeft], [Alignment.bottomRight])
///
/// See [ShimmeringGradient.light] for light backgrounds, and
/// [ShimmeringGradient.dark] for darker backgrounds.
class ShimmeringGradient extends LinearGradient {
  const ShimmeringGradient({
    required super.colors,
    super.stops,
    super.tileMode,
    super.transform,
    // almost topLeft * bottomRight
    super.begin = const Alignment(-1.0, -0.5),
    super.end = const Alignment(1.0, 0.5),
  });

  /// Linear slightly diagonal gradient for light backgrounds
  ///
  /// [colors]: [20%, 50%, 20%] of 0xCCCCCC
  /// [stops]: [0.2, 0.5, 0.8]
  static const light = ShimmeringGradient(
    colors: [
      Color(0x33CCCCCC),
      Color(0x7FCCCCCC),
      Color(0x33CCCCCC),
    ],
    stops: [0.3, 0.5, 0.7],
  );

  /// Linear slightly diagonal gradient for dark backgrounds
  ///
  /// [colors]: [50%, 20%, 50%] of 0xCCCCCC
  /// [stops]: [0.2, 0.5, 0.8]
  static const dark = ShimmeringGradient(
    colors: [
      Color(0x7FCCCCCC),
      Color(0x33CCCCCC),
      Color(0x7FCCCCCC),
    ],
    stops: [0.3, 0.5, 0.7],
  );
}

/// An enum defines all supported directions of shimmer effect
///
/// * [ShimmerDirection.ltr] left to right direction
/// * [ShimmerDirection.rtl] right to left direction
/// * [ShimmerDirection.ttb] top to bottom direction
/// * [ShimmerDirection.btt] bottom to top direction
enum ShimmerDirection { ltr, rtl, ttb, btt }

/// A widget renders shimmer effect over [child] widget tree.
///
/// [child] defines an area that shimmer effect blends on. You can build [child]
/// from whatever [Widget] you like but there're some notices in order to get
/// exact expected effect and get better rendering performance:
///
/// * Use static [Widget] (which is an instance of [StatelessWidget]).
/// * [Widget] should be a solid color element. Every colors you set on these
/// [Widget]s will be overridden by colors of [gradient].
/// * Shimmer effect only affects to opaque areas of [child], transparent areas
/// still stays transparent.
///
/// [speed] controls the speed of shimmer effect. The default value is 100.0.
///
/// [direction] controls the direction of shimmer effect. The default value
/// is [ShimmerDirection.ltr].
///
/// [gradient] controls colors of shimmer effect.
///
/// See:
/// - [ShimmeringGradient.light] for light backgrounds.
/// - [ShimmeringGradient.dark] for dark backgrounds.
class Shimmer extends StatefulWidget {
  /// Builds a [Shimmer] widget
  ///
  /// Uses [ShimmeringGradient.light] by default.
  ///
  /// See:
  /// - [ShimmeringGradient.light] for light backgrounds.
  /// - [ShimmeringGradient.dark] for dark backgrounds.
  const Shimmer({
    super.key,
    this.gradient,
    this.direction = ShimmerDirection.ltr,
    this.period = const Duration(milliseconds: 1500),
    this.enabled = true,
    required this.child,
  });

  final Gradient? gradient;
  final ShimmerDirection direction;
  final Duration period;
  final bool enabled;
  final Widget child;

  /// A convenience global value to make sure [Shimmers] don't animate and
  /// hang tests (i.e. pumpAndSettle).
  static bool disableForTesting = false;

  @override
  State<Shimmer> createState() => _ShimmerState();

  @override
  void debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DiagnosticsProperty('gradient', gradient, defaultValue: null));
    properties.add(EnumProperty('direction', direction));
    properties.add(DiagnosticsProperty('period', period, defaultValue: null));
  }
}

class _ShimmerState extends State<Shimmer> with SingleTickerProviderStateMixin {
  late AnimationController _controller;

  @override
  void initState() {
    super.initState();

    _controller = AnimationController(vsync: this, duration: widget.period);
    if (!Shimmer.disableForTesting) {
      _controller.repeat();
    }
  }

  @override
  void didUpdateWidget(covariant Shimmer oldWidget) {
    super.didUpdateWidget(oldWidget);

    if (widget.enabled && !_controller.isAnimating) {
      _controller.repeat();
    } else if (!widget.enabled && _controller.isAnimating) {
      _controller.stop();
    }
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final mediaQuery = MediaQuery.of(context);
    final gradient = widget.gradient ??
        (Theme.of(context).brightness == Brightness.dark
            ? ShimmeringGradient.dark
            : ShimmeringGradient.light);

    return AnimatedBuilder(
      animation: _controller,
      builder: (context, child) => _Shimmer(
        direction: widget.direction,
        gradient: gradient,
        percent: _controller.value,
        screenSize: mediaQuery.size,
        child: child,
      ),
      child: widget.child,
    );
  }
}

class _Shimmer extends SingleChildRenderObjectWidget {
  const _Shimmer({
    required this.direction,
    required this.gradient,
    required this.percent,
    required this.screenSize,
    super.child,
  });

  final ShimmerDirection direction;
  final Gradient gradient;
  final double percent;
  final Size screenSize;

  @override
  _ShimmerFilter createRenderObject(BuildContext context) {
    return _ShimmerFilter(direction, gradient, percent, screenSize);
  }

  @override
  void updateRenderObject(BuildContext context, _ShimmerFilter shimmer) {
    shimmer
      ..percent = percent
      ..direction = direction
      ..gradient = gradient
      ..screenSize = screenSize;
  }
}

class _ShimmerFilter extends RenderProxyBox {
  _ShimmerFilter(
    this._direction,
    this._gradient,
    this._percent,
    this._screenSize,
  );

  ShimmerDirection _direction;
  Gradient _gradient;
  double _percent;
  Size _screenSize;

  @override
  bool get alwaysNeedsCompositing => child != null;

  @override
  ShaderMaskLayer? get layer => super.layer as ShaderMaskLayer?;

  set direction(ShimmerDirection newValue) {
    if (newValue == _direction) return;
    _direction = newValue;
    markNeedsPaint();
  }

  set gradient(Gradient newValue) {
    if (newValue == _gradient) return;
    _gradient = newValue;
    markNeedsPaint();
  }

  set percent(double newValue) {
    if (newValue == _percent) return;
    _percent = newValue;
    markNeedsPaint();
  }

  set screenSize(Size newValue) {
    if (newValue == _screenSize) return;
    _screenSize = newValue;
    markNeedsPaint();
  }

  @override
  void paint(PaintingContext context, Offset offset) {
    if (child == null) return;
    assert(needsCompositing);

    var width = _screenSize.width, height = _screenSize.height;
    var dx = 0.0, dy = 0.0;
    if (_direction == ShimmerDirection.ltr) {
      dx = _lerp(-2 * width, 0.0, _percent);
      width *= 3;
    } else if (_direction == ShimmerDirection.rtl) {
      dx = _lerp(0.0, -2 * width, _percent);
      width *= 3;
    } else if (_direction == ShimmerDirection.ttb) {
      dy = _lerp(-2 * height, 0.0, _percent);
      height *= 3;
    } else {
      dy = _lerp(0.0, -2 * height, _percent);
      height *= 3;
    }
    // adjusting dy to the device screen's zero offset
    final global = child!.localToGlobal(Offset.zero);
    final rect = Rect.fromLTWH(dx, dy - global.dy, width, height);

    layer ??= ShaderMaskLayer();
    layer!
      ..shader = _gradient.createShader(rect)
      ..maskRect = offset & size
      ..blendMode = BlendMode.srcIn;
    context.pushLayer(layer!, super.paint, offset);
  }

  static double _lerp(double start, double end, double percent) =>
      start + (end - start) * percent;
}

class PreferredSizeShimmer extends StatelessWidget implements PreferredSizeWidget {
  const PreferredSizeShimmer({
    super.key,
    required this.child,
  });

  @override
  Size get preferredSize => child.preferredSize;

  final PreferredSizeWidget child;

  @override
  Widget build(BuildContext context) {
    return Shimmer(child: child);
  }
}
