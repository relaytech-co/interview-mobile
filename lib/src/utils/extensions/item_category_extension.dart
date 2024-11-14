import 'package:app_ui/app_ui.dart';
import 'package:flutter/widgets.dart';
import 'package:models/models.dart';
import 'package:relay_interview/i18n/strings.g.dart';

extension ItemCategoryExtension on ItemCategory {
  String localized(BuildContext context) {
    switch (this) {
      case ItemCategory.emptyBags:
        return context.t.emptyBags;
      case ItemCategory.fullBags:
        return context.t.fullBags;
      case ItemCategory.parcels:
        return context.t.parcels;
    }
  }

  SvgGenImage icon() {
    switch (this) {
      case ItemCategory.emptyBags:
        return Assets.icons.emptyBag;
      case ItemCategory.fullBags:
        return Assets.icons.fullBag;
      case ItemCategory.parcels:
        return Assets.icons.parcel;
    }
  }
}
