#include <stdio.h>

float soma(float a, float b) {
	return a+b;
}

float subtrai(float a, float b) {
	return a-b;
}

void imprime(float (*funcao)(float, float)) {
	float a=(float)13,b=(float)1.14;
	printf("%.2f+%.2f=%.2f\n", a, b, funcao(a, b));
}

int main() {
	
	imprime(soma);
	
	return 0;
}
