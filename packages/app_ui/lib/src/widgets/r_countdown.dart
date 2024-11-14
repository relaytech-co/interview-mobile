import 'package:flutter/material.dart';

import '../../app_ui.dart';

class RCountdown extends StatelessWidget {
  const RCountdown({Key? key, required this.expiration, this.outOfTimeDialog})
      : super(key: key);
  final DateTime expiration;
  final Widget? outOfTimeDialog;

  @override
  Widget build(BuildContext context) {
    return Container(
        margin: const EdgeInsets.only(right: 5),
        padding: const EdgeInsets.symmetric(vertical: 5, horizontal: 8),
        decoration: BoxDecoration(
            color: expiration.difference(DateTime.now()).inMinutes < 1
                ? Theme.of(context).colorScheme.onError
                : Theme.of(context).colorScheme.surface,
            borderRadius: BorderRadius.circular(100)),
        child: Row(children: [
          Icon(Icons.timer, size: 20, color: Theme.of(context).colorScheme.onSurface),
          const SizedBox(width: 3),
          RCountdownText(
            expiration: expiration,
            outOfTimeDialog: outOfTimeDialog,
          )
        ]));
  }
}
