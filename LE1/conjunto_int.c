#include <stdlib.h>
#include <stdio.h>
#include "conjunto_int.h"
int main(int argc, char *argv[])
{

    int lista_uniao[20];
    Conjunto M1, M2, M3,null;
    printf("Criando um conjunto vazio\n");
    Cria_Conjunto_Vazio(&M1);
    printf("--Conjunto M1 vazio--\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d\t\n", M1.lista[i]);
    }
    printf("Inserindo valores randomicos em\nM1 e\tM2\n");
    insere(&M1);
    insere(&M2);
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d\t%d\t\n", M1.lista[i], M2.lista[i]);
    }
    printf("\n");
    printf("Resultados valores de M1: \n");
    menor_valor(&M1);
    maior_valor(&M1);

    printf("\n");
    printf("Resultados valores de M2: \n");
    menor_valor(&M2);
    maior_valor(&M2);
    printf("\n");

    uniao(&M1, &M2, lista_uniao);
    printf("-----Uniao de M1 com M2---\n\n");
    printf("--M1----M2----Uniao.M1----Uniao.M2\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d\t%d\t%d\t %d\t\n", M1.lista[i], M2.lista[i], lista_uniao[i], lista_uniao[i + 10]);
    }
}
