// ignore_for_file: public_member_api_docs

import 'package:dio/dio.dart';
// import 'package:firebase_crashlytics/firebase_crashlytics.dart';
import 'package:logging/logging.dart';
import 'package:user_tracing/trace.dart';

class LoggingInterceptor extends Interceptor {
  final _logger = Logger('Relay Network logs');

  @override
  void onRequest(RequestOptions options, RequestInterceptorHandler handler) {
    _logger.fine('Request[${options.method}] => PATH: ${options.path}');
    super.onRequest(options, handler);
  }

  @override
  void onResponse(
    Response<dynamic> response,
    ResponseInterceptorHandler handler,
  ) {
    _logger
      ..fine('Response[${response.statusCode}] => PATH: '
          '${response.requestOptions.path}')
      ..fine('Response[${response.data}]');

    // trace log the response
    Trace.log(
      'api_request',
      traceProps: {
        'method': response.requestOptions.method,
        'endpoint': response.requestOptions.uri.path,
        'request_data': response.requestOptions.data,
        'response_code': response.statusCode,
        // cap the response body logged at 100 characters max
        'response_body': response.data.toString().substring(
              0,
              response.data.toString().length.clamp(0, 100),
            ),
      },
    );
    super.onResponse(response, handler);
  }

  @override
  void onError(DioException err, ErrorInterceptorHandler handler) {
    _logger.fine(
      'Error[${err.response?.statusCode}] => PATH: ${err.requestOptions.path}',
    );
    // FirebaseCrashlytics.instance.recordError(err, err.stackTrace);
    super.onError(err, handler);
  }
}
