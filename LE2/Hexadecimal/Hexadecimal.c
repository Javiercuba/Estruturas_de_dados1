#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *prox;
};
typedef struct Node node;

int tam;

int menu(void);
int divide(node *PILHA, int x);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
int desempilha(node *PILHA);
void push(node *PILHA, int x);
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

int divide(node *PILHA, int x)
{
    if ((float)x / 16 > 0.01)
    {
        push(PILHA, x % 16);
        divide(PILHA, x / 16);
    }
    
}
int desempilha(node *PILHA)
{
    node *PILHA2 = (node *)malloc(sizeof(node));
    inicia(PILHA2);
    node *tmp, *tmp2;

    tmp2 = PILHA2->prox;
    tmp = PILHA->prox;
    printf("PILHA:");
    while (tmp != NULL)
    {
        tmp2->num = tmp->num;

        printf("%5d", tmp2->num);
        tmp = tmp->prox;
    }

}
/*
int hexa(int x)
{
    switch (x)
    {
    case 10:
        return "A";
        break;
    case 11:
        return "B";
        break;
    case 12:
        return "C";
        break;
    case 13:
        return "D";
        break;
    case 14:
        return "E";
        break;
    case 15:
        return "F";
        break;
    default:
        return x;
    }
}
*/
void inicia(node *PILHA)
{
    PILHA->prox = NULL;
    tam = 0;
}

int menu(void)
{
    int opt;

    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar PILHA\n");
    printf("2. Exibir PILHA\n");
    printf("3. PUSH\n");
    printf("4. POP\n");
    printf("5. DESEMPILHAR\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, int op)
{
    node *tmp;
    switch (op)
    {
    case 0:
        libera(PILHA);
        break;

    case 1:
        libera(PILHA);
        inicia(PILHA);
        break;

    case 2:
        exibe(PILHA);
        break;

    case 3:
        divide(PILHA, 392);
        break;

    case 4:
        tmp = pop(PILHA);
        if (tmp != NULL)
            printf("Retirado: %3d\n\n", tmp->num);
        break;
    case 5:
        desempilha(PILHA);
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
        scanf("%d", &novo->num);

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
    printf("PILHA:");
    while (tmp != NULL)
    {
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n        ");
    int count;
    for (count = 0; count < tam; count++)
        printf("  ^  ");
    printf("\nOrdem:");
    for (count = 0; count < tam; count++)
        printf("%5d", count + 1);

    printf("\n\n");
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

void push(node *PILHA, int x)
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

node *pop(node *PILHA)
{
    if (PILHA->prox == NULL)
    {
        printf("PILHA ja vazia\n\n");
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
        return ultimo;
    }
}
