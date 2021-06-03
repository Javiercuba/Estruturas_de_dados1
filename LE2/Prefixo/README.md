# Prefixa

## Explicando o funcionamento do projeto.

- Pilha

```c
    struct Node
    {
        char num;
        struct Node *prox;
    };
    typedef struct Node node;
```
- Fila

```c
typedef struct element
{
    struct element *prox;
    int valor;
} no;

typedef struct
{
    no *comeco;
    no *fim;
} fila;
```

- Função main

##

```c
   int main()
{
    node *PILHA = cria_pilha();
    fila *f = alocar_fila();
    int opt;
    do
    {
        opt = menu();
        opcao(f, PILHA, opt);
    } while (opt);

    return 0;
}
```
#

- Funções **opcao( )** e **menu( )** :

```c
int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("1. Inserir\n");
    printf("2. Remover\n");
    printf("3. Prefixa\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}
```

#

```c
void opcao(fila *f, node *PILHA, int op)
{

    switch (op)
    {
    case 1:
        inserir_fila(f);
        imprimir_fila(f);
        break;

    case 2:
        remover_fila(f);
        imprimir_fila(f);
        break;

    case 3:
        prefixa(f, PILHA);
        exibePilha(PILHA);
        break;
    default:
        printf("Comando invalido\n\n");
    }
}
```

#

# Explicação das funções

## - Função **prefixa** recebe como parametro uma pilha e uma fila.

```c

int prefixa(fila *f, node *PILHA)
{
    no *temp = f->comeco;
    node *ultimo_valor_pilha, *penultimo_valor_pilha;
    int resultado_equacao;

    if (temp != NULL) //Verifico se a fila ainda não terminou
    {
        char valor_pilha = remover_fila(f); //Uma variavel recebe o primeiro valor da fila

            /* Se for um operador */
        if (valor_pilha == '+' || valor_pilha == '*' || valor_pilha == '-' || valor_pilha == '/') //Verifico se é um operador
        {
            /* Recebendo o ultimo valor da pilha*/
            ultimo_valor_pilha = pop(PILHA); 
            
            /* Recebendo o penultimo valor da pilha*/
            penultimo_valor_pilha = pop(PILHA); 

            /* resolve_equacao() retorna a operação dos valores anteriores*/
            resultado_equacao = resolve_equacao(valor_pilha, ultimo_valor_pilha->num, penultimo_valor_pilha->num);

            /* Inserindo na Pilha o resultado da operação */
            push2(PILHA, resultado_equacao + '0');

            /* Chamo a função denovo*/
            prefixa(f, PILHA);
        }
        else
        {
            /* Se não for um operador insiro normalmente na pilha e chamo a função prefixa() denovo */
            push2(PILHA, valor_pilha);
            prefixa(f, PILHA);
        }
        printf("PILHA -> ");
        exibePilha(PILHA);
    }
}
```
## - Função **resolve_equacao** recebe como parametro uma pilha e uma fila.

```c
char resolve_equacao(char operador, char primeiro, char segundo)
{

    int primeiro_valor = 0, segundo_valor = 0;

    sscanf(&primeiro, "%d", &primeiro_valor); //Transformando de char para inteiro
    sscanf(&segundo, "%d", &segundo_valor);   //Transformando de char para inteiro

    switch (operador) //dependendo o operador retorna uma equacao
    {
    case '+':
        printf(" Resutado Soma %d + %d = %d\n", primeiro_valor, segundo_valor, (primeiro_valor + segundo_valor));
        return (primeiro_valor + segundo_valor);
        break;
    case '*':
        printf(" Resutado Multiplicacao %d x %d = %d\n", primeiro_valor, segundo_valor, (primeiro_valor * segundo_valor));
        return primeiro_valor * segundo_valor;
        break;
    case '/':
        printf(" Resutado Divisao: %d", (primeiro_valor / segundo_valor));
        return primeiro_valor / segundo_valor;
        break;
    case '-':
        printf(" Resutado Subtracao: %d - %d = %d\n", primeiro_valor, segundo_valor, (primeiro_valor - segundo_valor));
        return primeiro_valor - segundo_valor;

        break;
    default:
        return 0;
    }
}
```

##  Execução do código
#
#### Inserindo os valores manualmente.


<p align="center"><img src="inserindo.png " /></p>

#

#### Executando a opcao 3.


<p align="center"><img src="resultado.png " /></p>


- Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/palindromo).
