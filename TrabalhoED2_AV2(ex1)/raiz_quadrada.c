#include <stdio.h>
#include <stdlib.h>
#include "raiz_quadrada.h"
#define CASAS_DECIMAIS 100  // são as quantidades de posicoes em relação a quantidade de casas decimais.

int buscaBinariaLista(TipoItem* item)
{
    int inf = 0, sup = item->chave, busca = -1, meio;
    int valor_proximo1, i;
    float auxiliar = 0.00, valor_proximo2;

    if(item->tipo_de_lista == 2)
    {
        sup = CASAS_DECIMAIS;

        while (inf <= sup)
        {
            meio = (inf + sup) / 2;

            if ((item->lista2[meio]*item->lista2[meio]) == item->chave)
            {
                busca = meio; // índice do nó encontrado
                inf = sup + 1;
            }

            else if ((item->lista2[meio]*item->lista2[meio]) < item->chave)
            {
                inf = meio + 1;
                valor_proximo2 = item->lista2[meio];
            }

            else
            {
                sup = meio - 1;
                valor_proximo2 = item->lista2[meio];
            }
        }

        busca = meio - 1;
    }

    if(item->tipo_de_lista == 1)
    {
        while (inf <= sup)
        {
            meio = (inf + sup) / 2;

            if ((item->lista1[meio]*item->lista1[meio]) == item->chave)
            {
                busca = meio; // índice do nó encontrado
                inf = sup + 1;
            }

            else if ((item->lista1[meio]*item->lista1[meio]) < item->chave)
            {
                inf = meio + 1;
                valor_proximo1 = item->lista1[meio];
            }

            else
            {
                sup = meio - 1;
                valor_proximo1 = item->lista1[meio];
            }
        }

        //se não encontrar com valores inteiros ele irá buscar com números decimais.
        if(busca == -1)
        {
            if(valor_proximo1 * valor_proximo1 > item->chave)
            {
                valor_proximo1--;
            }

            item->lista2 = (float*) malloc(CASAS_DECIMAIS * sizeof(float));

            if(item->lista2 == NULL)
            {
                printf("\n>>>> Memoria insuficiente! <<<<\n");
                system("pause");
            }

            for(i = 0; i < CASAS_DECIMAIS; i++)
            {
                auxiliar += 0.01;
                item->lista2[i] = valor_proximo1 + auxiliar;
            }

            item->tipo_de_lista = 2;

            busca = buscaBinariaLista(item);
        }

        else
        {
            while (inf <= sup)
            {
                meio = (inf + sup) / 2;

                if ((item->lista2[meio]*item->lista2[meio]) == item->chave)
                {
                    busca = meio; // índice do nó encontrado
                    inf = sup + 1;
                }

                else if ((item->lista2[meio]*item->lista2[meio]) < item->chave)
                {
                    inf = meio + 1;
                    valor_proximo1 = item->lista2[meio];
                }

                else
                {
                    sup = meio - 1;
                    valor_proximo1 = item->lista2[meio];
                }
            }
        }
    }

    //retorna o indice
    return busca;
}


int raizQuadrada(TipoItem *item)
{
    int minimo = 0, i, posicao;

    //se a o valor da raiz quadrada for menor que zero,
    //então retorne zero.
    if(item->chave <= minimo)
    {
        return 0;
    }

    //(valor + 1), necessário para poder inclui o próprio valor e o zero.
    item->lista1 = (int*) malloc((item->chave + 1) * sizeof(int));

    if(item->lista1 == NULL)
    {
        printf("\n>>>> Memoria insuficiente! <<<<\n");
        system("pause");
    }

    for(i = 0; i <= item->chave; i++)
    {
        item->lista1[i] = i;
    }

    return buscaBinariaLista(item);
}
