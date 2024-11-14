import 'dart:async';
import 'package:async/async.dart';

extension CommonFutureExtensions<T> on Future<T> {
  CancelableOperation<T> toCancelable({FutureOr Function()? onCancel}) {
    return CancelableOperation.fromFuture(this, onCancel: onCancel);
  }
}
