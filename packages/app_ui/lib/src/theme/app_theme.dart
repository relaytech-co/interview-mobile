import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';

import '../../app_ui.dart';

abstract final class RelayThemeData {
  static ThemeData dark() {
    return _themeDataFor(
      colorScheme: RelayColors.colorSchemeDark,
      relayColorScheme: RelayColorScheme.dark,
      textTheme: relayTextTheme,
      appBarTheme: AppBarTheme(
        backgroundColor: RelayColors.black,
        centerTitle: true,
        surfaceTintColor: Colors.transparent,
        iconTheme: IconThemeData(color: relayTextTheme.bodyLarge!.color),
        titleTextStyle: TextStyle(
            fontWeight: FontWeight.w700,
            fontSize: 21,
            color: relayTextTheme.bodyLarge!.color,
            letterSpacing: -0.8,
            fontFamily: 'SanFrancisco'),
      ),
    );
  }

  static ThemeData light() {
    return _themeDataFor(
      colorScheme: RelayColors.colorSchemeLight,
      relayColorScheme: RelayColorScheme.light,
      textTheme: lightRelayTextTheme,
      appBarTheme: AppBarTheme(
        backgroundColor: Colors.white,
        centerTitle: true,
        surfaceTintColor: Colors.transparent,
        iconTheme: IconThemeData(color: lightRelayTextTheme.bodyLarge!.color),
        titleTextStyle: TextStyle(
            fontWeight: FontWeight.w700,
            fontSize: 21,
            color: lightRelayTextTheme.bodyLarge!.color,
            letterSpacing: -0.8,
            fontFamily: 'SanFrancisco'),
      ),
    );
  }

  static ThemeData _themeDataFor({
    TargetPlatform? platform,
    required ColorScheme colorScheme,
    required TextTheme textTheme,
    required RelayColorScheme relayColorScheme,
    required AppBarTheme appBarTheme,
  }) {
    platform ??= defaultTargetPlatform;

    final commonButtonStyle = ButtonStyle(
        shape: MaterialStatePropertyAll(
          RoundedRectangleBorder(
            borderRadius: BorderRadius.all(Radius.circular(14.0)),
          ),
        ),
        padding: MaterialStateProperty.resolveWith((states) {
          return EdgeInsets.symmetric(vertical: 14, horizontal: 16);
        }),
        textStyle: MaterialStateProperty.resolveWith((states) {
          return TextStyle(
              fontFamily: 'SanFrancisco',
              fontSize: 17,
              letterSpacing: -0.8,
              fontWeight: FontWeight.w700);
        }));

    return ThemeData(
      textTheme: textTheme,
      primaryColor: colorScheme.primary,
      extensions: [relayColorScheme],
      inputDecorationTheme: InputDecorationTheme(
        floatingLabelBehavior: FloatingLabelBehavior.always,
        border: MaterialStateUnderlineInputBorder.resolveWith((states) {
          final Color color;
          // Retrieved from InputDecorator default M3 values
          if (states.contains(MaterialState.error)) {
            if (states.contains(MaterialState.focused)) {
              color = colorScheme.error;
            } else if (states.contains(MaterialState.hovered)) {
              color = colorScheme.onErrorContainer;
            } else {
              color = colorScheme.error;
            }
          } else if (states.contains(MaterialState.focused)) {
            color = colorScheme.primary;
          } else if (states.contains(MaterialState.hovered)) {
            color = colorScheme.onSurface;
          } else if (states.contains(MaterialState.disabled)) {
            color = colorScheme.onSurface.withOpacity(0.12);
          } else {
            color = colorScheme.outline;
          }

          return UnderlineInputBorder(
            borderSide: BorderSide(
              width: 4.0,
              color: color,
            ),
          );
        }),
      ),
      useMaterial3: true,
      // COLOR
      colorScheme: colorScheme,
      // TYPOGRAPHY & ICONOGRAPHY
      typography: Typography.material2021(
        platform: platform,
        colorScheme: colorScheme,
      ),
      // COMPONENT THEMES
      appBarTheme: appBarTheme,
      cardTheme: CardTheme(
        clipBehavior: Clip.hardEdge,
        color: colorScheme.surface,
        elevation: 1.0,
        shape: const RoundedRectangleBorder(
          borderRadius: BorderRadius.all(Radius.circular(4.0)),
        ),
        surfaceTintColor: Colors.transparent,
      ),

      elevatedButtonTheme: null,
      expansionTileTheme: null,
      filledButtonTheme: FilledButtonThemeData(
        style: commonButtonStyle,
      ),
      fontFamily: 'SanFrancisco',
      floatingActionButtonTheme: null,

      iconButtonTheme: IconButtonThemeData(
        style: ButtonStyle(
          backgroundColor: MaterialStatePropertyAll(Colors.transparent),
          foregroundColor: MaterialStateProperty.resolveWith((states) {
            if (states.contains(MaterialState.disabled)) {
              return colorScheme.onSurface.withOpacity(0.12);
            } else if (states.contains(MaterialState.pressed)) {
              return colorScheme.primary.withOpacity(0.12);
            }
            return colorScheme.onSurface;
          }),
          padding: MaterialStateProperty.resolveWith((states) {
            return EdgeInsets.all(10);
          }),
        ),
      ),
      listTileTheme: null,
      menuBarTheme: null,
      menuButtonTheme: null,
      drawerTheme: DrawerThemeData(
          surfaceTintColor: Colors.transparent,
          backgroundColor: RelayColors.black),
      menuTheme: null,
      bottomSheetTheme: BottomSheetThemeData(
        backgroundColor: Colors.black,
        surfaceTintColor: Colors.transparent,
        elevation: 0,
        modalBackgroundColor: Colors.black,
        modalElevation: 0,
        shape: const RoundedRectangleBorder(
          borderRadius: BorderRadius.only(
            topLeft: Radius.circular(16),
            topRight: Radius.circular(16),
          ),
        ),
      ),
      navigationBarTheme: null,
      navigationDrawerTheme: NavigationDrawerThemeData(
          surfaceTintColor: const Color.fromARGB(0, 57, 39, 39)),
      navigationRailTheme: null,
      outlinedButtonTheme: OutlinedButtonThemeData(
        style: commonButtonStyle,
      ),
      popupMenuTheme: PopupMenuThemeData(
        color: colorScheme.background,
        elevation: 1.0,
        surfaceTintColor: Colors.transparent,
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(8),
        ),
      ),
      progressIndicatorTheme: null,
      radioTheme: null,
      searchBarTheme: null,
      searchViewTheme: null,
      segmentedButtonTheme: null,

      sliderTheme: null,
      snackBarTheme: const SnackBarThemeData(
        shape: ContinuousRectangleBorder(
          borderRadius: BorderRadius.all(Radius.circular(8)),
        ),
        behavior: SnackBarBehavior.floating,
      ),
      dialogTheme: DialogTheme(
        backgroundColor: colorScheme.surface,
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(8),
        ),
        surfaceTintColor: Colors.transparent,
      ),
      switchTheme: SwitchThemeData(
        materialTapTargetSize: MaterialTapTargetSize.shrinkWrap,
        overlayColor: MaterialStatePropertyAll(Colors.transparent),
        trackOutlineColor: MaterialStatePropertyAll(Colors.transparent),
        thumbIcon: MaterialStatePropertyAll(Icon(Icons.abc,
            color: Colors.transparent)), //To make the thumb bigger
        thumbColor: MaterialStateProperty.resolveWith((states) {
          if (states.contains(MaterialState.disabled)) {
            return colorScheme.onSurface.withOpacity(0.12);
          } else if (states.contains(MaterialState.selected)) {
            return colorScheme.primary;
          }
          return colorScheme.onSurface;
        }),
        trackColor: MaterialStateProperty.resolveWith((states) {
          if (states.contains(MaterialState.disabled)) {
            return colorScheme.onSurface.withOpacity(0.12);
          } else if (states.contains(MaterialState.selected)) {
            return colorScheme.surfaceVariant;
          }
          return colorScheme.surfaceVariant;
        }),
      ),
      tabBarTheme: TabBarTheme(
        labelStyle: textTheme.titleMedium!
            .copyWith(fontWeight: FontWeight.w600, fontSize: 17),
        unselectedLabelStyle: textTheme.titleMedium!
            .copyWith(fontWeight: FontWeight.w400, fontSize: 17),
        labelColor: Colors.white,
        indicatorSize: TabBarIndicatorSize.tab,
        indicatorColor: Colors.white,
      ),
      textButtonTheme: TextButtonThemeData(
        style: commonButtonStyle,
      ),
      // DEPRECATED (newest deprecations at the bottom)
    );
  }

  static TextTheme get relayTextTheme {
    return TextTheme(
      displayLarge: Typography.whiteCupertino.displayLarge!.copyWith(
          fontFamily: 'SanFrancisco', letterSpacing: -0.2, fontSize: 20),
      displayMedium: Typography.whiteCupertino.displayMedium!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      displaySmall: Typography.whiteCupertino.displaySmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      headlineLarge: Typography.whiteCupertino.headlineLarge!.copyWith(
          fontFamily: 'SanFrancisco',
          letterSpacing: -1,
          fontSize: 24,
          fontWeight: FontWeight.w600,
          color: Colors.white,
          height: 1),
      headlineMedium: Typography.whiteCupertino.headlineMedium!.copyWith(
        fontFamily: 'SanFrancisco',
        letterSpacing: -0.2,
        color: Colors.white,
        fontWeight: FontWeight.w600,
        fontSize: 20,
      ),
      headlineSmall: Typography.whiteCupertino.headlineSmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      titleLarge: Typography.whiteCupertino.titleLarge!.copyWith(
          fontFamily: 'SanFrancisco',
          letterSpacing: -0.9,
          fontWeight: FontWeight.w600),
      titleMedium: Typography.whiteCupertino.titleMedium!.copyWith(
          fontFamily: 'SanFrancisco',
          fontSize: 17,
          letterSpacing: -0.5,
          height: 1),
      titleSmall: TextStyle(
          fontFamily: 'SanFrancisco',
          fontSize: 14,
          letterSpacing: -0.3,
          fontWeight: FontWeight.w700),
      bodyLarge: Typography.whiteCupertino.bodyLarge!.copyWith(
          fontFamily: 'SanFrancisco',
          letterSpacing: -0.8,
          fontWeight: FontWeight.w400,
          color: Colors.white,
          height: 1.2,
          fontSize: 18),
      bodyMedium: Typography.whiteCupertino.bodyMedium!.copyWith(
          fontFamily: 'SanFrancisco',
          letterSpacing: -0.6,
          fontWeight: FontWeight.w400,
          color: Colors.white,
          height: 1.2,
          fontSize: 15),
      bodySmall: Typography.whiteCupertino.bodySmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      labelLarge: Typography.whiteCupertino.labelLarge!.copyWith(
          fontFamily: 'SanFrancisco',
          letterSpacing: -0.2,
          fontWeight: FontWeight.w400,
          fontSize: 16),
      labelMedium: Typography.whiteCupertino.labelMedium!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      labelSmall: Typography.whiteCupertino.labelSmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
    );
  }

  static TextTheme get lightRelayTextTheme {
    return TextTheme(
      displayLarge: Typography.blackCupertino.displayLarge!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      displayMedium: Typography.blackCupertino.displayMedium!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      displaySmall: Typography.blackCupertino.displaySmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      headlineLarge: Typography.whiteCupertino.headlineLarge!.copyWith(
          fontFamily: 'SanFrancisco',
          letterSpacing: -0.2,
          fontSize: 24,
          fontWeight: FontWeight.w600,
          height: 1),
      headlineMedium: Typography.blackCupertino.headlineMedium!.copyWith(
        fontFamily: 'SanFrancisco',
        letterSpacing: -0.2,
        fontWeight: FontWeight.w600,
        fontSize: 20,
      ),
      headlineSmall: Typography.blackCupertino.headlineSmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      titleLarge: Typography.blackCupertino.titleLarge!.copyWith(
          fontFamily: 'SanFrancisco',
          letterSpacing: -0.5,
          fontSize: 16,
          fontWeight: FontWeight.w600),
      titleMedium: Typography.blackCupertino.titleMedium!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      titleSmall: TextStyle(
        fontFamily: 'SanFrancisco',
        fontSize: 14,
        color: Colors.black,
        letterSpacing: -0.3,
      ),
      bodyLarge: Typography.blackCupertino.bodyLarge!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      bodyMedium: Typography.blackCupertino.bodyMedium!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      bodySmall: Typography.blackCupertino.bodySmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      labelLarge: Typography.blackCupertino.labelLarge!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      labelMedium: Typography.blackCupertino.labelMedium!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
      labelSmall: Typography.blackCupertino.labelSmall!
          .copyWith(fontFamily: 'SanFrancisco', letterSpacing: -0.2),
    );
  }
}
