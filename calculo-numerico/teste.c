#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void acha_x(float *v, float *vd, int grau, float ini, float ini_der, float x, float *coefs) {
   float b, c;
    
    if(grau > 0) {
        
        b = coefs[grau-1] + ini * x;
        c = b + ini_der * x;

        v[grau-1] = b;
        vd[grau-1] = c;

        printf("b%d -> %f\n", grau-1, b);        
        printf("c%d -> %f\n", grau-1, c);   

        acha_x(v, vd, grau-1, b, c, x, coefs);
        
    } 
}

void formula_newton(float *v, float *vd, int grau, float *coefs, float x0, float fx, float fx_der, float precisao) {
  float x;
   

   if(fx > precisao) {
    x = x0-(fx/fx_der);
     acha_x(v, vd, grau, x, x, x0, coefs);
     formula_newton(v, vd, grau, coefs, x, v[0], vd[1], precisao);
     printf("%f", x);
   }

   //return x;
}

int main()
{
    int grau=3, i;
    float x0=0.5, precisao = pow(10, -5);
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

    puts("Resultado x1:");
    // for (int i = 0; i < grau; i++)
    //   printf("b%d->%f\n",i, aux[i]);
    // puts("\n");
    // for (int i = 1; i < grau; i++)
    //   printf("c%d->%f\n", i, aux2[i]);
    formula_newton(aux, aux2, grau, coef, x0, aux[0], aux2[1], precisao);

    //printf("%f", resultado);

    return 0;
}
