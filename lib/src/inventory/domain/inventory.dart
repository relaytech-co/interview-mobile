import 'package:models/models.dart';

///Inventory Model
class Inventory {
  ///Inventory Model
  Inventory({
    required this.emptyBags,
    required this.fullBags,
    required this.parcels,
  });

  ///List of empty bags
  final List<ItemModel> emptyBags;

  ///List of full bags
  final List<ItemModel> fullBags;

  ///List of parcels
  final List<ItemModel> parcels;

  ///Check if the inventory is empty
  bool get isEmpty => emptyBags.isEmpty && fullBags.isEmpty && parcels.isEmpty;

  ///Copy the inventory
  Inventory copyWith({
    List<ItemModel>? emptyBags,
    List<ItemModel>? fullBags,
    List<ItemModel>? parcels,
  }) {
    return Inventory(
      emptyBags: emptyBags ?? this.emptyBags,
      fullBags: fullBags ?? this.fullBags,
      parcels: parcels ?? this.parcels,
    );
  }

  ///Get items for a specific category
  List<ItemModel>? itemsForCategory(ItemCategory category) {
    switch (category) {
      case ItemCategory.emptyBags:
        return emptyBags;
      case ItemCategory.fullBags:
        return fullBags;
      case ItemCategory.parcels:
        return parcels;
    }
  }
}
