#ifndef matriz_h
#define matriz_h
#include <stdio.h>
#include <stdlib.h>


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

int soma_matrizes(int A[3][3], int B[3][3])
{
    int resultado[3][3];
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

int multiplica_matrizes(int A[3][3], int B[3][3])
{
    int resultado[3][3];
    int aux=0;
    for (int x = 0; x < 3; x++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                aux = aux + A[i][j] * B[j][x];
            }
            resultado[i][x] = aux;
            aux = 0;
        }
        //printf("%d %d %d\n", resultado[x][0], resultado[x][1], resultado[x][2]);
    }

    
        for (int x = 0; x < 3; x++)
        {
            printf("%d %d %d\n", resultado[x][0], resultado[x][1], resultado[x][2]);
        }
}

#endif