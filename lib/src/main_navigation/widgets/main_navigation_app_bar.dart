import 'package:app_ui/app_ui.dart';
import 'package:connectivity_repository/connectivity_repository.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:relay_interview/i18n/strings.g.dart';
import 'package:relay_interview/src/app_status/presentation/controller/app_state_controller.dart';
import 'package:relay_interview/src/authentication/presentation/authentication_controller.dart';
import 'package:relay_interview/src/common/connectivity/connectivity_provider.dart';
import 'package:relay_interview/src/main_navigation/main_navigation_tab_controller.dart';

class MainAppBar extends ConsumerWidget {
  const MainAppBar({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final hasConnection =
        ref.watch(connectivityNotifierProvider) == ConnectivityStatus.online;
    return AppBar(
        title: _AppBarTitle(),
        actions: const [_MainNavigationActions()],
        leading: _AppBarLeading(),
        bottom: !hasConnection
            ? PreferredSize(
                preferredSize: AppBar().preferredSize,
                child: const Padding(
                  padding: EdgeInsets.symmetric(horizontal: 12),
                  child: RInfoBanner(
                    title: 'No internet connection',
                    leading: Icon(Icons.wifi_off_rounded),
                    type: BannerType.error,
                  ),
                ),
              )
            : null);
  }
}

class _AppBarTitle extends ConsumerWidget {
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final currentIndex = ref.watch(mNTabControllerProvider);
    switch (currentIndex) {
      case 0:
        return Text(ref.watch(appStateControllerProvider).user?.name ?? '');
      case 1:
        return Text(context.t.checkin);
      case 2:
        return Text(context.t.checkout);
      default:
        return const SizedBox();
    }
  }
}

class _AppBarLeading extends ConsumerWidget {
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final currentIndex = ref.watch(mNTabControllerProvider);
    switch (currentIndex) {
      case 0:
        return const SizedBox.shrink();

      case 1:
        return const SizedBox.shrink();
      case 2:
        return const SizedBox.shrink();
      default:
        return const SizedBox.shrink();
    }
  }
}

class _MainNavigationActions extends ConsumerWidget {
  const _MainNavigationActions();

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return PopupMenuButton<int>(
      icon: Icon(Icons.more_vert_outlined,
          color: Theme.of(context).colorScheme.onSurface),
      offset: const Offset(0, 50),
      color: Theme.of(context).colorScheme.surface,
      elevation: 0.5,
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
      itemBuilder: (context) => [
        PopupMenuItem(
          onTap: () {
            ref.read(authenticationControllerProvider.notifier).logout();
          },
          child: Row(
            children: [
              const Icon(Icons.logout_rounded),
              const Spacer4(),
              Text(t.logout)
            ],
          ),
        ),
      ],
    );
  }
}
