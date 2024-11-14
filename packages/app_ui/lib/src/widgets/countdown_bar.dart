// ignore_for_file: public_member_api_docs

import 'dart:async';

import 'package:flutter/material.dart';

class RCountdownBar extends StatefulWidget {
  const RCountdownBar({super.key, required this.expiration});
  final DateTime expiration;

  @override
  State<RCountdownBar> createState() => _RCountdownState();
}

class _RCountdownState extends State<RCountdownBar> {
  Timer? countdownTimer;
  late Duration remainingSeconds;
  late Duration overallDuration;

  @override
  void initState() {
    remainingSeconds = widget.expiration.difference(DateTime.now());
    overallDuration = const Duration(seconds: 60);
    startTimer();
    super.initState();
  }

  void startTimer() {
    countdownTimer = Timer.periodic(const Duration(seconds: 1), (_) => setCountDown());
  }

  void setCountDown() {
    const reduceSecondsBy = 1;
    if (mounted) {
      setState(() {
        final newSeconds = remainingSeconds.inSeconds - reduceSecondsBy;
        if (newSeconds < 0) {
          countdownTimer!.cancel();
        } else {
          remainingSeconds = Duration(seconds: newSeconds);
        }
      });
    }
  }

  @override
  void dispose() {
    countdownTimer?.cancel();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(
      builder: (context, constraints) {
        final width = constraints.maxWidth;
        final progressWidth = (remainingSeconds.inSeconds * width) / overallDuration.inSeconds;
        return Container(
          alignment: Alignment.center,
          width: width,
          height: 10,
          decoration: const BoxDecoration(
            color: Colors.black,
            borderRadius: BorderRadius.all(Radius.circular(10)),
          ),
          child: Align(
            alignment: Alignment.centerLeft,
            child: AnimatedContainer(
              duration: const Duration(milliseconds: 1000),
              width: progressWidth,
              height: 10,
              decoration: BoxDecoration(
                color: Theme.of(context).colorScheme.primary,
                borderRadius: const BorderRadius.all(Radius.circular(10)),
              ),
            ),
          ),
        );
      },
    );
  }
}
