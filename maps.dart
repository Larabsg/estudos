class InfoPessoa {
  int idade;

  InfoPessoa(this.idade);
}

void main() {
  Map<int, String> dds = <int, String>{};
  dds[11] = "São Paulo";
  dds[88] = "Aracati";
  dds[85] = "Fortaleza";

  print(dds);
  print(dds.keys);
  print(dds.values);

  dds.remove(11);
  print(dds);

  Map<String, dynamic> pessoa = <String, dynamic>{};
  pessoa["nome"] = "Enzo";
  pessoa["idade"] = 19;
  pessoa["altura"] = 1.76;

  Map<String, InfoPessoa> pessoas = <String, InfoPessoa>{};
  pessoas["João"] = InfoPessoa(19);
  pessoas["Edsom"] = InfoPessoa(19);
  pessoas["Lara"] = InfoPessoa(25);
}
