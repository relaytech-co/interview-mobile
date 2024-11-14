import 'dart:async';
import 'package:connectivity_plus/connectivity_plus.dart';

/// The application's connectivity status (online or offline).
enum ConnectivityStatus {
  /// Indicates the application has a network connection.
  online,

  /// Indicates the application has no network connection
  offline
}

/// {@template connectivity_repository}
/// Flutter package which manages the connectivity domain.
/// {@endtemplate}
class ConnectivityRepository {
  /// {@macro connectivity_repository}
  ConnectivityRepository({Connectivity? connectivity})
      : _connectivity = connectivity ?? Connectivity();

  final Connectivity _connectivity;

  /// Fires whenever the connectivity status changes.
  Stream<ConnectivityStatus> get onConnectivityChanged {
    return _connectivity.onConnectivityChanged
        .map(_getStatusFromResults)
        .asBroadcastStream();
  }

  /// Can be used to query the current connectivity status.
  Future<ConnectivityStatus> connectivityStatus() async {
    final connectivityResult = await _connectivity.checkConnectivity();
    return _getStatusFromResults(connectivityResult);
  }

  ConnectivityStatus _getStatusFromResults(List<ConnectivityResult> results) {
    if (results.contains(ConnectivityResult.none)) {
      return ConnectivityStatus.offline;
    } else {
      return ConnectivityStatus.online;
    }
  }
}
