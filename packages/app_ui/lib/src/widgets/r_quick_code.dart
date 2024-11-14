import 'package:flutter/material.dart';

class RQuickCode extends StatelessWidget {
  const RQuickCode({required this.quickCode});
  final String quickCode;

  @override
  Widget build(BuildContext context) {
    return Container(
        padding: const EdgeInsets.symmetric(vertical: 2, horizontal: 10),
        decoration: BoxDecoration(
            border: Border.all(color: Theme.of(context).colorScheme.primary),
            borderRadius: BorderRadius.circular(8)),
        child: Text(quickCode,
            style: Theme.of(context).textTheme.bodyMedium!.copyWith(
                color: Theme.of(context).colorScheme.primary, fontWeight: FontWeight.bold)));
  }
}
