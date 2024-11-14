import 'package:equatable/equatable.dart';
import 'package:flutter/material.dart';

import '../../app_ui.dart';

extension RelayColorSchemeThemeExtensions on ThemeData {
  RelayColorScheme get relayColorScheme =>
      extension<RelayColorScheme>() ?? RelayColorScheme.dark;
}

class RelayColorScheme extends ThemeExtension<RelayColorScheme> with EquatableMixin {
  const RelayColorScheme({
    required this.danger,
    required this.onDanger,
    Color? dangerContainer,
    Color? onDangerContainer,
    required this.warning,
    required this.onWarning,
    Color? warningContainer,
    Color? onWarningContainer,
    required this.success,
    required this.onSuccess,
    Color? successContainer,
    Color? onSuccessContainer,
    required this.muted,
    required this.onMuted,
    Color? mutedContainer,
    Color? onMutedContainer,
    required this.info,
    required this.onInfo,
    Color? infoContainer,
    Color? onInfoContainer,
  })  : _dangerContainer = dangerContainer,
        _onDangerContainer = onDangerContainer,
        _warningContainer = warningContainer,
        _onWarningContainer = onWarningContainer,
        _successContainer = successContainer,
        _onSuccessContainer = onSuccessContainer,
        _mutedContainer = mutedContainer,
        _onMutedContainer = onMutedContainer,
        _infoContainer = infoContainer,
        _onInfoContainer = onInfoContainer;

  static final RelayColorScheme dark = RelayColorScheme(
    danger: RelayColors.rose.shade700,
    onDanger: RelayColors.warmGray.shade50,
    dangerContainer: null,
    onDangerContainer: null,
    warning: Colors.black,
    onWarning: Colors.black,
    warningContainer: null,
    onWarningContainer: null,
    success: RelayColors.emerald.shade700,
    onSuccess: RelayColors.warmGray.shade50,
    successContainer: null,
    onSuccessContainer: null,
    muted: Colors.black,
    onMuted: Colors.black,
    mutedContainer: null,
    onMutedContainer: null,
    info: RelayColors.lightBlue.shade600,
    onInfo: RelayColors.warmGray.shade50,
    infoContainer: null,
    onInfoContainer: null,
  );

  final Color danger;
  final Color onDanger;
  final Color? _dangerContainer;
  final Color? _onDangerContainer;

  Color get dangerContainer => _dangerContainer ?? danger;

  Color get onDangerContainer => _onDangerContainer ?? onDanger;

  final Color warning;
  final Color onWarning;
  final Color? _warningContainer;
  final Color? _onWarningContainer;

  Color get warningContainer => _warningContainer ?? warning;

  Color get onWarningContainer => _onWarningContainer ?? onWarning;

  final Color success;
  final Color onSuccess;
  final Color? _successContainer;
  final Color? _onSuccessContainer;

  Color get successContainer => _successContainer ?? success;

  Color get onSuccessContainer => _onSuccessContainer ?? onSuccess;

  final Color muted;
  final Color onMuted;
  final Color? _mutedContainer;
  final Color? _onMutedContainer;

  Color get mutedContainer => _mutedContainer ?? muted;

  Color get onMutedContainer => _onMutedContainer ?? onMuted;

  final Color info;
  final Color onInfo;
  final Color? _infoContainer;
  final Color? _onInfoContainer;

  Color get infoContainer => _infoContainer ?? info;

  Color get onInfoContainer => _onInfoContainer ?? onInfo;

  @override
  RelayColorScheme copyWith({
    Color? danger,
    Color? onDanger,
    Color? dangerContainer,
    Color? onDangerContainer,
    Color? warning,
    Color? onWarning,
    Color? warningContainer,
    Color? onWarningContainer,
    Color? success,
    Color? onSuccess,
    Color? successContainer,
    Color? onSuccessContainer,
    Color? muted,
    Color? onMuted,
    Color? mutedContainer,
    Color? onMutedContainer,
    Color? info,
    Color? onInfo,
    Color? infoContainer,
    Color? onInfoContainer,
  }) {
    return RelayColorScheme(
      danger: danger ?? this.danger,
      onDanger: onDanger ?? this.onDanger,
      dangerContainer: dangerContainer ?? this.dangerContainer,
      onDangerContainer: onDangerContainer ?? this.onDangerContainer,
      warning: warning ?? this.warning,
      onWarning: onWarning ?? this.onWarning,
      warningContainer: warningContainer ?? this.warningContainer,
      onWarningContainer: onWarningContainer ?? this.onWarningContainer,
      success: success ?? this.success,
      onSuccess: onSuccess ?? this.onSuccess,
      successContainer: successContainer ?? this.successContainer,
      onSuccessContainer: onSuccessContainer ?? this.onSuccessContainer,
      muted: muted ?? this.muted,
      onMuted: onMuted ?? this.onMuted,
      mutedContainer: mutedContainer ?? this.mutedContainer,
      onMutedContainer: onMutedContainer ?? this.onMutedContainer,
      info: info ?? this.info,
      onInfo: onInfo ?? this.onInfo,
      infoContainer: infoContainer ?? this.infoContainer,
      onInfoContainer: onInfoContainer ?? this.onInfoContainer,
    );
  }

  @override
  RelayColorScheme lerp(ThemeExtension<RelayColorScheme>? other, double t) {
    if (other is! RelayColorScheme) {
      return this;
    }

    ColorScheme;
    return RelayColorScheme(
      danger: Color.lerp(danger, other.danger, t)!,
      onDanger: Color.lerp(onDanger, other.onDanger, t)!,
      dangerContainer: Color.lerp(dangerContainer, other.dangerContainer, t),
      onDangerContainer: Color.lerp(onDangerContainer, other.onDangerContainer, t),
      warning: Color.lerp(warning, other.warning, t)!,
      onWarning: Color.lerp(onWarning, other.onWarning, t)!,
      warningContainer: Color.lerp(warningContainer, other.warningContainer, t),
      onWarningContainer: Color.lerp(onWarningContainer, other.onWarningContainer, t),
      success: Color.lerp(success, other.success, t)!,
      onSuccess: Color.lerp(onSuccess, other.onSuccess, t)!,
      successContainer: Color.lerp(successContainer, other.successContainer, t),
      onSuccessContainer: Color.lerp(onSuccessContainer, other.onSuccessContainer, t),
      muted: Color.lerp(muted, other.muted, t)!,
      onMuted: Color.lerp(onMuted, other.onMuted, t)!,
      mutedContainer: Color.lerp(mutedContainer, other.mutedContainer, t),
      onMutedContainer: Color.lerp(onMutedContainer, other.onMutedContainer, t),
      info: Color.lerp(info, other.info, t)!,
      onInfo: Color.lerp(onInfo, other.onInfo, t)!,
      infoContainer: Color.lerp(infoContainer, other.infoContainer, t),
      onInfoContainer: Color.lerp(onInfoContainer, other.onInfoContainer, t),
    );
  }

  @override
  List<Object?> get props => [
        danger,
        onDanger,
        dangerContainer,
        onDangerContainer,
        warning,
        onWarning,
        warningContainer,
        onWarningContainer,
        success,
        onSuccess,
        successContainer,
        onSuccessContainer,
        muted,
        onMuted,
        mutedContainer,
        onMutedContainer,
        info,
        onInfo,
        infoContainer,
        onInfoContainer,
      ];
}
