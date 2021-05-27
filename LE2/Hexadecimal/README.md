## Hexadecimal

#

## Explicando o funcionamento do projeto. 

* Struct

 ##
```c
    struct Node
    {
        char num;
        struct Node *prox;
    };
    typedef struct Node node;

```
* Função main

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
* Funções __opcao( )__ e __menu( )__ :
 



```c
int menu(void)
{
    int opt;

    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar PILHA\n");
    printf("2. Exibir PILHA\n");
    printf("3. PUSH\n");
    printf("4. POP/DESEMPILHAR\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}
```


#
```c
void opcao(node *PILHA, node *invertida, int op)
{
    node *tmp;
    switch (op)
    {
    case 0:
        exibe_int(PILHA);
        break;

    case 1:
        divide(PILHA, 44221);
        exibe_int(PILHA);
        break;

    case 2:
        tmp = pop(PILHA, invertida);
        if (tmp != NULL)
            printf("Retirado/Adicionado: %3d\n\n", tmp->num);
        break;

    default:
        printf("Comando invalido\n\n");
    }
}
```
#
## Explicação de cada caso

#
* Caso 0 - Mostra na tela a pilha original com a função __exibe_int__.
```c
void opcao(node *PILHA, node *invertida, int op)
{
    node *tmp;
    switch (op)
    {
    case 2:
        exibe_int(PILHA);
        break;
}

```
#

* Caso 1 - A função __divide__ insere na pilha original o resto das divisões, importante saber que o valor inserido está ___estático___.

```c
void opcao(node *PILHA, node *invertida, int op)
{
    node *tmp;
    switch (op)
    {
   case 3:
        divide(PILHA, 12444556);
        exibe_int(PILHA);
        break;
}

```
#

* Caso 2 - A função __pop__ retorna e remove o ultimo elemento da pilha.
```c
void opcao(node *PILHA, node *invertida, int op)
{
    node *tmp;
    switch (op)
    {
   case 4:
        tmp = pop(PILHA, invertida);
        if (tmp != NULL)
            printf("Retirado/Adicionado: %3d\n\n", tmp->num);
        break;
}
```
#



* Execução do código

 <p align="center"><img src="Capturar.jpg " /></p>

Como nos já predefinimos o valor da variável na função __divide__ no `caso 3`, essa função ira inserir o resto de cada divisão por 16 desse valor na pilha usando a função __push__. 
```c
        divide(PILHA, 12444556);
```
#
A função __divide__ é uma função recursiva que insere na pilha o resto da sua propria divisão por `16` enquanto sua divisao seja maior que `0`.
```c
int divide(node *PILHA, int x) 
{
    if ((float)x / 16 > 0.01)
    {
        push(PILHA, x % 16); 
        divide(PILHA, x / 16);
    }
}
```
#

Em seguida temos a função __desempilha__ que tem a função de filtrar os elementos transformando para hexadecimal e inseri-los em uma nova pilha. 


```c
char desempilha(node *PILHA, int x)
{
    char c = hexa(x);
    push(PILHA, c);
}
```
#

A filtragem para hexadecimal é feita pela função __hexa__ que retorna a variavel do tipo `char`.

```c

int hexa(int x)
{
    switch (x)
    {
    case 10:
        return 'A';
        break;
    case 11:
        return 'B';
        break;
    case 12:
        return 'C';
        break;
    case 13:
        return 'D';
        break;
    case 14:
        return 'E';
        break;
    case 15:
        return 'F';
        break;
    default:
        return x;
    }
}
```
#

Para executar o desempilhamento chamei o `caso 2`que é a função __pop__ que remove o ultimo valor da pilha original
e em seguida chamo a função __desempilha__ que vai inserir esse valor removido na nova pilha.


```c
node *pop(node *PILHA, node *invertida)
{
    if (PILHA->prox == NULL)
    {
        printf("Pilha Original vazia\n\n");
        printf("Pilha Hexadecimal: ");
        exibe(invertida);
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
        desempilha(invertida, ultimo->num);

        penultimo->prox = NULL;

        tam--;
        printf("Pilha Decimal");
        exibe(PILHA);
        printf("\n");
        printf("Pilha Hexadecimal");
        exibe(invertida);
        printf("\n");
        return ultimo;
    }
}
```
#

 <p align="center"><img align="center" src="./gif.gif"  width="50%" height="60%" /> </p>

+ Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/hexadecimal).

    
