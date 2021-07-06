# Árvore - Questão 2

## Explicando o funcionamento do exercicio.
#
- Struct

```c
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} *root = 0; //Inicializando a variavel globalmente
```
#
- Função **create( )** para criar a raiz da árvore

```c
struct node *create(struct node *ptr, int data)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->parent = ptr;// Guarda a sub-árvore
    new->left = 0;
    new->right = 0;
    return new;
}
```


<h1>Funções auxiliares</h1>

- **altura( )**

Função recursiva que retorna a altura do nó dessa raiz da árvore ou sub-árvore.

```c

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
```
- **diferenca()**

Retorna o resultado do lado esquerdo menos o direito usando a função altura para cada lado.  
```c
int diferenca(struct node *ptr)
{
    int result = altura(ptr->left) - altura(ptr->right);
    printf("Altura do lado direito = %d \n", altura(ptr->right)); //Altura do lado direito
    printf("Altura do lado esquerdo = %d \n", altura(ptr->left)); //Altura do lado esquerdo
    printf("diferença = %d ", result);
    return result;
}
```

- **inserir( )**

Função para inserir os valores na arvore manualmente. 
```c
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
```
#
- Função **main( )**
```c
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
```


#
##  Execução do código

- Inserção de valores e impressão
<p align="center"><img src="Balanceamento.png " /></p>


#
- Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/balanceamento).
