import 'package:inventory_repository/inventory_repository.dart';
import 'package:models/models.dart';
import 'package:relay_interview/src/common/data/repository_providers.dart';
import 'package:relay_interview/src/inventory/domain/inventory.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';

part 'inventory_service.g.dart';

@Riverpod(keepAlive: true)
InventoryRepository inventoryRepository(InventoryRepositoryRef ref) {
  return InventoryRepository(
    apiClient: ref.read(apiClientProvider),
    databaseClient: ref.read(databaseClientProvider),
  );
}
