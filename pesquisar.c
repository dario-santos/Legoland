#include "pesquisa.h"

void pesquisar(Pixel** L, int r, int g, int b, int d)
{
    Pixel* aux = NULL;
    int i = 0, j = 0;

    if(L == NULL)
    {
        printf("A imagem esta nula");
        return;
    }

    for(i = 0 ; i < 1080 ; i++)
    {
        aux = L[i];
        printf("%d ", aux->column);
        for(j = 0 ; j < 1920 ; j++)
        {
            if(aux->r >= r - d && aux->r <= r + d)
                printf("Achamos uma cor dentro do limite RGB = %d %d %d\n", aux->r, aux->g, aux->b);
            aux = aux->pnext;
        }
    }
}
