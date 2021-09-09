#include <stdio.h>

void soma(int a, int b) {
	printf("%d + %d = %d\n", a, b, a+b);
}

void imprime(void (*ptr)(int, int)) {
	int a =10, b=13;
	
	ptr(a, b);
}

int main() {
	
	imprime(soma);
	
	return 0;
}
