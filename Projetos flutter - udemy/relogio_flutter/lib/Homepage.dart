import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {


  @override
  Widget build(BuildContext context) {

    return Scaffold(
      body: Center(
        child: RawMaterialButton(
          fillColor: Colors.blue,
          child: Text(_selectedTime,
            style: TextStyle(color: Colors.white),),
          onPressed: () {
            _openTimePicker(context);
          },
        ),
      ),
    );
  }
}

void inputTimeSelect() async {

  Future<void> _openTimePicker(BuildContext context) async {
    final TimeOfDay? t =
    await showTimePicker(context: context, initialTime: TimeOfDay.now());

    if (t != null) {
      setState(() {
        _selectedTime = t.format(context);
      });
    }
  }
}
