#include <stdio.h>
#include <stdlib.h>
#include "../fila.h"
#include "../pilha.h"

void opcao(fila *f, node *PILHA, int op);
int prefixa(fila *f, node *PILHA);
void exibePilha(node *PILHA);
char resolve_equacao(char equacao, char primeiro, char segundo);
int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("1. Inserir\n");
    printf("2. Remover\n");
    printf("3. Prefixa\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

int main()
{
    node *PILHA = cria_pilha();
    fila *f = alocar_fila();
    int opt;
    do
    {
        opt = menu();
        opcao(f, PILHA, opt);
    } while (opt);

    return 0;
}

void opcao(fila *f, node *PILHA, int op)
{

    switch (op)
    {
    case 1:
        inserir_fila(f);
        imprimir_fila(f);
        break;

    case 2:
        remover_fila(f);
        imprimir_fila(f);
        break;

    case 3:
        prefixa(f, PILHA);
        exibePilha(PILHA);
        break;
    default:
        printf("Comando invalido\n\n");
    }
}

int prefixa(fila *f, node *PILHA)
{
    no *temp = f->comeco;
    node *ultimo_valor_pilha, *penultimo_valor_pilha;
    int resultado_equacao;

    if (temp != NULL)
    {
        char valor_pilha = remover_fila(f);

        if (valor_pilha == '+' || valor_pilha == '*' || valor_pilha == '-' || valor_pilha == '/')
        {

            ultimo_valor_pilha = pop(PILHA);
            penultimo_valor_pilha = pop(PILHA);
            
            resultado_equacao = resolve_equacao(valor_pilha, ultimo_valor_pilha->num, penultimo_valor_pilha->num);

            push2(PILHA, resultado_equacao + '0');

            prefixa(f, PILHA);
        }
        else
        {
            push2(PILHA, valor_pilha);
            prefixa(f, PILHA);
        }
        printf("PILHA -> ");
        exibePilha(PILHA);
    }
}

char resolve_equacao(char operador, char primeiro, char segundo)
{

    int primeiro_valor = 0, segundo_valor = 0;

    sscanf(&primeiro, "%d", &primeiro_valor); //Transformando de char para inteiro
    sscanf(&segundo, "%d", &segundo_valor);   //Transformando de char para inteiro

    switch (operador)
    {
    case '+':
        printf(" Resutado Soma %d + %d = %d\n", primeiro_valor, segundo_valor, (primeiro_valor + segundo_valor));
        return (primeiro_valor + segundo_valor);
        break;
    case '*':
        printf(" Resutado Multiplicacao %d x %d = %d\n", primeiro_valor, segundo_valor, (primeiro_valor * segundo_valor));
        return primeiro_valor * segundo_valor;
        break;
    case '/':
        printf(" Resutado Divisao: %d", (primeiro_valor / segundo_valor));
        return primeiro_valor / segundo_valor;
        break;
    case '-':
        printf(" Resutado Subtracao: %d - %d = %d\n", primeiro_valor, segundo_valor, (primeiro_valor - segundo_valor));
        return primeiro_valor - segundo_valor;

        break;
    default:
        return 0;
    }
}

void exibePilha(node *PILHA)
{
    if (vazia(PILHA))
    {
        printf("PILHA vazia!\n\n");
        return;
    }

    node *tmp;
    tmp = PILHA->prox;

    while (tmp != NULL)
    {
        printf("%c\t", tmp->num);
        tmp = tmp->prox;
    }

    printf("\n");
}
