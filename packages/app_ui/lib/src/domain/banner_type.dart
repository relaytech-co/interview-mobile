import 'package:flutter/material.dart';

///Information banner type
enum BannerType {
  ///Banner type for warning
  warning(
    backgroundColor: Color.fromARGB(255, 247, 204, 200),
    foregroundColor: Colors.black,
    borderColor: Color.fromARGB(255, 247, 204, 200),
  ),

  ///Banner type for error
  error(
    backgroundColor: Color(0xFFFC5B51),
    foregroundColor: Colors.white,
    borderColor: Color(0xFFFC5B51),
  ),

  ///Banner type for info
  info(
    backgroundColor: Color(0xFFD7F7FD),
    foregroundColor: Colors.black,
    borderColor: Colors.transparent,
  ),

  ///Banner type for muted
  muted(
    backgroundColor: Color(0xFF282828),
    foregroundColor: Colors.white,
    borderColor: Colors.transparent,
  ),

  ///Banner type for success
  success(
    backgroundColor: Color(0xFFF6FFD4),
    foregroundColor: Colors.black,
    borderColor: Colors.transparent,
  ),

  ///BannerType constructor
  highlight1(
    backgroundColor: Color(0xFFD7F7FD),
    foregroundColor: Colors.black,
    borderColor: Color(0xFFD7F7FD),
  ),

  ///BannerType constructor
  highlight2(
    backgroundColor: Color(0xFFFFE2B7),
    foregroundColor: Colors.black,
    borderColor: Color(0xFFFFE2B7),
  );

  const BannerType({
    required this.backgroundColor,
    required this.foregroundColor,
    required this.borderColor,
  });

  ///Banner backgroundColor
  final Color backgroundColor;

  ///Banner foregroundColor
  final Color foregroundColor;

  ///Banner borderColor
  final Color borderColor;
}
