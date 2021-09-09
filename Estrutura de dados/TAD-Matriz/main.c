#include <stdio.h>
#include "matriz.h"

int main() {
	
	int l, c;
	
	printf("Digite o numero de linhas e colunas da matriz: ");
	scanf("%d %d", &l, &c);
	
	printf("Digite os valores para a matriz %d X %d: ", l, c);
	Matriz* mat = mat_cria(l, c);
	
	mat_imprime(mat);
	
	printf("\nNumero de linhas: %d\n", l);
	printf("Numero de colunas: %d\n", c);
	
	mat_libera(mat);
	
	return 0;
}
