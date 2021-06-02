#ifndef QUEUE_H
#define QUEUE_H
#define TRUE 1
#define FALSE 0

typedef struct element
{
    struct element *prox;
    int valor;
} no;

typedef struct
{
    no *comeco;
    no *fim;
} fila;

fila *alocar_fila()
{
    fila *f = malloc(sizeof(fila));
    f->comeco = NULL;
    f->fim = NULL;
    return f;
}

void destruir_fila(fila *f)
{
    //while (remover_fila(f) != -1){
    //        free(f);
     //}
    
}

void imprimir_fila(fila *f)
{
    no *temp = f->comeco;
    while (temp != NULL)
    {
        printf("\n%c ", temp->valor);
       
        temp = temp->prox;
    }
    printf("\n");
}

void inserir_fila(fila *f, int valor)
{
    char x;
    scanf("%s", &x);
    no *novo = malloc(sizeof(no));
    novo->valor = x;
    novo->prox = NULL;

    if (f->comeco == NULL)
    {
        f->comeco = novo;
        f->fim = novo;
        return;
    }

    f->fim->prox = novo;
    f->fim = novo;
}

int remover_fila(fila *f)
{

    if (f->comeco == NULL)
    {
        printf("Fila vazia!");
        return -1;
    }

    no *temp = f->comeco;
    int valor = temp->valor;

    f->comeco = f->comeco->prox;
    free(temp);
    return valor;
}


#endif