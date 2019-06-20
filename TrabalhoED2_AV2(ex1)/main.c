#include <stdio.h>
#include <stdlib.h>


float raizQuadrada(int valor)
{
    int minimo = 0, i;
    int* vetor;
    //se a o valor da raiz quadrada for menor que zero,
    //ent�o retorne zero.
    if(valor <= minimo)
    {
        return 0;
    }

    //(valor + 1), necess�rio para poder inclui o pr�prio valor e o zero.
    vetor = (int*) malloc((valor + 1) * sizeof(int));

    if(vetor == NULL)
    {
        printf("\n>>>> Mem�ria insuficiente! <<<<\n");
    }

    for(i = 0; i <= valor + 1; i++)
    {
        vetor[i] = i;
    }

    /*   Testa vetor
    for(i = 0; i <= valor; i++)
    {
        printf("posicao %i: %d\n\n", i, vetor[i]);
    }*/



}


void main()
{
    int numero = 10;
    printf("Raiz quadrada: %f\n", raizQuadrada(numero));

}
