#include <stdio.h>
#include <stdlib.h>
#include "raiz_quadrada.h"

void main()
{
    TipoItem item;
    int posicao, valor, condicao_de_parada = 1;
    printf("Fundacao Centro Universitario Estadual da Zona Oeste (UEZO)\nProfessor: Eugenio");
    printf("\nTrabalho de Estrutura de Dados 2 (AV2): \"Obtendo a Raiz Quadrada\" \n");
    do
    {
        printf("\n\n\nInsira um numero para obter a raiz quadrada: ");
        scanf("%d", &valor);


        item.tipo_de_lista = 1;
        item.chave = valor;
        posicao = raizQuadrada(&item);

        if(posicao == -1)
        {
            printf("\n\n>>> Nao eh possivel obter a raiz quadrada de %d\n\n\n", valor);
        }

        else if(item.tipo_de_lista == 1)
        {
            printf("\n\n>>> A Raiz quadrada de %d eh: %d\n\n\n", valor, item.lista1[posicao]);
        }

        else
        {
            printf("\n\n>>> A Raiz quadrada de %d eh: %.2f\n\n\n", item.chave, item.lista2[posicao]);
        }

        printf("\n\nDeseja continuar? Digite 0(zero) para sair.  --> ");
        scanf("%d", &condicao_de_parada);

    }while(condicao_de_parada != 0);
}
