#include <stdio.h>
#include <stdlib.h>

//ESTRUTURAS
//Criando a estrutura de cada nó
struct node
{
    char nome[10];
    int numero;
    struct node *left;
    struct node *right;
};

//Nomeando o nó
typedef struct node *Tree;

//Função para criar a raiz da árvore, isto é o primeiro nó da árvore.
Tree *newTree()
{
    Tree *mainTree = (Tree *)malloc(sizeof(Tree));
    if (mainTree != NULL)
    {
        *mainTree = NULL;
        return mainTree;
    }
}

//Função menu do programa.
int menu(void);
//Função para executar as opções do menu do programa.
void choice(Tree *mainTree, int option);
//Função para o segundo menu, quando ativado a opção de imprimir.
int print(void);
//Função para executar as opções do segundo menu do programa.
void choice2(Tree *mainTree, int option2);
//Função para imprimir de forma pré-Ordem.
void preOrder(Tree *mainTree);
//Função para imprimir de forma em-Ordem.
void inOrder(Tree *mainTree);
//Função para imprimir de forma pós-Ordem.
void postOrder(Tree *mainTree);
//Função para imprimir o total de nós tem na árvore.
int totalTree(Tree *mainTree);
//Função para adicionar folhas na árvore.
int addSheet(Tree *mainTree);
//Função para remover folhas na árvore.
int delSheet(Tree *mainTree, int data);
struct node *delTemp1(struct node *temp1);
//PROGRAMA PRINCIPAL
int main()
{

    Tree *mainTree = newTree();

    while (3 > 0)
    {

        choice(mainTree, menu());
    }

    return 0;
}
//FIM PROGRAMA PRINCIPAL

int menu()
{
    int option;
    printf("Realize a operacao desejada:\n");
    printf("1. Imprimir\n");
    printf("2. Inserir novo valor\n");
    printf("3. Remover a arvore\n");
    printf("4. Sair\n");
    scanf("%d", &option);
    return option;
}

//INICIO FUNCAO DE EXECUCAO DAS OPCOES DO MENU
void choice(Tree *mainTree, int option)
{
    switch (option)
    {
        int numero;
       // char nome[10];
    case 1:

        choice2(mainTree, print());
        break;

    case 2:
        addSheet(mainTree);
        break;

    case 3:
        printf("Digite qual valor inteiro sera excluido: \n");
        scanf("%d", &numero);
        delSheet(mainTree, numero);
        break;

    case 4:
        printf("Encerrando programa\n");
        exit(1);
        break;

    default:
        printf("Opcao invalida\n");
    }
}
//FIM FUNCAO OPCOES DO MENU
//INICIO FUNCAO OPCOES DO SUBMENU
int print()
{
    int option2;
    printf("1. Pre-Ordem\n");
    printf("2. Em-Ordem\n");
    printf("3. Pos-Ordem\n");
    scanf("%d", &option2);
    return option2;
}
//FIM FUNCAO OPCOES DO SUBMENU
//INICIO FUNCAO DA EXECUCAO DAS OPCOES DO SUBMENU
void choice2(Tree *mainTree, int option2)
{

    switch (option2)
    {
    case 1:
        printf("Pre-Ordem\n\n");
        preOrder(mainTree);

        break;

    case 2:
        printf("Em-Ordem\n\n");
        inOrder(mainTree);
        break;

    case 3:
        printf("Pos-Ordem\n");
        postOrder(mainTree);
        break;

    default:
        printf("Opcao invalida2\n\n");
    }
}

//INICIO DA FUNCAO PRÉ-ORDEM
void preOrder(Tree *mainTree)
{
    if (*mainTree != NULL)
    {
        printf("%d \n", (*mainTree)->numero);
      //  printf("%s \n", (*mainTree)->nome);
        preOrder(&((*mainTree)->left));
        preOrder(&((*mainTree)->right));
    }
}

//INICIO DA FUNCAO EM-ORDEM
void inOrder(Tree *mainTree)
{
    if (mainTree == NULL)
        return;

    if (*mainTree != NULL)
    {
        inOrder(&((*mainTree)->left));
        printf("%d\n", (*mainTree)->numero);
        inOrder(&((*mainTree)->right));
    }
}
//FIM DA FUNCAO EM-ORDEM
//INICIO DA FUNCAO PÓS-ORDEM
void postOrder(Tree *mainTree)
{
    if (mainTree == NULL)
        return;

    if (*mainTree != NULL)
    {
        postOrder(&((*mainTree)->left));
        postOrder(&((*mainTree)->right));
        printf("%d\n", (*mainTree)->numero);
    }
}
//FIM DA FUNCAO PÓS-ORDEM
//INICIO DA FUNCAO ADICIONAR FOLHA
int addSheet(Tree *mainTree)
{

    struct node *newSheet;
    newSheet = (struct node *)malloc(sizeof(struct node));
    int numero;
    char nomessss[10];
    printf("Digite numero do usuario: \n");
    scanf("%d", &numero);
    printf("Digite nome do usuario: \n");
    scanf("%s", newSheet->nome);


    newSheet->numero = numero;
    newSheet->left = NULL;
    newSheet->right = NULL;
    printf(" o nome é %s ", newSheet->nome);

    if (*mainTree == NULL)
        *mainTree = newSheet;
    else
    {
        struct node *temp1 = *mainTree;
        struct node *temp2 = NULL;
        while (temp1 != NULL)
        {
            temp2 = temp1;
            if (numero == temp1->numero)
            {
                free(newSheet);
                printf("\nValor ja inserido na arvore.\n\n");
                return 0;
            }
            if (numero > temp1->numero) //verifica qual lado eh maior
                temp1 = temp1->right;
            else
                temp1 = temp1->left;
        }
        if (numero > temp2->numero) // quem vai ter o novo filho
            temp2->right = newSheet;
        else
            temp2->left = newSheet;
    }
    if (newSheet != NULL)
        printf("\nValor inserido com sucesso\n\n");
    return 1;
}
//FIM DA FUNCAO ADICIONAR FOLHA
//INICIO DA FUNCAO REMOVER FOLHA
int delSheet(Tree *mainTree, int data)
{

    struct node *temp1 = *mainTree;
    struct node *temp2 = NULL;
    while (temp1 != NULL)
    {
        if (data == temp1->numero)
        {
            if (temp1 == *mainTree)
                *mainTree = delTemp1(temp1);
            else
            {
                if (temp2->right == temp1)
                    temp2->right = delTemp1(temp1);
                else
                    temp2->left = delTemp1(temp1);
            }
            printf("\nValor removido com sucesso\n");
            return 1;
        }
        temp2 = temp1;
        if (data > temp1->numero)
            temp1 = temp1->right;
        else
            temp1 = temp1->left;
    }
    if (data != (temp1 && temp2))
        printf("\nValor nao encontrado\n");
    return 0;
}

struct node *delTemp1(struct node *temp1)
{

    struct node *temp1a;
    struct node *temp2a;

    if (temp1->left == NULL)
    {
        temp2a = temp1->right;
        free(temp1);
        return temp2a;
    }
    temp1a = temp1;
    temp2a = temp1->left;
    while (temp2a->right != NULL)
    {
        temp1a = temp2a;
        temp2a = temp2a->right;
    }
    if (temp1a != temp1)
    {
        temp1a->right = temp2a->left;
        temp2a->left = temp1->left;
    }
    temp2a->right = temp1->right;
    free(temp1);
    return temp2a;
}
//FIM DA FUNCAO REMOVER FOLHA