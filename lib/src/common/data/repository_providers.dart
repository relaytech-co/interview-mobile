import 'package:api_client/api_client.dart';
import 'package:app_config_repository/app_config_repository.dart';
import 'package:database_client/database_client.dart';
import 'package:relay_interview/config/navigation/navigation/unauthorized_interceptor.dart';
import 'package:relay_interview/src/common/data/environment.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';
import 'package:secure_storage/secure_storage.dart';

part 'repository_providers.g.dart';

final tokenProvider = TokenProvider(const SecureStorage());

@Riverpod(keepAlive: true)
DatabaseClient databaseClient(DatabaseClientRef ref) {
  return DatabaseClient();
}

@Riverpod(keepAlive: true)
ApiClient apiClient(ApiClientRef ref) {
  return ApiClient(
      apiUrl: RelayEnvironment.apiBaseUrl.origin,
      tokenProvider: tokenProvider,
      interceptors: [UnauthorizedRequestInterceptor(ref)]);
}

@Riverpod(keepAlive: true)
AppConfigRepository appConfigRepository(AppConfigRepositoryRef ref) {
  return AppConfigRepository(
      launchDarklyKey: RelayEnvironment.launchDarklyMobileKey);
}
