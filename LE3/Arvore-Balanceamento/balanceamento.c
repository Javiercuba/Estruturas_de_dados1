
#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} *root = 0;


int altura(struct node *ptr)
{
    int l_count = 0, r_count = 0;
    if (ptr != 0)
    {
        l_count = 1 + altura(ptr->left);
        r_count = 1 + altura(ptr->right);
        return (l_count > r_count) ? l_count : r_count;
    }
    else
        return 0;
}

int diferenca(struct node *ptr)
{
    int result = altura(ptr->left) - altura(ptr->right);
    printf("Altura do lado direito = %d \n", altura(ptr->right));
    printf("Altura do lado esquerdo = %d \n", altura(ptr->left));
    printf("diferença = %d ", result);
    return result;
}

struct node *create(struct node *ptr, int data)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->parent = ptr;
    new->left = 0;
    new->right = 0;
    return new;
}

void inserir(struct node *ptr, int data)
{
    if (ptr == 0 && ptr == root)
        root = create(ptr, data);
    else if ((data > ptr->data) && (ptr->right != 0))
        inserir(ptr->right, data);
    else if (data > ptr->data)
        ptr->right = create(ptr, data);
    else if ((data < ptr->data) && (ptr->left != 0))
        inserir(ptr->left, data);
    else
        ptr->left = create(ptr, data);
}

void main()
{
    inserir(root, 30);
    inserir(root, 50);
    inserir(root, 55);
    inserir(root, 51);
    inserir(root, 50);
    inserir(root, 80);
    inserir(root, 15);
    inserir(root, 10);

    diferenca(root);
}