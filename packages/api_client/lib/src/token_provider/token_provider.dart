import 'dart:convert';
import 'dart:io';

import 'package:dio/dio.dart';
import 'package:models/models.dart';
import 'package:storage_client/storage_client.dart';

const _refreshEndpoint = '/session/refresh';

/// {@template token_provider}
/// Provides an abstraction for API access token retrieval
/// {@endtemplate}
class TokenProvider {
  /// {@macro token_provider}
  ///
  /// Provide [StorageClient], preferably SecureStorage
  /// for persisting the token.
  /// Provide [Dio] as http client to execute the
  /// refresh token request.
  TokenProvider(
    this._storage, [
    Dio? httpClient,
  ]) : _httpClient = httpClient ?? Dio();

  static const _tokenKey = 'token';
  final StorageClient _storage;
  final Dio _httpClient;

  /// Deletes the token from the [StorageClient]
  Future<void> delete() async {
    await _storage.delete(
      key: _tokenKey,
    );
  }

  /// Fetches the current access token available in the session.
  Future<AuthTokens?> read() async {
    final token = await _storage.read(key: _tokenKey);
    if (token == null) {
      return null;
    }
    return AuthTokens.fromJson(jsonDecode(token) as Map<String, dynamic>);
  }

  /// Saves the token to [StorageClient]
  Future<void> write(AuthTokens token) async {
    await _storage.write(
      key: _tokenKey,
      value: jsonEncode(token.toJson()),
    );
  }

  /// Executes the refresh token request via the API
  ///
  /// Throws [MissingTokenException] if previous token
  /// is not present in the [StorageClient].
  Future<AuthTokens> refreshToken(String apiUrl) async {
    final token = await read();
    if (token == null) {
      throw MissingTokenException();
    }

    final baseOptions = BaseOptions(
      baseUrl: apiUrl,
      contentType: Headers.formUrlEncodedContentType,
      headers: <String, String>{
        'Accept': 'application/json',
        'Authorization': 'Bearer ${token.accessToken}',
      },
    );

    _httpClient.options = baseOptions;
    // ignore: inference_failure_on_function_invocation
    final response = await _httpClient.post(
      _refreshEndpoint,
      data: <String, dynamic>{
        'refresh_token': token.refreshToken,
      },
    );
    if (response.statusCode == HttpStatus.ok && response.data != null) {
      final token = AuthTokens.fromJson(
        Map<String, dynamic>.from(response.data! as Map<String, dynamic>),
      );
      await write(token);
      return token;
    }
    throw DioException(
      error: 'HTTP status code is invalid: '
          '${response.statusCode} ${response.statusMessage}',
      requestOptions: response.requestOptions,
    );
  }
}

/// Exception thrown when token is not available
class MissingTokenException implements Exception {}
