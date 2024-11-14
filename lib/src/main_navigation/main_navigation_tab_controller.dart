import 'package:relay_interview/i18n/strings.g.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';

part 'main_navigation_tab_controller.g.dart';

@Riverpod(keepAlive: true)
class MNTabController extends _$MNTabController {
  @override
  int build() {
    return TabIndex.inventory;
  }

  void setTabIndex(int index) {
    state = index;
  }

  void reset() {
    state = TabIndex.inventory;
  }
}

mixin TabIndex {
  static const int inventory = 0;
  static const int checkin = 1;
  static const int checkout = 2;

  static String getLabel(int value) {
    switch (value) {
      case 0:
        return t.inventory;
      case 1:
        return t.checkin;
      case 2:
        return t.checkout;
      default:
        return t.inventory;
    }
  }
}
