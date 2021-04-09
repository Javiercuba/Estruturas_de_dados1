#ifndef raiz_h
#define raiz_h
#include <stdio.h>
#include <stdlib.h>

int calcula_raiz(float raiz, float approx, float tolerancia)
{
    if (abs((approx * approx) - raiz) >= tolerancia)
    {
        calcula_raiz(raiz, ((approx*approx) + raiz)/(2*approx), tolerancia);
    }
    printf("%.3f\n", approx);
}

#endif