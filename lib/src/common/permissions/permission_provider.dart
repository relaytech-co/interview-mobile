import 'dart:collection';

import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:permission_handler/permission_handler.dart';

final permissionServiceProvider =
    NotifierProvider<PermissionsService, PermissionState>(
  () => PermissionsService()..initialize(),
  name: 'Permissions',
);

class PermissionsService extends Notifier<PermissionState> {
  @override
  PermissionState build() {
    return PermissionState.uninitialized;
  }

  Future<void> initialize() async {
    final statuses = await Future.wait(PermissionState.requiredPermissions.map(
      (permission) => permission.status.then(
        (status) => MapEntry(permission, status),
      ),
    ));

    state = PermissionState(Map.fromEntries(statuses));
  }

  Future<void> requestPermission(Permission permission) async {
    if (!state.initialized) {
      await initialize();
    }
    final requestedPermission = PermissionState.requiredPermissions
        .firstWhere((element) => element.value == permission.value);

    final status = await requestedPermission.status;

    // updating with latest value
    state[requestedPermission] = status;

    if (state.needsToOpenAppSettings) {
      await openAppSettings();
    }

    if (status == PermissionStatus.denied) {
      try {
        final newStatus = await requestedPermission.request();
        state[requestedPermission] = newStatus;
      } catch (e) {
        print(e);
      }
    }
  }
}

class PermissionState extends MapView<Permission, PermissionStatus> {
  const PermissionState(super.permissions);

  static const PermissionState uninitialized = PermissionState({});

  static final requiredPermissions = [
    Permission.notification,
    Permission.camera,
    Permission.locationWhenInUse,
    Permission.locationAlways,
  ];

  bool get initialized =>
      requiredPermissions.every((permission) => this[permission] != null);

  bool get foregroundLocationPermissionGranted =>
      this[Permission.locationWhenInUse] == PermissionStatus.granted;

  bool get cameraPermissionGranted =>
      this[Permission.camera] == PermissionStatus.granted;

  bool get notificationsPermissionGranted =>
      this[Permission.notification] == PermissionStatus.granted;

  bool granted(Permission permission) =>
      this[permission] == PermissionStatus.granted;

  bool get allRequiredPermissionsGranted => requiredPermissions.every(granted);

  bool get needsToOpenAppSettings => requiredPermissions.any(
        (permission) => this[permission] == PermissionStatus.permanentlyDenied,
      );
}
