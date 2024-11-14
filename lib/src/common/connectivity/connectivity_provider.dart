import 'dart:async';
import 'dart:io';

import 'package:connectivity_repository/connectivity_repository.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';
import '../../app_status/presentation/controller/app_state.dart';
import '../../app_status/presentation/controller/app_state_controller.dart';

part 'connectivity_provider.g.dart';

@Riverpod(keepAlive: true)
ConnectivityRepository connectivityRepository(ConnectivityRepositoryRef ref) {
  return ConnectivityRepository();
}

@Riverpod(keepAlive: true)
class ConnectivityNotifier extends _$ConnectivityNotifier {
  StreamSubscription<ConnectivityStatus>? _connectivityStatusSubscription;

  @override
  ConnectivityStatus build() {
    _initConnectivityMonitoring();
    return ConnectivityStatus.online;
  }

  void _initConnectivityMonitoring() {
    _connectivityStatusSubscription = ref
        .read(connectivityRepositoryProvider)
        .onConnectivityChanged
        .listen((event) async {
      state = event;
      if (state == ConnectivityStatus.online) {
        bool hasInternet = await _retryCheckInternetAccess(
            attempts: 10, delay: const Duration(seconds: 10));
        final appState = ref.read(appStateControllerProvider);

        bool loggedIn = appState.status == AppStatus.authenticated;

        if (hasInternet && loggedIn) {}
      }
    });

    ref.onDispose(() {
      _connectivityStatusSubscription?.cancel();
    });
  }

  Future<bool> _checkInternetAccess() async {
    try {
      final result = await InternetAddress.lookup('clients3.google.com');
      return result.isNotEmpty && result[0].rawAddress.isNotEmpty;
    } catch (_) {
      return false;
    }
  }

  Future<bool> _retryCheckInternetAccess(
      {required int attempts, required Duration delay}) async {
    int currentAttempt = 0;
    while (currentAttempt < attempts) {
      if (await _checkInternetAccess()) {
        return true;
      }
      await Future.delayed(delay);
      currentAttempt++;
    }
    return false;
  }
}
