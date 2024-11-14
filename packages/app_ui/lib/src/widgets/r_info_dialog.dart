import 'package:flutter/material.dart';

import '../../app_ui.dart';

class RInfoDialog extends StatelessWidget {
  const RInfoDialog(
      {Key? key,
      required this.traceName,
      required this.onClose,
      required this.title,
      required this.body,
      this.bottom,
      this.shouldScroll = false})
      : super(key: key);
  final String traceName;
  final Function() onClose;
  final String title;
  final Widget body;
  final Widget? bottom;
  final bool shouldScroll;

  @override
  Widget build(BuildContext context) {
    return Dialog(
      backgroundColor: Colors.transparent,
      elevation: 0,
      insetPadding: const EdgeInsets.all(0),
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 20).copyWith(bottom: 0),
        margin: const EdgeInsets.all(10),
        height: MediaQuery.of(context).size.height,
        width: MediaQuery.of(context).size.width,
        decoration: BoxDecoration(
          gradient: RadialGradient(
              radius: 2,
              center: Alignment.bottomLeft,
              colors: [Color(0xFFD0CFE0), Color(0xFFFBFBFC)],
              stops: [0.2, 1]),
          borderRadius: BorderRadius.circular(20),
        ),
        child: Stack(
          children: [
            ListView(
              physics: shouldScroll
                  ? const AlwaysScrollableScrollPhysics()
                  : const NeverScrollableScrollPhysics(),
              shrinkWrap: false,
              children: [
                const Spacer4(),
                Center(
                  child: Text(
                    title,
                    textAlign: TextAlign.center,
                    style: Theme.of(context)
                        .textTheme
                        .titleLarge!
                        .copyWith(color: Colors.black, fontSize: 25),
                  ),
                ),
                const Spacer3(),
                body,
                const Spacer3(),
              ],
            ),
            RIconButton.filled(
                style: IconButton.styleFrom(backgroundColor: Colors.white),
                color: Colors.black,
                onPressed: onClose,
                icon: Icon(Icons.close),
                traceName: traceName),
            if (bottom != null) Positioned(bottom: 0, left: 0, right: 0, child: bottom!)
          ],
        ),
      ),
    );
  }
}
