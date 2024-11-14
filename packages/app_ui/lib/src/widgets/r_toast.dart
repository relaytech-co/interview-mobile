import 'package:flutter/widgets.dart';
import 'package:toastification/toastification.dart';

import '../../app_ui.dart';

class RToast {
  static void warning({required String title, String? body}) {
    toastification.showCustom(
      autoCloseDuration: const Duration(seconds: 4),
      alignment: Alignment.topCenter,
      builder: (BuildContext context, ToastificationItem holder) {
        return Container(
          decoration: BoxDecoration(
            borderRadius: BorderRadius.circular(8),
            color: RelayColors.amber,
          ),
          padding: const EdgeInsets.all(10),
          margin: const EdgeInsets.all(8),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              Text(title, style: TextStyle(color: RelayColors.black, fontSize: 14)),
              if (body != null) ...[
                const Spacer1(),
                Text(body, style: TextStyle(color: RelayColors.black, fontSize: 12))
              ],
            ],
          ),
        );
      },
    );
  }
}
