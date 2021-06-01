# Rainha

## Explicando o funcionamento do exercicio.
#
- Struct

```c
   
// Tamanho máximo do vetor que representa a pilha
#define MAX 100

// Tamanho do tabuleiro
#define N 10

struct Board
{
    int b[N][N];
};

typedef struct pilha Pilha;

struct pilha
{
    int qtd;
    struct Board dados[MAX];
};

```
#
- Função **main( )**



```c
   int main(void)
{
    pi = criar_Pilha();

    resolver_NRainha(&dado, 0);
    printf("Tamanho da pilha %d\n", tamanho_Pilha(pi));

    print(&dado);

    return 0;
}
```
#
- Função **resolver_NRainha( )**

```c
bool resolver_NRainha(struct Board *board, int col)
{
    /*Se todas as rainhas forem colocadas então retorna verdadeiro*/
    if (col >= N)
        return true;

    /* Considere esta coluna e tente colocar a rainha em todas as linhas, uma por uma */
    for (int i = 0; i < N; i++)
    {

        /* Verifica se a rainha pode ser colocada board[i][col] */
        if (isSafe(board, i, col))
        {

            /* Coloque a rainha em board[i][col] */
            board->b[i][col] = 1;
            insere_Pilha(pi, dado); //add na pilha

            /* Recursão para colocar o resto das rainhas */
            if (resolver_NRainha(board, col + 1))
                return true;

            /* Se colocar a rainha no board[i][col] não levar a uma solução, remova a rainha de board[i][col] */
            board->b[i][col] = 0; // BACKTRACK
            remove_Pilha(pi);     // remove da pilha
        }
    }

    /* Se a rainha não poder ser colocada em nenhuma linha nesta coluna, retorne falso  */
    return false;
}
```
#
- Função **isSafe( )**

```c
bool isSafe(struct Board *board, int linha, int col)
{
    int i, j;
    /* Verifica a linha do lado esquerdo */
    for (i = 0; i < col; i++)
        if (board->b[linha][i])
            return false;

    /* Verifica a diagonal superior do lado esquerdo */
    for (i = linha, j = col; i >= 0 && j >= 0; i--, j--)
        if (board->b[i][j])
            return false;

    /* verifica a diagonal inferior do lado esquerdo */
    for (i = linha, j = col; j >= 0 && i < N; i++, j--)
        if (board->b[i][j])
            return false;

    return true;
}
```
#
##  Execução do código

<p align="center"><img src="rainha.jpg " /></p>

#
- Caso queira baixar o executável [Clique Aqui](https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/rainha).
