import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';

class DownForMaintenancePage extends StatelessWidget {
  const DownForMaintenancePage({super.key});

  @override
  Widget build(BuildContext context) {
    return const Scaffold(
      body: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.construction_rounded, size: 100),
            Spacer4(),
            Center(
                child: Text(
              'Down for maintenance.\nWe will be back shortly',
              textAlign: TextAlign.center,
            ))
          ]),
    );
  }
}
