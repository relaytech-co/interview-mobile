import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

import '../../app_ui.dart';

class RSwitch extends StatelessWidget {
  const RSwitch({
    Key? key,
    required this.isSelected,
    this.thumbSize = 30,
    required this.traceName,
    required this.props,
    required this.onSelect,
    this.selectedLabel,
    this.unselectedLabel,
  }) : super(key: key);
  final bool isSelected;
  final Function() onSelect;
  final double thumbSize;
  final String traceName;
  final Map<String, dynamic> props;
  final String? selectedLabel;
  final String? unselectedLabel;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: Trace.wrapHandler(onSelect, traceName, 'switch', traceProps: props),
      child: Container(
        width: thumbSize * 2 + 10,
        padding: const EdgeInsets.all(2),
        decoration: BoxDecoration(
            borderRadius: BorderRadius.circular(30),
            color: Theme.of(context).colorScheme.surfaceVariant),
        child: Stack(
          alignment: Alignment.center,
          children: [
            AnimatedContainer(
              alignment: isSelected ? Alignment.centerRight : Alignment.centerLeft,
              duration: const Duration(milliseconds: 250),
              child: Container(
                width: thumbSize,
                height: thumbSize,
                decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(30),
                    color: isSelected
                        ? Theme.of(context).primaryColor
                        : Theme.of(context).colorScheme.onSurface),
              ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              crossAxisAlignment: CrossAxisAlignment.center,
              children: [
                Visibility(
                    visible: isSelected,
                    child: Text(
                      selectedLabel ?? 'On',
                      style: TextStyle(
                          color: isSelected
                              ? Colors.white
                              : Theme.of(context).colorScheme.surfaceVariant),
                    )),
                const Spacer1(),
                Visibility(
                  visible: !isSelected,
                  child: Text(
                    unselectedLabel ?? 'Off',
                    style: TextStyle(
                        color: !isSelected
                            ? Colors.white
                            : Theme.of(context).colorScheme.surfaceVariant),
                  ),
                )
              ],
            ),
          ],
        ),
      ),
    );
  }
}
