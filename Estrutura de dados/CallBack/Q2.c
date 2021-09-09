#include <stdio.h>
#define N 10

float soma_vetor(float* vetor, int n) {
	int i, soma=0;
	for(i = 0; i < n; i++) {
		soma+=vetor[i];
	}
	
	return soma;
}

float exec_vetor(float(*f)(float*, int), float* vetor, int n){
	float resul = f(vetor, n);
	
	return resul;
}

int main() {
	
	float v[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
	
	float a = exec_vetor(soma_vetor, v, N);
	
	printf("A soma eh: %.2f", a);
	
	return 0;
}
