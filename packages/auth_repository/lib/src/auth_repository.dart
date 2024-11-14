// ignore_for_file: public_member_api_docs

import 'dart:async';

import 'package:authentication_client/authentication_client.dart';
import 'package:authentication_client/models/auth_user.dart';
import 'package:database_client/database_client.dart';
import 'package:models/models.dart';

/// {@template auth_repository}
/// Repository which manages the user domain.
/// {@endtemplate}
class AuthRepository {
  /// {@macro auth_repository}
  AuthRepository({
    required AuthenticationClient authenticationClient,
    required DatabaseClient databaseClient,
  })  : _authenticationClient = authenticationClient,
        _databaseClient = databaseClient;

  final AuthenticationClient _authenticationClient;
  final DatabaseClient _databaseClient;
  StreamSubscription<AuthUser>? _authSub;

  /// Stream of [User] which will emit the current user when
  /// the authentication state changes.
  ///
  /// Emits [User.anonymous] if the user is not authenticated.
  Stream<User?> get user {
    _authSub ??= _authenticationClient.user.listen(
      (user) {
        if (user == AuthUser.anonymous) {
          _databaseClient.userResource.deleteUser();
        } else {
          final dbUser = user.toDbUser;
          _databaseClient.userResource.saveUser(dbUser);
        }
      },
      onDone: () {
        _authSub?.cancel();
        _authSub = null;
      },
      onError: _authSub?.onError,
    );

    return _databaseClient.userResource.currentUser().map(
      (user) {
        if (user == null) {
          return User.anonymous;
        }
        return user.toUser();
      },
    ).distinct();
  }

  /// Forces a refresh of the user by accessing the authentication
  /// client's user. This leads to fetching the most recent user from the
  /// API and emitting it onto the [user] stream.
  void refreshUser() {
    _authenticationClient.user;
  }

  /// Signs in with the provided [qrCode].
  ///
  /// Throws a [LogInWithQrIncorrectCredentialsFailure] if an exception occurs.
  Future<void> loginWithQrCode({
    required String qrCode,
  }) async {
    try {
      await _authenticationClient.loginWithQrCode(qrCode: qrCode);
    } on LogInWithQrIncorrectCredentialsFailure {
      rethrow;
    } on LogInWithQrFailure {
      rethrow;
    } on LogInConnectionFailure {
      rethrow;
    } catch (error, stackTrace) {
      throw LogInWithQrFailure(error, stackTrace);
    }
  }

  /// Signs out the current user which will emit
  /// [User.anonymous] from the [user] Stream.
  ///
  /// Throws a [LogOutFailure] if an exception occurs.
  Future<void> logOut() async {
    try {
      await _authenticationClient.logOut();
      await _databaseClient.clear();
    } on LogOutFailure {
      rethrow;
    } catch (error, stackTrace) {
      throw LogOutFailure(error, stackTrace);
    }
  }
}

extension on AuthUser {
  UserDbModel get toDbUser => UserDbModel(
        uid: uid,
        name: name,
        email: email,
      );
}

extension on UserDbModel {
  User toUser() => User(
        uid: uid,
        email: email,
        name: name,
      );
}
