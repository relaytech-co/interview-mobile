import 'package:hive/hive.dart';
import 'package:models/models.dart';
import 'package:rxdart/rxdart.dart';

/// {@template user_resource}
/// Resource responsible for retrieving user related data.
/// {@endtemplate}
class UserResource {
  /// {@macro user_resource}
  UserResource({required this.box});
  final Box<UserDbModel> box;

  /// Returns current user
  Stream<UserDbModel?> currentUser() {
    return Rx.concat([
      Stream.value(box.get('current_user')),
      box
          .watch(key: 'current_user')
          .map((BoxEvent el) => box.get('current_user'))
    ]);
  }

  /// It updates the current user.
  ///
  /// If there are any other users, it deletes them, so that we always
  /// have at most 1 user in the [UserDbModel] box.
  Future<void> saveUser(UserDbModel user) async {
    try {
      await box.put('current_user', user);
    } catch (err) {
      print('Error saving user');
      print(err.toString());
    }
  }

  /// Deletes the current user
  void deleteUser() {
    box.clear();
  }
}
