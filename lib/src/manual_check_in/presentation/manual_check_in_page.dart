import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:relay_interview/config/navigation/navigation/app_routes.dart';
import 'package:relay_interview/src/manual_check_in/domain/manual_check_in_controller.dart';

class ManualCheckInPage extends ConsumerWidget {
  const ManualCheckInPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final state = ref.watch(checkedInItemsControllerProvider);
    return Scaffold(
        floatingActionButton: FloatingActionButton(
            child: const Icon(Icons.add),
            onPressed: () {
              context.navigator.pushReplacementCreateManualCheckIn();
            }),
        body: ListView.builder(
          itemCount: state.length,
          itemBuilder: (context, index) {
            final item = state[index];
            return ListTile(
              title: Text(item.barcode),
              subtitle: Text(item.courierId),
            );
          },
        ));
  }
}
