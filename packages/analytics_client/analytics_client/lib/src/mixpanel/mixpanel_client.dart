import 'package:mixpanel_flutter/mixpanel_flutter.dart';

import '../../analytics_client.dart';

class MixpanelClient implements AnalyticsClient {
  MixpanelClient(this.mixpanel);

  Mixpanel mixpanel;

  static initialise(String token) async {
    Mixpanel mixpanel = await Mixpanel.init(token, trackAutomaticEvents: false);
    return MixpanelClient(mixpanel);
  }

  @override
  void identify(String userId, {String? name, String? email}) {
    mixpanel.identify(userId);
    if (name != null && email != null) {
      mixpanel.getPeople().set(name, email);
    }
  }

  @override
  Future<void> reportNonFatalError(
      {required String error,
      required StackTrace stackTrace,
      String? reason,
      String? userId}) async {
    mixpanel.track('reportNonFatalError', properties: {
      'error': error,
      'reason': reason,
      'userId': userId,
      'stackTrace': stackTrace.toString(),
    });
  }

  @override
  Future<void> setCurrentScreen(
      {required String? screenName, String screenClassOverride = 'Flutter'}) async {
    mixpanel.track('setCurrentScreen', properties: {
      'screenName': screenName,
      'screenClassOverride': screenClassOverride,
    });
  }

  @override
  void track(AnalyticsEvent event) {
    mixpanel.track(event.name, properties: event.properties);
  }

  @override
  Future<void> updateProperties(Map<String, dynamic>? userProperties) async {
    userProperties?.forEach((key, value) {
      mixpanel.getPeople().set(key, value);
    });
  }
}
