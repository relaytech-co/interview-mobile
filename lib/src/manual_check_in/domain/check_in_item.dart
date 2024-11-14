import 'package:models/models.dart';

class CheckInItem {
  final String courierId;
  final String barcode;
  final ItemType type;

  CheckInItem({
    required this.courierId,
    required this.barcode,
    required this.type,
  });

  copyWith({
    String? courierId,
    String? barcode,
    ItemType? type,
  }) {
    return CheckInItem(
      courierId: courierId ?? this.courierId,
      barcode: barcode ?? this.barcode,
      type: type ?? this.type,
    );
  }

  factory CheckInItem.fromJson(Map<String, dynamic> json) {
    return CheckInItem(
      courierId: json['courier_id'],
      barcode: json['barcode'],
      type: ItemType.values.firstWhere(
        (e) => e.toString() == json['type'],
      ),
    );
  }
}
