#ifndef matriz_h
#define matriz_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 800

int preenche_matriz(int matriz[TAM][TAM])
{
    for (int x = 0; x < TAM; x++)
    {
        for (int y = 0; y < TAM; y++)
        {
            matriz[x][y] = rand() % 10;
        }
    }
    printf("\n");
}

int soma_matrizes(int A[TAM][TAM], int B[TAM][TAM])
{
    int numero_interacoes = 0;
    int resultado[TAM][TAM];
    for (int x = 0; x < TAM; x++)
    {
        for (int y = 0; y < TAM; y++)
        {

            resultado[x][y] = (A[x][y] + B[x][y]);
            numero_interacoes++;
        }
    }
    printf("Numero de interacoes da soma : %d\n", numero_interacoes);
    printf("\n");
}

int multiplica_matrizes(int A[TAM][TAM], int B[TAM][TAM])
{
    int numero_interacoes=0;
    int resultado[TAM][TAM];
    int aux=0;
    for (int x = 0; x < TAM; x++)
    {
        for (int i = 0; i < TAM; i++)
        {
            for (int j = 0; j < TAM; j++)
            {
                aux = aux + A[i][j] * B[j][x];
                numero_interacoes ++;
            }
            resultado[i][x] = aux;
            aux = 0;
        }
        //printf("%d %d %d\n", resultado[x][0], resultado[x][1], resultado[x][2]);
    }
    printf("Numero de interacoes da multiplicacao : %d\n", numero_interacoes);
}

int calcula_tempo(clock_t t0,clock_t t1)
{
    double tempo_gasto = ((double)(t1 - t0)) / ((double)CLOCKS_PER_SEC);
    printf("Tempos gasto %.4f ms\n", tempo_gasto );

}
#endif