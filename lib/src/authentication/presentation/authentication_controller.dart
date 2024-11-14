import 'package:auth_repository/auth_repository.dart';
import 'package:authentication_client/authentication_client.dart';
import 'package:relay_interview/src/authentication/data/auth_repository.dart';
import 'package:relay_interview/src/authentication/presentation/auth_state.dart';
import 'package:riverpod_annotation/riverpod_annotation.dart';

part 'authentication_controller.g.dart';

@riverpod
class AuthenticationController extends _$AuthenticationController {
  late final AuthRepository _authRepository;

  @override
  AuthState build() {
    _authRepository = ref.read(authRepositoryProvider);
    return const AuthState(isLoading: false);
  }

  Future<void> login({required String qrCode}) async {
    try {
      state = const AuthState(isLoading: true);
      await _authRepository.loginWithQrCode(
        qrCode: qrCode,
      );
      state = const AuthState(isLoading: false, errorMessage: '');
    } on LogInWithQrIncorrectCredentialsFailure {
      state = const AuthState(
          isLoading: false, errorMessage: 'Incorrect credentials');
    } on LogInWithQrFailure {
      state = const AuthState(
          isLoading: false, errorMessage: 'Incorrect credentials');
    } on LogInConnectionFailure {
      state =
          const AuthState(isLoading: false, errorMessage: 'Connection failure');
    } catch (error) {
      state = const AuthState(
          isLoading: false, errorMessage: 'There has been an error');
    }
  }

  Future<void> logout() async {
    await _authRepository.logOut();
  }
}
