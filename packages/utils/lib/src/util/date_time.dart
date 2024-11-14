import 'package:intl/intl.dart';

/// Extension to make displaying [DateTime] objects simpler.
extension DateTimeEx on DateTime {
  /// Converts [DateTime] into a d.M.yy h:mm a [String].
  String get dMyyhmma {
    final formatter = DateFormat('M.d.yy h:mm a');
    return formatter.format(this);
  }

  /// Converts [DateTime] into a d.M.yy [String].
  String get dMyy {
    final formatter = DateFormat('M.d.yy');
    return formatter.format(this);
  }

  /// Converts [DateTime] into a h:mm a [String].
  String get hmma {
    final formatter = DateFormat('h:mm a');
    return formatter.format(this);
  }

  /// Converts [DateTime] into a HH:mm [String].
  String get HHmm {
    final formatter = DateFormat('HH:mm');
    return formatter.format(this);
  }

  /// Converts [DateTime] into a MMMM dd, yyyy [String] March 04, 2024.
  String get mmmmddyyyy {
    final formatter = DateFormat('MMMM dd, yyyy');
    return formatter.format(this);
  }

  /// Converts [DateTime] into a EEEE dd MMMM [String] Thursday 25th January.
  String get eeeeddmmmm {
    final suffix = _getDaySuffix(day);
    final firstFormatter = DateFormat('EEEE dd');
    final monthFormatter = DateFormat('MMMM');
    return '${firstFormatter.format(this)}$suffix ${monthFormatter.format(this)}';
  }

  String get eeeddmmmmAndToday {
    if (isToday()) {
      return 'Today';
    } else if (isTomorrow()) {
      return 'Tomorrow';
    } else {
      final suffix = _getDaySuffix(day);
      final firstFormatter = DateFormat('EEE d');
      final monthFormatter = DateFormat('MMMM');
      return '${firstFormatter.format(this)}$suffix ${monthFormatter.format(this)}';
    }
  }

  /// Converts [DateTime] into a EEEE dd MMMM [String] Thursday 25th January.
  String get mmmmdd {
    final suffix = _getDaySuffix(day);
    final firstFormatter = DateFormat('dd');
    final monthFormatter = DateFormat('MMMM');
    return '${monthFormatter.format(this)} ${firstFormatter.format(this)}$suffix';
  }

  String get dd {
    final suffix = _getDaySuffix(day);
    final firstFormatter = DateFormat('dd');
    return '${firstFormatter.format(this)}$suffix.';
  }

  String _getDaySuffix(int day) {
    if (day >= 11 && day <= 13) {
      return 'th';
    }
    switch (day % 10) {
      case 1:
        return 'st';
      case 2:
        return 'nd';
      case 3:
        return 'rd';
      default:
        return 'th';
    }
  }

  bool isToday() {
    final now = DateTime.now();
    return now.day == day && now.month == month && now.year == year;
  }

  DateTime copyWithoutTime() {
    return DateTime(year, month, day);
  }

  bool isYesterday() {
    final yesterday = DateTime.now().subtract(const Duration(days: 1));
    return yesterday.day == day && yesterday.month == month && yesterday.year == year;
  }

  bool isTomorrow() {
    final yesterday = DateTime.now().add(const Duration(days: 1));
    return yesterday.day == day && yesterday.month == month && yesterday.year == year;
  }

  bool isSunday() {
    return weekday == 7;
  }

  DateTime nextDay(int day) {
    var date = this;
    while (date.weekday != day) {
      date = date.add(const Duration(days: 1));
    }
    return date;
  }

  String toDayString({bool showTomorrow = false}) {
    if (isToday()) {
      return 'Today';
    } else if (isYesterday()) {
      return 'Yesterday';
    } else if (isTomorrow() && showTomorrow) {
      return 'Tomorrow';
    } else {
      return DateFormat('MMM d, yyyy').format(this);
    }
  }

  DateTime roundDown({Duration delta = const Duration(minutes: 10)}) {
    return DateTime.fromMillisecondsSinceEpoch(
        millisecondsSinceEpoch - millisecondsSinceEpoch % delta.inMilliseconds);
  }

  DateTime nearestQuarter() {
    if (minute <= 7) {
      final quarter = DateTime(year, month, day, hour, 0);
      if (quarter.isAfter(DateTime.now())) {
        return quarter;
      } else {
        return DateTime.now();
      }
    } else if (minute >= 8 && minute <= 22) {
      final quarter = DateTime(year, month, day, hour, 15);
      if (quarter.isAfter(DateTime.now())) {
        return quarter;
      } else {
        return DateTime.now();
      }
    } else if (minute >= 23 && minute <= 37) {
      final quarter = DateTime(year, month, day, hour, 30);
      if (quarter.isAfter(DateTime.now())) {
        return quarter;
      } else {
        return DateTime.now();
      }
    } else if (minute >= 38 && minute <= 52) {
      final quarter = DateTime(year, month, day, hour, 45);
      if (quarter.isAfter(DateTime.now())) {
        return quarter;
      } else {
        return DateTime.now();
      }
    } else {
      final quarter = DateTime(year, month, day, hour + 1, 0);
      if (quarter.isAfter(DateTime.now())) {
        return quarter;
      } else {
        return DateTime.now();
      }
    }
  }

  DateTime calculateNearestQuarterAfter() {
    // Calculate the nearest quarter after the given time

    int remainder = minute % 15;
    int minutesToNextQuarter = remainder > 0 ? 15 - remainder : 0;

    // If the current time is exactly on a quarter, add 15 minutes to go to the next quarter
    //  minutesToNextQuarter += (remainder == 0) ? 15 : 0;

    // Create a new DateTime object with the rounded time
    DateTime roundedDateTime = add(Duration(minutes: minutesToNextQuarter));

    // Reset seconds and milliseconds to zero
    roundedDateTime = DateTime(
      roundedDateTime.year,
      roundedDateTime.month,
      roundedDateTime.day,
      roundedDateTime.hour,
      roundedDateTime.minute,
    );

    return roundedDateTime;
  }

  DateTime nearestTen() {
    if (minute <= 5) {
      return DateTime(year, month, day, hour, 0);
    } else if (minute >= 6 && minute <= 15) {
      return DateTime(year, month, day, hour, 10);
    } else if (minute >= 16 && minute <= 25) {
      return DateTime(year, month, day, hour, 20);
    } else if (minute >= 26 && minute <= 35) {
      return DateTime(year, month, day, hour, 30);
    } else if (minute >= 36 && minute <= 45) {
      return DateTime(year, month, day, hour, 40);
    } else if (minute >= 46 && minute <= 55) {
      return DateTime(year, month, day, hour, 50);
    } else {
      return DateTime(year, month, day, hour + 1, 0);
    }
  }

  int totalDaysInMonth() {
    var firstDayThisMonth = DateTime(year, month, 1);
    var firstDayNextMonth =
        DateTime(firstDayThisMonth.year, firstDayThisMonth.month + 1, firstDayThisMonth.day);
    return firstDayNextMonth.difference(firstDayThisMonth).inDays;
  }

  bool isSameDay(DateTime a) {
    return a.year == year && a.month == month && a.day == day;
  }

  int daysBetween(DateTime to) {
    final from = DateTime(year, month, day);
    to = DateTime(to.year, to.month, to.day);
    return (to.difference(from).inHours / 24).round();
  }
}

String getDayOfWeek(int dayNumber) {
  if (dayNumber < 1 || dayNumber > 7) {
    throw ArgumentError('Invalid day number. It should be between 1 and 7.');
  }

  DateTime date = DateTime.now().subtract(Duration(days: DateTime.now().weekday - dayNumber));

  return DateFormat('EEEE').format(date);
}
