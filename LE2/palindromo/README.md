## Palindromo

#

## Explicando o funcionamento do projeto.

- Struct

##

```c
    struct Node
    {
        char num;
        struct Node *prox;
    };
    typedef struct Node node;

```

- Função main

##

```c
    int main(void)
    {
        node *PILHA = (node *)malloc(sizeof(node));
        node *invertida = (node *)malloc(sizeof(node));
```

- Alocando memoria na pilha original e na pilha que será
  invertida e transformada para hexadecimal.

#

```c

    if (!PILHA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
}
```

- Verifico se tem memoria disponivel.

```c
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
```

- Se tiver memoria eu inicio as duas pilhas e abro o menu com a função "opcao".

#

- Funções **opcao( )** e **menu( )** :

```c
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
```

#

```c
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
```

#

# Explicação dos casos importantes

- Caso 1 - A função **push** insere na pilha com ajuda da função **aloca** que serve para dar o `scanf`.

```c
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

```

#

- Caso 4 - A função **desempilha** tem a função de inserir na pilha `auxiliar` e na `PILHA 2` a `PILHA 1` invertida.

A ideia é fazer a `PILHA 2` receber a `PILHA 1` invertida usando uma pilha auxiliar para em seguida comparar uma pilha com a outra e verificar se elas são iguais ou não.

```c

void desempilha(node *PILHA1, node *PILHA2)
{
    node *aux = (node *)malloc(sizeof(node));

    node *tmp, *ultimo;
    tmp = PILHA1;

    while (tmp->prox != NULL) //Inserindo o inverso
    {
        ultimo = pop(PILHA1); //removendo da pilha principal
        push2(PILHA2, ultimo->num); //inserindo esse valor na pilha 2
        push2(aux, ultimo->num); //inserindo esse valor na pilha 2
    }

    while (aux->prox != NULL) //Inserindo a pilha auxiliar na pilha original de volta
    {
        ultimo = pop(aux);
        push2(PILHA1, ultimo->num);
    }
    
    printf("\nAuxiliar:");
    exibe(aux); //exibe a pilha auxiliar vazia
    printf("\n");

    printf("Pilha Original:");
    exibe(PILHA1); //exibe a pilha original completa

    printf("\n Pilha Invertida:");
    exibe(PILHA2);//exibe a pilha 2 invertida

    verifica(PILHA1, PILHA2);//função para verificar as duas pilhas
}
```

#

### A função __verifica__ recebe duas pilhas como parametros e vai removendo cada valor da pilha e vai comparando.
```c

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
```


##  Execução do código

#### Escolhi o **Push** e digitei a frase `"testando o codigo"`.
#
 <p align="center"><img src="Capturar1.jpg " /></p>

#


#### Em seguida escolhi a opcao 4 **Desempilhar** que chama a função __desempilha__.

<p align="center"><img src="Capturar2.jpg " /></p>


- Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/hexadecimal).
