import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';
import 'package:user_tracing/trace.dart';

class RListTile extends StatelessWidget {
  const RListTile({
    Key? key,
    required this.leading,
    required this.title,
    required this.traceName,
    this.trailing,
    this.description,
    this.onTap,
    this.props,
  }) : super(key: key);
  final Widget leading;
  final Widget? trailing;
  final String title;
  final String? description;
  final String traceName;
  final Function()? onTap;
  final Map<String, dynamic>? props;

  @override
  Widget build(BuildContext context) {
    return Container(
        margin: const EdgeInsets.only(bottom: 10, left: 12, right: 12),
        decoration: BoxDecoration(borderRadius: BorderRadius.circular(24)),
        child: InkWell(
            onTap: Trace.wrapNullableHandler(onTap, traceName, 'list_tile',
                props: props, traceProps: props, sendAnalytics: true),
            child: Container(
                padding:
                    const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
                decoration: BoxDecoration(
                  color: Theme.of(context).colorScheme.surface,
                  borderRadius: BorderRadius.circular(24),
                ),
                child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Expanded(
                        child: Row(
                          children: [
                            leading,
                            const Spacer2(),
                            Flexible(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text(
                                    title,
                                    style:
                                        Theme.of(context).textTheme.titleMedium,
                                  ),
                                  if (description != null) ...[
                                    const SizedBox(height: 2),
                                    Text(
                                      description!,
                                      style: Theme.of(context)
                                          .textTheme
                                          .bodyMedium!
                                          .copyWith(
                                              color: Theme.of(context)
                                                  .colorScheme
                                                  .onSurface),
                                    )
                                  ],
                                ],
                              ),
                            ),
                          ],
                        ),
                      ),
                      if (trailing != null || onTap != null)
                        Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            if (trailing != null) trailing!,
                            if (onTap != null)
                              Padding(
                                padding: const EdgeInsets.only(left: 8.0),
                                child: Assets.icons.chevronRight.svg(),
                              ),
                          ],
                        )
                    ]))));
  }
}
