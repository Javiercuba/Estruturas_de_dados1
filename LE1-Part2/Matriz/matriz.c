#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include <time.h>

int main()
{
    int A[TAM][TAM];
    int B[TAM][TAM];
    int valor;

    clock_t t0, tf;

    printf("MATRIZ A\n");
    preenche_matriz(A);
    printf("MATRIZ B\n");
    preenche_matriz(B);
    printf("Voce deseja atribuir qual operacao nas matrizes\n 1-Somar\n 2-Multiplicar\n");
    scanf("%d", &valor);
    printf("\n");
    /*
        Tamanho n | Tempo Soma | Numero operacoes Soma| Tempo Multiplicacao | Numero operacoes Multi
           100       0.0002 ms           10000                0.0071 ms            1000000
           200       0.0007 ms           40000                0.0522 ms            8000000
           300       0.0011 ms           90000                0.0928 ms           27000000
           400       0.0021 ms          160000                0.1842 ms           64000000
           500       0.0025 ms          250000                0.3532 ms          125000000
           800       0.0071 ms          640000                1.5606 ms          512000000
    */

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