#ifndef conjunto_int_h
#define conjunto_int_h

#define TAMANHO 10
typedef struct
{
    int lista[TAMANHO];

} Conjunto;

int uniao(Conjunto *A, Conjunto *B, int *C)
{

    for (int i = 0; i <= TAMANHO * 2; i++)
    {
        if (i < TAMANHO)
        {
            C[i] = A->lista[i];
        }
        else
        {
            C[i] = B->lista[i - 10];
        }
    }
}

/*CRIAR UM CONJUNTO VAZIO */
int Cria_Conjunto_Vazio(Conjunto *A)
{

    for (int i = 0; i < TAMANHO; i++)
    {
        (*A).lista[i] = 0;
    }
}

/*INSERE OS VALORES DE FORMA RANDOMICA NO CONJUNTO*/
int insere(/*int valor, int posi,*/ Conjunto *A)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        (*A).lista[i] = rand() % 10;
    }
}

/*VERIFICA SE O ELEMENTO ESTÁ NO CONJUNTO*/
int testa_pertence(int posi, Conjunto *A)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        if ((*A).lista[i] == posi)
        {
            printf("O numero %d pertence ao conjunto\n", posi);
        }
    }
}

/*REMOVE O ELEMENTO DO CONJUNTO*/
int remover(int posi, Conjunto *A)
{
    if (posi >= TAMANHO || posi < 0 || ((*A).lista[posi] == 0))
    {
        return 0;
    }
    (*A).lista[posi] = 0;
}

/*RETORNA O MENOR ELEMENTO DO CONJUNTO*/
int menor_valor(Conjunto *A)
{
    int menor = (*A).lista[0];
    for (int i = 0; i < TAMANHO; i++)
    {
        if (A->lista[i] < menor)
        {
            menor = A->lista[i];
        }
    }
    printf("O menor valor do conjunto é %d \n", menor);
}
/*RETORNA O MAIOR ELEMENTO DO CONJUNTO*/
int maior_valor(Conjunto *A)
{
    int maior = (*A).lista[0];
    for (int i = 0; i < TAMANHO; i++)
    {
        if (A->lista[i] > maior)
        {
            maior = A->lista[i];
        }
    }
    printf("O maior valor do conjunto é %d \n", maior);
}

/*VERIFICA SE O CONJUNTO É VAZIO*/
int testa_vazio(Conjunto *A)
{

    for (int i = 0; i < TAMANHO; i++)
    {
        if (A->lista[i] != 0)
        {
            printf("Este conjunto não é vazio");
            break;
        }
        else
        {
            printf("Este é vazio");
        }
    }
}

#endif