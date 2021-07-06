# Árvore - Questão 1

## Explicando o funcionamento do exercicio.
#
- Struct

```c
 struct node
{
    char nome[10];
    int numero;
    struct node *left;
    struct node *right;
};

//Nomeando o nó
typedef struct node *Tree;

```
#
- Função para criar a raiz da árvore 
```c
Tree *newTree()
{
    Tree *mainTree = (Tree *)malloc(sizeof(Tree));
    if (mainTree != NULL)
    {
        *mainTree = NULL;
        return mainTree;
    }
}
```
#
- Função **main( )**



```c
  int main()
{
    Tree *mainTree = newTree();
    while (3 > 0) //Gambiarra activated
    {
        choice(mainTree, menu());
    }
    return 0;
}
```

<h1>Funções auxiliares</h1>

- **menu( )**

```c

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
```
- **choice( )**
```c
void choice(Tree *mainTree, int option)
{
    switch (option)
    {
        int numero;
    case 1:
        imprimi_arvore(mainTree);
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

```

 
<h1>Funções importantes</h1>

-  **imprime_arvore( )** é uma função recursiva onde ele imprime na forma "_pré-ordem_"


```c
void imprime_arvore(Tree *mainTree)
{
    if (*mainTree != NULL)
    {
        printf("%d - %s\n", (*mainTree)->numero, (*mainTree)->nome);
        imprime_arvore(&((*mainTree)->left));//Chamando a função sempre pro lado esquerdo
        imprime_arvore(&((*mainTree)->right));//Chamando a função sempre pro lado direito
    }
}
```
#
-  **addSheet( Tree *mainTree )**: Função que adiciona um ramo novo na árvore.


```c
int addSheet(Tree *mainTree)
{

   struct node *newSheet; //Criando uma arvore auxiliar
    newSheet = (struct node *)malloc(sizeof(struct node)); //Alocando memoria

    printf("Digite numero do usuario: \n");
    scanf("%d", &newSheet->numero);//Inserindo numero na arvore aux
    printf("Digite nome do usuario: \n");
    scanf("%s", newSheet->nome);//Inserindo nome na arvore aux

    newSheet->left = NULL;
    newSheet->right = NULL;

    if (*mainTree == NULL) // Se a árvore original estiver vazia recebe a auxiliar
        *mainTree = newSheet;
    else
    {
        struct node *temp1 = *mainTree; //Variavel temporaria 1 recebe a arvore original
        struct node *temp2 = NULL; //Variavel temporaria 1

        /*  */
        while (temp1 != NULL) //Percorrendo a árvore temporária até o final
        {
            temp2 = temp1;
            if (numero == temp1->numero)//Verifica se o valor ja está na árvore
            {
                free(newSheet);//Caso sim, libera a arvore auxiliar 
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
```
#

-  **busca_usuario( Tree *mainTree, int data )**: Função que retorna um usuário digitado.


```c
int busca_usuario(Tree *mainTree, int data)
{
    struct node *temp1 = *mainTree;
    while (temp1->numero != data)
    {
        /* Verifica se o numero digitado é maior ou menor que o ramo atual, caso sim ele recebe o filho direito */
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
```

- **delTemp1(struct node *temp1)**: Função que remove um ramo e reorganiza a arvore.

```c
struct node *delTemp1(struct node *temp1)
{

    struct node *temp1a;
    struct node *temp2a;

    if (temp1->left == NULL) //verifica se o lado esquerdo eh igual a nulo
    {
        temp2a = temp1->right; //temp2a recebe o lado direito
        free(temp1);//libera temp1 e retorna temp2a
        return temp2a;
    }
    temp1a = temp1;

    temp2a = temp1->left; //vai pro lado esquerdo

    while (temp2a->right != NULL)
    {
        temp1a = temp2a;
        temp2a = temp2a->right; //Valor mais a direita
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
```



#
- **delSheet(Tree *mainTree, int data)**: Função que percorre árvore até o ramo escolhido para ser removido.

```c
int delSheet(Tree *mainTree, int data)
{

    struct node *temp1 = *mainTree;
    struct node *temp2 = NULL;
    while (temp1 != NULL)
    {
        if (data == temp1->numero)// Encontrou o ramo que é igual
        {
            if (temp1 == *mainTree)//Se as duas arvores sao iguais
            { 
                *mainTree = delTemp1(temp1);
            }
            else
            {
                if (temp2->right == temp1)// Verificando qual dos filhos é igual a temp2
                    temp2->right = delTemp1(temp1);
                else
                    temp2->left = delTemp1(temp1);
            }
            printf("\nValor removido com sucesso\n");
            return 1;
        }
        temp2 = temp1;//temp2 será a antecessora de temp1

        //Percorrendo a arvore ate chegar em (data == temp1->numero)
        temp1 = (data > temp1->numero ? temp1->right : temp1->left);

    }
    if (data != (temp1 && temp2))
        printf("\nValor nao encontrado\n");
    return 0;
}

```

#
##  Execução do código

- Inserção de valores e impressão
<p align="center"><img src="Listagem.png " /></p>


- Busca de valores
<p align="center"><img src="Busca.png " /></p>


- Remoção de valores
<p align="center"><img src="Deletando.png " /></p>


#
- Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/Arvore-lista).
