#ifndef pilha_h
#define pilha_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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

#endif