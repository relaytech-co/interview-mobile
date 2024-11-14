import 'package:flutter/material.dart';

extension TimeOfDayExtension on TimeOfDay {
  int compareTo(TimeOfDay other) {
    if (hour < other.hour) return -1;
    if (hour > other.hour) return 1;
    if (minute < other.minute) return -1;
    if (minute > other.minute) return 1;
    return 0;
  }

  bool isAfter(TimeOfDay other) {
    return compareTo(other) > 0;
  }

  bool isAtSameTime(TimeOfDay other) {
    return compareTo(other) == 0;
  }

  bool isBefore(TimeOfDay other) {
    return compareTo(other) < 0;
  }

  static TimeOfDay toTimeOfDay(DateTime dateTime) {
    return TimeOfDay(hour: dateTime.hour, minute: dateTime.minute);
  }

  // ignore: non_constant_identifier_names
  String HHmm() {
    return '${hour.toString().padLeft(2, '0')}:${minute.toString().padLeft(2, '0')}';
  }
}
