#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    // int codigo;
    int numero;
    char endereco[15];
    char nome[10];
    // char data_primeira_compra[10];
    // char data_ultima_compra[10];
    // int valor_ultima_compra;

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
    char teste[10] = "string";
   // cliente.nome = {teste};
    printf("%s", cliente.nome);
    cria_cliente();


}
