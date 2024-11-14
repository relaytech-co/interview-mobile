import 'package:hive/hive.dart';
import 'package:models/models.dart';
import 'package:rxdart/rxdart.dart';

/// {@template inventory_resource}
/// Resource responsible for retrieving item related data
/// {@endtemplate}
class InventoryResource {
  /// {@macro inventory_resource}
  InventoryResource({required this.box});
  final Box<ItemDbModel> box;

  /// Returns all items in the inventory
  Stream<List<ItemDbModel>> getInventory() {
    final items = box.values.toList();
    return Rx.concat(
        [Stream.value(items), box.watch().map((_) => (box.values.toList()))]);
  }

  /// It updates the inventory with the given items.
  Future<void> saveAllItems(List<ItemDbModel> items) async {
    try {
      //simplifying it to start with the fetch
      await box.clear();
      await box.addAll(items);
    } catch (err) {
      print('Error saving inventory');
      print(err.toString());
    }
  }

  /// Clears inventory
  void clearBox() {
    box.clear();
  }
}
