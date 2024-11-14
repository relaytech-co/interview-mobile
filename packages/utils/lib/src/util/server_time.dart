// ignore: depend_on_referenced_packages
import 'package:flutter/material.dart';

/// A singleton that keeps track of the server time.
/// The implementation is a few milliseconds inaccurate depending on the CPU speed but
/// this should be irrelevant for the intended purposes.
class DateTimeServer {
  factory DateTimeServer() {
    return _instance;
  }

  DateTimeServer._internal();

  static final DateTimeServer _instance = DateTimeServer._internal();

  bool _disabled = false;
  DateTime _serverTime = DateTime.now().toUtc();
  DateTime _lastUpdated = DateTime.now().toUtc();

  /// Constructs a [DateTime] instance with current date and time on the
  /// server.
  ///
  /// ```dart
  /// final now = DateTime.now.server();
  /// ```
  DateTime utcnow() {
    if (_disabled) {
      return DateTime.now().toUtc();
    }
    // check now long it passed
    final diff = (_lastUpdated.millisecondsSinceEpoch -
            DateTime.now().toUtc().millisecondsSinceEpoch)
        .abs();

    // add that to server time and that will gives us current server time
    return DateTime.fromMillisecondsSinceEpoch(
            _serverTime.millisecondsSinceEpoch + diff)
        .toUtc();
  }

  /// Sets the new server time
  void setTime(String? serverTime) {
    if (serverTime == null || serverTime.isEmpty) return;
    _serverTime = DateTime.parse(serverTime).toUtc();
    _lastUpdated = DateTime.now().toUtc();
  }

  /// If set to true then DateTime.now.server() will return local machine time.
  set disabled(bool disabled) => _disabled = disabled;

  /// Will reset all variables
  @visibleForTesting
  void reset() {
    _disabled = false;
    _serverTime = DateTime.now().toUtc();
    _lastUpdated = DateTime.now().toUtc();
  }
}
