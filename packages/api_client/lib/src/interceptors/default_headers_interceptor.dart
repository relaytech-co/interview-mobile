// ignore_for_file: public_member_api_docs

import 'dart:io';

import 'package:dio/dio.dart';
import 'package:package_info_plus/package_info_plus.dart';

class DefaultHeadersInterceptor extends Interceptor {
  @override
  Future<void> onRequest(
    RequestOptions options,
    RequestInterceptorHandler handler,
  ) async {
    final appVersion = (await PackageInfo.fromPlatform()).version;
    options.headers[HttpHeaders.contentTypeHeader] = 'application/json';
    options.headers[HttpHeaders.acceptEncodingHeader] = 'gzip';
    options.headers['COPILOT_OS_PLATFORM'] = Platform.operatingSystem;
    options.headers['COPILOT_OS_VERSION'] = Platform.operatingSystemVersion;
    options.headers['COPILOT_APP_VERSION'] = appVersion;

    super.onRequest(options, handler);
  }
}
