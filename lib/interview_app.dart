import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_localizations/flutter_localizations.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:hive/hive.dart';
import 'package:relay_interview/config/navigation/navigation/app_router.dart';
import 'package:relay_interview/i18n/strings.g.dart';
import 'package:toastification/toastification.dart';
import 'package:hive_flutter/adapters.dart';

class RelayPitstopApp extends ConsumerStatefulWidget {
  const RelayPitstopApp({super.key});

  @override
  ConsumerState<RelayPitstopApp> createState() => _RelayPitstopAppState();
}

class _RelayPitstopAppState extends ConsumerState<RelayPitstopApp> {
  @override
  void dispose() {
    Hive.close();
    super.dispose();
  }

  void didChangeAppLifecycleState(AppLifecycleState state) {
    if (state == AppLifecycleState.paused) {
      Hive.close();
    }
  }

  @override
  void initState() {
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    final theme = RelayThemeData.dark();
    final goRouter = ref.watch(appRouterProvider);
    SystemChrome.setPreferredOrientations([
      DeviceOrientation.portraitUp,
    ]);
    return ToastificationWrapper(
      child: MaterialApp.router(
        title: 'Relay Interview',
        scrollBehavior: const MaterialScrollBehavior().copyWith(
          physics: const BouncingScrollPhysics(
            parent: AlwaysScrollableScrollPhysics(),
          ),
        ),
        themeMode: ThemeMode.dark,
        theme: theme,
        darkTheme: theme,
        highContrastTheme: theme,
        highContrastDarkTheme: theme,
        routeInformationParser: goRouter.routeInformationParser,
        routerDelegate: goRouter.routerDelegate,
        routeInformationProvider: goRouter.routeInformationProvider,
        locale: TranslationProvider.of(context).flutterLocale,
        supportedLocales: AppLocaleUtils.supportedLocales,
        localizationsDelegates: GlobalMaterialLocalizations.delegates,
      ),
    );
  }
}
