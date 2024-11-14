// ignore_for_file: public_member_api_docs
// ignore_for_file: prefer_final_locals

import 'package:equatable/equatable.dart';
import 'package:json_annotation/json_annotation.dart';

part 'location_models.g.dart';

typedef Coordinates = ({double lat, double lon});

@JsonSerializable(createToJson: true)
class LocationModel extends Equatable {
  const LocationModel(
    this.lat,
    this.lon,
    this.accuracy, {
    required this.timestamp,
  });

  final double lat, lon;

  /// estimated horizontal accuracy of this location, radial, in meters
  @JsonKey(name: 'location_accuracy_m')
  final int? accuracy;

  List<double> get laglng => [lat, lon];

  final DateTime? timestamp;

  static LocationModel fromJson(Map<String, dynamic> json) =>
      _$LocationModelFromJson(json);

  Map<String, dynamic> toJson() {
    var json = _$LocationModelToJson(this);
    json['location_latlon'] = laglng;
    json['location_accuracy_m'] = accuracy ?? 0;
    return json;
  }

  @override
  List<Object?> get props => [lat, lon, accuracy, timestamp, laglng];
}
