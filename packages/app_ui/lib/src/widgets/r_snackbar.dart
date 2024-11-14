import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import '../../app_ui.dart';

extension SnackBarBuildContextExtensions on BuildContext {
  SnackBarWrapper get snackBar => SnackBarWrapper.of(this);
}

final class SnackBarWrapper {
  /// A [BuildContext] must have a [Scaffold] or exception is thrown.
  SnackBarWrapper.of(this._context);

  final BuildContext _context;

  void info(
    String message, {
    bool positionedTop = false,
    bool haptics = false,
    VoidCallback? onClosed,
  }) {
    assert(message.isNotEmpty, 'Message cannot be empty');

    ScaffoldMessenger.of(_context)
      ..hideCurrentSnackBar()
      ..showSnackBar(_RelaySnackBar.info(
        _context,
        positionedTop: positionedTop,
        content: Text(message),
      )).closed.then((_) {
        if (onClosed != null) onClosed();
      });
    if (haptics) {
      HapticFeedback.mediumImpact();
    }
  }

  void infoWithIcon(
    String message,
    IconData icon, {
    bool positionedTop = false,
    bool haptics = false,
    VoidCallback? onClosed,
  }) {
    assert(message.isNotEmpty, 'Message cannot be empty');

    ScaffoldMessenger.of(_context)
      ..hideCurrentSnackBar()
      ..showSnackBar(_RelaySnackBar.info(
        _context,
        positionedTop: positionedTop,
        leading: Icon(icon),
        content: Text(message),
      )).closed.then((_) {
        if (onClosed != null) onClosed();
      });

    if (haptics) {
      HapticFeedback.mediumImpact();
    }
  }

  void success(
    String message, {
    bool positionedTop = false,
    bool haptics = false,
    VoidCallback? onVisible,
    VoidCallback? onClosed,
  }) {
    assert(message.isNotEmpty, 'Message cannot be empty');

    ScaffoldMessenger.of(_context)
      ..hideCurrentSnackBar()
      ..showSnackBar(_RelaySnackBar.success(
        _context,
        positionedTop: positionedTop,
        onVisible: onVisible,
        content: Text(message, style: TextStyle(color: Colors.black, fontSize: 14)),
      )).closed.then((_) {
        if (onClosed != null) onClosed();
      });

    if (haptics) {
      HapticFeedback.mediumImpact();
    }
  }

  void error(
    String message, {
    bool positionedTop = false,
    VoidCallback? onVisible,
    VoidCallback? onClosed,
  }) {
    assert(message.isNotEmpty, 'Message cannot be empty');

    ScaffoldMessenger.of(_context)
      ..hideCurrentSnackBar()
      ..showSnackBar(_RelaySnackBar.error(
        _context,
        positionedTop: positionedTop,
        onVisible: onVisible,
        content: Text(message),
      )).closed.then((_) {
        if (onClosed != null) onClosed();
      });
  }
}

EdgeInsets _computePositionedTopMargins(BuildContext context) =>
    EdgeInsets.only(bottom: MediaQuery.of(context).size.height / 1.3, right: 15, left: 15);

final class _RelaySnackBar {
  static SnackBar info(
    final BuildContext context, {
    required final Widget content,
    final Widget? leading,
    final Duration duration = const Duration(seconds: 2),
    bool positionedTop = false,
  }) {
    final theme = Theme.of(context);

    return SnackBar(
      backgroundColor: theme.relayColorScheme.info,
      content: _SnackBarContents(
        foregroundColor: theme.relayColorScheme.onInfo,
        leading: leading,
        content: content,
      ),
      duration: duration,
      margin: positionedTop ? _computePositionedTopMargins(context) : null,
    );
  }

  static SnackBar error(
    BuildContext context, {
    required Widget content,
    Widget? leading = const Icon(Icons.warning),
    VoidCallback? onVisible,
    bool positionedTop = false,
  }) {
    final theme = Theme.of(context);

    return SnackBar(
      backgroundColor: theme.relayColorScheme.danger,
      content: _SnackBarContents(
        foregroundColor: theme.relayColorScheme.onDanger,
        leading: leading,
        content: content,
      ),
      onVisible: onVisible,
      margin: positionedTop ? _computePositionedTopMargins(context) : null,
    );
  }

  static SnackBar success(
    BuildContext context, {
    required Widget content,
    Widget? leading = const Icon(Icons.check_circle),
    VoidCallback? onVisible,
    bool positionedTop = false,
  }) {
    final theme = Theme.of(context);

    return SnackBar(
      backgroundColor: theme.colorScheme.primary,
      content: _SnackBarContents(
        foregroundColor: theme.colorScheme.onPrimary,
        leading: leading,
        content: content,
      ),
      onVisible: onVisible,
      margin: positionedTop ? _computePositionedTopMargins(context) : null,
    );
  }
}

class _SnackBarContents extends StatelessWidget {
  const _SnackBarContents({
    this.foregroundColor,
    this.leading,
    required this.content,
  });

  final Color? foregroundColor;

  final Widget? leading;
  final Widget content;

  @override
  Widget build(BuildContext context) {
    final theme = Theme.of(context);

    return Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        if (leading != null)
          Padding(
            padding: const EdgeInsetsDirectional.only(end: 12.0),
            child: IconTheme.merge(
              data: IconThemeData(
                color: foregroundColor,
                size: 16,
              ),
              child: leading!,
            ),
          ),
        Expanded(
          child: DefaultTextStyle(
            style: theme.textTheme.titleMedium!.copyWith(
              color: foregroundColor,
            ),
            child: content,
          ),
        ),
      ],
    );
  }
}
