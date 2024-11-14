import 'package:flutter/material.dart';

class RIconWithNotification extends StatelessWidget {
  const RIconWithNotification(
      {Key? key,
      required this.icon,
      this.size = 24.0,
      this.notificationCount = 0,
      this.color,
      this.showCount = true})
      : super(key: key);
  final Widget icon;
  final double size;
  final int notificationCount;
  final Color? color;
  final bool showCount;

  @override
  Widget build(BuildContext context) {
    return Stack(
      alignment: Alignment.center,
      children: [
        icon,
        if (notificationCount > 0)
          Positioned(
            right: 0,
            top: 0,
            child: Container(
              padding: EdgeInsets.all(0),
              decoration: BoxDecoration(
                color: Colors.red,
                borderRadius: BorderRadius.circular(6),
              ),
              constraints: BoxConstraints(
                minWidth: 12,
                minHeight: 12,
              ),
              child: Text(
                _formatCount(notificationCount, showCount),
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 8,
                ),
                textAlign: TextAlign.center,
              ),
            ),
          ),
      ],
    );
  }

  String _formatCount(int count, bool showCount) {
    if (!showCount) return '';
    if (count < 1000) return count.toString();
    if (count < 1000000) return '${(count / 1000).toStringAsFixed(1)}k';
    return '${(count / 1000000).toStringAsFixed(1)}m';
  }
}
