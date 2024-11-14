import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:relay_interview/i18n/strings.g.dart';
import 'package:relay_interview/src/main_navigation/main_navigation_tab_controller.dart';

class RBottomNavigationBar extends ConsumerStatefulWidget {
  const RBottomNavigationBar({super.key});

  @override
  ConsumerState<ConsumerStatefulWidget> createState() =>
      _BottomNavigationBarState();
}

class _BottomNavigationBarState extends ConsumerState<RBottomNavigationBar> {
  @override
  Widget build(BuildContext context) {
    final currentTabIndex = ref.watch(mNTabControllerProvider);
    return BottomNavigationBar(
        backgroundColor: Theme.of(context).colorScheme.surface,
        useLegacyColorScheme: false,
        currentIndex: currentTabIndex,
        selectedLabelStyle: Theme.of(context).textTheme.labelLarge!.copyWith(
            color: Theme.of(context).primaryColor, fontWeight: FontWeight.bold),
        unselectedLabelStyle: Theme.of(context).textTheme.labelLarge,
        showSelectedLabels: true,
        showUnselectedLabels: true,
        selectedItemColor: Theme.of(context).textTheme.labelLarge!.color,
        onTap: (int index) {
          ref.read(mNTabControllerProvider.notifier).setTabIndex(index);
        },
        items: [
          _renderButton(
              label: t.inventory,
              isSelected: currentTabIndex == 0,
              icon: Icons.list_alt_rounded),
          _renderButton(
              label: t.checkin,
              isSelected: currentTabIndex == 1,
              icon: Icons.download_rounded),
          _renderButton(
              label: t.checkout,
              isSelected: currentTabIndex == 2,
              icon: Icons.upload_rounded),
        ]);
  }

  BottomNavigationBarItem _renderButton(
      {required String label,
      required IconData icon,
      required bool isSelected}) {
    return BottomNavigationBarItem(
        backgroundColor: Theme.of(context).colorScheme.primary,
        icon: Icon(icon,
            color: isSelected
                ? Theme.of(context).primaryColor
                : Theme.of(context).colorScheme.onSurface),
        label: label);
  }
}
