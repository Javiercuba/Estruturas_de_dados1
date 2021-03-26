#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int preenche_matriz(int matriz[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            matriz[x][y] = rand() % 10;
        }

        printf("%d %d %d\n", matriz[x][0], matriz[x][1], matriz[x][2]);
    }
    printf("\n");
}

int soma_matrizes(int A[3][3], int B[3][3], int resultado[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {

            resultado[x][y] = (A[x][y] + B[x][y]);
        }

        printf("%d %d %d\n", resultado[x][0], resultado[x][1], resultado[x][2]);
    }
    printf("\n");
}
int multiplica_matrizes(int A[3][3], int B[3][3], int resultado[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {

            resultado[x][y] = (A[x][x] * B[x][y]) + (A[x][y] * B[x+1][x]);
        }

        printf("%d %d %d\n", resultado[x][0], resultado[x][1], resultado[x][2]);
    }
    printf("\n");
}

int main()
{
    int A[3][3];
    int B[3][3];
    int resultado[3][3];

    printf("-MATRIZ A\n");
    preenche_matriz(A);
    printf("-MATRIZ B\n");
    preenche_matriz(B);
    printf("-SOMATORIO A + B\n");
    soma_matrizes(A, B, resultado /*Simbolo da esquacao*/);
    printf("-MULTIPLICACAO A + B\n");
    multiplica_matrizes(A, B, resultado /*Simbolo da esquacao*/);
}