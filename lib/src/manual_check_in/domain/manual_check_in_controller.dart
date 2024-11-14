import 'package:relay_interview/src/manual_check_in/domain/check_in_item.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';

part 'manual_check_in_controller.g.dart';

@riverpod
class CheckedInItemsController extends _$CheckedInItemsController {
  @override
  List<CheckInItem> build() {
    return [];
  }

  void create(CheckInItem newItem) {
    state = [...state, newItem];
  }
}
