import 'package:json_annotation/json_annotation.dart';

/// Enum for item type
enum ItemType {
  /// Parcel
  parcel('parcel'),

  /// Route bag
  routeBag('route_bag'),

  /// Unknown
  unknown('unknown');

  const ItemType(this.name);

  ///Name of the item type
  final String name;
}

/// Item type converter
class ItemTypeConverter implements JsonConverter<ItemType, String> {
  /// Item type converter constructor
  const ItemTypeConverter();

  @override
  ItemType fromJson(String? json) {
    if (json == null) return ItemType.unknown;
    return ItemType.values.firstWhere(
      (element) {
        return element.name == json;
      },
      orElse: () => ItemType.unknown,
    );
  }

  @override
  String toJson(ItemType state) {
    return state.name;
  }
}
