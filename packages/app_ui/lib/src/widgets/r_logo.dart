import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';

class RelayLogo extends StatelessWidget {
  const RelayLogo({super.key});

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisSize: MainAxisSize.min,
      crossAxisAlignment: CrossAxisAlignment.center,
      children: [
        Assets.images.relayLogo.image(),
        SizedBox(height: 28),
        Assets.images.relay.image(),
      ],
    );
  }

  static Future<void> precache(BuildContext context) {
    return Future<void>.microtask(
      () => Future.wait<void>([
        precacheImage(Assets.images.relayLogo.provider(), context),
        precacheImage(Assets.images.relay.provider(), context),
      ]),
    );
  }
}
