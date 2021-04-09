#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientes.h"

int main()
{
    Cliente cliente;

    printf("Qual é o codigo do cliente?\n");
    scanf("%d", &cliente.codigo);
   
    printf("Qual é o nome do cliente?\n");
    scanf("%s", cliente.nome);

    printf("Qual é o numero do cliente?\n");
    scanf("%d", &cliente.numero);

    printf("Qual é a data da primeira compra do cliente?\n");
    scanf("%s", cliente.data_primeira_compra);

    printf("Qual é a data da ultima compra do cliente?\n");
    scanf("%s", cliente.data_ultima_compra);

    printf("Qual é o valor da ultima compra do cliente?\n");
    scanf("%d", &cliente.valor_ultima_compra);

    printf("Qual é o endereço do cliente?\n");
    scanf("%s", cliente.endereco);
    printf("\n");
    printf("nome : %s\n", cliente.nome);
    printf("codigo: %d\n", cliente.codigo);
    printf("numero: %d\n", cliente.numero);
    printf("Endereço: %s\n", cliente.endereco);
    printf("Data da primeira compra: %s\n", cliente.data_primeira_compra);

    printf("\n");
    cria_cliente(&cliente);
}
