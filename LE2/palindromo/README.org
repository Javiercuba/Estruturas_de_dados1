#+title: Hexadecimal
#+author: Javier Ernesto Lopez del real
#+email: javierernesto2000@gmail.com

Explicando o funcionamento do projeto. 

* Struct
#+begin_src c
struct Node
{
    char num;
    struct Node *prox;
};
typedef struct Node node;
#+end_src c

* Função main
#+begin_src c
int main(void)
{
    node *PILHA = (node *)malloc(sizeof(node));  
    node *invertido = (node *)malloc(sizeof(node)); 
#+end_src c
- Alocando memoria na pilha original e na pilha que será
 invertida e transformada para hexadecimal.

#+begin_src c

    if (!PILHA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
}
#+end_src c
- Verifico se tem memoria disponivel.


#+begin_src c

    else
    {
        inicia(PILHA);
        inicia(invertida);
        int opt;

        do
        {
            opt = menu();
            opcao(PILHA, invertida, opt);
        } while (opt);

        free(PILHA);
        return 0;
    }
}
#+end_src c

* Funções =opcao= e =menu=
#+begin_src c
int menu(void)
{
    int opt;

     printf("\nEscolha a opcao\n");
    printf("1. PUSH \n");
    printf("2. POP \n");
    printf("3. Exibir PILHA\n");
    printf("4. Desempilhar\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}
#+end_src c


#+begin_src c

void opcao(node *PILHA, node *invertida, int op)
{
      node *tmp;
    switch (op)
    {
    case 1:
        push(PILHA);
        break;
    case 2:
        tmp = pop(PILHA);
        break;
    case 3:
        exibe(PILHA);
        break;
    case 4:
        desempilha(PILHA, invertido);
    default:
        printf("\n");
    }
}
#+end_src c
* Explicação dos casos importantes

** Caso 1 - Insere a string na pilha original.
Na primeira linha eu chamo a função =aloca()= que retorna uma 
pilha com um valor lido pelo usuario e neste caso está sendo armazenada na variavel do tipo
node que é nosso struct, em seguida ele verifica se a pilha original está
vazia caso esteja vazia o ponteiro da pilha principal recebe essa pilha nova, caso contrario
o ponteiro se desloca até o proximo apontador apontar para =NULL=, encontrando o ultimo 
apontador ele recebe essa nova pilha.

#+begin_src c
void push(node *PILHA)
{

    node *novo = aloca();
    novo->prox = NULL;
    printf("%c", novo->num);
    if (vazia(PILHA))
    {
        PILHA->prox = novo;
    }
    else
    {
        node *tmp = PILHA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
}

#+end_src c
A função =aloca()= está presente no arquivo =pilha.h= por ser uma função mais genérica,
e tem a função de ler um valor digitado.
#+begin_src c
node *aloca()
{
    node *novo = (node *)malloc(sizeof(node)); 
    if (!novo)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        printf("Novo elemento: ");
        scanf(" %c", &novo->num);

        return novo;
    }
}
#+end_src c

** Caso 4 - A função =desempilha= tem a função de desempilhar uma pilha.
Essa função recebe duas pilhas como parametro uma que é a original e outra vazia que será o inverso da
original. Para fazer essa inversão alem dessa pilha vazia eu utilizei uma pilha auxiliar onde as duas pilhas
recebem a original invertida e a pilha auxiliar "devolve" seus valores pra pilha original.  

a questão é ter 
#+begin_src c

void desempilha(node *PILHA1, node *PILHA2)
{
    node *aux = (node *)malloc(sizeof(node)); //PILHA AUXILIAR

    node *tmp, *ultimo;
    tmp = PILHA1;

    while (tmp->prox != NULL) //PERCORRENDO ENQUANTO NÃO CHEGA NO FINAL DA PILHA ORIGINAL
    {
        ultimo = pop(PILHA1); //REMOVENDO OS VALORES DA PILHA ORIGINAL
        push2(PILHA2, ultimo->num); //INSERINDO NA PILHA INVERTIDA
        push2(aux, ultimo->num);    //INSERINDO NA PILHA AUXILIAR
    }
#+end_src c



#+begin_src c
    while (aux->prox != NULL) //PERCORRENDO ENQUANTO NÃO CHEGA NO FINAL DA PILHA AUXILIAR
    {
        ultimo = pop(aux); //REMOVENDO OS VALORES DA PILHA AUXILIAR
        push2(PILHA1, ultimo->num);  //INSERINDO NA PILHA ORIGINAL DEVOLTA
    }
    printf("\n");
    printf("Auxiliar:");
    exibe(aux);
    printf("\n");

    printf("Pilha Original:");
    exibe(PILHA1);
    printf("\n");
    printf("Pilha Invertida:");
    exibe(PILHA2);
#+end_src c
A função =verifica= se a =Pilha original= e a =Pilha invertida= são iguais(Se são palindromos).
#+begin_src c
    verifica(PILHA1, PILHA2);
}
#+end_src c



* Execução do código
Primeiro se escolhe o =caso 1= onde o usuario vai pode escrever a frase.

#+begin_src c
        divide(PILHA, 12444556);
#+end_src c

#+begin_src c
int divide(node *PILHA, int x) 
{
    if ((float)x / 16 > 0.01)
    {
        push(PILHA, x % 16); 
        divide(PILHA, x / 16);
    }
}
#+end_src c

Em seguida temos a função "desempilha" que tem a função de filtrar os elementos transformando para hexadecimal e 
inseri-los em uma nova pilha. 


#+begin_src c
char desempilha(node *PILHA, int x)
{
    char c = hexa(x);
    push(PILHA, c);
}
#+end_src c

A filtragem para hexa é feita pela função =hexa=, que retorna a variavel em =char=.

#+begin_src c

int hexa(int x)
{
    switch (x)
    {
    case 10:
        return 'A';
        break;
    case 11:
        return 'B';
        break;
    case 12:
        return 'C';
        break;
    case 13:
        return 'D';
        break;
    case 14:
        return 'E';
        break;
    case 15:
        return 'F';
        break;
    default:
        return x;
    }
}
#+end_src c

Para executar o desempilhamento chamei o =caso 2= que é a função =pop= que remove o ultimo valor da pilha original
e em seguida chamo a função =desempilha= que vai inserir esse valor removido na nova pilha.


#+begin_src c
node *pop(node *PILHA, node *invertida)
{
    if (PILHA->prox == NULL)
    {
        printf("Pilha Original vazia\n\n");
        printf("Pilha Hexadecimal: ");
        exibe(invertida);
        return NULL;
    }
    else
    {
        node *ultimo = PILHA->prox,
             *penultimo = PILHA;

        while (ultimo->prox != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        desempilha(invertida, ultimo->num);

        penultimo->prox = NULL;

        tam--;
        printf("Pilha Decimal");
        exibe(PILHA);
        printf("\n");
        printf("Pilha Hexadecimal");
        exibe(invertida);
        printf("\n");
        return ultimo;
    }
}
#+end_src c

#+html: <p align="center"><img align="center" src="./gif.gif"  width="50%" height="60%" /> </p>

** Caso queira baixar o executável [[https://github.com/Javiercuba/Estruturas_de_dados1/releases/download/1.0/hexadecimal][Clique aqui]].

    
