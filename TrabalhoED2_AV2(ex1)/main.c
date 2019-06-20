#include <stdio.h>
#include <stdlib.h>
#define VALOR_RAIZ_QUADRADA 121

typedef struct item
{
    int* lista;    //vetor
    int chave;  // VALOR_RAIZ_QUADRADA
    float resultado_raiz_quadrada;

}TipoItem;

typedef struct lista
{
    int primeiro;
    int ultimo;

}TipoLista;


int buscaBinariaLista(TipoItem item);
int raizQuadrada(TipoItem item);


void main()
{
    TipoItem item;
    int posicao;

    item.chave = VALOR_RAIZ_QUADRADA;
    item.resultado_raiz_quadrada = raizQuadrada(item);

    printf("\n\n>>> Raiz quadrada de %d eh: %f\n\n\n", VALOR_RAIZ_QUADRADA, item.resultado_raiz_quadrada);

    system("pause");


}


int buscaBinariaLista(TipoItem item)
{
    int inf = 0, sup = VALOR_RAIZ_QUADRADA, busca = -1, meio;

    while (inf <= sup)
    {
        meio = (inf + sup) / 2;

        if ((item.lista[meio]*item.lista[meio]) == item.chave)
        {
            busca = meio; // índice do nó encontrado
            inf = sup + 1;
        }

        else if ((item.lista[meio]*item.lista[meio]) < item.chave)
            inf = meio + 1;

        else
            sup = meio - 1;
    }

    //se não encontrar com valores inteiros ele irá buscar com números decimais.
    if(busca == -1)
    {


    }

    //retorna o indice
    return busca;
}


int raizQuadrada(TipoItem item)
{
    int minimo = 0, i, posicao;

    //se a o valor da raiz quadrada for menor que zero,
    //então retorne zero.
    if(item.chave <= minimo)
    {
        return 0;
    }

    //(valor + 1), necessário para poder inclui o próprio valor e o zero.
    item.lista = (int*) malloc((item.chave + 1) * sizeof(int));

    if(item.lista == NULL)
    {
        printf("\n>>>> Memoria insuficiente! <<<<\n");
        system("pause");
    }

    for(i = 0; i <= item.chave; i++)
    {
        item.lista[i] = i;
    }

       //Testa vetor
    for(i = 0; i <= item.chave; i++)
    {
        printf("posicao %d: %d\n\n", i, item.lista[i]);
    }


    return buscaBinariaLista(item);
}
