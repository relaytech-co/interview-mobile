import 'package:equatable/equatable.dart';
import 'package:models/models.dart';

enum AppStatus {
  uninitialized,
  unauthenticated,
  authenticated,
  forceUpdateRequired,
  downForMaintenance,
}

class AppState extends Equatable {
  const AppState({
    required this.status,
    this.soonToBeDeprecated = false,
    this.user,
  });

  final AppStatus status;
  final bool soonToBeDeprecated;
  final User? user;

  copyWith({
    AppStatus? status,
    bool? soonToBeDeprecated,
    User? user,
  }) {
    return AppState(
      status: status ?? this.status,
      soonToBeDeprecated: soonToBeDeprecated ?? this.soonToBeDeprecated,
      user: user ?? this.user,
    );
  }

  @override
  List<Object?> get props => [status, soonToBeDeprecated, user];
}
