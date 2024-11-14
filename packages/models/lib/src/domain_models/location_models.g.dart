// GENERATED CODE - DO NOT MODIFY BY HAND

// ignore_for_file: implicit_dynamic_parameter, cast_nullable_to_non_nullable, always_use_package_imports

part of 'location_models.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

LocationModel _$LocationModelFromJson(Map<String, dynamic> json) =>
    $checkedCreate(
      'LocationModel',
      json,
      ($checkedConvert) {
        final val = LocationModel(
          $checkedConvert('lat', (v) => (v as num).toDouble()),
          $checkedConvert('lon', (v) => (v as num).toDouble()),
          $checkedConvert('location_accuracy_m', (v) => v as int?),
          timestamp: $checkedConvert('timestamp',
              (v) => v == null ? null : DateTime.parse(v as String)),
        );
        return val;
      },
      fieldKeyMap: const {'accuracy': 'location_accuracy_m'},
    );

Map<String, dynamic> _$LocationModelToJson(LocationModel instance) =>
    <String, dynamic>{
      'lat': instance.lat,
      'lon': instance.lon,
      'location_accuracy_m': instance.accuracy,
      'timestamp': instance.timestamp?.toIso8601String(),
    };
