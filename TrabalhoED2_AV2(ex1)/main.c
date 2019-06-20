#include <stdio.h>
#include <stdlib.h>
#define VALOR_RAIZ_QUADRADA 100

typedef struct item
{
    int* lista; //vetor
    float chave;  // VALOR_RAIZ_QUADRADA

}TipoItem;

typedef struct lista
{
    int primeiro;
    int ultimo;

}TipoLista;


float BuscaBinariaLista(TipoItem item);
float raizQuadrada(TipoItem item);



void main()
{
    TipoItem item;

    item.chave = VALOR_RAIZ_QUADRADA;
    printf("\n\n>>> Raiz quadrada: %f\n", raizQuadrada(item));

}


float BuscaBinariaLista(TipoItem item)
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

    return busca;
}


float raizQuadrada(TipoItem item)
{
    int minimo = 0, i;

    //se a o valor da raiz quadrada for menor que zero,
    //então retorne zero.
    if(item.chave <= minimo)
    {
        return 0;
    }

    //(valor + 1), necessário para poder inclui o próprio valor e o zero.
    item.lista = (int*) malloc((item.chave) * sizeof(int));

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


    return BuscaBinariaLista(item);


}
