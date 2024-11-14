import 'dart:async';

import 'package:flutter/foundation.dart';
import 'package:hive_flutter/hive_flutter.dart';
import 'package:models/models.dart';

import '../database_client.dart';

/// {@template database_client}
/// Client communicating with the underlying database
/// {@endtemplate}
///
const currentUserBox = 'current_user';
const inventoryBox = 'inventory';

class DatabaseClient {
  /// {@macro database_client}
  DatabaseClient();

  /// Used to initialize the database.
  /// Should be called before using any database resources.
  Future<void> initialize() async {
    try {
      Hive.registerAdapter<UserDbModel>(UserDbModelAdapter());
      Hive.registerAdapter<ItemDbModel>(ItemDbModelAdapter());
    } catch (e) {
      debugPrint(e.toString());
    } finally {
      await Hive.openBox<UserDbModel>(currentUserBox);
      await Hive.openBox<ItemDbModel>(inventoryBox);
    }
  }

  /// Clears all the boxes in the database
  Future<void> clear() async {
    Hive.box<UserDbModel>(currentUserBox).clear();
  }

  Future<void> deleteStore() async {
    Hive.deleteFromDisk();
  }

  UserResource get userResource {
    return UserResource(box: Hive.box<UserDbModel>(currentUserBox));
  }

  InventoryResource get inventoryResource {
    return InventoryResource(box: Hive.box<ItemDbModel>(inventoryBox));
  }

  // BackgroundRequestResource get backgroundRequestResource {
  //   return BackgroundRequestResource(
  //       box: Hive.box<BackgroundDbRequestModel>('backgroundRequests'));
  // }

  // CurrentShipmentResource get currentShipmentResource {
  //   return CurrentShipmentResource(box: Hive.box<CurrentShipmentDbModel>('currentShipment'));
  // }
}
