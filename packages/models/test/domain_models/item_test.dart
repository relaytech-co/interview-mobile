import 'package:flutter_test/flutter_test.dart';
import 'package:models/models.dart';

void main() {
  group('ItemModel', () {
    const uid = 'testUid';
    const barcode = 'testBarcode';
    const linkedItemUid = 'linkedUid';
    const lastEventUid = 'eventUid';
    const lastEventCourierOperativeUid = 'courierUid';
    final lastEventTime = DateTime.now();
    const type = ItemType.routeBag;
    const bagStatus = BagStatus.full;

    final item = ItemModel(
      uid,
      barcode,
      linkedItemUid,
      lastEventUid,
      lastEventCourierOperativeUid,
      lastEventTime,
      bagStatus,
      type,
    );

    test('should support value equality', () {
      final item2 = ItemModel(
        uid,
        barcode,
        linkedItemUid,
        lastEventUid,
        lastEventCourierOperativeUid,
        lastEventTime,
        bagStatus,
        type,
      );

      expect(item, equals(item2));
    });

    test('fromJson should return a valid instance', () {
      final json = item.toJson();
      final itemFromJson = ItemModel.fromJson(json);

      expect(itemFromJson, equals(item));
    });

    test('toJson should return a valid map', () {
      final json = item.toJson();
      expect(json['uid'], uid);
      expect(json['barcode'], barcode);
    });

    test('category should return correct value', () {
      expect(item.category, ItemCategory.fullBags);

      final emptyBagItem = item.copyWith(
        bagStatus: BagStatus.empty,
      );
      expect(emptyBagItem.category, ItemCategory.emptyBags);

      final parcelItem = item.copyWith(
        type: ItemType.parcel,
      );
      expect(parcelItem.category, ItemCategory.parcels);
    });

    test('ItemModel.from(ItemDbModel) should correctly initialize an instance',
        () {
      final itemDbModel = ItemDbModel(
        uid: uid,
        barcode: barcode,
        linkedItemUid: linkedItemUid,
        lastEventUid: lastEventUid,
        lastEventCourierOperativeUid: lastEventCourierOperativeUid,
        lastEventTime: lastEventTime,
        bagStatus: 'full',
        type: 'route_bag',
      );

      final itemFromDbModel = ItemModel.from(itemDbModel);

      expect(itemFromDbModel.uid, uid);
      expect(itemFromDbModel.barcode, barcode);
      expect(itemFromDbModel.type, ItemType.routeBag);
      expect(itemFromDbModel.bagStatus, BagStatus.full);
    });
  });
}
