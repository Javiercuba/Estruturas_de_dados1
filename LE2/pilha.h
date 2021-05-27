#ifndef pilha_h
#define pilha_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Node
{
    char num;
    struct Node *prox;
};
typedef struct
{
    char row;
    char col;
} POSITION;
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

void push2(node *PILHA,POSITION *position)
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

int cria_pilha()
{
    node *PILHA = (node *)malloc(sizeof(node));
    return PILHA;
}

#endif