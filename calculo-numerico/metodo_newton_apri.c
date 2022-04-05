#include <stdio.h>
#include <stdlib.h>

float acha_x(int grau, float ini, float x, float *coefs) {
    static float b;
    
    if(grau > 0) {
        
        b = coefs[grau-1] + ini * x;
        printf("%d -> %f\n",grau, b);        
        acha_x(grau-1, b, x, coefs);
        
    } else {
        return b;
    }
}

int main()
{
    int grau, i;
    float x0, precisao;
    float *coef;
    float *aux;
    float resultado;
    
    
    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);
    
    coef = (float*)malloc(grau * sizeof(float));
    aux = (float*)malloc(grau * sizeof(float));
    
    printf("Digite o X0: ");
    scanf("%f", &x0);
    
    // printf("Digite o valor da precisão: ");
    // scanf("%f", &precisao);
    
    for(i = grau; i >= 0; i--) {
        printf("Digite o valor do coeficiente a%d: ", i);
        scanf("%f", &coef[i]);
    }
    
    printf("Resultado: %f", acha_x(grau, coef[grau], x0, coef));
    

    return 0;
}
