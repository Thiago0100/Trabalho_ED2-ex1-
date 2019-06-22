#ifndef RAIZ_QUADRADA_H_INCLUDED
#define RAIZ_QUADRADA_H_INCLUDED

typedef struct item
{
    int* lista1;    //vetor1
    float* lista2;    //vetor2
    int chave;  // VALOR_RAIZ_QUADRADA
    float resultado_raiz_quadrada;
    int tipo_de_lista;

}TipoItem;

int buscaBinariaLista(TipoItem* item);
int raizQuadrada(TipoItem* item);

#endif // RAIZ_QUADRADA_H_INCLUDED
