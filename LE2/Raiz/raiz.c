#include <stdio.h>
#include <stdlib.h>
#include "raiz.h"

int main()
{
    printf("Primeira raiz a ser calculada (5)\n");
    calcula_raiz(5, 2, 0.01);

    printf("Segunda raiz a ser calculada (4)\n");
    calcula_raiz(4, 2, 0.01);
}