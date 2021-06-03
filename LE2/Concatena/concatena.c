#include <stdio.h>
#include <stdlib.h>
#include "../fila.h"

void opcao(fila *fila1, fila *fila2, int op);
int concatena(fila *fila1, fila *fila2);

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

int concatena(fila *fila1, fila *fila2)
{
    no *temp = fila2->comeco;

    while (temp != NULL)
    {
        
        insere_fila_manual(fila1, temp->valor);
        temp = temp->prox;
    }
    printf("\nFila 1:\n");
    imprimir_fila(fila1);

    printf("\nFila 2:\n");
    imprimir_fila(fila2);

}
