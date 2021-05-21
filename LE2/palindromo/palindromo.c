#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char num;
    struct Node *prox;
};
typedef struct Node node;


int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);

int main(void)
{
    node *PILHA = (node *)malloc(sizeof(node));
    
    if (!PILHA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        inicia(PILHA);
        
        int opt;

        do
        {
            opt = menu();
            opcao(PILHA, opt);
        } while (opt);

        free(PILHA);
        return 0;
    }
}

void inicia(node *PILHA)
{
    PILHA->prox = NULL;
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

void opcao(node *PILHA, int op)
{
    node *tmp;
    switch (op)
    {
    case 3:
        exibe(PILHA);
        break;

    case 1:
        push(PILHA);
        break;

    case 2:
        tmp = pop(PILHA);
        if (tmp != NULL)
            printf("Retirado/Adicionado: %3c\n\n", tmp->num);
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
        printf("\nNovo elemento: ");
        scanf(" %c" , &novo->num);

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
    
    printf("\n\n");
}

void push(node *PILHA)
{
    node *novo = aloca();
    novo->prox = NULL;
    printf("%c", novo->num);
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

node *pop(node *PILHA)
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
        

        penultimo->prox = NULL;

        
        return ultimo;
    }
}
