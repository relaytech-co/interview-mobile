import 'package:flutter_test/flutter_test.dart';
import 'package:models/models.dart';

void main() {
  group('ItemTypeConverter', () {
    const converter = ItemTypeConverter();

    test('should return unknown for unrecognized JSON string', () {
      final result = converter.fromJson('non_existent_type');
      expect(result, ItemType.unknown);
    });

    test('should return unknown when JSON string is null', () {
      final result = converter.fromJson(null);
      expect(result, ItemType.unknown);
    });

    test('should return the correct ItemType from valid JSON string', () {
      expect(converter.fromJson('parcel'), ItemType.parcel);
      expect(converter.fromJson('route_bag'), ItemType.routeBag);
    });

    test('should convert ItemType to correct JSON string', () {
      expect(converter.toJson(ItemType.parcel), 'parcel');
      expect(converter.toJson(ItemType.routeBag), 'route_bag');
    });
  });
}
