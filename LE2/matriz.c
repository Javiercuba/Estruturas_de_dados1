#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include <time.h>

int main()
{
    int A[3][3];
    int B[3][3];
    int valor;

    clock_t t0, tf;

    printf("MATRIZ A\n");
    preenche_matriz(A);
    printf("MATRIZ B\n");
    preenche_matriz(B);
    printf("Voce deseja atribuir qual operacao nas matrizes\n 1-Somar\n 2-Multiplicar\n");
    scanf("%d", &valor);
    printf("\n");

    switch (valor)
    {
   case 1:
        printf("SOMA A + B\n");
        t0 = clock();
        soma_matrizes(A, B);
        tf = clock();
        calcula_tempo(t0, tf);

        break;

    case 2:
        printf("MULTIPLICA A * B\n");
        t0 = clock();
        multiplica_matrizes(A, B);
        tf = clock();
        calcula_tempo(t0, tf);
        main();
        break;
    case 3:
        printf("MULTIPLICA e SOMA A e B\n");
        t0 = clock();
        printf("SOMA A + B\n");
        soma_matrizes(A, B);
        printf("MULTIPLICA A * B\n");
        multiplica_matrizes(A, B);
        tf = clock();
        calcula_tempo(t0, tf);
        break;
    default:
        printf("Essa opção não existe!\n");
        break;
    }
    
}