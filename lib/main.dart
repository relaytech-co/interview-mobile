import 'package:database_client/database_client.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:hive_flutter/hive_flutter.dart';
import 'package:relay_interview/i18n/strings.g.dart';
import 'package:relay_interview/interview_app.dart';
import 'package:scandit_flutter_datacapture_barcode/scandit_flutter_datacapture_barcode.dart';

import 'package:path_provider/path_provider.dart';

Future<void> main() async {
  // initializeLoggers();

  WidgetsFlutterBinding.ensureInitialized();
  // final firebase = await initializeFirebase(RelayEnvironment.environment);
  //RelayEnvironment.validateAll();
  final appDocumentDirectory = await getApplicationDocumentsDirectory();
  Hive.init(appDocumentDirectory.path);
  await DatabaseClient().initialize();
  await ScanditFlutterDataCaptureBarcode.initialize();
  LocaleSettings.useDeviceLocale();
  // final mixpanelClient =
  //     await MixpanelClient.initialise(RelayEnvironment.mixpanelToken);

  // initializeCrashlytics();

  //final analyticsClient_ = _getAnalyticsClient(firebase, mixpanelClient);

  runApp(ProviderScope(
      // observers: [
      //   // if (kDebugMode) LoggingProviderObserver(),
      // ],
      // overrides: [
      //   // firebaseAppProvider.overrideWithValue(firebase),
      //   // analyticsClient.overrideWithValue(analyticsClient_),
      // ],
      child: TranslationProvider(
    child: const RelayPitstopApp(),
  )));
}

// CompositeAnalyticsClient _getAnalyticsClient(
//     FirebaseApp firebase, MixpanelClient mixpanelClient) {
//   return CompositeAnalyticsClient([
//     FirebaseAnalyticsClient(
//       FirebaseAnalytics.instanceFor(app: firebase),
//       FirebaseCrashlytics.instance,
//       onIdentify: (userId, {email, name}) {},
//       onUserPropertiesUpdated: (userProperties) {},
//       onLogout: () {},
//       onTrack: (String? val) {},
//     ),
//     if (!kDebugMode) mixpanelClient
//   ]);
// }
