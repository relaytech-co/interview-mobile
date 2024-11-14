// // ignore_for_file: public_member_api_docs, lines_longer_than_80_chars

// import 'package:api_client/src/network_utils.dart';
// import 'package:dio/dio.dart';
// import 'package:firebase_performance/firebase_performance.dart';

// class FirebasePerformanceInterceptor extends Interceptor {
//   @override
//   Future<void> onRequest(
//     RequestOptions options,
//     RequestInterceptorHandler handler,
//   ) async {
//     final httpMetric = FirebasePerformance.instance.newHttpMetric(
//       options.uri.toString(),
//       httpMethodFromString(
//         options.method,
//       ),
//     );

//     await httpMetric.start();

//     options.extra['httpMetric'] = httpMetric;

//     return super.onRequest(options, handler);
//   }

//   @override
//   Future<void> onResponse(
//     Response<dynamic> response,
//     ResponseInterceptorHandler handler,
//   ) async {
//     final httpMetric = (response.requestOptions.extra['httpMetric'] as HttpMetric)
//       ..httpResponseCode = response.statusCode ?? 0;
//     await httpMetric.stop();

//     return super.onResponse(response, handler);
//   }

//   @override
//   Future<void> onError(
//     DioException err,
//     ErrorInterceptorHandler handler,
//   ) async {
//     final httpMetric = (err.requestOptions.extra['httpMetric'] as HttpMetric)
//       ..httpResponseCode = err.response?.statusCode ?? 0;
//     await httpMetric.stop();
//     return super.onError(err, handler);
//   }
// }
