import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

class FirstTab extends ConsumerStatefulWidget {
  const FirstTab({super.key});

  @override
  ConsumerState<FirstTab> createState() => _InventoryTabState();
}

class _InventoryTabState extends ConsumerState<FirstTab> {
  @override
  Widget build(BuildContext context) {
    return const SizedBox();
  }
}
