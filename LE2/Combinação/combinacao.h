#ifndef combinacao_h
#define combinacao_h
#include <stdio.h>
#include <stdlib.h>

int C(int n, int k)
{
    int x;
    if (k == 0 || n == k)
    {
        return 1;
    }
    
    if (n > k > 0)
    {
        x = C(n - 1, k) + C(n - 1, k - 1);
        return (x);
    }
}

#endif