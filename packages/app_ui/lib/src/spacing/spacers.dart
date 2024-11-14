import 'package:flutter/material.dart';

double _space = 8;

class Spacer1 extends StatelessWidget {
  const Spacer1({super.key});

  @override
  Widget build(BuildContext context) => SizedBox.square(dimension: _space);
}

class Spacer2 extends StatelessWidget {
  const Spacer2({super.key});

  @override
  Widget build(BuildContext context) => SizedBox.square(dimension: _space * 2);
}

class Spacer3 extends StatelessWidget {
  const Spacer3({super.key});

  @override
  Widget build(BuildContext context) => SizedBox.square(dimension: _space * 3);
}

class Spacer4 extends StatelessWidget {
  const Spacer4({super.key});

  @override
  Widget build(BuildContext context) => SizedBox.square(dimension: _space * 4);
}

class Spacer5 extends StatelessWidget {
  const Spacer5({super.key});

  @override
  Widget build(BuildContext context) => SizedBox.square(dimension: _space * 5);
}
