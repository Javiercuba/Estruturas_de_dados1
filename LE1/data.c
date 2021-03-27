#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

int main()
{
    Data d;
    int dias=0;
    printf("Digite o numero de dias\n");
    scanf("%d", &d.dia);
    printf("Digite o mes\n");
    scanf("%d", &d.mes);
    printf("Digite o ano\n");
    scanf("%d", &d.ano);
    
    if (validacao_data(&d) == 1)
    {
        printf("\n");
        formata_data(&d);
        printf("\n");
        printf("Quantos dias voce quer somar a data?\n");
        printf("\n");
        scanf("%d", &dias);
        printf("Resultado final\n");
        somatorio_dias(&d,dias);
    }
    
}
