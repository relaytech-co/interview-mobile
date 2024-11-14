import 'package:equatable/equatable.dart';

/// {@template user}
/// User model
///
/// [AuthUser.anonymous] represents an unauthenticated user.
/// {@endtemplate}
class AuthUser extends Equatable {
  /// {@macro user}
  const AuthUser({
    required this.uid,
    this.email,
    this.name,
  });

  /// The current user's email address.
  final String? email;

  /// The current user's id.
  final String uid;

  /// User's name
  final String? name;

  /// Anonymous user which represents an unauthenticated user.
  static const anonymous = AuthUser(uid: '');

  AuthUser copyWith({
    String? uid,
    String? email,
    String? name,
  }) {
    return AuthUser(
      uid: uid ?? this.uid,
      email: email ?? this.email,
      name: name ?? this.name,
    );
  }

  @override
  List<Object?> get props => [
        uid,
        email,
        name,
      ];
}
