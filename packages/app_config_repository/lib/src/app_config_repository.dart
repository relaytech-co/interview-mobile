// ignore_for_file: public_member_api_docs

import 'dart:async';

import 'package:launchdarkly_flutter_client_sdk/launchdarkly_flutter_client_sdk.dart';
import 'package:version/version.dart';

/// {@template app_config_repository}
/// Repository which manages determining the current configuration of the app
/// based on remote configurations.
/// {@endtemplate}
///
///
class AppConfigRepository {
  /// {@macro app_config_repository}
  AppConfigRepository({
    required String launchDarklyKey,
  }) : _launchDarklyKey = launchDarklyKey {
    initializeLaunchDarkly();
  }

  late String _buildVersion;
  final String _launchDarklyKey;
  late bool _platformIsAndroid;

  final StreamController<bool> underMaintenanceController =
      StreamController<bool>();
  final StreamController<bool> forceUpdateController = StreamController<bool>();
  final StreamController<bool> showSoonToBeDeprecatedBanner =
      StreamController<bool>();
  LDClient? client;

  Future<void> initializeLaunchDarkly() async {
    final config = LDConfig(
      _launchDarklyKey,
      AutoEnvAttributes.enabled,
      dataSourceConfig: DataSourceConfig(evaluationReasons: true),
    );

    // final context = LDContextBuilder().build();
    // client = LDClient(config, context);
    // await client!.start().timeout(const Duration(seconds: 30));
    // final appInfo = await PackageInfo.fromPlatform();
    // _buildVersion = appInfo.version;
    // _platformIsAndroid = Platform.isAndroid;

    // await applyValues();
    // client!.flagChanges.listen((changeEvent) {
    //   applyValues();
    // });
  }

  Future<void> applyValues() async {
    await initDownForMaintenance(
        client!.boolVariation('IS_DOWN_FOR_MAINTENANCE', false));
    final minVals = client!
        .jsonVariation('MIN_SUPPORTED_VERSION', LDValue.buildObject().build());
    Map<String, dynamic> minVersions = Map.fromIterables(
        minVals.keys, minVals.values.map((e) => e.stringValue()));

    await fetchInitialMinSupportedVersion(minVersions);
    final maxVals = client!.jsonVariation(
        'MAX_SUGGESTED_UPDATE_VERSION', LDValue.buildObject().build());
    final maxVersions = Map.fromIterables(
        maxVals.keys, maxVals.values.map((e) => e.stringValue()));

    await initSoonToBeDeprecated(maxVersions);
  }

  /// Returns a [Stream<bool>] which indicates whether
  /// the current application status is down for maintenance.
  Future<void> initDownForMaintenance(bool status) async {
    underMaintenanceController.add(status);
  }

  Future<void> initForceUpgradeRequired(Map<String, dynamic> versions) async {
    final minBuildNumber =
        (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
    final Version currentVersion = Version.parse(_buildVersion);
    final Version latestVersion = Version.parse(minBuildNumber);
    final needsUpdate = currentVersion < latestVersion;
    forceUpdateController.add(needsUpdate);
  }

  Future<void> fetchInitialMinSupportedVersion(
      Map<String, dynamic> versions) async {
    final minBuildNumber =
        (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
    final Version currentVersion = Version.parse(_buildVersion);
    final Version latestVersion = Version.parse(minBuildNumber);
    forceUpdateController.add(currentVersion < latestVersion);
  }

  Future<void> initSoonToBeDeprecated(Map<String, dynamic> versions) async {
    final maxBuildNumber =
        (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
    if (maxBuildNumber.toString() == '-1') {
      showSoonToBeDeprecatedBanner.add(false);
    } else {
      final Version currentVersion = Version.parse(_buildVersion);
      final Version maxSuggestedUpdate = Version.parse(maxBuildNumber);
      final showBanner = currentVersion <= maxSuggestedUpdate;
      showSoonToBeDeprecatedBanner.add(showBanner);
    }
    fetchInitialSoonToBeDeprecatedVersion();
  }

  Future<void> fetchInitialSoonToBeDeprecatedVersion() async {
    final val = client!.jsonVariation(
        'MAX_SUGGESTED_UPDATE_VERSION', LDValue.buildObject().build());

    Map<String, dynamic> versions =
        Map.fromIterables(val.keys, val.values.map((e) => e.stringValue()));
    final maxBuildNumber =
        (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
    if (maxBuildNumber.toString() == '-1') {
      showSoonToBeDeprecatedBanner.add(false);
    } else {
      final Version currentVersion = Version.parse(_buildVersion);
      final Version maxSuggestedUpdate = Version.parse(maxBuildNumber);
      final showBanner = currentVersion <= maxSuggestedUpdate;
      showSoonToBeDeprecatedBanner.add(showBanner);
    }
  }
}

// import 'dart:async';

// import 'package:launchdarkly_flutter_client_sdk/launchdarkly_flutter_client_sdk.dart';
// import 'package:version/version.dart';

// class AppConfigRepository {
//   AppConfigRepository({
//     required String launchDarklyKey,
//   }) : _launchDarklyKey = launchDarklyKey {
//     initializeLaunchDarkly();
//   }

//   late String _buildVersion;
//   final String _launchDarklyKey;
//   late bool _platformIsAndroid;

//   final _underMaintenanceController = StreamController<bool>.broadcast();
//   final _forceUpdateController = StreamController<bool>.broadcast();
//   final _showSoonToBeDeprecatedBannerController =
//       StreamController<bool>.broadcast();
//   LDClient? client;

//   // Expose the streams
//   Stream<bool> get underMaintenanceStream => _underMaintenanceController.stream;
//   Stream<bool> get forceUpdateStream => _forceUpdateController.stream;
//   Stream<bool> get showSoonToBeDeprecatedBannerStream =>
//       _showSoonToBeDeprecatedBannerController.stream;

//   Future<void> initializeLaunchDarkly() async {
//     final config = LDConfig(
//       _launchDarklyKey,
//       AutoEnvAttributes.enabled,
//       dataSourceConfig: DataSourceConfig(evaluationReasons: true),
//     );

//     // final context = LDContextBuilder().build();
//     // client = LDClient(config, context);
//     // await client!.start().timeout(const Duration(seconds: 30));
//     // final appInfo = await PackageInfo.fromPlatform();
//     // _buildVersion = appInfo.version;
//     // _platformIsAndroid = Platform.isAndroid;

//     // await applyValues();
//     // client!.flagChanges.listen((changeEvent) {
//     //   applyValues();
//     // });
//   }

//   Future<void> applyValues() async {
//     await initDownForMaintenance(
//         client!.boolVariation('IS_DOWN_FOR_MAINTENANCE', false));
//     final minVals = client!
//         .jsonVariation('MIN_SUPPORTED_VERSION', LDValue.buildObject().build());
//     Map<String, dynamic> minVersions = Map.fromIterables(
//         minVals.keys, minVals.values.map((e) => e.stringValue()));

//     await fetchInitialMinSupportedVersion(minVersions);
//     final maxVals = client!.jsonVariation(
//         'MAX_SUGGESTED_UPDATE_VERSION', LDValue.buildObject().build());
//     final maxVersions = Map.fromIterables(
//         maxVals.keys, maxVals.values.map((e) => e.stringValue()));

//     await initSoonToBeDeprecated(maxVersions);
//   }

//   Future<void> initDownForMaintenance(bool status) async {
//     _underMaintenanceController.add(status);
//   }

//   Future<void> initForceUpgradeRequired(Map<String, dynamic> versions) async {
//     final minBuildNumber =
//         (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
//     final Version currentVersion = Version.parse(_buildVersion);
//     final Version latestVersion = Version.parse(minBuildNumber);
//     final needsUpdate = currentVersion < latestVersion;
//     _forceUpdateController.add(needsUpdate);
//   }

//   Future<void> fetchInitialMinSupportedVersion(
//       Map<String, dynamic> versions) async {
//     final minBuildNumber =
//         (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
//     final Version currentVersion = Version.parse(_buildVersion);
//     final Version latestVersion = Version.parse(minBuildNumber);
//     _forceUpdateController.add(currentVersion < latestVersion);
//   }

//   Future<void> initSoonToBeDeprecated(Map<String, dynamic> versions) async {
//     final maxBuildNumber =
//         (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
//     if (maxBuildNumber.toString() == '-1') {
//       _showSoonToBeDeprecatedBannerController.add(false);
//     } else {
//       final Version currentVersion = Version.parse(_buildVersion);
//       final Version maxSuggestedUpdate = Version.parse(maxBuildNumber);
//       final showBanner = currentVersion <= maxSuggestedUpdate;
//       _showSoonToBeDeprecatedBannerController.add(showBanner);
//     }
//     fetchInitialSoonToBeDeprecatedVersion();
//   }

//   Future<void> fetchInitialSoonToBeDeprecatedVersion() async {
//     final val = client!.jsonVariation(
//         'MAX_SUGGESTED_UPDATE_VERSION', LDValue.buildObject().build());

//     Map<String, dynamic> versions =
//         Map.fromIterables(val.keys, val.values.map((e) => e.stringValue()));
//     final maxBuildNumber =
//         (_platformIsAndroid ? versions['android'] : versions['ios']) ?? '0';
//     if (maxBuildNumber.toString() == '-1') {
//       _showSoonToBeDeprecatedBannerController.add(false);
//     } else {
//       final Version currentVersion = Version.parse(_buildVersion);
//       final Version maxSuggestedUpdate = Version.parse(maxBuildNumber);
//       final showBanner = currentVersion <= maxSuggestedUpdate;
//       _showSoonToBeDeprecatedBannerController.add(showBanner);
//     }
//   }

//   void dispose() {
//     _underMaintenanceController.close();
//     _forceUpdateController.close();
//     _showSoonToBeDeprecatedBannerController.close();
//   }
// }
