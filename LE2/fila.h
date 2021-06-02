#ifndef fila_h
#define fila_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define ERRO -1

typedef char TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX + 1];
    int nroRegistros;
} FILA;

void inicializa(FILA *F)
{
    F->nroRegistros = 0;
}

void mostraFila(FILA *F)
{
    int i = 0;
    printf("FILA:\n");
    for (i; i < F->nroRegistros; i++)
    {
        if (F->A[i].chave > '0'){
            printf("[ %c ] ", F->A[i].chave);
        }else{
            printf("[ %d ] ", F->A[i].chave);
        }
            
    }
    printf("\n\n");
}

bool insereFila(TIPOCHAVE ch, FILA *F)
{
    if (F->nroRegistros >= MAX)
        return false;
    F->A[F->nroRegistros].chave = ch;
    F->nroRegistros++;
    return true;
}

bool removeFila(FILA *F)
{
    if (F->nroRegistros <= 0)
        return false;
    int i = 1;
    for (i; i < F->nroRegistros; i++)
    {
        F->A[i - 1].chave = F->A[i].chave;
    }
    F->nroRegistros--;
    return true;
}

int buscaFila(TIPOCHAVE ch, FILA *F)
{
    F->A[F->nroRegistros].chave = ch; // Coloca a ch na ultima posição para fazer busca Sentinela
    int i = 0;
    while (F->A[i].chave != ch)
        i++;
    if (i >= F->nroRegistros)
        return ERRO;
    return i;
}

int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("1. Inserir no final da fila\n");
    printf("2. remover\n");
    printf("3. prefixa\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}


#endif