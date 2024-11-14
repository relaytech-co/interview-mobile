import 'package:flutter/widgets.dart';
import 'package:go_router/go_router.dart';

/// Declaration of the route's names.
enum AppRoutes {
  splash('Splash', '/splash'),
  login('Log in', '/login'),
  forceUpdateRequired('Force update required', '/force-update'),
  downForMaintenance('Down for maintenance', '/down-for-maintenance'),
  home('Home', '/'),
  courierDropOff('Courier drop-off', '/courier-drop-off'),
  courierDropOffDetails(
      'Courier drop-off details', '/courier-drop-off-details/:courier_id'),
  manualCheckIn('Manual check-in', '/manual-check-in'),
  createManualCheckIn('Create manual check-in', '/create-manual-check-in'),
  ;

  const AppRoutes(this.name, this.path);

  final String name;
  final String path;
}

final class AppNavigator {
  AppNavigator.of(this._context);

  final BuildContext _context;

  static final rootKey = GlobalKey<NavigatorState>(
    debugLabel: 'root navigator',
  );

  static AppNavigator get root {
    final context = rootKey.currentContext;
    return AppNavigator.of(context!);
  }

  void goToSplash() => _context.goNamed(AppRoutes.splash.name);

  void goToSignIn() => _context.goNamed(AppRoutes.login.name);

  void goToForceUpdate() =>
      _context.goNamed(AppRoutes.forceUpdateRequired.name);

  void goToDownForMaintenance() =>
      _context.goNamed(AppRoutes.downForMaintenance.name);

  void goToHome() => _context.goNamed(AppRoutes.home.name);

  void pushReplacementCourierDropOffDetails({required String courierId}) =>
      _context.pushReplacementNamed(AppRoutes.courierDropOffDetails.name,
          pathParameters: {
            'courier_id': courierId,
          });

  void pushReplacementCreateManualCheckIn() =>
      _context.pushReplacementNamed(AppRoutes.createManualCheckIn.name);

  void pushCreateManualCheckIn() =>
      _context.pushNamed(AppRoutes.createManualCheckIn.name);
}

extension AppNavigationBuildContextExtensions on BuildContext {
  AppNavigator get navigator => AppNavigator.of(this);
}
