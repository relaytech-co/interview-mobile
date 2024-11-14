// ignore_for_file: public_member_api_docs

import 'package:dio/dio.dart';
import 'package:utils/utils.dart';

class TimeInterceptor extends Interceptor {
  @override
  // ignore: strict_raw_type
  void onResponse(Response response, ResponseInterceptorHandler handler) {
    DateTimeServer().setTime(response.headers['relay_server_time']?.first);
    super.onResponse(response, handler);
  }
}
