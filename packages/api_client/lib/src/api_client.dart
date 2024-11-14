// ignore_for_file: unused_field

import 'package:api_client/api_client.dart';
import 'package:api_client/src/interceptors/interceptors.dart';
import 'package:dio/dio.dart';

/// {@template api_client}
/// A Dart client for the HTTP API
/// {@endtemplate}
class ApiClient {
  /// {@macro api_client}
  ApiClient({
    required String apiUrl,
    required TokenProvider tokenProvider,
    Dio? httpClient,
    List<Interceptor>? interceptors,
  }) {
    _httpClient = httpClient ?? Dio();
    _apiUrl = apiUrl;
    _httpClient.interceptors.add(DefaultHeadersInterceptor());
    _httpClient.interceptors.add(LoggingInterceptor());

    // _httpClient.interceptors.add(FirebasePerformanceInterceptor());
    _httpClient.interceptors.add(TimeInterceptor());
    _httpClient.interceptors.add(AuthInterceptor(tokenProvider));
    _httpClient.interceptors.add(
      RefreshTokenInterceptor(apiUrl, tokenProvider),
    );

    if (interceptors != null && interceptors.isNotEmpty) {
      for (final interceptor in interceptors) {
        _httpClient.interceptors.add(interceptor);
      }
    }

    _prepareHttpClient();
  }

  void _prepareHttpClient() {
    final baseOptions = BaseOptions(
      baseUrl: _apiUrl,
      contentType: Headers.jsonContentType,
    );
    _httpClient.options = baseOptions;
  }

  late final String _apiUrl;

  late final Dio _httpClient;

  /// Resource exposing the endpoints responsible
  /// for fetching everything related to the logged user
  AccountResource get accountResource => AccountResource(
        _httpClient,
        baseUrl: _apiUrl,
      );

  /// Resource exposing the endpoints responsible
  /// for fetching everything related to the inventory
  InventoryResource get inventoryResource => InventoryResource(
        _httpClient,
        baseUrl: _apiUrl,
      );
}
