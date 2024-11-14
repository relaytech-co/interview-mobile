import 'dart:developer';
import 'dart:ui';

import 'package:json_annotation/json_annotation.dart';
import 'package:models/models.dart';

/// Converts [value] into a JSON serializable object.
Object? normalizeData(Object? value) {
  switch (value) {
    case Map():
      return value.map<String, dynamic>(
        (key, value) => MapEntry(key.toString(), normalizeData(value)),
      );
    case Iterable():
      return value.map(normalizeData).toList();
    case Locale():
      return value.toLanguageTag();
    case num():
      return value;
    case Enum():
      return value.name;
    case Uri():
      return value.toString();
    default:
      // unknown types must be normalized to json
      return value?.toString();
  }
}

class CoordinatesJsonConverter implements JsonConverter<Coordinates, List<dynamic>> {
  const CoordinatesJsonConverter();

  @override
  Coordinates fromJson(List<dynamic> json) {
    return (
      lat: (json[0] as num).toDouble(),
      lon: (json[1] as num).toDouble(),
    );
  }

  @override
  List<dynamic> toJson(Coordinates object) {
    return [object.lat, object.lon];
  }
}

class MinutesDurationConverter implements JsonConverter<Duration, int> {
  const MinutesDurationConverter();

  @override
  Duration fromJson(int json) {
    return Duration(minutes: json);
  }

  @override
  int toJson(Duration object) {
    return object.inMinutes;
  }
}

class TimezoneConversion implements JsonConverter<DateTime, DateTime> {
  const TimezoneConversion();

  @override
  DateTime fromJson(DateTime date) {
    return date;
  }

  @override
  DateTime toJson(DateTime object) {
    return object.toUtc();
  }
}

void printWrapped(String text) {
  final pattern = RegExp('.{1,800}');
  pattern.allMatches(text).forEach((match) => log(match.group(0)!));
}
