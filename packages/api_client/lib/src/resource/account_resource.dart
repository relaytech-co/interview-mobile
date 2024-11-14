// ignore_for_file: public_member_api_docs

import 'dart:io';

import 'package:dio/dio.dart';
import 'package:models/models.dart';
import 'package:retrofit/retrofit.dart';

part 'account_resource.g.dart';

/// Exception thrown when the user is not authenticated
class HttpAuthenticationException implements Exception {}

/// Exception thrown when connection failsb
class HttpConnectionException implements Exception {}

/// {@template validation_failed_exception}
/// Exception thrown when the user could not be registered
/// {@endtemplate}
class ValidationFailedException implements HttpException {
  /// {@macro validation_failed_exception}
  ValidationFailedException(this.message, {this.uri});

  @override
  final String message;

  @override
  final Uri? uri;
}

@RestApi()
abstract class AccountResource {
  factory AccountResource(
    Dio dio, {
    required String baseUrl,
  }) = _AccountResource;

  @POST('/v0/pitstop-network/qr-code-auth')
  Future<LoginWithQrResponse> login(@Body() Map<String, dynamic> map);

  @GET('/v0/pitstop-network/')
  Future<User> fetchProfile();
}
