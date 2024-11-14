import '../../app_ui.dart';
import 'package:flutter/material.dart';

class RCardSubtitle extends StatelessWidget {
  const RCardSubtitle({required this.text, super.key});
  final String text;

  @override
  Widget build(BuildContext context) {
    return Text(text,
        style: Theme.of(context).textTheme.titleSmall!.copyWith(color: RelayColors.muted));
  }
}
