// ignore_for_file: public_member_api_docs

import 'dart:convert';

import 'package:api_client/api_client.dart';
import 'package:dio/dio.dart';
import 'package:logging/logging.dart';
import 'package:models/models.dart';

class RefreshTokenInterceptor extends Interceptor {
  RefreshTokenInterceptor(this.apiUrl, this.tokenProvider) {
    _tokenDio = Dio();
  }

  final _logger = Logger('Relay Network logs');
  late Dio? _tokenDio;

  final TokenProvider tokenProvider;
  final String apiUrl;

  @override
  Future<void> onError(DioException err, ErrorInterceptorHandler handler) async {
    if (err.response?.statusCode == 401) {
      final dio = (err.requestOptions.extra['dio'] as Dio?) ?? Dio();
      final options = err.requestOptions;

      try {
        final tokenResponse = await _refresh();
        if (tokenResponse == null) {
          return super.onError(err, handler);
        }
        final newOptions = options.copyWith(
          headers: {
            'Authorization': 'Bearer $tokenResponse',
          },
        );
        final newResponse = await dio.fetch<dynamic>(newOptions);
        return handler.resolve(newResponse);
      } catch (e) {
        return super.onError(err, handler);
      }
    } else {
      return super.onError(err, handler);
    }
  }

  Future<String?> _refresh() async {
    final authTokenRefreshUri = Uri.parse('$apiUrl/v0/copilot/auth/token/refresh');
    final tokens = await tokenProvider.read();
    final refreshToken = tokens?.refreshToken;
    final response = await _tokenDio!.post<dynamic>(
      authTokenRefreshUri.toString(),
      data: jsonEncode(
        {
          'refresh_token': refreshToken,
        },
      ),
    );
    if (response.statusCode == 200) {
      return _updateAccessTokens(response.toString());
    } else {
      _logger.fine('Forcing sign out');
      // ignore: flutter_style_todos
      // MAVI FIX SIGN OUT
      // await userNotifier.signOut();
      return null;
    }
  }

  Future<String> _updateAccessTokens(String response) async {
    final payload = json.decode(response) as Map<String, dynamic>;
    final accessToken = payload['access_token'].toString();
    final tokens = await tokenProvider.read();
    final refreshToken = tokens?.refreshToken;
    if (refreshToken != null) {
      await tokenProvider.write(
        AuthTokens(accessToken: accessToken, refreshToken: refreshToken),
      );
    }
    return accessToken;
  }
}
