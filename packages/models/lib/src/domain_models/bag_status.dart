import 'package:json_annotation/json_annotation.dart';

/// Enum for bag status
@JsonEnum(fieldRename: FieldRename.snake)
enum BagStatus {
  /// Empty
  empty('empty'),

  ///Full
  full('full'),

  /// Unknown
  unknown('unknown');

  /// Bag status constructor
  const BagStatus(this.name);

  ///Name of the bag status
  final String name;
}

/// Bag status converter
class BagStatusConverter implements JsonConverter<BagStatus, String> {
  /// Bag status converter constructor
  const BagStatusConverter();

  @override
  BagStatus fromJson(String? json) {
    if (json == null) return BagStatus.unknown;
    return BagStatus.values.firstWhere(
      (element) => element.name == json,
      orElse: () => BagStatus.unknown,
    );
  }

  @override
  String toJson(BagStatus state) {
    return state.name;
  }
}
