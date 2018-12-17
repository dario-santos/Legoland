#include "pixel.h"

Pixel* *make_vector(int n)
{
    Pixel* *L = (Pixel**) malloc(n * sizeof(Pixel*));

    int i = 0;
    for(i = 0 ; i < n ; i++)
        L[i] = NULL;

    return L;
}

Pixel* make_pixel(int column, int r, int g, int b)
{
    Pixel *aux = (Pixel*) malloc(sizeof(Pixel));
    aux->column = column;
    aux->r = r;
    aux->g = g;
    aux->b = b;

    aux->pnext = NULL;
    aux->pprev = NULL;

    return aux;
}

Pixel* insert_last(Pixel *L, Pixel *new_pixel)
{
    Pixel *aux = L;
    if(L == NULL)
        return new_pixel;

    while(aux != NULL)
    {
        if(aux->pnext == NULL)
        {
            aux->pnext = new_pixel;
            new_pixel->pprev = aux;
            break;
        }
        aux = aux->pnext;
    }
    return L;
}

void free_list(Pixel *L)
{
    if(L == NULL)
        return;

    while(L != NULL)
    {
        if(L->pprev != NULL)
            free(L->pprev);
        if(L->pnext == NULL)
        {
            free(L);
            return;
        }
        L = L->pnext;
    }
}
