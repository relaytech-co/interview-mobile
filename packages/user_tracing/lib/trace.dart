import 'dart:collection';

// import 'package:firebase_analytics/firebase_analytics.dart';

typedef VoidCallback = void Function();
typedef _TraceEvent = Map<String, dynamic>;

class _AnalyticsEvent {
  _AnalyticsEvent({required this.name, required this.props});

  final String name;
  final Map<String, dynamic> props;
}

class Trace {
  static final Queue<_TraceEvent> _traceEvents = Queue<_TraceEvent>();
  static final Queue<_AnalyticsEvent> _analyticEvents =
      Queue<_AnalyticsEvent>();
  static bool _checking = false;
  // static FirebaseAnalytics? _analyticsClient;
  static DateTime? _traceOverrideUntil;

  static void setup(
      //   {
      //   // FirebaseAnalytics? analyticsClient = null,
      // }
      ) {
    // _analyticsClient = analyticsClient ?? FirebaseAnalytics.instance;
    _traceEvents.clear();
    _analyticEvents.clear();
  }

  static bool _traceOverrideEnabled() {
    return _traceOverrideUntil != null &&
        DateTime.now().toUtc().isBefore(_traceOverrideUntil!);
  }

  static void traceOverrideUntil(DateTime? until) {
    if (until != null && !until.isUtc) {
      until = until.toUtc();
    }
    _traceOverrideUntil = until;
  }

  static Future<void> checkAndSend(bool shouldTrace) async {
    if (_checking) return;
    _checking = true;

    // if (_analyticsClient == null) {
    //   setup();
    // }

    while (_analyticEvents.isNotEmpty) {
      try {
        // in theory it's impossible to have a race condition here, but try/catch anyway
        //  var e = _analyticEvents.removeFirst();
        //   await _analyticsClient!.logEvent(name: e.name, parameters: e.props);
      } catch (error) {}
    }

    final traceEnabled = shouldTrace || _traceOverrideEnabled();
    if (!traceEnabled) {
      _checking = false;
      return;
    }

    while (_traceEvents.isNotEmpty) {
      try {
        // there is a theoretical chance of a race condition between `checkAndSend` and `log`
        // but it is extremely unlikely - we wrap each in a try/catch just to be safe
        //var e = _traceEvents.removeFirst();
        // await _analyticsClient!
        //     .logEvent(name: 'trace_log', parameters: e)
        //     .catchError((error, trace) {
        //   print('Error while fetching cache $error, $trace');
        // });
      } catch (error) {}
    }

    _checking = false;
  }

  static void log(String trace_name,
      {Map<String, dynamic>? analyticsProps,
      Map<String, dynamic>? traceProps,
      bool sendAnalytics = true}) {
    trace_name = trace_name.toLowerCase();
    var name_parts = trace_name.split('_');
    final name_type = name_parts[0];
    // normalise the trace names to a common format
    final name_ctx =
        name_parts.skip(1).join('_').replaceAll(RegExp(r'[\W_]+'), '_');
    final name = name_type + '_' + name_ctx;

    if (sendAnalytics) {
      _analyticEvents
          .add(_AnalyticsEvent(name: name, props: analyticsProps ?? {}));
    }

    final newTraceProps = Map.from(traceProps ?? {});
    final newAnalyticsProps = Map.from(analyticsProps ?? {});
    newAnalyticsProps['trace_name'] = name;
    newAnalyticsProps['captured_at'] = DateTime.now().toUtc().toIso8601String();
    _traceEvents.add({...newAnalyticsProps, ...newTraceProps});

    // we keep a rolling history of the last 300 events, so if a user has an issue
    // we can turn on tracing and see what happened
    while (_traceEvents.length > 300) {
      try {
        _traceEvents.removeFirst();
      } catch (error) {}
    }
  }

  static void Function() wrapHandler(
      void Function() handler, String traceName, String traceType,
      {Map<String, dynamic>? props,
      Map<String, dynamic>? traceProps,
      bool sendAnalytics = true}) {
    return () {
      handler();
      log(traceType + '_' + traceName,
          analyticsProps: props,
          traceProps: traceProps,
          sendAnalytics: sendAnalytics);
    };
  }

  static void Function()? wrapNullableHandler(
      void Function()? handler, String traceName, String traceType,
      {Map<String, dynamic>? props,
      Map<String, dynamic>? traceProps,
      bool sendAnalytics = true}) {
    final new_handler = handler == null
        ? null
        : () {
            handler.call();
            log(traceType + '_' + traceName,
                analyticsProps: props,
                traceProps: traceProps,
                sendAnalytics: sendAnalytics);
          };

    return new_handler;
  }
}
