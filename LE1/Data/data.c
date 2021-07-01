#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

int main()
{
    Data d;
    int dias=0;
    printf("Digite o dia da primeira dose\n");
    scanf("%d", &d.dia);
    printf("Digite o mes\n");
    scanf("%d", &d.mes);
    printf("Digite o ano\n");
    scanf("%d", &d.ano);
    
    if (validacao_data(&d) == 1)
    {
        //formata_data(&d);
        printf("\n");
        printf("Quantos dias para a proxima dose?\n");
        scanf("%d", &dias);
        printf("A sua proxima dose será dia:\n");
        somatorio_dias(&d,dias);
        formata_data(&d);
    }
    
}
