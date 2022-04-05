#include <stdio.h>
#include <stdlib.h>

//static 

float* acha_x(int grau, float ini, float ini_der, float x, float *coefs) {
    
    float *b; 
    float *c; // valor de x na derivada

    b = (float*)malloc(grau * sizeof(float));
    c = (float*)malloc(grau * sizeof(float));

    //size_t n = sizeof(c)/sizeof(c[grau]);
    
    if(grau > 0) {
        
        b[grau] = coefs[grau-1] + ini * x;
        c[grau] = b[grau] + ini_der * x;

        printf("b%d -> %f\n", grau-1, b[grau]);        
        printf("c%d -> %f\n", grau-1, c[grau]);   

        acha_x(grau-1, b[grau], c[grau], x, coefs);
        
    } else {
        return b;
    }
}

int main()
{
    int grau=3, i;
    float x0=0.5, precisao;
    float *coef;
    float *aux;
    float resultado;
    
    
    //printf("Digite o grau do polinomio: ");
    //scanf("%d", &grau);
    
    coef = (float*)malloc(grau * sizeof(float));
    //aux = (float*)malloc(grau * sizeof(float));
    
    //printf("Digite o X0: ");
    //scanf("%f", &x0);
    
    // printf("Digite o valor da precisão: ");
    // scanf("%f", &precisao);
    
    for(i = grau; i >= 0; i--) {
        printf("Digite o valor do coeficiente a%d: ", i);
        scanf("%f", &coef[i]);
    }

    aux = acha_x(grau, coef[grau], coef[grau], x0, coef);

    printf("Resultado: %f", aux[0]);
    

    return 0;
}
