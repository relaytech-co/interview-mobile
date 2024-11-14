// ignore_for_file: public_member_api_docs

import 'package:hive/hive.dart';

part 'user_db_model.g.dart';

/// {@template route}
/// User model for the database
/// {@endtemplate}

@HiveType(typeId: 1)
class UserDbModel extends HiveObject {
  UserDbModel({
    required this.uid,
    required this.name,
    required this.email,
  });

  UserDbModel copyWith({
    String? uid,
    String? name,
    String? email,
  }) =>
      UserDbModel(
        uid: uid ?? this.uid,
        name: name ?? this.name,
        email: email ?? this.email,
      );

  @HiveField(0)
  final String? uid;

  @HiveField(1)
  final String? name;

  @HiveField(2)
  final String? email;
}
