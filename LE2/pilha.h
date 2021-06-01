#ifndef pilha_h
#define pilha_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Tamanho máximo do vetor que representa a pilha
#define MAX 100

// Tamanho do tabuleiro
#define N 10

struct Board
{
    int b[N][N];
};

typedef struct pilha Pilha;

struct pilha
{
    int qtd;
    struct Board dados[MAX];
};

struct Node
{
    char num;
    struct Node *prox;
};

typedef struct Node node;

void inicia(node *PILHA)
{
    PILHA->prox = NULL;
   
}

int vazia(node *PILHA)
{
    if (PILHA->prox == NULL)
        return 1;
    else
        return 0;
}

node *aloca()
{
    node *novo = (node *)malloc(sizeof(node)); //alocando espaco em memoria
    if (!novo)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        printf("Novo elemento: ");
        scanf(" %c", &novo->num);

        return novo;
    }
}

void push2(node *PILHA, char x)
{

    node *novo = (node *)malloc(sizeof(node)); //alocando espaco em memoria

    novo->num = x;
    novo->prox = NULL;

    if (vazia(PILHA))
        PILHA->prox = novo;
    else
    {
        node *tmp = PILHA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
}

/*
void push22(node *PILHA,POSITION *position)
{

    node *novo = (node *)malloc(sizeof(node)); //alocando espaco em memoria

    novo->num = position;
    novo->prox = NULL;

    if (vazia(PILHA))
        PILHA->prox = novo;
    else
    {
        node *tmp = PILHA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
}
*/
node *pop(node *PILHA)
{
    if (PILHA->prox == NULL)
    {
        printf("Pilha Original vazia\n\n");
        return NULL;
    }
    else
    {
        node *ultimo = PILHA->prox,
             *penultimo = PILHA;

        while (ultimo->prox != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;

        return ultimo;
    }
}

void libera(node *PILHA)
{
    if (!vazia(PILHA))
    {
        node *proxNode,
            *atual;

        atual = PILHA->prox;
        while (atual != NULL)
        {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}

node *cria_pilha()
{
    node *PILHA = (node *)malloc(sizeof(node));
    return PILHA;
}

/* RAINHA */

int tamanho_Pilha(Pilha *pi)
{
    if (pi == NULL)
        return -1;
    else
        return pi->qtd;
}

int Pilha_cheia(Pilha *pi)
{
    if (pi == NULL)
        return -1;
    // cheia == 1,  != 0;
    return (pi->qtd == MAX);
}

int insere_Pilha(Pilha *pi, struct Board al)
{
    if (pi == NULL)
        return 0;

    if (Pilha_cheia(pi))
        return 0;

    pi->dados[pi->qtd] = al; //Copio os dados
    pi->qtd++;               // incremento os valor

    return 1;
}

int remove_Pilha(Pilha *pi)
{
    if (pi == NULL || pi->qtd == 0)
        return 0;

    pi->qtd--;
    return 1;

    // o Dado continua na Pilha, mas pode ser sobrescrito.(não é mais possível acessalo)
}

Pilha *criar_Pilha()
{
    Pilha *pi;

    pi = (Pilha *)malloc(sizeof(struct pilha));

    if (pi != NULL)
        pi->qtd = 0;

    return pi;
}

#endif