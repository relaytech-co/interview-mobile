import 'package:api_client/api_client.dart';
import 'package:authentication_client/authentication_client.dart';
import 'package:authentication_client/models/auth_user.dart';
import 'package:models/models.dart';
import 'package:rxdart/rxdart.dart';

/// {@template authentication_client}
/// {@endtemplate}
class AuthenticationClient {
  /// {@macro authentication_client}
  AuthenticationClient({
    required AccountResource accountResource,
    required TokenProvider tokenProvider,
  })  : _accountResource = accountResource,
        _tokenProvider = tokenProvider;
  // _appTarget = appFlavor;

  final AccountResource _accountResource;
  final TokenProvider _tokenProvider;
  final BehaviorSubject<AuthUser> _userStream = BehaviorSubject<AuthUser>();

  Future<void> _initialize() async {
    try {
      //final user = await _accountResource.fetchProfile();
      //  _userStream.add(user.toUser());
    } on HttpAuthenticationException {
      _userStream.add(AuthUser.anonymous);
    } on HttpConnectionException catch (_) {
    } catch (e, s) {
      _userStream.addError(e, s);
    }
  }

  /// Stream of [AuthUser] which will emit the current user when
  /// the authentication state changes.
  ///
  /// Emits [AuthUser.anonymous] if the user is not authenticated.
  Stream<AuthUser> get user {
    _initialize();
    return _userStream.stream;
  }

  /// Signs in with the provided [qrCode].
  Future<void> loginWithQrCode({required String qrCode}) async {
    try {
      final response = await _accountResource.login({'auth_qr_code': qrCode});
      final authToken = AuthTokens.fromJson({
        'access_token': response.jwtToken,
        'refresh_token': '',
      });
      await _tokenProvider.write(authToken);
      final user = AuthUser(
          uid: response.uid, email: response.email, name: response.name);
      _userStream.add(user);
    } on HttpAuthenticationException catch (error, stackTrace) {
      throw LogInWithQrIncorrectCredentialsFailure(
        error,
        stackTrace,
      );
    } on HttpConnectionException catch (error, stackTrace) {
      throw LogInConnectionFailure(error, stackTrace);
    } catch (error, stackTrace) {
      throw LogInWithQrFailure(error, stackTrace);
    }
  }

  /// Signs out the current user which will emit
  /// [AuthUser.anonymous] from the [user] Stream.
  ///
  /// Throws a [LogOutFailure] if an exception occurs.
  Future<void> logOut() async {
    try {
      await _tokenProvider.delete();
    } catch (error, stackTrace) {
      throw LogOutFailure(error, stackTrace);
    } finally {
      _userStream.add(AuthUser.anonymous);
    }
  }
}
