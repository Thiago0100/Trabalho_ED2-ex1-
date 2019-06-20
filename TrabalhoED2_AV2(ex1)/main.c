#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int* vetor;
    int numero;

}TipoItem;

typedef struct lista
{
    int* primeiro;
    int* ultimo;

}TipoLista;


/*
int BuscaBinariaLista(TipoLista *lista, TipoItem item)
{
    int inf = 0, sup = lista->ultimo, busca = -1, meio;

    while (inf <= sup)
    {
        meio = (inf + sup) / 2;

        if (lista->itens[meio].chave == item.chave)
        {
            busca = meio; // índice do nó encontrado
            inf = sup + 1;
        }

        else if (lista->itens[meio].chave < item.chave)
            inf = meio + 1;

        else
            sup = meio - 1;
    }

    return busca;
}
*/

float raizQuadrada(TipoItem item)
{
    int minimo = 0, i;

    //se a o valor da raiz quadrada for menor que zero,
    //então retorne zero.
    if(item.numero <= minimo)
    {
        return 0;
    }

    //(valor + 1), necessário para poder inclui o próprio valor e o zero.
    item.vetor = (int*) malloc((item.numero + 1) * sizeof(int));

    if(item.vetor == NULL)
    {
        printf("\n>>>> Memória insuficiente! <<<<\n");
    }

    for(i = 0; i <= item.numero + 1; i++)
    {
        item.vetor[i] = i;
    }

       //Testa vetor
    for(i = 0; i <= item.numero; i++)
    {
        printf("posicao %i: %d\n\n", i, item.vetor[i]);
    }



}


void main()
{
    TipoItem item;

    item.numero = 10;
    printf("Raiz quadrada: %f\n", raizQuadrada(item));

}
