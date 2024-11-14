// import 'package:flutter/foundation.dart';

import 'package:flutter/foundation.dart';

abstract final class RelayEnvironment {
  static final Environment environment = Environment.parse(
    const String.fromEnvironment('ENVIRONMENT'),
  );

  // static const String dixaToken = String.fromEnvironment('DIXA_TOKEN');
  // static const String dixaMessengerToken =
  //     String.fromEnvironment('DIXA_MESSENGER_TOKEN');
  // static const String mixpanelToken =
  //     String.fromEnvironment('MIXPANEL_PROJECT_TOKEN');

  static final Uri apiBaseUrl = Uri.parse(
    const String.fromEnvironment('API_BASE_URL'),
  );

  // static const String mapboxPublicAccessToken =
  //     String.fromEnvironment('MAPBOX_PUBLIC_ACCESS_TOKEN');

  static String scandit() {
    switch (defaultTargetPlatform) {
      case TargetPlatform.android:
        return const String.fromEnvironment('SCANDIT_ANDROID');
      case TargetPlatform.iOS:
        return const String.fromEnvironment('SCANDIT_IOS');
      default:
        throw 'unsupported platform $defaultTargetPlatform';
    }
  }

  static String launchDarklyMobileKey =
      const String.fromEnvironment('LAUNCH_DARKLY_MOBILE_KEY');

  /// Validates environment values or throws.
  static void validateAll() {
    void check(bool Function() validate, String envName) {
      final isValid = validate();
      if (!isValid) {
        throw StateError('Error validating environment value "$envName"');
      }
    }

    check(() => environment.name.isNotEmpty, 'ENVIRONMENT');
    // check(() => dixaToken.toString().isNotEmpty, 'DIXA_TOKEN');
    // check(() => launchDarklyMobileKey.toString().isNotEmpty,
    //     'LAUNCH_DARKLY_MOBILE_KEY');
    // check(() => apiBaseUrl.toString().isNotEmpty, 'API_BASE_URL');
    // check(
    //   () => mapboxPublicAccessToken.isNotEmpty,
    //   'MAPBOX_PUBLIC_ACCESS_TOKEN',
    // );
    // check(() => scandit().isNotEmpty,
    //     'SCANDIT_${defaultTargetPlatform.name.toUpperCase()}');
  }

  // static bool isMaestroBuild() {
  //   return const bool.hasEnvironment('IS_MAESTRO_TEST_BUILD')
  //       ? const bool.fromEnvironment('IS_MAESTRO_TEST_BUILD')
  //       : false;
  // }
}

enum Environment {
  sandbox,
  production;

  factory Environment.parse(String value) {
    return Environment.values.byName(value);
  }
}
