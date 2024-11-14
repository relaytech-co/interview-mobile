import 'package:authentication_client/models/auth_user.dart';
import 'package:models/models.dart' as models;

/// Extensions for the [models.User] model
extension UserExtension on models.User {
  /// Converts the [models.User] to [AuthUser]
  AuthUser toUser({bool? isStg}) => AuthUser(
        uid: uid ?? '',
        email: email,
        name: name,
      );
}
