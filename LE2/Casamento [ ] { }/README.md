# Casamento de parenteses

## Explicando o funcionamento do projeto.

- Struct

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
        node *PILHA = cria_pilha();
```

- Alocando memoria na pilha original.

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
```

- Se tiver memoria eu inicio a pilhas e abro o menu com a função `opcao`.

#

- Funções **opcao( )** e **menu( )** :

```c
int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("1. PUSH \n");
    printf("2. POP \n");
    printf("4. Verifica casamento\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}
```

#

```c
void opcao(node *PILHA, int op)
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
    case 4:
        casamento(PILHA);
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

- Caso 4 - A função **casamento** compara o ultimo valor da pilha com o penultimo, a função não reconhece caso um parenteses seja fechado dentro de outro, como `( { } )`.
  É uma função recursiva que vai removendo o ultimo e penultimo da pilha e compara ate chegar no final.

```c
void casamento(node *PILHA)
{
    exibe(PILHA);
    node *ultimo = PILHA->prox,
         *penultimo = PILHA;

    while (ultimo->prox != NULL)
    {
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }

    if (ultimo->num == casa(penultimo->num))
    {
        pop(PILHA);
        pop(PILHA);
        casamento(PILHA);
    }
    else
    {
        printf("Erro no casamento");
    }
    printf("Casamento Ok");
}
```

### Na função acima eu passo o penultimo valor pela função `casa`, que me retorna o valor invertido da chave.

````c
int casa(char x)
{
    switch (x)
    {
    case '[':
        return ']';
        break;
    case '{':
        return '}';
        break;
    case '(':
        return ')';
        break;
    default:
        return 0;
    }
}
````

- Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/casamento).
