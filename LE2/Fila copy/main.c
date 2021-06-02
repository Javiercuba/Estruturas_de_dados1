#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void opcao(fila *f, int op);

int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("1. Inserir\n");
    printf("2. Remover\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

int main()
{
    fila *f = alocar_fila();
    int opt;
    do
    {
       opt = menu();
        opcao(f,opt);
    } while (opt);


    inserir_fila(f, '+');
    inserir_fila(f, 13);
    inserir_fila(f, 43);

    imprimir_fila(f);

    return 0;
}


void opcao(fila *f, int op)
{
   
    switch (op)
    {
    case 1:
        inserir_fila(f,3);
        imprimir_fila(f);
        break;

    case 2:
        remover_fila(f);
        imprimir_fila(f);
        break;
    default:
        printf("Comando invalido\n\n");
    }
}