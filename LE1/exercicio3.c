#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
    char data_formatada[9];
    int ultimo_dia_mes;

} Data;
//FORMATANDO A DATA PARA STRING NO FORMATO DD/MM/AAAA
int formata_data(Data *data)
{
    sprintf(data->data_formatada, "%d/%d/%d\n", data->dia, data->mes, data->ano);
    printf("%s", data->data_formatada);
}
//VALIDANO O ANO
int validacao_ano(Data *data)
{
    if ((*data).ano <= 2021 && (*data).ano > 1000) //VERIFICAR SE O ANO É VALIDO, ENTRE 2020 E 1000
    {
        if (((*data).ano % 4 == 0 && (*data).ano % 100 == 0 && (*data).ano % 400 == 0) || ((*data).ano % 4 == 0 && (*data).ano % 100 != 0)) //VERIFICAR SE O ANO É BISSEXTO
        {
           
            return 1; //RETORNA QUE O ANO É VALIDO E BISSEXTO
        }
        else
        {
            return 2; //RETORNA QUE O ANO É VALIDO E NÃO BISSEXTO
        }
    }
    else
    {
        return 3; //RETORNA QUE O ANO NÃO É VALIDO
    }
}
//VALIDANO O MÊS
int validacao_mes(Data *data)
{
    if ((*data).mes > 0 && (*data).mes <= 12)
    {
        return (*data).mes; //RETORNANDO O NUMERO DO MÊS PARA SABER A QUANTIDADE DE DIAS QUE ESSE MÊS TERÁ
    }
    else
    {
        return 0;
    }
}
//VALIDANO O DIA
int validacao_dia(Data *data)
{
    if ((*data).dia > 1 && (*data).dia <= (*data).ultimo_dia_mes)
    {
        return 1;
    }
    return 0;
}
//VERIFICANDO A DATA COM UMA FUNÇÃO PRINCIPAL QUE CHAMA AS OUTRAS QUE VERIFICAM O ANO A DATA E O DIA
int validacao_data(Data *data)
{

    switch (validacao_mes(data))
    {
    case 2:
        if (validacao_ano(data) == 1)
        {
            (*data).ultimo_dia_mes = 29;
        }
        (*data).ultimo_dia_mes = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        (*data).ultimo_dia_mes = 30;
        break;
    default:
        (*data).ultimo_dia_mes = 31;
    }

    if (validacao_ano(data) != 3 && validacao_mes(data) != 0 && validacao_dia(data) != 0) //VERIFICANDO SE O ANO E O SÃO VALIDOS PARA FORMATAR
    {
        formata_data(data);
        return 1;
    }
    else
    {
        printf("Data indisponivel para formatar\n");
        return 0;
    }
}


int somatorio_dias(Data *data, int num_dias_acrescentar)
{
    if (validacao_data(data) == 1)//VALIDAÇÃO DA DATA PARA PODER FAZER O SOMATORIO
    {

        if (num_dias_acrescentar + data->dia > data->ultimo_dia_mes) //VERIFICANDO SE O NUMERO DE DIAS MAIS O VALOR A SE ACRESCENTAR É MAIOR QUE O NUMERO DE DIAS NO MES
        {
            if ((num_dias_acrescentar) / data->ultimo_dia_mes >= 1)
            /*SE A DIVISAO DA SOMA DOS DIAS COM O NUMERO
            DE DIAS NO MES FOR MAIOR QUE 1 CONSEQUENTEMENTE
            TEMOS UM MÊS EMBUTIDO DENTRO DESSES DIAS, LOGO SE
            ACRESCENTA MAIS 1 NO MÊS, E O NUMERO DE DIAS RECEBE
            A SUBTRAÇÃO DELE COM O NUMERO DE DIAS DESSE MES,
            SENDO ASSIM A FUNÇÃO É CHAMADA DE NOVO.
            */
            {
                data->mes += 1;   //MÊS RECEBE MAIS 1 E CHAMA A FUNÇÃO DE NOVO
                if(data->mes > 12){ //CASO O MÊS ULTRAPASSE O NUMERO 12, ELE SERÁ REINICIADO E O ANO SERA ACRESCENTADO MAIS UM
                    data->mes = 1;
                    data->ano = data->ano + 1;
                   
                }
                num_dias_acrescentar -= data->ultimo_dia_mes;
                /*O VALOR INICIAL DE DIAS A SER ACRESCENTADO DE 
                 DIAS SERÁ SUBTRAIDO PELO NUMERO DE DIAS NESSE MÊS,
                 POIS JA ACRESCENTAMOS UM MÊS
                */
               

                somatorio_dias(data, num_dias_acrescentar);
                /*A FUNÇÃO ESTÁ SENDO CHAMADA INCIANDO UM NOVO LOOP COM SEUS NOVOS VALORES.
                ELE SÓ VAI PARAR DE SE CHAMAR QUANDO O NUMERO DE DIAS PARA ACRESCENTAR 
                FOR MENOR QUE O NUMERO DE DIAS DESSE MÊS.  
                */
            }
        }
        else
        {
            data->dia += num_dias_acrescentar;
            validacao_data(data);
            /*AQUI O LOOP SE FINALIZOU, E SERÁ FEITA A VALIDAÇÃO DA DATA PARA VERIFICAR E TERMINAR O PROCESSO  
                */
        }
    }
}
int main()
{
    Data d;
    d.dia = 2;
    d.mes = 4;
    d.ano = 2011;
    //validacao_data(&d);
    somatorio_dias(&d, 360);
}
