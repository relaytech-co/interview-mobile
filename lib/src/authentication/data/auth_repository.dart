import 'package:auth_repository/auth_repository.dart';
import 'package:authentication_client/authentication_client.dart';
import 'package:relay_interview/src/common/data/repository_providers.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';

part 'auth_repository.g.dart';

@Riverpod(keepAlive: true)
AuthenticationClient authenticationClient(AuthenticationClientRef ref) {
  return AuthenticationClient(
    accountResource: ref.read(apiClientProvider).accountResource,
    tokenProvider: tokenProvider,
  );
}

@Riverpod(keepAlive: true)
AuthRepository authRepository(AuthRepositoryRef ref) {
  return AuthRepository(
    authenticationClient: ref.read(authenticationClientProvider),
    databaseClient: ref.read(databaseClientProvider),
  );
}
