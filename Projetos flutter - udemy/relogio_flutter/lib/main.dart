import 'package:flutter/material.dart';
import 'Homepage.dart';

void main() {
  runApp(MaterialApp(
    builder: (context, child) => MediaQuery(
      data: MediaQuery.of(context).copyWith(alwaysUse24HourFormat: true),
      child: child!),
    debugShowCheckedModeBanner: false,
    home: HomePage(),
  ));
}
