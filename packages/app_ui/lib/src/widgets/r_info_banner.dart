import 'package:app_ui/src/domain/banner_type.dart';
import 'package:auto_size_text/auto_size_text.dart';

import '../../app_ui.dart';
import 'package:flutter/material.dart';

class RInfoBanner extends StatelessWidget {
  const RInfoBanner({
    super.key,
    required this.title,
    this.subtitle,
    required this.leading,
    required this.type,
    this.onTap,
    this.bottom,
  });
  final String title;
  final String? subtitle;
  final dynamic leading;
  final Widget? bottom;
  final BannerType type;
  final Function()? onTap;

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: onTap,
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 15, vertical: 15),
        decoration: BoxDecoration(
          color: type.backgroundColor,
          borderRadius: BorderRadius.circular(8),
          border: Border.all(color: type.borderColor),
        ),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Row(
              children: [
                leading is AssetGenImage
                    ? (leading as AssetGenImage).image(width: 45)
                    : leading,
                const Spacer2(),
                Expanded(
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        AutoSizeText(
                          title,
                          maxLines: 2,
                          style: Theme.of(context)
                              .textTheme
                              .titleSmall!
                              .copyWith(
                                  color: type.foregroundColor,
                                  fontSize: 15,
                                  height: 1.1),
                        ),
                        if (subtitle != null) ...[
                          const Spacer1(),
                          AutoSizeText(
                            subtitle!,
                            maxLines: 2,
                            style: Theme.of(context)
                                .textTheme
                                .bodyMedium!
                                .copyWith(
                                    color: type.foregroundColor,
                                    fontSize: 13,
                                    height: 1.1),
                          ),
                        ]
                      ]),
                ),
                if (onTap != null)
                  Icon(Icons.chevron_right_rounded, color: type.foregroundColor)
              ],
            ),
            if (bottom != null) ...[const Spacer1(), bottom!],
          ],
        ),
      ),
    );
  }
}
