import 'dart:async';

import '../analytics_client.dart';

/// {@template analytics_client}
/// Abstract class which manages tracking analytics.
/// {@endtemplate}
abstract class AnalyticsClient {
  /// {@macro analytics_client}
  AnalyticsClient();

  /// Tracks the provided [AnalyticsEvent].
  void track(AnalyticsEvent event);

  /// Is used to identify the user
  ///
  /// It clears the user if the [userId] is empty string
  void identify(
    String userId, {
    String? name,
    String? email,
  });

  /// Sends user properties to the analytics
  Future<void> updateProperties(
    Map<String, dynamic>? userProperties,
  );

  /// Tracks screen changes
  Future<void> setCurrentScreen({
    required String? screenName,
    String screenClassOverride = 'Flutter',
  });

  /// Report a non-fatal error.
  Future<void> reportNonFatalError({
    required String error,
    required StackTrace stackTrace,
    String? reason,
    String? userId,
  });
}
