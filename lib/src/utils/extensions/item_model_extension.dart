import 'package:flutter/widgets.dart';
import 'package:models/models.dart';
import 'package:relay_interview/i18n/strings.g.dart';

extension ItemModelExtension on ItemModel {
  String displayText(BuildContext context) {
    final quickCode = barcode.length > 3
        ? barcode.substring(barcode.length - 3, barcode.length)
        : barcode;
    String typeLabel;
    switch (type) {
      case ItemType.routeBag:
        typeLabel = context.t.bag;
      case ItemType.parcel:
        typeLabel = context.t.parcel;
      default:
        typeLabel = context.t.bag;
    }
    return '$typeLabel $quickCode';
  }
}
