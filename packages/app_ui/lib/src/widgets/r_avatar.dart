import 'package:flutter/material.dart';

class RAvatar extends StatelessWidget {
  const RAvatar({super.key, required this.imageUrl, this.label});
  final String imageUrl;
  final String? label;

  @override
  Widget build(BuildContext context) {
    return SizedBox(
        height: 145,
        child: Stack(children: [
          if (label != null)
            Positioned(
                bottom: 0,
                left: 0,
                right: 0,
                child: Center(
                    child: Container(
                  padding:
                      const EdgeInsets.symmetric(horizontal: 15, vertical: 15),
                  decoration: BoxDecoration(
                    color: Theme.of(context).primaryColor,
                    borderRadius: BorderRadius.circular(1000),
                  ),
                  child: Text(
                    label!,
                    style: Theme.of(context)
                        .textTheme
                        .bodyLarge!
                        .copyWith(color: Colors.black, height: 1),
                  ),
                ))),
          Positioned(
            top: 0,
            left: 0,
            right: 0,
            child: Center(
              child: Container(
                decoration: BoxDecoration(
                    shape: BoxShape.circle,
                    border: Border.all(
                        color: Theme.of(context).canvasColor, width: 4)),
                child: CircleAvatar(
                  radius: 50,
                  backgroundImage: NetworkImage(
                    imageUrl,
                  ),
                  backgroundColor: Theme.of(context).primaryColor,
                ),
              ),
            ),
          ),
        ]));
  }
}
