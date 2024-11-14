// ignore_for_file: public_member_api_docs

import 'dart:async';

import 'package:flutter/material.dart';

class RCountdownText extends StatefulWidget {
  const RCountdownText(
      {super.key, required this.expiration, this.outOfTimeDialog, this.showHours = false});
  final DateTime expiration;
  final bool showHours;
  final Widget? outOfTimeDialog;

  @override
  State<RCountdownText> createState() => _RCountdownState();
}

class _RCountdownState extends State<RCountdownText> {
  Timer? countdownTimer;

  Duration? remainingSeconds;

  @override
  void initState() {
    // if (widget.expiration.isAfter(DateTime.now())) {
    remainingSeconds = widget.expiration.difference(DateTime.now());

    startTimer();
    // }

    super.initState();
  }

  @override
  void didUpdateWidget(covariant RCountdownText oldWidget) {
    //  if (widget.expiration.isAfter(DateTime.now())) {
    remainingSeconds = widget.expiration.difference(DateTime.now());
    //   }

    super.didUpdateWidget(oldWidget);
  }

  @override
  void didChangeDependencies() {
    super.didChangeDependencies();
  }

  void startTimer() {
    countdownTimer = Timer.periodic(const Duration(seconds: 1), (_) => setCountDown());
  }

  Future<void> setCountDown() async {
    const reduceSecondsBy = 1;
    if (mounted && remainingSeconds != null) {
      setState(() {
        final seconds = remainingSeconds!.inSeconds - reduceSecondsBy;
        if (seconds < 0) {
          countdownTimer?.cancel();
          if (widget.outOfTimeDialog != null) {
            showDialog(
              barrierDismissible: false,
              context: context,
              builder: (context) => widget.outOfTimeDialog!,
            );
          }
        } else {
          remainingSeconds = Duration(seconds: seconds);
        }
      });
    }
  }

  @override
  void dispose() {
    countdownTimer?.cancel();
    //dialogTimer?.cancel();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    if (remainingSeconds != null) {
      String strDigits(int n) => n.toString().padLeft(2, '0');
      final hours = strDigits(remainingSeconds!.inHours.remainder(24));
      final minutes = strDigits(remainingSeconds!.inMinutes.remainder(60));
      final seconds = strDigits(remainingSeconds!.inSeconds.remainder(60));

      return Text(
        '${widget.showHours ? '$hours:' : ''}$minutes.$seconds',
        style: Theme.of(context).textTheme.titleSmall,
      );
    } else {
      return const SizedBox.shrink();
    }
  }
}
