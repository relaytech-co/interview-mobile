import 'package:equatable/equatable.dart';
import 'package:json_annotation/json_annotation.dart';
import 'package:models/models.dart';
import 'package:models/utils/utils.dart';

part 'item.g.dart';

@JsonSerializable(createToJson: true)

/// ItemModel
class ItemModel extends Equatable {
  /// ItemModel constructor
  const ItemModel(
    this.uid,
    this.barcode,
    this.linkedItemUid,
    this.lastEventUid,
    this.lastEventCourierOperativeUid,
    this.lastEventTime,
    this.bagStatus,
    this.type,
  );

  /// Creates a [ItemModel] object from [ItemDbModel].
  ItemModel.from(ItemDbModel data)
      : this(
          data.uid,
          data.barcode,
          data.linkedItemUid,
          data.lastEventUid,
          data.lastEventCourierOperativeUid,
          data.lastEventTime,
          const BagStatusConverter().fromJson(data.bagStatus),
          const ItemTypeConverter().fromJson(data.type),
        );

  /// The unique identifier for this item
  final String uid;

  /// The barcode for this item
  final String barcode;

  /// The unique identifier for the linked item
  final String linkedItemUid;

  /// The unique identifier for the last event
  final String lastEventUid;

  /// The unique identifier for the last event courier operative
  final String? lastEventCourierOperativeUid;

  /// The item type
  @ItemTypeConverter()
  @JsonKey(name: 'item_type')
  final ItemType? type;

  /// The last event time for the item
  @TimezoneConversion()
  final DateTime? lastEventTime;

  /// The bag status for the item
  @BagStatusConverter()
  final BagStatus? bagStatus;

  /// Item fromJson
  static ItemModel fromJson(Map<String, dynamic> json) =>
      _$ItemModelFromJson(json);

  /// Item toJson
  Map<String, dynamic> toJson() {
    final json = _$ItemModelToJson(this);
    return json;
  }

  /// Copy with
  ItemModel copyWith({
    String? uid,
    String? barcode,
    String? linkedItemUid,
    String? lastEventUid,
    String? lastEventCourierOperativeUid,
    DateTime? lastEventTime,
    BagStatus? bagStatus,
    ItemType? type,
  }) {
    return ItemModel(
      uid ?? this.uid,
      barcode ?? this.barcode,
      linkedItemUid ?? this.linkedItemUid,
      lastEventUid ?? this.lastEventUid,
      lastEventCourierOperativeUid ?? this.lastEventCourierOperativeUid,
      lastEventTime ?? this.lastEventTime,
      bagStatus ?? this.bagStatus,
      type ?? this.type,
    );
  }

  @override
  List<Object?> get props => [uid];

  /// The category for this item
  ItemCategory get category {
    if (type == ItemType.routeBag) {
      return bagStatus == BagStatus.full
          ? ItemCategory.fullBags
          : ItemCategory.emptyBags;
    } else {
      return ItemCategory.parcels;
    }
  }
}
