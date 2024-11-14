import 'package:dio/dio.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:relay_interview/src/authentication/data/auth_repository.dart';

class UnauthorizedRequestInterceptor extends Interceptor {
  UnauthorizedRequestInterceptor(this.ref);
  final Ref ref;

  @override
  Future<void> onError(
    DioException err,
    ErrorInterceptorHandler handler,
  ) async {
    if (err.response?.statusCode == 401 || err.response?.statusCode == 403) {
      ref.read(authenticationClientProvider).logOut();
    }
    return handler.reject(err);
  }
}
