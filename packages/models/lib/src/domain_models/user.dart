// ignore_for_file: public_member_api_docs, sort_constructors_first

import 'package:equatable/equatable.dart';
import 'package:json_annotation/json_annotation.dart';

/// {@template user_data}
/// API model of the User
/// {@endtemplate}
@JsonSerializable()
class User extends Equatable {
  /// {@macro user_data}
  const User({
    required this.uid,
    this.name,
    this.email,
  });

  final String? uid;
  final String? name;
  final String? email;

  /// Anonymous user which represents an unauthenticated user.
  static const anonymous = User(uid: '');

  User copyWith({
    String? uid,
    String? name,
    String? email,
  }) =>
      User(
        uid: uid ?? this.uid,
        name: name ?? this.name,
        email: email ?? this.email,
      );

  factory User.fromJson(
    Map<String, dynamic> json,
  ) {
    return User(
      uid: json['uid'] as String?,
      name: json['pitstop_name'] as String?,
      email: json['pitstop_email'] as String?,
    );
  }

  @override
  List<Object?> get props => [
        name,
        uid,
        email,
      ];
}
