// ignore_for_file: prefer_void_to_null

import 'dart:async';

import 'package:api_client/api_client.dart';
import 'package:database_client/database_client.dart';
import 'package:equatable/equatable.dart';
import 'package:models/models.dart';
import 'package:rxdart/rxdart.dart';

/// {@template inventory_failure}
/// Is thrown when an error occurs in instructor repository.
/// {@endtemplate}
class InventoryFailure with EquatableMixin implements Exception {
  /// {@macro inventory_failure}
  const InventoryFailure(this.error, this.stackTrace);

  /// The error that was caught.
  final Object error;

  /// The StackTrace associated with the [error].
  final StackTrace stackTrace;

  @override
  List<Object?> get props => [error, stackTrace];
}

/// {@template inventory_repository}
/// A repository that exposes inventory resources.
/// {@endtemplate}
class InventoryRepository {
  /// {@macro inventory_repository}
  InventoryRepository({
    required ApiClient apiClient,
    required DatabaseClient databaseClient,
  })  : _apiClient = apiClient,
        _databaseClient = databaseClient;

  final ApiClient _apiClient;
  final DatabaseClient _databaseClient;

  /// Returns a stream of items.
  ///
  /// It returns values from the local database first,
  /// when the subscription starts.
  /// Then it loads data from the API and adds it to the stream.
  Stream<List<ItemModel>> inventory() {
    throw UnimplementedError();
  }

  /// Returns a stream of checked out items.
  ///
  /// For now this will just fetch from the API because I dont really
  /// know how the logic works here
  Stream<List<ItemModel>> checkedOutItems() {
    final stream = BehaviorSubject<List<ItemModel>>();

    Future<void> _handleError(Object error, StackTrace stackTrace) async {
      stream.addError(InventoryFailure(error, stackTrace));
    }

    try {
      _apiClient.inventoryResource.getCheckedOutItems().then((items) {
        stream.add(items.toList());
      }).catchError((Object error, StackTrace stackTrace) async {
        await _handleError(error, stackTrace);
      });
    } catch (error, stackTrace) {
      _handleError(error, stackTrace);
    }

    return stream.stream;
  }
}
