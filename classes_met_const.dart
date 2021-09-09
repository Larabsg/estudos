class Animal {
  String nome = "";
  double peso = 0.0;

  Animal(this.nome, this.peso);

  void comeu() {
    print("$nome comeu!");
  }

  void som() {
    print("$nome fez som!");
  }
}

class Cachorro extends Animal {
  int fofura = 0;

  Cachorro(String nome, double peso, this.fofura) : super(nome, peso);

  void brincar() {
    fofura += 10;
    print("Fofura de $nome aumentou para $fofura!!!");
  }

  @override
  void som() {
    print("$nome fez auau!");
  }

  @override
  String toString() {
    return "Cachorro | Nome: $nome | Peso: $peso | Fofura: $fofura";
  }
}

class Gato extends Animal {
  Gato(String nome, double peso) : super(nome, peso);

  bool amigavel() {
    return true;
  }

  @override
  void som() {
    print("$nome fez miaaaaau!");
  }

  @override
  String toString() {
    return "Gato | Nome: $nome | Peso: $peso";
  }
}

void main() {
  Cachorro dog = Cachorro("Dandara", 10.0, 100);
  Gato cat = Gato("Kiou", 5.0);

  dog.brincar();
  dog.comeu();
  dog.brincar();

  print("${cat.nome} está amigável? ${cat.amigavel()}");

  dog.som();

  cat.som();

  print(dog);
  print(cat);
}
