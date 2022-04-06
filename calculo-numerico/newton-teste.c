#include <stdio.h>
#include <stdlib.h>



float b;

void
acha_x(float *b, float *c, int grau, float ini, float ini_der, float x, float *coefs) {

    //size_t n = sizeof(c)/sizeof(c[grau]);
    /*
    if (!b)
      b = (float*)malloc(grau * sizeof(float));
    if (!c)
      c = (float*)malloc(grau * sizeof(float));
    */
    if(grau > 0) {
        b[grau-1] = coefs[grau] + ini * x;
        c[grau-1] = b[grau-1] + ini_der * x;

        printf("b%d -> %f\n", grau, b[grau-1]);        
    //printf("c%d -> %f\n", grau, c[grau-1]);   

        acha_x(b, c, --grau, b[grau-1], c[grau-1], x, coefs);
        
    }/* 
    else {
        return b;
    }*/
}


#include <string.h>

int main()
{
    int grau=3, i;
    float x0=0.5, precisao;
    float *coef;
    float *aux, *aux2;
    float resultado;
    
    
    //printf("Digite o grau do polinomio: ");
    //scanf("%d", &grau);
    
    coef = (float*)malloc(grau * sizeof(float));
    aux = (float*)malloc(grau * sizeof(float));
    aux2 = (float*)malloc(grau * sizeof(float));
    
    //printf("Digite o X0: ");
    //scanf("%f", &x0);
    
    // printf("Digite o valor da precisão: ");
    // scanf("%f", &precisao);
    
    for(i = grau; i >= 0; i--) {
        printf("Digite o valor do coeficiente a%d: ", i);
        scanf("%f", &coef[i]);
    }


    acha_x(aux, aux2, grau, coef[grau], coef[grau], x0, coef);

    printf("Resultado: %f", aux[2]);
    

    return 0;
}
