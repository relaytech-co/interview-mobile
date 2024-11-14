import 'dart:io';

import 'package:analytics_client/analytics_client.dart';
import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:in_app_update/in_app_update.dart';
import 'package:url_launcher/url_launcher.dart';

class ForceUpdatePage extends ConsumerStatefulWidget {
  const ForceUpdatePage({super.key});

  @override
  ConsumerState<ForceUpdatePage> createState() => _ForceUpdatePageState();
}

class _ForceUpdatePageState extends ConsumerState<ForceUpdatePage> {
  @override
  void initState() {
    // if on Android, display the system immediate update dialog
    if (Platform.isAndroid) {
      _displayAndroidSystemUpgradeDialog();
    }

    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        automaticallyImplyLeading: false,
        title: const Text('Update Required'),
      ),
      body: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Spacer(),
            const Icon(Icons.update, size: 100),
            const Spacer4(),
            Center(
                child: Text(
              'Please update the app\nto continue using Relay Copilot.',
              textAlign: TextAlign.center,
              style: Theme.of(context).textTheme.titleMedium,
            )),
            const Spacer(),
            const Padding(
                padding: EdgeInsets.symmetric(horizontal: 20),
                child: _UpdateButton(
                  darkBackground: false,
                )),
            const SizedBox(height: 40),
          ]),
    );
  }

  void _displayAndroidSystemUpgradeDialog() async {
    // only on Android, display the system immediate update dialog
    try {
      final updateInfo = await InAppUpdate.checkForUpdate();
      if (updateInfo.updateAvailability == UpdateAvailability.updateAvailable) {
        // logger.info('Displaying Android system immediate update dialog');
        await InAppUpdate.performImmediateUpdate();
      }
    } catch (_) {
      // don't need to handle this error
    }
  }
}

class _UpdateButton extends ConsumerWidget {
  const _UpdateButton({required this.darkBackground});
  final bool darkBackground;

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    if (darkBackground == true) {
      return RFilledButton.lightMode(
        traceName: TraceNames.updateApp.name,
        analyticsProps: {'platform': Platform.isAndroid ? 'android' : 'ios'},
        sendAnalytics: true,
        onPressed: () => onPressed(ref),
        child: const Text('Update your app'),
      );
    }
    return RFilledButton(
      traceName: TraceNames.updateApp.name,
      analyticsProps: {'platform': Platform.isAndroid ? 'android' : 'ios'},
      sendAnalytics: true,
      onPressed: () => onPressed(ref),
      child: const Text('Update your app'),
    );
  }

  Future<void> onPressed(WidgetRef ref) async {
    Uri uri;
    if (Platform.isAndroid) {
      uri = Uri.parse(
          'https://play.google.com/store/apps/details?id=co.relaytech.copilot');
    } else {
      uri =
          Uri.parse('https://apps.apple.com/gb/app/relay-copilot/id6450905421');
    }
    if (!await launchUrl(uri, mode: LaunchMode.externalApplication)) {
      //logger.warning('Could not launch Store');
    }
  }
}
