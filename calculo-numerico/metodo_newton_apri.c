#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void acha_x(float *v, float *vd, int grau, float ini, float ini_der, float x, float *coefs)
{
    float b, c;

    if (grau > 0)
    {
        b = coefs[grau - 1] + ini * x;
        c = b + ini_der * x;

        v[grau - 1] = b;
        vd[grau - 1] = c;

        acha_x(v, vd, grau - 1, b, c, x, coefs);
    }
}

float Abs(float x)
{
    x = sqrt(x * x);
    return x;
}

int main()
{
    int grau, i, cont = 1;
    float x0, precisao, fx, fx2, xn;
    float *coef;
    float *aux, *aux2;

    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);

    coef = (float *)malloc(grau * sizeof(float));
    aux = (float *)malloc(grau * sizeof(float));
    aux2 = (float *)malloc(grau * sizeof(float));

    printf("Digite o X0: ");
    scanf("%f", &xn);

    printf("Digite o valor da precisao: ");
    scanf("%f", &precisao);

    for (i = grau; i >= 0; i--)
    {
        printf("Digite o valor do coeficiente a%d: ", i);
        scanf("%f", &coef[i]);
    }

    do
    {
        printf("_____________________________");
        printf("\nIteracao = %d\n\n", cont);

        x0 = xn;
        
        acha_x(aux, aux2, grau, coef[grau], coef[grau], x0, coef);

        for (int i = grau-1; i >= 0; i--)
            printf("b%d-> %f\n", i, aux[i]);
        puts("\n");
        for (int i = grau-1; i >= 1; i--)
            printf("c%d-> %f\n", i, aux2[i]);

        fx = aux[0];
        fx2 = aux2[1];
        xn = x0 - (fx / fx2);

        cont++;

        printf("\nx0 = %f\nxn = %f\n", x0, xn);

    } while (Abs(xn - x0) >= precisao || Abs(fx) >= precisao);

    printf("______________________________\n");
    printf("\nxn - x0 = %f\n", xn - x0);
    printf("Aproximacao de x: %f\n", xn);
    printf("Quantidade de iteracoes: %d\n", cont-1);
    printf("______________________________\n");

    return 0;
}
