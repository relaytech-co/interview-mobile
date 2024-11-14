import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'dart:math' as math;

class RCalendarIcon extends StatelessWidget {
  const RCalendarIcon({
    required this.date,
    this.size = 40,
  });

  final DateTime date;
  final double size;

  @override
  Widget build(BuildContext context) {
    final double size = 40;
    return Transform.rotate(
        angle: 3 * math.pi / 180,
        child: ClipRRect(
            borderRadius: BorderRadius.circular(5),
            child: Column(
              children: [
                Container(
                  color: Colors.red,
                  height: size / 2.5,
                  width: size,
                  child: Center(
                      child: Text(DateFormat('MMM').format(date).toUpperCase(),
                          style: Theme.of(context).textTheme.bodyMedium?.copyWith(
                              color: Colors.white,
                              fontWeight: FontWeight.bold,
                              fontSize: 12))),
                ),
                Container(
                  color: Color(0xFFF4F3FB),
                  height: (size / 3) * 2,
                  width: size,
                  child: Center(
                      child: Text(DateFormat('dd').format(date).toUpperCase(),
                          style: Theme.of(context).textTheme.bodyMedium?.copyWith(
                              color: Colors.black,
                              fontWeight: FontWeight.bold,
                              fontSize: 20))),
                )
              ],
            )));
  }
}
