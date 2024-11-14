// ignore_for_file: public_member_api_docs

import 'package:hive/hive.dart';

part 'item_db_model.g.dart';

/// {@template route}
/// Item model for the database
/// {@endtemplate}

@HiveType(typeId: 2)
class ItemDbModel extends HiveObject {
  ItemDbModel({
    required this.uid,
    required this.barcode,
    required this.linkedItemUid,
    required this.lastEventUid,
    required this.lastEventCourierOperativeUid,
    required this.lastEventTime,
    required this.bagStatus,
    required this.type,
  });

  ItemDbModel copyWith({
    String? uid,
    String? barcode,
    String? linkedItemUid,
    String? lastEventUid,
    String? lastEventCourierOperativeUid,
    DateTime? lastEventTime,
    String? bagStatus,
    String? type,
  }) =>
      ItemDbModel(
        uid: uid ?? this.uid,
        barcode: barcode ?? this.barcode,
        linkedItemUid: linkedItemUid ?? this.linkedItemUid,
        lastEventUid: lastEventUid ?? this.lastEventUid,
        lastEventCourierOperativeUid:
            lastEventCourierOperativeUid ?? this.lastEventCourierOperativeUid,
        lastEventTime: lastEventTime ?? this.lastEventTime,
        bagStatus: bagStatus ?? this.bagStatus,
        type: type ?? this.type,
      );

  @HiveField(0)
  final String uid;

  @HiveField(1)
  final String barcode;

  @HiveField(2)
  final String linkedItemUid;

  @HiveField(3)
  final String lastEventUid;

  @HiveField(4)
  final String? lastEventCourierOperativeUid;

  @HiveField(5)
  final DateTime? lastEventTime;

  @HiveField(6)
  final String? bagStatus;

  @HiveField(7)
  final String? type;
}
