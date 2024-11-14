import 'package:equatable/equatable.dart';

/// {@template authentication_exception}
/// Exceptions from the authentication client.
/// {@endtemplate}
abstract class AuthenticationException
    with EquatableMixin
    implements Exception {
  /// {@macro authentication_exception}
  const AuthenticationException(this.error, this.stackTrace);

  /// The error which was caught.
  final Object error;

  /// The stack trace associated with the [error].
  final StackTrace stackTrace;

  @override
  List<Object?> get props => [error, stackTrace];
}

/// {@template log_in_with_qr_failure}
/// Thrown during the login process if a failure occurs.
/// {@endtemplate}
class LogInWithQrFailure extends AuthenticationException {
  /// {@macro log_in_with_qr_failure}
  const LogInWithQrFailure(super.error, super.stackTrace);
}

/// {@template log_in_with_qr_incorrect_credentials_failure}
/// Thrown during the login process if a failure
/// occurs due to incorrect credentials.
/// {@endtemplate}
class LogInWithQrIncorrectCredentialsFailure extends AuthenticationException {
  /// {@macro log_in_with_qr_incorrect_credentials_failure}
  const LogInWithQrIncorrectCredentialsFailure(
    super.error,
    super.stackTrace,
  );
}

/// {@template log_in_connection_failure}
/// Thrown during the login process if a connection failure occurs.
/// {@endtemplate}
class LogInConnectionFailure extends AuthenticationException {
  /// {@macro log_in_connection_failure}
  const LogInConnectionFailure(super.error, super.stackTrace);
}

/// {@template log_out_failure}
/// Thrown during the logout process if a failure occurs.
/// {@endtemplate}
class LogOutFailure extends AuthenticationException {
  /// {@macro log_out_failure}
  const LogOutFailure(super.error, super.stackTrace);
}
