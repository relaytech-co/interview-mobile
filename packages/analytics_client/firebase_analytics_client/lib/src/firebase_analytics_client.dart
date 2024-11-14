import 'dart:async';

import 'package:analytics_client/analytics_client.dart';
import 'package:firebase_analytics/firebase_analytics.dart';
import 'package:firebase_crashlytics/firebase_crashlytics.dart';

/// Type definition of the function to identify the user
/// when they log in.
typedef OnIdentify = void Function(
  String userId, {
  String? email,
  String? name,
});

/// Type definition of the function to update the
/// user properties
typedef OnUserPropertiesUpdated = void Function(
  Map<String, dynamic>? userProperties,
);

/// {@template firebase_analytics_client}
/// Repository which manages tracking analytics.
/// {@endtemplate}
class FirebaseAnalyticsClient implements AnalyticsClient {
  /// {@macro firebase_analytics_client}
  FirebaseAnalyticsClient(
    FirebaseAnalytics analytics,
    FirebaseCrashlytics crashlytics, {
    OnIdentify? onIdentify,
    void Function()? onLogout,
    void Function(String)? onTrack,
    OnUserPropertiesUpdated? onUserPropertiesUpdated,
  })  : _analytics = analytics,
        _crashlytics = crashlytics,
        _onTrack = onTrack,
        _onLogout = onLogout,
        _onIdentify = onIdentify,
        _onUserPropertiesUpdated = onUserPropertiesUpdated;

  final FirebaseAnalytics _analytics;
  final FirebaseCrashlytics _crashlytics;
  final OnIdentify? _onIdentify;
  final void Function()? _onLogout;
  final void Function(String)? _onTrack;
  final OnUserPropertiesUpdated? _onUserPropertiesUpdated;

  Future<void>? _isUpdatingUserProperties;

  /// Tracks the provided [AnalyticsEvent].
  @override
  void track(AnalyticsEvent event) {
    _analytics.logEvent(
      name: event.name,
      parameters: event.properties,
    );
    _onTrack?.call(event.name);
  }

  /// Is used to identify the user
  ///
  /// It clears the user if the [userId] is empty string
  @override
  void identify(
    String userId, {
    String? name,
    String? email,
  }) {
    if (userId.isEmpty) {
      _analytics.setUserId();
      _crashlytics.setUserIdentifier('');
      _onLogout?.call();
    } else {
      _analytics.setUserId(id: userId);
      _crashlytics.setUserIdentifier(userId);
      _onIdentify?.call(
        userId,
        email: email,
        name: name,
      );
    }
  }

  /// Sends user properties to the analytics
  @override
  Future<void> updateProperties(
    Map<String, dynamic>? userProperties,
  ) async {
    if (_isUpdatingUserProperties != null) {
      await _isUpdatingUserProperties;
      return updateProperties(userProperties);
    }

    final completer = Completer<void>();
    _isUpdatingUserProperties = completer.future;

    _onUserPropertiesUpdated?.call(userProperties);
    await Future<void>.delayed(const Duration(seconds: 3));

    completer.complete();
    _isUpdatingUserProperties = null;
  }

  /// Tracks screen changes
  @override
  Future<void> setCurrentScreen({
    required String? screenName,
    String screenClassOverride = 'Flutter',
  }) async {
    return _analytics.logScreenView(
      screenName: screenName,
      screenClass: screenClassOverride,
    );
  }

  /// Uses [FirebaseCrashlytics] to report a non-fatal error.
  @override
  Future<void> reportNonFatalError({
    required String error,
    required StackTrace stackTrace,
    String? reason,
    String? userId,
  }) async {
    if (userId != null) {
      await _crashlytics.log('Error associated with User ID: $userId');
    }
    await _crashlytics.recordError(error, stackTrace, reason: reason);
  }
}
