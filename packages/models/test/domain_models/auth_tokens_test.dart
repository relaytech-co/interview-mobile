import 'package:flutter_test/flutter_test.dart';
import 'package:models/models.dart';

void main() {
  group('AuthTokens', () {
    const accessToken = 'testAccessToken';
    const refreshToken = 'testRefreshToken';

    test(
        'copyWith should return the same instance if no new values are provided',
        () {
      const tokens =
          AuthTokens(accessToken: accessToken, refreshToken: refreshToken);
      final copiedTokens = tokens.copyWith();
      expect(copiedTokens.accessToken, tokens.accessToken);
      expect(copiedTokens.refreshToken, tokens.refreshToken);
    });

    test('props should contain correct values', () {
      const tokens =
          AuthTokens(accessToken: accessToken, refreshToken: refreshToken);
      expect(tokens.props, [accessToken, refreshToken]);
    });

    test('should support value equality', () {
      const tokens1 =
          AuthTokens(accessToken: accessToken, refreshToken: refreshToken);
      const tokens2 =
          AuthTokens(accessToken: accessToken, refreshToken: refreshToken);
      const tokens3 = AuthTokens(
          accessToken: 'differentAccessToken', refreshToken: refreshToken);

      expect(tokens1, equals(tokens2)); // Should be equal
      expect(tokens1, isNot(equals(tokens3))); // Should not be equal
    });

    test('should support value equality', () {
      expect(
        const AuthTokens(accessToken: accessToken, refreshToken: refreshToken),
        const AuthTokens(accessToken: accessToken, refreshToken: refreshToken),
      );
    });

    test('fromJson should return a valid instance', () {
      final json = {
        'access_token': accessToken,
        'refresh_token': refreshToken,
      };
      expect(AuthTokens.fromJson(json), isA<AuthTokens>());
    });

    test('toJson should return a valid map', () {
      const tokens =
          AuthTokens(accessToken: accessToken, refreshToken: refreshToken);
      final json = tokens.toJson();
      expect(json['access_token'], accessToken);
      expect(json['refresh_token'], refreshToken);
    });

    test('copyWith should return a valid instance with updated fields', () {
      const tokens =
          AuthTokens(accessToken: accessToken, refreshToken: refreshToken);
      final updatedTokens = tokens.copyWith(accessToken: 'newAccessToken');
      expect(updatedTokens.accessToken, 'newAccessToken');
      expect(updatedTokens.refreshToken, refreshToken);
    });
  });
}
