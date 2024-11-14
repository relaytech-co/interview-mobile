import 'package:go_router/go_router.dart';
import 'package:relay_interview/config/navigation/navigation/app_routes.dart';
import 'package:relay_interview/src/app_status/presentation/down_for_maintenance_page.dart';
import 'package:relay_interview/src/app_status/presentation/force_update_page.dart';
import 'package:relay_interview/src/app_status/presentation/splash_page.dart';
import 'package:relay_interview/src/authentication/presentation/login_page.dart';
import 'package:relay_interview/src/main_navigation/main_navigation_page.dart';
import 'package:relay_interview/src/manual_check_in/presentation/create_manual_check_in_page.dart';
import 'package:relay_interview/src/manual_check_in/presentation/manual_check_in_page.dart';

List<GoRoute> routes = [
  GoRoute(
    name: AppRoutes.splash.name,
    path: AppRoutes.splash.path,
    builder: (context, state) => const SplashPage(),
  ),
  GoRoute(
    name: AppRoutes.forceUpdateRequired.name,
    path: AppRoutes.forceUpdateRequired.path,
    builder: (context, state) => const ForceUpdatePage(),
  ),
  GoRoute(
    name: AppRoutes.downForMaintenance.name,
    path: AppRoutes.downForMaintenance.path,
    builder: (context, state) => const DownForMaintenancePage(),
  ),
  GoRoute(
    name: AppRoutes.login.name,
    path: AppRoutes.login.path,
    builder: (context, state) => const LoginPage(),
  ),
  GoRoute(
    name: AppRoutes.home.name,
    path: AppRoutes.home.path,
    builder: (context, state) => const MainNavigationPage(),
  ),
  GoRoute(
    name: AppRoutes.manualCheckIn.name,
    path: AppRoutes.manualCheckIn.path,
    builder: (context, state) => const ManualCheckInPage(),
  ),
  GoRoute(
    name: AppRoutes.createManualCheckIn.name,
    path: AppRoutes.createManualCheckIn.path,
    builder: (context, state) => const CreateManualCheckInPage(),
  ),
];
