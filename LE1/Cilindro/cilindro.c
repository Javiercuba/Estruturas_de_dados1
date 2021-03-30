#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cilindro.h"


int main()
{

    cilindro c;   //VARIAVEL DO TIPO "cilindro"
    formula area; //VARIAVEL DO TIPO "formula"
    
    printf("Atribuir valores de raio e altura manualmente\n");
    atribui_valores(&c, rand() % 100 /* raio*/, rand() % 100 /* altura*/); //ATRIBUINDO OS VALORES ALEATORIAMENTE
    printf("O valor do raio é %.1f, e a altura é %.1f\n", c.raio, c.altura);
    
    calcula_base(c, &area);    //CALCULO DA BASE POR PASSAGEM DE REFERENCIA
    calcula_lateral(c, &area); //CALCULO DA LATERAL POR PASSAGEM DE REFERENCIA
    calcula_volume(c, &area);  //CALCULO DO VOLUME
    calcula_area_total(&area); //CALCULO DA AREA TOTAL

    ImprimeResultado(area);
}
