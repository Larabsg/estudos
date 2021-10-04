import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    home: Home(),
  ));
}

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {

  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController pesoController = TextEditingController();
  TextEditingController alturaController = TextEditingController();
  String _info = "Informe seus dados";

  void _reset() {
    pesoController.text = "";
    alturaController.text = "";
    setState(() {
      _info = "Informe seus dados";
    });
  }

  void _imc() {
    setState(() {
      double peso = double.parse(pesoController.text);
      double altura = double.parse(alturaController.text) / 100;

      double imc = peso/(altura*altura);

      if(imc < 18.5) {
        _info = "Abaixo do peso: ${imc.toStringAsPrecision(4)}";
      } else if(imc < 24.9) {
        _info = "Normal: ${imc.toStringAsPrecision(4)}";
      } else if (imc < 30) {
        _info = "Sobrepeso: ${imc.toStringAsPrecision(4)}";
      } else {
        _info = "Obesidade: ${imc.toStringAsPrecision(4)}";
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Calculadora de IMC"),
        centerTitle: true,
        backgroundColor: Colors.deepPurple,
        actions: [IconButton(icon: Icon(Icons.refresh), onPressed: _reset)],
      ),
      backgroundColor: Colors.white,
      body: SingleChildScrollView(
        padding: EdgeInsets.only(left: 10.0, right: 10.0),
        child: Form(
          key: _formKey,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              Icon(Icons.person_outline, size: 120.0, color: Colors.deepPurple),
              TextFormField(
                keyboardType: TextInputType.number,
                decoration: InputDecoration(
                    labelText: "Peso (kg)",
                    labelStyle: TextStyle(color: Colors.deepPurple)),
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 25.0, color: Colors.deepPurple),
                controller: pesoController,
                validator: (value) {
                  if(value.isEmpty) {
                    return "Informe seu peso";
                  }
                  return null;
                },
              ),
              TextFormField(
                keyboardType: TextInputType.number,
                decoration: InputDecoration(
                    labelText: "Altura (cm)",
                    labelStyle: TextStyle(color: Colors.deepPurple)),
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 25.0, color: Colors.deepPurple),
                controller: alturaController,
                validator: (value) {
                  if(value.isEmpty) {
                    return "Informe sua altura";
                  }
                  return null;
                },
              ),
              Padding(padding: EdgeInsets.only(top: 10.0, bottom: 10.0),
                child: Container(
                  height: 50.0,
                  child: RaisedButton(
                    onPressed: () {
                      if(_formKey.currentState.validate()) {
                        _imc();
                      }
                    },
                    child: Text("Calcular",
                        style: TextStyle(color: Colors.white, fontSize: 25.0)),
                    color: Colors.deepPurple,
                  ),
                ),
              ),
              Text(_info,
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 25.0, color: Colors.deepPurple),
              )
            ],
          ),
        )
      )
    );
  }
}
