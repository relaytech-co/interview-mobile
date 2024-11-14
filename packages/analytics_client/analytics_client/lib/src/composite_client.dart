import '../analytics_client.dart';

class CompositeAnalyticsClient implements AnalyticsClient {
  CompositeAnalyticsClient(this.clients);

  final List<AnalyticsClient> clients;

  @override
  void identify(String userId, {String? name, String? email}) {
    for (var client in clients) {
      client.identify(userId, name: name, email: email);
    }
  }

  @override
  Future<void> reportNonFatalError(
      {required String error,
      required StackTrace stackTrace,
      String? reason,
      String? userId}) async {
    for (var client in clients) {
      client.reportNonFatalError(
          error: error, stackTrace: stackTrace, reason: reason, userId: userId);
    }
  }

  @override
  Future<void> setCurrentScreen(
      {required String? screenName, String screenClassOverride = 'Flutter'}) async {
    for (var client in clients) {
      client.setCurrentScreen(
          screenName: screenName, screenClassOverride: screenClassOverride);
    }
  }

  @override
  void track(AnalyticsEvent event) {
    for (var client in clients) {
      client.track(event);
    }
  }

  @override
  Future<void> updateProperties(Map<String, dynamic>? userProperties) async {
    for (var client in clients) {
      client.updateProperties(userProperties);
    }
  }
}
