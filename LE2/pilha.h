#ifndef pilha_h
#define pilha_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam=0;

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
    tam++;
}
/*
void exibe(node *PILHA)
{
    if (vazia(PILHA))
    {
        printf("PILHA vazia!\n\n");
        return;
    }

    node *tmp;
    tmp = PILHA->prox;
    printf("PILHA:");
    while (tmp != NULL)
    {
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n");
}
*/
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

#endif