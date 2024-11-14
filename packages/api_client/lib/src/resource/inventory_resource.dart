// ignore_for_file: public_member_api_docs

import 'package:dio/dio.dart';
import 'package:models/models.dart';
import 'package:retrofit/retrofit.dart';

part 'inventory_resource.g.dart';

@RestApi()
abstract class InventoryResource {
  factory InventoryResource(
    Dio dio, {
    required String baseUrl,
  }) = _InventoryResource;

  @GET('/v0/pitstop-network/items?event_type=checked_out')
  Future<List<ItemModel>> getCheckedOutItems();
}
