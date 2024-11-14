// import 'package:flutter_test/flutter_test.dart';
// import 'package:mockito/mockito.dart';

// import '../lib/trace.dart';
// import 'mocks/firebase_analytics.mocks.dart';

// void main() {
//   group('Trace Class Tests', () {
//     late MockFirebaseAnalytics mockFirebaseAnalytics;
//     late bool enableTracing;

//     setUp(() {
//       mockFirebaseAnalytics = MockFirebaseAnalytics();
//       when(mockFirebaseAnalytics.logEvent(
//               name: anyNamed('name'), parameters: anyNamed('parameters')))
//           .thenAnswer((_) => Future.value());

//       Trace.setup(analyticsClient: mockFirebaseAnalytics);
//       Trace.traceOverrideUntil(null);
//     });

//     test('log analytic events always', () async {
//       enableTracing = false;

//       Trace.log('test_trace', sendAnalytics: true);
//       await Trace.checkAndSend(enableTracing);

//       verify(mockFirebaseAnalytics.logEvent(
//               name: 'test_trace', parameters: anyNamed('parameters')))
//           .called(1);
//       verifyNever(mockFirebaseAnalytics.logEvent(
//           name: 'trace_log', parameters: anyNamed('parameters')));
//     });

//     test('log trace events when enabled', () async {
//       enableTracing = true;

//       Trace.log('test_trace', sendAnalytics: true);
//       await Trace.checkAndSend(enableTracing);

//       verify(mockFirebaseAnalytics.logEvent(
//               name: 'test_trace', parameters: anyNamed('parameters')))
//           .called(1);
//       verify(mockFirebaseAnalytics.logEvent(
//               name: 'trace_log', parameters: anyNamed('parameters')))
//           .called(1);
//     });

//     test('log trace events when override enabled', () async {
//       enableTracing = false;

//       Trace.traceOverrideUntil(DateTime.now().add(const Duration(minutes: 1)));
//       Trace.log('test_trace', sendAnalytics: true);
//       await Trace.checkAndSend(enableTracing);

//       verify(mockFirebaseAnalytics.logEvent(
//               name: 'test_trace', parameters: anyNamed('parameters')))
//           .called(1);
//       verify(mockFirebaseAnalytics.logEvent(
//               name: 'trace_log', parameters: anyNamed('parameters')))
//           .called(1);
//     });

//     test('send queued events in order', () async {
//       enableTracing = false;

//       Trace.log('test_trace1', sendAnalytics: true);
//       Trace.log('test_trace2', sendAnalytics: true);
//       Trace.log('test_trace3', sendAnalytics: true);
//       await Trace.checkAndSend(enableTracing);

//       verifyInOrder([
//         mockFirebaseAnalytics.logEvent(
//             name: 'test_trace1', parameters: anyNamed('parameters')),
//         mockFirebaseAnalytics.logEvent(
//             name: 'test_trace2', parameters: anyNamed('parameters')),
//         mockFirebaseAnalytics.logEvent(
//             name: 'test_trace3', parameters: anyNamed('parameters')),
//       ]);
//     });

//     test('analytics are not sent', () async {
//       enableTracing = true;

//       Trace.log('test_trace', sendAnalytics: false);
//       await Trace.checkAndSend(enableTracing);

//       verifyNever(mockFirebaseAnalytics.logEvent(
//           name: 'test_trace', parameters: anyNamed('parameters')));
//     });

//     test('log names are normalised', () async {
//       enableTracing = true;

//       Trace.log('test_TraCe__dfdf--243', sendAnalytics: true);
//       await Trace.checkAndSend(enableTracing);

//       verify(mockFirebaseAnalytics.logEvent(
//               name: 'test_trace_dfdf_243', parameters: anyNamed('parameters')))
//           .called(1);
//     });

//     test('only log last 300 events', () async {
//       enableTracing = true;

//       for (var i = 0; i < 350; i++) {
//         Trace.log('test_t$i', sendAnalytics: false);
//       }
//       await Trace.checkAndSend(enableTracing);

//       verify(mockFirebaseAnalytics.logEvent(
//               name: anyNamed('name'), parameters: anyNamed('parameters')))
//           .called(300);
//     });

//     test('properties are merged', () async {
//       enableTracing = true;

//       Trace.log('test_trace',
//           sendAnalytics: false, analyticsProps: {'foo': 'bar'}, traceProps: {'hi': 'bye'});
//       await Trace.checkAndSend(enableTracing);

//       verifyNever(mockFirebaseAnalytics.logEvent(
//           name: 'test_trace', parameters: anyNamed('parameters')));
//       final params = verify(mockFirebaseAnalytics.logEvent(
//               name: 'trace_log', parameters: captureAnyNamed('parameters')))
//           .captured[0] as Map<String, dynamic>;
//       expect(params['trace_name'], equals('test_trace'));
//       expect(params['foo'], equals('bar'));
//       expect(params['hi'], equals('bye'));
//       expect(params.containsKey('captured_at'), isTrue);
//     });
//   });
// }
