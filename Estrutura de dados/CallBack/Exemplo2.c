#include <stdio.h>

float pi(void) {
	return (float)3.14;
}

float raiz_de_2(void) {
	return (float)1.42;
}

void imprime(float(*funcao)(void)) {
	printf("%.2f", funcao());
}

int main() {
	
	imprime(pi);
	
	return 0;
}
