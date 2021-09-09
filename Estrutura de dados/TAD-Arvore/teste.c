#include <stdio.h>

int retorne(int valor) {
  printf("RETORNE %d\n", valor);
  return valor;
}

int main() {
  return (retorne(0) || retorne(1) || retorne(2));
}
