import 'dart:async';

import 'package:app_config_repository/app_config_repository.dart';
import 'package:auth_repository/auth_repository.dart';
import 'package:models/models.dart';
import 'package:relay_interview/src/common/data/repository_providers.dart';
import 'package:relay_interview/src/authentication/data/auth_repository.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';
import 'app_state.dart';

part 'app_state_controller.g.dart';

@Riverpod(keepAlive: true)
class AppStateController extends _$AppStateController {
  @override
  AppState build() {
    _isDownForMaintenanceSubscription = _appConfigRepository
        .underMaintenanceController.stream
        .listen(_onDownForMaintenanceStatusChanged);
    _forceUpgradeSubscription = _appConfigRepository
        .forceUpdateController.stream
        .listen(_onForceUpdateStatusChanged);
    _soonToBeDeprecatedSubscription = _appConfigRepository
        .showSoonToBeDeprecatedBanner.stream
        .listen(_onSoonToBeDeprecatedChanged);
    _accountSubscription = _authRepository.user.listen(_updateUser);

    ref.onDispose(() {
      _isDownForMaintenanceSubscription.cancel();
      _forceUpgradeSubscription.cancel();
      _soonToBeDeprecatedSubscription.cancel();
      _accountSubscription.cancel();
    });
    return const AppState(status: AppStatus.uninitialized);
  }

  AppConfigRepository get _appConfigRepository =>
      ref.read(appConfigRepositoryProvider);
  AuthRepository get _authRepository => ref.read(authRepositoryProvider);

  late StreamSubscription<bool> _forceUpgradeSubscription;
  late StreamSubscription<bool> _isDownForMaintenanceSubscription;
  late StreamSubscription<bool> _soonToBeDeprecatedSubscription;
  late StreamSubscription<User?> _accountSubscription;

  Future<void> _updateUser(User? user) async {
    if (user == null) {
      state = AppState(
        status: AppStatus.uninitialized,
        soonToBeDeprecated: state.soonToBeDeprecated,
        user: null,
      );
    } else {
      switch (state.status) {
        case AppStatus.forceUpdateRequired:
          state = AppState(
            status: AppStatus.forceUpdateRequired,
            user: user,
            soonToBeDeprecated: state.soonToBeDeprecated,
          );
          break;

        case AppStatus.downForMaintenance:
          state = AppState(
            status: AppStatus.downForMaintenance,
            user: user,
            soonToBeDeprecated: state.soonToBeDeprecated,
          );
          break;
        case AppStatus.uninitialized:
        case AppStatus.authenticated:
        case AppStatus.unauthenticated:
          if (user == User.anonymous) {
            state = AppState(
              status: AppStatus.unauthenticated,
              soonToBeDeprecated: state.soonToBeDeprecated,
              user: null,
            );
          } else {
            state = AppState(
              status: AppStatus.authenticated,
              soonToBeDeprecated: state.soonToBeDeprecated,
              user: user,
            );
          }
          break;
      }
    }
  }

  void _onDownForMaintenanceStatusChanged(bool underMaintenance) {
    if (underMaintenance) {
      state = AppState(
        status: AppStatus.downForMaintenance,
        soonToBeDeprecated: state.soonToBeDeprecated,
        user: state.user,
      );
    } else {
      if (state.status != AppStatus.downForMaintenance) {
        return;
      } else {
        _updateBasedOnUser();
      }
    }
  }

  void _onSoonToBeDeprecatedChanged(bool soonToBeDeprecated) {
    state = state.copyWith(soonToBeDeprecated: soonToBeDeprecated);
  }

  void _onForceUpdateStatusChanged(bool forceUpdate) {
    if (forceUpdate) {
      state = AppState(
        status: AppStatus.forceUpdateRequired,
        soonToBeDeprecated: state.soonToBeDeprecated,
        user: state.user,
      );
    } else {
      if (state.status != AppStatus.forceUpdateRequired) {
        return;
      } else {
        _updateBasedOnUser();
      }
    }
  }

  void _updateBasedOnUser() {
    if (state.user == null) {
      state = AppState(
        status: AppStatus.unauthenticated,
        soonToBeDeprecated: state.soonToBeDeprecated,
        user: null,
      );
    } else {
      state = AppState(
        status: AppStatus.authenticated,
        soonToBeDeprecated: state.soonToBeDeprecated,
        user: state.user,
      );
    }
  }
}
