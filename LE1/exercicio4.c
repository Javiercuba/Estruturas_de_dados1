#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    int numero;
    char endereco[15];
    char nome[10];
    int data_primeira_compra;
    int data_ultima_compra;
    int valor_ultima_compra;

} Cliente;

int lista_cliente()
{
    FILE *csvfile = fopen("clientes.csv", "r+");
    int numero_linhas = 1;
    int posicao_linha = 0;
    ssize_t line_size;
    ssize_t line_buf_size = 0;
    char *line_buf = NULL;
    while (line_size >= 0)
    {
        line_size = getline(&line_buf, &line_buf_size, csvfile);

        /* Show the line details */
        // printf("line[%02d]: chars=%03zd, buf size=%06zu, contents: %s", numero_linhas, line_size, line_buf_size, line_buf);
        printf("linha[%02d]: %s", numero_linhas, line_buf);
        numero_linhas++;
    }

    fclose(csvfile);
}
int cria_cliente()
{
    FILE *csvfile = fopen("clientes.csv", "r+");
    int numero_linhas = 1;
    int posicao_linha = 0;
    ssize_t line_size;
    ssize_t line_buf_size = 0;
    char *line_buf = NULL;
    while (line_size >= 0)
    {
        line_size = getline(&line_buf, &line_buf_size, csvfile);
    }

    fprintf(csvfile, "23223234,marcelom,");
    lista_cliente();
}

int main()
{
    Cliente cliente;

    cliente.nome* = (char *)malloc(21 * sizeof(char));

    printf("Qual é o codigo do cliente?\n");
    scanf("%d", &cliente.codigo);
   

    printf("Qual é o nome do cliente?\n");
    scanf("%s", cliente.nome);

    
    printf("Qual é o numero do cliente?\n");
    scanf("%d", &cliente.numero);

    printf("Qual é a data da primeira compra do cliente?\n");
    scanf("%d", &cliente.data_primeira_compra);
    

    printf("nome : %s\n", cliente.nome);
    printf("codigo: %d\n", cliente.codigo);
    printf("numero: %d\n", cliente.numero);
    
    //cria_cliente();
}
