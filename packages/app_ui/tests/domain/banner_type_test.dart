import 'package:app_ui/src/domain/domain.dart';
import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';

void main() {
  group('BannerType', () {
    test('should have correct properties for warning type', () {
      expect(BannerType.warning.backgroundColor,
          const Color.fromARGB(255, 247, 204, 200));
      expect(BannerType.warning.foregroundColor, Colors.black);
      expect(BannerType.warning.borderColor,
          const Color.fromARGB(255, 247, 204, 200));
    });

    test('should have correct properties for error type', () {
      expect(BannerType.error.backgroundColor, const Color(0xFFFC5B51));
      expect(BannerType.error.foregroundColor, Colors.white);
      expect(BannerType.error.borderColor, const Color(0xFFFC5B51));
    });

    test('should have correct properties for info type', () {
      expect(BannerType.info.backgroundColor, const Color(0xFFD7F7FD));
      expect(BannerType.info.foregroundColor, Colors.black);
      expect(BannerType.info.borderColor, Colors.transparent);
    });

    test('should have correct properties for muted type', () {
      expect(BannerType.muted.backgroundColor, const Color(0xFF282828));
      expect(BannerType.muted.foregroundColor, Colors.white);
      expect(BannerType.muted.borderColor, Colors.transparent);
    });

    test('should have correct properties for success type', () {
      expect(BannerType.success.backgroundColor, const Color(0xFFF6FFD4));
      expect(BannerType.success.foregroundColor, Colors.black);
      expect(BannerType.success.borderColor, Colors.transparent);
    });

    test('should have correct properties for highlight1 type', () {
      expect(BannerType.highlight1.backgroundColor, const Color(0xFFD7F7FD));
      expect(BannerType.highlight1.foregroundColor, Colors.black);
      expect(BannerType.highlight1.borderColor, const Color(0xFFD7F7FD));
    });

    test('should have correct properties for highlight2 type', () {
      expect(BannerType.highlight2.backgroundColor, const Color(0xFFFFE2B7));
      expect(BannerType.highlight2.foregroundColor, Colors.black);
      expect(BannerType.highlight2.borderColor, const Color(0xFFFFE2B7));
    });
  });
}
