#include <stdlib.h>
#include "matriz.h"

struct matriz {
	int lin;
	int col;
	float** v;
};

Matriz* mat_cria (int l, int c) {
	int i, j;
	
	Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
	mat->lin = l;
	mat->col = c;
	
	mat->v = (float**)malloc(l * sizeof(float*));
	
	for(i = 0; i < l; i++) {
		mat->v[i] = (float*)malloc(c * sizeof(float));
	}
	
	for(i = 0; i < l; i++)
		for(j = 0; j < c; j++)
			scanf("%f", &mat->v[i][j]);
			
	return mat;
	
}

void mat_imprime(Matriz* mat) {
	int i, j;
	
	for(i = 0; i < mat->lin; i++) {
		for(j = 0; j < mat->col; j++)
			printf("%.1f\t", mat->v[i][j]);
		
		printf("\n");
	}
}

void mat_libera (Matriz* mat) {
	int i;
	
	for(i = 0; i <mat->lin; i++)
		free(mat->v[i]);
	
	free(mat->v);
}
