import 'package:flutter_test/flutter_test.dart';
import 'package:utils/utils.dart';

void main() {
  group('TitleCase Extension Tests', () {
    test('Test toTitleCase method with regular string', () {
      final input = 'KING STREET LONDON';
      final expectedOutput = 'King Street London';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method containing digits', () {
      final input = '124 KING STREET LONDON';
      final expectedOutput = '124 King Street London';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method containing emojis', () {
      final input = 'Mavi 🎀 MARTINEZ';
      final expectedOutput = 'Mavi 🎀 Martinez';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method containing chinese characters', () {
      final input = '汉字';
      final expectedOutput = '汉字';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method containing chinese characters 2', () {
      final input = '汉字 汉字';
      final expectedOutput = '汉字 汉字';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method containing chinese characters 3', () {
      final input = '汉字 a 汉字';
      final expectedOutput = '汉字 A 汉字';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method with string containing digits (post code)', () {
      final input = 'WC62 5JG';
      final expectedOutput = 'WC62 5JG';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method with string containing special characters', () {
      final input = '!hello world@';
      final expectedOutput = '!Hello World@';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method with string containing only one character', () {
      final input = '71 | Warrington Road';
      final expectedOutput = '71 | Warrington Road';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test toTitleCase method with empty string', () {
      final input = '';
      final expectedOutput = '';

      final result = input.toTitleCase();

      expect(result, expectedOutput);
    });

    test('Test containsDigits method with string containing digits', () {
      final input = 'hello123world';

      final result = input.containsDigits(input);

      expect(result, true);
    });

    test('Test containsDigits method with string not containing digits', () {
      final input = 'helloworld';

      final result = input.containsDigits(input);

      expect(result, false);
    });
  });
}
