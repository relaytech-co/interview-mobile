// ignore_for_file: public_member_api_docs

import 'dart:developer';
import 'dart:typed_data';
import 'dart:ui';

import 'package:flutter/material.dart';
import 'package:json_annotation/json_annotation.dart';
import 'package:models/models.dart';
import 'package:models/utils/calendar_timezones.dart';
import 'package:utils/utils.dart';

class CoordinatesJsonConverter
    implements JsonConverter<Coordinates, List<dynamic>> {
  const CoordinatesJsonConverter();

  @override
  Coordinates fromJson(List<dynamic>? json) {
    if (json?.isEmpty == true || json == null) {
      return (lat: 0, lon: 0);
    }
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

class CoordinatesListJsonConverter
    implements JsonConverter<List<Coordinates>, List<dynamic>> {
  const CoordinatesListJsonConverter();

  @override
  List<Coordinates> fromJson(List<dynamic> json) {
    return json
        .map(
          (e) => (
            lat: ((e as List<dynamic>)[0] as num).toDouble(),
            lon: (e[1] as num).toDouble(),
          ),
        )
        .toList();
  }

  @override
  List<dynamic> toJson(List<Coordinates> object) {
    return object.map((e) => [e.lat, e.lon]).toList();
  }
}

class PolygonCoordinatesListJsonConverter
    implements JsonConverter<List<Coordinates>, List<dynamic>> {
  const PolygonCoordinatesListJsonConverter();

  @override
  List<Coordinates> fromJson(List<dynamic>? json) {
    if (json == null) {
      return [];
    }
    return json
        .map(
          (e) => (
            lat: ((e as List<dynamic>)[1] as num).toDouble(),
            lon: (e[0] as num).toDouble(),
          ),
        )
        .toList();
  }

  @override
  List<dynamic> toJson(List<Coordinates> object) {
    return object.map((e) => [e.lat, e.lon]).toList();
  }
}

class PolylineConverter implements JsonConverter<List<Coordinates>, String?> {
  const PolylineConverter();

  @override
  List<Coordinates> fromJson(String? encoded) {
    if (encoded == null || encoded.isEmpty) {
      return [];
    }
    final poly = <Coordinates>[];
    var index = 0, len = encoded.length;
    var lat = 0, lng = 0;

    while (index < len) {
      int b, shift = 0, result = 0;
      do {
        b = encoded.codeUnitAt(index++) - 63;
        result |= (b & 0x1f) << shift;
        shift += 5;
      } while (b >= 0x20);
      final dlat = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));
      lat += dlat;

      shift = 0;
      result = 0;
      do {
        b = encoded.codeUnitAt(index++) - 63;
        result |= (b & 0x1f) << shift;
        shift += 5;
      } while (b >= 0x20);
      final dlng = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));
      lng += dlng;
      final p = (
        lat: lat / 1E5,
        lon: lng / 1E5,
      );

      poly.add(p);
    }
    return poly;
  }

  @override
  String toJson(List<Coordinates> object) {
    return object.map((e) => [e.lat, e.lon]).toList().toString();
  }
}

class CalendarTimezoneConverter {
  String getCalendarTimezone(int timezoneOffsetInMinutes) {
    for (final tz in calendarTimezones) {
      final utcDifferenceInMinutes =
          parseStringToMinutes(tz['utc_difference'] ?? '0');
      if (utcDifferenceInMinutes == timezoneOffsetInMinutes) {
        return tz['name'] ?? 'GMT Standard Time';
      }
    }
    return 'GMT Standard Time';
  }

  int parseStringToMinutes(String timezone) {
    if (timezone == '0') {
      return 0;
    } else {
      final hours = int.parse(timezone.substring(0, 3));
      final minutes = int.parse(timezone.substring(4, 6));
      return hours * 60 + minutes;
    }
  }
}

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

class TimezoneConversion implements JsonConverter<DateTime, String> {
  const TimezoneConversion();

  @override
  DateTime fromJson(String? date) {
    return DateTime.parse(date ?? DateTimeServer().utcnow().toString())
        .toLocal();
  }

  @override
  String toJson(DateTime object) {
    return object.toIso8601String();
  }
}

class TimeOfDayConversion implements JsonConverter<DateTime, String> {
  const TimeOfDayConversion();

  @override
  DateTime fromJson(String? date) {
    if (date != null) {
      if (DateTime.tryParse(date) != null) {
        final aux = DateTime.parse(date).toLocal();
        return aux;
      }
      final parts = date.split(':');
      final hours = int.parse(parts[0]);
      final minutes = int.parse(parts[1]);
      final seconds = int.parse(parts[2]);
      final ret = DateTimeServer()
          .utcnow()
          .copyWith(
            hour: hours,
            minute: minutes,
            second: seconds,
          )
          .toLocal();
      return ret;
    } else {
      return DateTime.now().copyWith(hour: 10, minute: 0);
    }
  }

  @override
  String toJson(DateTime object) {
    return object.toIso8601String();
  }
}

void printWrapped(String text) {
  final pattern = RegExp('.{1,800}');
  pattern.allMatches(text).forEach((match) => log(match.group(0)!));
}

// https://stackoverflow.com/questions/63716036/how-to-serialize-uint8list-to-json-with-json-annotation-in-dart
class Uint8ListConverter implements JsonConverter<Uint8List, List<dynamic>> {
  const Uint8ListConverter();

  @override
  Uint8List fromJson(List<dynamic> json) {
    return Uint8List.fromList(json.map((e) => e as int).toList());
  }

  @override
  List<dynamic> toJson(Uint8List object) {
    return object.toList();
  }
}

class TitleCaseConverter implements JsonConverter<String, String> {
  const TitleCaseConverter();

  @override
  String fromJson(String json) {
    return json.toTitleCase();
  }

  /// Not really needed, but it's here for consistency, backend always returns
  /// uppercase
  @override
  String toJson(String object) {
    return object.toUpperCase();
  }
}
