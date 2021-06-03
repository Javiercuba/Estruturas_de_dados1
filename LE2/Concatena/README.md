# Concatenando Filas

## Explicando o funcionamento do projeto.

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

## Criando duas filas:

##

```c
int main()
{
    fila *fila1 = alocar_fila();
    fila *fila2 = alocar_fila();

    int opt;
    do
    {
        opt = menu();
        opcao(fila1,fila2, opt);
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
    printf("1. Inserir na Fila 1\n");
    printf("2. Inserir na Fila 2\n");
    printf("3. Concatenar filas\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}
```

#

```c
void opcao(fila *fila1, fila *fila2, int op)
{

    switch (op)
    {
    case 1:
        inserir_fila(fila1);
        printf("Fila 1:\n");
        imprimir_fila(fila1);
        break;

    case 2:
        printf("Fila 2:\n");
        inserir_fila(fila2);
        imprimir_fila(fila2);
        break;

    case 3:
        concatena(fila1,fila2);
        break;
    default:
        printf("Comando invalido\n\n");
    }
}
```

#

# Explicação das funções

## - Função **concatena** recebe como parametro duas filas.

```c
int concatena(fila *fila1, fila *fila2)
{
    no *temp = fila2->comeco;

    while (temp != NULL)//Percorro a fila2 ate o final
    {
        insere_fila_manual(fila1, temp->valor); //Inserindo o inicio da fila2 no final da fila 1
        temp = temp->prox; //Passa para o proximo valor 
    }
    printf("\nFila 1:\n");
    imprimir_fila(fila1);

    printf("\nFila 2:\n");
    imprimir_fila(fila2);

}

```

##  Execução do código
#
#### Inserindo os valores manualmente na fila 1.


<p align="center"><img src="fila1.png " /></p>

#

#### Inserindo os valores manualmente na fila 2.


<p align="center"><img src="fila2.png " /></p>

#

#### Concatenando as Filas.


<p align="center"><img src="concatenado.png " /></p>


- Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/palindromo).
