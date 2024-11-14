import 'dart:io';

import 'package:analytics_client/analytics_client.dart';
import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:permission_handler/permission_handler.dart';
import 'package:relay_interview/i18n/strings.g.dart';
import 'package:relay_interview/src/common/permissions/permission_provider.dart';

Future<bool> verifyPermissionWithDialogAction(
    WidgetRef ref, Permission permission) async {
  bool shouldRequestPermission = (await showDialog<bool>(
        routeSettings: const RouteSettings(
          name: 'Request Dialog',
        ),
        context: ref.context,
        barrierDismissible: true,
        builder: (context) {
          return Scaffold(
            backgroundColor: Colors.transparent,
            body: Dialog(
              child: Padding(
                padding:
                    const ScreenMarginInsets.symmetric(vertical: kScreenMargin),
                child: Column(
                  mainAxisSize: MainAxisSize.min,
                  children: [
                    Text(permissionDetails(permission),
                        style: Theme.of(context).textTheme.titleMedium),
                    const Spacer1(),
                    const Divider(),
                    const Spacer1(),
                    RFilledButton(
                      loading: false,
                      expand: true,
                      traceName: TraceNames.allowPermission.name,
                      onPressed: () {
                        Navigator.of(context).maybePop(true);
                      },
                      analyticsProps: {'permission': permission.toString()},
                      sendAnalytics: true,
                      child: Text(t.allow),
                    ),
                    const Spacer1(),
                    SizedBox(
                      width: double.maxFinite,
                      child: ROutlinedButton(
                        traceName: TraceNames.maybePermission.name,
                        sendAnalytics: true,
                        analyticsProps: {'permission': permission.toString()},
                        onPressed: () {
                          Navigator.of(context).maybePop(Platform.isIOS);
                        },
                        label: t.maybeLater,
                      ),
                    ),
                  ],
                ),
              ),
            ),
          );
        },
      )) ??
      false;

  if (!shouldRequestPermission) {
    return false;
  }
  await ref
      .read(permissionServiceProvider.notifier)
      .requestPermission(permission);
  return ref.read(permissionServiceProvider).granted(permission);
}

//temporary
String permissionDetails(Permission permission) {
  switch (permission) {
    case Permission.locationWhenInUse:
      return 'We need access to your location before you can use Relay Copilot';
    case Permission.locationAlways:
      return 'We need access to your location before you can use Relay Copilot';
    case Permission.camera:
      return 'We need access to your camera to take pictures of parcels or scan barcodes';
  }
  return '';
}
