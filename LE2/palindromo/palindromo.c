#include "../pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(void);

void opcao(node *PILHA, node *invertido, node *aux, int op);
void exibe(node *PILHA);
void push(node *PILHA);

node *pop(node *PILHA, node *aux,node *invertido);
void desempilha(node *PILHA, char c, char tipo[]);
int main(void)
{
    node *PILHA = (node *)malloc(sizeof(node));
    node *invertido = (node *)malloc(sizeof(node));
    node *aux = (node *)malloc(sizeof(node));
    if (!PILHA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        inicia(PILHA);
        inicia(invertido);

        int opt;

        do
        {
            opt = menu();
            opcao(PILHA, invertido,aux, opt);
        } while (opt);

        free(PILHA);
        return 0;
    }
}



int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("1. PUSH \n");
    printf("2. POP/DESEMPILHAR\n");
    printf("3. Exibir PILHA\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, node *invertido,node *aux, int op)
{
    node *tmp;
    switch (op)
    {
    case 1:
        push(PILHA);
        break;

    case 2:
        tmp = pop(PILHA,aux,invertido);
          break;
    case 3:
        exibe(PILHA);
        break;
    default:
        printf("Comando invalido\n\n");
    }
}

void exibe(node *PILHA)
{
    if (vazia(PILHA))
    {
        printf("PILHA vazia!\n\n");
        return;
    }

    node *tmp;
    tmp = PILHA->prox;

    while (tmp != NULL)
    {
        printf("%4c", tmp->num);
        tmp = tmp->prox;
    }

    printf("\n");
}

void push(node *PILHA)
{

    node *novo = aloca();
    novo->prox = NULL;
    printf("%c", novo->num);
    if (vazia(PILHA))
    {
        PILHA->prox = novo;
    }
    else
    {
        node *tmp = PILHA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
}

void desempilha(node *PILHA, char c, char tipo[])
{
    
    push2(PILHA, c);
    printf("Pilha %s", tipo);
    exibe(PILHA);
}

node *pop(node *PILHA, node *aux, node *invertido)
{
    
    printf("Pilha Original");
    exibe(PILHA);

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
        desempilha(aux, ultimo->num,"Auxiliar");
        desempilha(invertido, ultimo->num,"invertida");
        penultimo->prox = NULL;

        return ultimo;
    }
}
