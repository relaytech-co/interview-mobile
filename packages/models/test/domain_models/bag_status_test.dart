import 'package:flutter_test/flutter_test.dart';
import 'package:models/src/models.dart';

void main() {
  group('BagStatus', () {
    test('should convert BagStatus to JSON string', () {
      expect(const BagStatusConverter().toJson(BagStatus.empty), 'empty');
      expect(const BagStatusConverter().toJson(BagStatus.full), 'full');
      expect(const BagStatusConverter().toJson(BagStatus.unknown), 'unknown');
    });

    test('should convert JSON string to BagStatus', () {
      expect(const BagStatusConverter().fromJson('empty'), BagStatus.empty);
      expect(const BagStatusConverter().fromJson('full'), BagStatus.full);
      expect(const BagStatusConverter().fromJson('unknown'), BagStatus.unknown);
      expect(const BagStatusConverter().fromJson('non_existent'),
          BagStatus.unknown);
      expect(const BagStatusConverter().fromJson(null), BagStatus.unknown);
    });
  });
}
