// ignore_for_file: public_member_api_docs, lines_longer_than_80_chars

import 'package:dio/dio.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:relay_interview/src/authentication/presentation/authentication_controller.dart';

class UnauthorizedRequestInterceptor extends Interceptor {
  UnauthorizedRequestInterceptor(this.ref);
  final Ref ref;

  @override
  Future<void> onError(
    DioException err,
    ErrorInterceptorHandler handler,
  ) async {
    if (err.response?.statusCode == 401 || err.response?.statusCode == 403) {
      ref.read(authenticationControllerProvider.notifier).logout();
    }
    return handler.reject(err);
  }
}
