#include <stdio.h>
#include <stdlib.h>
#include "raiz_quadrada.h"
#define CASAS_DECIMAIS 100  // s�o as quantidades de posicoes em rela��o a quantidade de casas decimais.

int buscaBinariaLista(TipoItem* item)
{
    int inf = 0, sup = item->chave, busca = -1, meio;
    int valor_proximo1, i, controle = 2, flag;
    float auxiliar = 0.01, valor_proximo2;

    if(item->tipo_de_lista == 2)
    {
        sup = CASAS_DECIMAIS;

        while (inf <= sup)
        {
            meio = (inf + sup) / 2;

            if ((item->lista2[meio]*item->lista2[meio]) == item->chave)
            {
                busca = meio; // �ndice do n� encontrado
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

        do
        {

            if(item->lista2[meio]*item->lista2[meio] < item->chave && flag != 0)
            {
                item->lista2[meio] += auxiliar;
                flag = 1; // utilizado para n�o permitir entrar nas ouras condi��es
            }

            else if(flag != 0)
            {
                item->lista2[meio] -= auxiliar;
            }

            if(item->lista2[meio]*item->lista2[meio] > item->chave && flag != 1)
            {
                item->lista2[meio] += auxiliar;
                flag = 0; // utilizado para n�o permitir entrar nas ouras condi��es
            }

            else if(flag != 1)
            {
                item->lista2[meio] -= auxiliar;
            }

            controle--;

        }while(controle > 0);  //usado para 2 vezes

        busca = meio;
    }

    if(item->tipo_de_lista == 1)
    {
        while (inf <= sup)
        {
            meio = (inf + sup) / 2;

            if ((item->lista1[meio]*item->lista1[meio]) == item->chave)
            {
                busca = meio; // �ndice do n� encontrado
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

        //se n�o encontrar com valores inteiros ele ir� buscar com n�meros decimais.
        if(busca == -1)
        {
            if(valor_proximo1 * valor_proximo1 > item->chave)
            {
                valor_proximo1--;
            }

            item->lista2 = (float*) malloc(CASAS_DECIMAIS * sizeof(float));

            if(item->lista2 == NULL)
            {
                perror("\n>>>> Memoria insuficiente! <<<<\n");
                system("pause");
                exit(EXIT_FAILURE);
            }

            for(i = 0; i < CASAS_DECIMAIS; i++)
            {
                item->lista2[i] = valor_proximo1 + auxiliar;
                auxiliar += 0.01;
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
                    busca = meio; // �ndice do n� encontrado
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

    //se a o item->chave da raiz quadrada for menor que zero,
    //ent�o retorne zero.
    if(item->chave <= minimo)
    {
        return - 1;
    }

    //(item->chave + 1), necess�rio para poder inclui o pr�prio valor e o zero.
    item->lista1 = (int*) malloc((item->chave + 1) * sizeof(int));

    if(item->lista1 == NULL)
    {
        perror("\n>>>> Memoria insuficiente! <<<<\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i <= item->chave; i++)
    {
        item->lista1[i] = i;
    }

    return buscaBinariaLista(item);
}
