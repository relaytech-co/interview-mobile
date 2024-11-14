// ignore_for_file: public_member_api_docs

import 'dart:io';

import 'package:api_client/api_client.dart';
import 'package:dio/dio.dart';

class AuthInterceptor extends Interceptor {
  AuthInterceptor(this.tokenProvider);

  final TokenProvider? tokenProvider;

  @override
  Future<void> onRequest(
    RequestOptions options,
    RequestInterceptorHandler handler,
  ) async {
    final authTokens = await tokenProvider?.read();

    final token = authTokens?.accessToken;

    if (token != null) {
      options.headers[HttpHeaders.authorizationHeader] = 'Bearer $token';
    }
    super.onRequest(options, handler);
  }
}
