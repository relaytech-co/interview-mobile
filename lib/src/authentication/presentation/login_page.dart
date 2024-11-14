import 'package:analytics_client/analytics_client.dart';
import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:relay_interview/src/authentication/presentation/authentication_controller.dart';

const testQr =
    '25aea5a17f1b530fc1ed844a271374167784a43cf15d3d4fc46a9879e20d5ea84ad9f12b66dc472d9310359d61d4be585e15b3d51d4c5e43bf33a2ca6ff49aea';

class LoginPage extends ConsumerStatefulWidget {
  const LoginPage({super.key});

  @override
  ConsumerState<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends ConsumerState<LoginPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Login'),
      ),
      body: Center(
        child: RFilledButton(
            loading: ref.watch(authenticationControllerProvider).isLoading,
            traceName: TraceNames.login.name,
            onPressed: () {
              ref
                  .read(authenticationControllerProvider.notifier)
                  .login(qrCode: testQr);
            },
            child: const Text('Scan your QR code to verify your ID')),
      ),
    );
  }
}
