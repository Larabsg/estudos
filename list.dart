class Pessoa {
  String nome;
  int idade;

  Pessoa(this.nome, this.idade);
}

void main() {
  List<String> nomes = ["Lara", "Mari", "Edsom"];

  print(nomes[0]);

  nomes.add("Joelma"); // adiciona na lista
  print(nomes);

  print(nomes.length); //imp tamanho da lista

  nomes.removeAt(1); // remove pelo indice
  print(nomes);

  nomes.insert(0, "Dandara"); // insere no indice indicado
  print(nomes);

  print(nomes.contains("Edsom")); // verifica se contém

  List<Pessoa> pessoas = [];

  pessoas.add(Pessoa("Lara", 19));
  pessoas.add(Pessoa("Edsom", 20));

  for (Pessoa p in pessoas) {
    print("${p.nome} tem ${p.idade} anos");
  }
}
