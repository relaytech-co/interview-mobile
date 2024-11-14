import 'package:flutter/material.dart';

import '../../app_ui.dart';

class RPopUpDialog extends StatelessWidget {
  const RPopUpDialog(
      {Key? key,
      required this.traceName,
      required this.title,
      required this.description,
      required this.bottom,
      this.icon,
      this.shouldScroll = false})
      : super(key: key);
  final String traceName;

  final String title;
  final String description;
  final Widget bottom;
  final Widget? icon;
  final bool shouldScroll;

  @override
  Widget build(BuildContext context) {
    return Dialog(
      backgroundColor: Colors.transparent,
      elevation: 0,
      insetPadding: const EdgeInsets.symmetric(horizontal: 10),
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 20).copyWith(bottom: 0),
        margin: const EdgeInsets.all(10),
        decoration: BoxDecoration(
          color: Theme.of(context).colorScheme.surface,
          borderRadius: BorderRadius.circular(30),
        ),
        child: ListView(
          physics: shouldScroll
              ? const AlwaysScrollableScrollPhysics()
              : const NeverScrollableScrollPhysics(),
          shrinkWrap: true,
          children: [
            const Spacer4(),
            if (icon != null) icon!,
            const Spacer4(),
            Center(
              child: Text(
                title,
                textAlign: TextAlign.center,
                style: Theme.of(context)
                    .textTheme
                    .titleLarge!
                    .copyWith(color: Colors.white, fontSize: 20),
              ),
            ),
            const Spacer3(),
            Center(
              child: Text(
                description,
                textAlign: TextAlign.center,
                style: Theme.of(context)
                    .textTheme
                    .bodySmall!
                    .copyWith(color: Colors.white, fontSize: 16),
              ),
            ),
            const Spacer3(),
            bottom,
            const Spacer3(),
          ],
        ),
      ),
    );
  }
}
