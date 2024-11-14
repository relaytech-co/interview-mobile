import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:go_router/go_router.dart';
import 'package:relay_interview/config/navigation/navigation/app_routes.dart';
import 'package:relay_interview/src/app_status/presentation/controller/app_state.dart';
import 'package:relay_interview/src/app_status/presentation/controller/app_state_controller.dart';

import 'routes.dart';

final appRouterProvider = Provider<GoRouter>((ref) {
  return GoRouter(
    routes: routes,
    debugLogDiagnostics: kDebugMode,
    observers: [
      //CustomAnalyticsObserver(analyticsClient: analyticsClient),
      // UserTracingObserver(),
    ],
    redirect: (BuildContext context, GoRouterState state) {
      final status = ref.watch(appStateControllerProvider).status;
      final location = state.uri.toString();
      switch (status) {
        case AppStatus.downForMaintenance:
          if (location == AppRoutes.downForMaintenance.path) {
            return null;
          }
          return AppRoutes.downForMaintenance.path;

        case AppStatus.forceUpdateRequired:
          if (location == AppRoutes.forceUpdateRequired.path) {
            return null;
          }
          return AppRoutes.forceUpdateRequired.path;
        case AppStatus.authenticated:
          if (location == AppRoutes.login.path) {
            return '/';
          }
          if (location == AppRoutes.splash.path) {
            return '/';
          }
          if (location == AppRoutes.downForMaintenance.path) {
            return '/';
          }

          return null;

        case AppStatus.unauthenticated:
          if (location == AppRoutes.login.path) {
            return null;
          }
          return AppRoutes.login.path;
        case AppStatus.uninitialized:
          return AppRoutes.splash.path;
      }
    },
  );
});
