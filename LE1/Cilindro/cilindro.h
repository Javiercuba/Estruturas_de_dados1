#ifndef cilindro_h
#define cilindro_h

//CRIANDO UM STRUCT DO TIPO CILINDRO PARA GUARDAR OS PARAMETROS DO CILINDRO
typedef struct
{
    float raio;
    float altura;
} cilindro;

//CRIANDO UM STRUCT DO TIPO "resultados" PARA GUARDAR OS RESULTADOS DE CADA EQUAÇÃO
typedef struct
{
    float area_base;
    float area_lateral;
    float area_total;
    float volume;

} formula;

//VARIAVEL RECEBENDO O VALOR DO CALCULO DA BASE POR REFERENCIA
int calcula_base(cilindro c, formula *p)
{
    (*p).area_base = c.raio * c.raio * 3.14;
}

//VARIAVEL RECEBENDO O VALOR DO CALCULO DA LATERAL POR REFERENCIA
int calcula_lateral(cilindro c, formula *p)
{
    (*p).area_lateral = c.raio * 3.14 * c.altura;
}

//CALCULANDO O VOLUME PASSANDO A VARIAVEL POR REFERENCIA
int calcula_volume(cilindro c, formula *p)
{
    (*p).volume = c.raio * c.raio * 3.14 * c.altura;
}

//CALCULANDO A AREA TOTAL DO CILINDRO
int calcula_area_total(formula *p)
{
    (*p).area_total = (2 * (*p).area_base) + (2 * (*p).area_lateral);
}

//ATRIBUINDO OS VALORES NA STRUCT POR REFERENCIA, DESSA FORMA NÃO NECESSITO DE UMA "GAMBIARRA" PARA GUARDAR OS VALORES
void atribui_valores(cilindro *c, int raio, int altura)
{
    (*c).raio = raio;
    (*c).altura = altura;
}

//IMPRIMINDO OS RESULTADOS FINAIS
void ImprimeResultado(formula resultado)
{
    printf("Area do Cilindro = %.2f\n", resultado.area_total);
    printf("Volume do Cilindro = %.2f\n", resultado.volume);
}

#endif