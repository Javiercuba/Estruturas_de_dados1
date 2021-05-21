#include "../pilha.h"


int menu(void);
void opcao(node *PILHA, node *invertido, int op);
void exibe(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);
int verifica(node *PILHA1, node *PILHA2);
void desempilha(node *PILHA1, node *PILHA2);

int main(void)
{
    node *PILHA = (node *)malloc(sizeof(node));
    node *invertido = (node *)malloc(sizeof(node));

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
            opcao(PILHA, invertido, opt);
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
    printf("2. POP \n");
    printf("3. Exibir PILHA\n");
    printf("4. Desempilhar\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, node *invertido, int op)
{
    node *tmp;
    switch (op)
    {
    case 1:
        push(PILHA);
        break;
    case 2:
        tmp = pop(PILHA);
        break;
    case 3:
        exibe(PILHA);
        break;
    case 4:
        desempilha(PILHA, invertido);
    default:
        printf("\n");
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

void desempilha(node *PILHA1, node *PILHA2)
{
    node *aux = (node *)malloc(sizeof(node));

    node *tmp, *ultimo;
    tmp = PILHA1;

    while (tmp->prox != NULL) //INSERINDO O INVERSO
    {
        ultimo = pop(PILHA1);
        push2(PILHA2, ultimo->num);
        push2(aux, ultimo->num);
    }

    while (aux->prox != NULL) //INSERINDO O AUXILIAR DE VOLTA NA PILHA ORIGINAL
    {
        ultimo = pop(aux);
        push2(PILHA1, ultimo->num);
    }
    printf("\n");
    printf("Auxiliar:");
    exibe(aux);
    printf("\n");

    printf("Pilha Original:");
    exibe(PILHA1);
    printf("\n");
    printf("Pilha Invertida:");
    exibe(PILHA2);

    verifica(PILHA1, PILHA2);
}

int verifica(node *PILHA1, node *PILHA2)
{
    node *tmp, *ultimo, *ultimoP1, *ultimoP2;
    tmp = PILHA1;
    int result = 0;
    while (tmp->prox != NULL) //INSERINDO O INVERSO
    {
        ultimoP1 = pop(PILHA1);
        ultimoP2 = pop(PILHA2);

        if (ultimoP1->num != ultimoP2->num)
        {
            result++;
            break;
        }
    }
    result > 0 ? printf("\nNão é palindromo"): printf("\nÉ palindromo");
}

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
