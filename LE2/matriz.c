#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

int main()
{
    int A[3][3];
    int B[3][3];
    int resultado[3][3];
    int valor;
    printf("MATRIZ A\n");
    preenche_matriz(A);
    printf("MATRIZ B\n");
    preenche_matriz(B);
    printf("Voce deseja atribuir qual operacao nas matrizes\n 1-Somar\n 2-Multiplicar\n\n ");
    scanf("%d", &valor);
   
    
    switch (valor)
    {
   case 1:
        printf("SOMA A + B\n");
        soma_matrizes(A, B);
        break;

    case 2:
        multiplica_matrizes(A, B);
        break;
    default:
        printf("Essa opção não existe!\n");
        break;
    }
    
}