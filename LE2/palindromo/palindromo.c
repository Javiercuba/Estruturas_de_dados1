#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char num;
    struct Node *prox;
};
typedef struct Node node;

int tam;

int menu(void);
int divide(node *PILHA, int x);
void inicia(node *PILHA);
void opcao(node *PILHA, node *invertida, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
char desempilha(node *PILHA, int x);
void push(node *PILHA);
node *pop(node *PILHA, node *invertida);

int main(void)
{
    node *PILHA = (node *)malloc(sizeof(node));
    node *invertida = (node *)malloc(sizeof(node));

    if (!PILHA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        inicia(PILHA);
        inicia(invertida);
        int opt;

        do
        {
            opt = menu();
            opcao(PILHA, invertida, opt);
        } while (opt);

        free(PILHA);
        return 0;
    }
}



void inicia(node *PILHA)
{
    PILHA->prox = NULL;
    tam = 0;
}

int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("0. Exibir PILHA\n");
    printf("1. PUSH - Resto da divisao (Valor definido)\n");
    printf("2. POP/DESEMPILHAR\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, node *invertida, int op)
{
    node *tmp;
    switch (op)
    {
    case 0:
        exibe(PILHA);
        break;

    case 1:
        push(PILHA);
        break;

    case 2:
        tmp = pop(PILHA, invertida);
        if (tmp != NULL)
            printf("Retirado/Adicionado: %3d\n\n", tmp->num);
        break;

    default:
        printf("Comando invalido\n\n");
    }
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
        scanf("%c", &novo->num);

        return novo;
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
        printf("%5c", tmp->num);

        tmp = tmp->prox;
    }
    int count;
}

void push(node *PILHA)
{
    node *novo = (node *)malloc(sizeof(node)); //alocando espaco em memoria
    printf("Novo elemento: ");
    scanf(" %c ", &novo->num);
    
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

node *pop(node *PILHA, node *invertida)
{
    if (PILHA->prox == NULL)
    {
        printf("Pilha Original vazia\n\n");
        printf("Pilha Hexadecimal: ");
        exibe(invertida);
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

        tam--;
        printf("Pilha Decimal");
        exibe(PILHA);
        printf("\n");
        printf("Pilha Hexadecimal");
        exibe(invertida);
        printf("\n");
        return ultimo;
    }
}
