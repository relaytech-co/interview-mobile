import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

import 'slider.dart';

class RSlidableButton extends StatelessWidget {
  const RSlidableButton({
    Key? key,
    required this.onSubmit,
    required this.label,
    required this.traceName,
    this.sendAnalytics = true,
    this.analyticsProps,
    this.traceProps,
  }) : super(key: key);

  final void Function()? onSubmit;
  final String label;
  final String traceName;
  final bool sendAnalytics;
  final Map<String, dynamic>? analyticsProps;
  final Map<String, dynamic>? traceProps;

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(builder: (context, constraints) {
      return SliderButton(
        disable: onSubmit == null,
        action: Trace.wrapHandler(onSubmit ?? () {}, traceName, 'btn',
            props: analyticsProps, traceProps: traceProps, sendAnalytics: sendAnalytics),
        width: constraints.maxWidth,
        alignLabel: Alignment.center,
        label: Text(
          label,
          textAlign: TextAlign.center,
          style: TextStyle(
              fontWeight: FontWeight.w500,
              fontSize: 17,
              color: onSubmit != null ? Colors.white : Colors.grey[700]),
        ),
        icon: onSubmit == null
            ? const SizedBox.shrink()
            : Center(
                child: Icon(
                Icons.chevron_right,
                color: Theme.of(context).canvasColor,
                size: 40.0,
              )),
        radius: 20,
        buttonColor: Theme.of(context).colorScheme.primary,
        backgroundColor: Theme.of(context).colorScheme.surface,
        highlightedColor: Theme.of(context).colorScheme.secondary,
        baseColor: Colors.white,
      );
    });
  }
}
