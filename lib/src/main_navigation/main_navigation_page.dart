import 'package:analytics_client/analytics_client.dart';
import 'package:app_ui/app_ui.dart';
import 'package:connectivity_repository/connectivity_repository.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:relay_interview/config/navigation/navigation/app_router.dart';
import 'package:relay_interview/config/navigation/navigation/app_routes.dart';
import 'package:relay_interview/src/common/connectivity/connectivity_provider.dart';
import 'package:relay_interview/src/common/permissions/permission_provider.dart';
import 'package:relay_interview/src/inventory/presentation/inventory_tab.dart';
import 'package:relay_interview/src/main_navigation/main_navigation_tab_controller.dart';
import 'package:relay_interview/src/main_navigation/widgets/main_navigation_app_bar.dart';
import 'package:relay_interview/src/main_navigation/widgets/r_bottom_navigation_bar.dart';
import 'package:relay_interview/src/manual_check_in/domain/manual_check_in_controller.dart';
import 'package:relay_interview/src/manual_check_in/presentation/manual_check_in_page.dart';

class MainNavigationPage extends ConsumerStatefulWidget {
  const MainNavigationPage({super.key});

  @override
  ConsumerState<MainNavigationPage> createState() => _MainNavigationPageState();
}

class _MainNavigationPageState extends ConsumerState<MainNavigationPage> {
  final GlobalKey<ScaffoldState> scaffoldKey = GlobalKey();

  @override
  void initState() {
    WidgetsBinding.instance.addPostFrameCallback((_) {
      ref.read(permissionServiceProvider.notifier).initialize();
    });
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).colorScheme.surface,
      key: scaffoldKey,
      appBar:
          PreferredSize(preferredSize: appBarSize(), child: const MainAppBar()),
      bottomNavigationBar: const RBottomNavigationBar(),
      body: IndexedStack(
        index: ref.watch(mNTabControllerProvider),
        children: [
          const FirstTab(),
          const ManualCheckInPage(),
          const SizedBox.shrink(),
        ],
      ),
    );
  }

  Size appBarSize() {
    if (ref.watch(connectivityNotifierProvider) == ConnectivityStatus.offline) {
      return AppBar().preferredSize * 2;
    } else {
      return AppBar().preferredSize;
    }
  }
}
