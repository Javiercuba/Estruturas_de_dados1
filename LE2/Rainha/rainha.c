#include "../pilha.h"

preenche_tabuleiro(node *pilha, int tamanho_matriz);




int main(void)
{
    int tamanho_matriz = 4;

    node *pilha = cria_pilha();
}


preenche_tabuleiro(node *pilha, int tamanho_matriz)
{
    int row = 1;
    int col = 0;
    int board[9][9] = {0};

    POSITION *pPOS;

    while (row <= tamanho_matriz && col <= tamanho_matriz)
    {
        col++;
        if( !verifica(board, row, col, tamanho_matriz)){
            board[row][col] = 1;
            pPOS = (POSITION *)malloc(sizeof(POSITION));
            pPOS->row = row;
            pPOS->col = col;

            push2(pilha, pPOS);

            row++;
            col = 0;
        }

        while(col >= tamanho_matriz){
            pPOS = pop(pilha);
            row = pPOS->row;
            col = pPOS->col;
            board[row][col] = 0;
            free(pPOS);
        }
    }
    return;
}

node *pop(node *PILHA)
{
    if (PILHA->prox == NULL)
    {
        printf("Pilha Original vazia\n\n");
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
        penultimo->prox = NULL;

        return ultimo;
    }
}

verifica(int board[][9],int chkRow,int chkCol, int tamanho_matriz){
    int row, col;

    col = chkCol;

    for (row = 1; row <= chkRow;row++){
        if(board[row][col] == 1){
            return true;
        }
    }
    for (row = chkRow - 1, col = chkCol + 1; row > 0 && col <= tamanho_matriz; row--, col++){
        if (board[row][col] == 1)
        {
            return true;
        }
    }
    for (row = chkRow - 1, col = chkCol + 1; row > 0 && col <= tamanho_matriz; row--, col++)
    {
        if (board[row][col] == 1)
        {
            return true;
        }
    }
}