// import 'dart:math' as math;

// import 'package:app_ui/app_ui.dart';
// import 'package:flutter/widgets.dart';
// import 'package:gap/gap.dart' as gap;

// /// A sliver that takes a fixed amount of space.
// ///
// /// See also:
// ///
// ///  * [Gap], the render box version of this widget.
// class SliverGap extends StatelessWidget {
//   /// {@macro gap}
//   const SliverGap(
//     this.size, {
//     super.key,
//   }) : _includeBottomSafeArea = false;

//   /// Variant of [Gap] for [AppSpacing.xxxs]
//   const SliverGap.xxxs({Key? key}) : this(AppSpacing.xxxs, key: key);

//   /// Variant of [Gap] for [AppSpacing.xxs]
//   const SliverGap.xxs({Key? key}) : this(AppSpacing.xxs, key: key);

//   /// Variant of [Gap] for [AppSpacing.xs]
//   const SliverGap.xs({Key? key}) : this(AppSpacing.xs, key: key);

//   /// Variant of [Gap] for [AppSpacing.sm]
//   const SliverGap.sm({Key? key}) : this(AppSpacing.sm, key: key);

//   /// Variant of [Gap] for [AppSpacing.md]
//   const SliverGap.md({Key? key}) : this(AppSpacing.md, key: key);

//   /// Variant of [Gap] for [AppSpacing.lg]
//   const SliverGap.lg({Key? key}) : this(AppSpacing.lg, key: key);

//   /// Variant of [Gap] for [AppSpacing.xlg]
//   const SliverGap.xlg({Key? key}) : this(AppSpacing.xlg, key: key);

//   /// Variant of [Gap] for [AppSpacing.xxlg]
//   const SliverGap.xxlg({Key? key}) : this(AppSpacing.xxlg, key: key);

//   /// Variant of [Gap] for [AppSpacing.xxxlg]
//   const SliverGap.xxxlg({Key? key}) : this(AppSpacing.xxxlg, key: key);

//   /// Variant of [Gap] that takes the bottom safe area space
//   ///
//   /// By providing [minimum], you can ensure the gap will take
//   /// that minimum amount of space
//   const SliverGap.bottomSafeArea({super.key, double? minimum})
//       : _includeBottomSafeArea = true,
//         size = minimum ?? 0;

//   /// Size of the gap between widgets
//   final double size;

//   final bool _includeBottomSafeArea;

//   @override
//   Widget build(BuildContext context) {
//     var size = this.size;
//     if (_includeBottomSafeArea) {
//       final bottomSafeArea = MediaQuery.of(context).padding.bottom;
//       size = math.max(bottomSafeArea, size);
//     }
//     return gap.SliverGap(size);
//   }
// }
