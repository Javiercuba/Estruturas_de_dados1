#ifndef TREE_H
#define TREE_H

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



#endif