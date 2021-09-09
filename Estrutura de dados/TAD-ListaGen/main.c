#include <stdio.h>
#include <locale.h>
#include "listagen.h"

void imprime_aluno(void* vals);

int main() {
	
	setlocale(LC_ALL, "");
	
	ListaGen* LG = lgen_cria();
	
	if(lgen_vazia(LG))
		printf("Lista vazia!\n");
	else
		printf("Lista não está vazia!\n");
	
	lgen_imprime(LG, imprime_aluno);
	
	return 0;
}

void imprime_aluno(void* vals) {
	Aluno* alun = (Aluno*)vals;
	printf("\n_____________________________\n");
	printf("Matrícula: %d\n", alun->mat);
	printf("Nome: %s\n", alun->nome);
	printf("Email: %s\n", alun->email);
	printf("______________________________\n");
}
