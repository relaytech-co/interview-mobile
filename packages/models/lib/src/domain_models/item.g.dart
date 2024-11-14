// GENERATED CODE - DO NOT MODIFY BY HAND

// ignore_for_file: implicit_dynamic_parameter, cast_nullable_to_non_nullable, always_use_package_imports

part of 'item.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

ItemModel _$ItemModelFromJson(Map<String, dynamic> json) => $checkedCreate(
      'ItemModel',
      json,
      ($checkedConvert) {
        final val = ItemModel(
          $checkedConvert('uid', (v) => v as String),
          $checkedConvert('barcode', (v) => v as String),
          $checkedConvert('linked_item_uid', (v) => v as String),
          $checkedConvert('last_event_uid', (v) => v as String),
          $checkedConvert(
              'last_event_courier_operative_uid', (v) => v as String?),
          $checkedConvert(
              'last_event_time',
              (v) => _$JsonConverterFromJson<String, DateTime>(
                  v, const TimezoneConversion().fromJson)),
          $checkedConvert(
              'bag_status',
              (v) => _$JsonConverterFromJson<String, BagStatus>(
                  v, const BagStatusConverter().fromJson)),
          $checkedConvert(
              'item_type',
              (v) => _$JsonConverterFromJson<String, ItemType>(
                  v, const ItemTypeConverter().fromJson)),
        );
        return val;
      },
      fieldKeyMap: const {
        'linkedItemUid': 'linked_item_uid',
        'lastEventUid': 'last_event_uid',
        'lastEventCourierOperativeUid': 'last_event_courier_operative_uid',
        'lastEventTime': 'last_event_time',
        'bagStatus': 'bag_status',
        'type': 'item_type'
      },
    );

Map<String, dynamic> _$ItemModelToJson(ItemModel instance) => <String, dynamic>{
      'uid': instance.uid,
      'barcode': instance.barcode,
      'linked_item_uid': instance.linkedItemUid,
      'last_event_uid': instance.lastEventUid,
      'last_event_courier_operative_uid': instance.lastEventCourierOperativeUid,
      'item_type': _$JsonConverterToJson<String, ItemType>(
          instance.type, const ItemTypeConverter().toJson),
      'last_event_time': _$JsonConverterToJson<String, DateTime>(
          instance.lastEventTime, const TimezoneConversion().toJson),
      'bag_status': _$JsonConverterToJson<String, BagStatus>(
          instance.bagStatus, const BagStatusConverter().toJson),
    };

Value? _$JsonConverterFromJson<Json, Value>(
  Object? json,
  Value? Function(Json json) fromJson,
) =>
    json == null ? null : fromJson(json as Json);

Json? _$JsonConverterToJson<Json, Value>(
  Value? value,
  Json? Function(Value value) toJson,
) =>
    value == null ? null : toJson(value);
