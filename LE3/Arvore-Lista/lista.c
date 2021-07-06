
#include <stdio.h>
#include <stdlib.h>

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
int print(void);

int menu(void);

void escolhe(Tree *mainTree, int option);

int busca_usuario(Tree *mainTree, int data);

void imprime_arvore(Tree *mainTree);
//Função para adicionar folhas na árvore.
int insere(Tree *mainTree);
//Função para remover folhas na árvore.
int remove(Tree *mainTree, int data);

struct node *delTemp1(struct node *temp1);

//PROGRAMA PRINCIPAL
int main()
{
    Tree *mainTree = newTree();
    while (3 > 0)
    {
        escolhe(mainTree, menu());
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
    printf("4. Buscar um usuario\n");
    printf("5. Sair\n");
    scanf("%d", &option);
    return option;
}

//INICIO FUNCAO DE EXECUCAO DAS OPCOES DO MENU
void escolhe(Tree *mainTree, int option)
{
    switch (option)
    {
        int numero;
    case 1:
        imprime_arvore(mainTree);
        break;

    case 2:
        insere(mainTree);
        break;

    case 3:
        printf("Digite qual valor inteiro sera excluido: \n");
        scanf("%d", &numero);
        remove(mainTree, numero);
        break;
    case 4:
        printf("Digite qual numero sera buscado: \n");
        scanf("%d", &numero);
        busca_usuario(mainTree, numero);
        break;
    case 5:
        printf("Encerrando programa\n");
        exit(1);
        break;

    default:
        printf("Opcao invalida\n");
    }
}

void imprime_arvore(Tree *mainTree)
{
    if (*mainTree != NULL)
    {
        printf("%d - %s\n", (*mainTree)->numero, (*mainTree)->nome);
        imprime_arvore(&((*mainTree)->left));
        imprime_arvore(&((*mainTree)->right));
    }
}

//INICIO DA FUNCAO ADICIONAR FOLHA
int insere(Tree *mainTree)
{

    struct node *newSheet;
    newSheet = (struct node *)malloc(sizeof(struct node));

    printf("Digite numero do usuario: \n");
    scanf("%d", &newSheet->numero);
    printf("Digite nome do usuario: \n");
    scanf("%s", newSheet->nome);

    newSheet->left = NULL;
    newSheet->right = NULL;

    if (*mainTree == NULL) // Se a arvore estiver vazia
        *mainTree = newSheet;
    else
    {
        struct node *temp1 = *mainTree;
        struct node *temp2 = NULL;
        while (temp1 != NULL)
        {
            temp2 = temp1;
            if (newSheet->numero == temp1->numero)
            {
                free(newSheet);
                printf("\nValor ja inserido na arvore.\n\n");
                return 0;
            }
            if (newSheet->numero > temp1->numero) //verifica qual lado eh maior
                temp1 = temp1->right;
            else
                temp1 = temp1->left;
        }
        if (newSheet->numero > temp2->numero) // quem vai ter o novo filho
            temp2->right = newSheet;
        else
            temp2->left = newSheet;
    }
    if (newSheet != NULL)
        printf("\nValor inserido com sucesso\n\n");
    return 1;
}

//INICIO DA FUNCAO REMOVER FOLHA
int remove(Tree *mainTree, int data)
{

    struct node *temp1 = *mainTree;
    struct node *temp2 = NULL;
    while (temp1 != NULL)
    {
        if (data == temp1->numero)
        {
            if (temp1 == *mainTree)
            { //Primeira posição igual
                *mainTree = delTemp1(temp1);
            }
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

        temp1 = (data > temp1->numero ? temp1->right : temp1->left);

    }
    if (data != (temp1 && temp2))
        printf("\nValor nao encontrado\n");
    return 0;
}

int busca_usuario(Tree *mainTree, int data)
{
    struct node *temp1 = *mainTree;
    while (temp1->numero != data)
    {
        temp1 = data > temp1->numero ? temp1->right : temp1->left;

        if (temp1 == NULL)
        {
            printf("Usario nao encontrado");
            return 0;
        }
    }
    printf("-------------------------------------\n");
    printf("Usuario: %s\nNumero: %d\n", temp1->nome, temp1->numero);
    printf("-------------------------------------\n");
}

struct node *delTemp1(struct node *temp1)
{

    struct node *temp1a;
    struct node *temp2a;

    if (temp1->left == NULL) //verifica se o lado esquerdo eh igual a nulo
    {
        temp2a = temp1->right;
        free(temp1);
        return temp2a;
    }
    temp1a = temp1;

    temp2a = temp1->left; //vai pro lado esquerdo
    while (temp2a->right != NULL)
    {
        temp1a = temp2a;
        temp2a = temp2a->right; //VALOR MAIS A DIREITA
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
