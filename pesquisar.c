#include "pesquisa.h"

void pesquisar(Pixel** L, int r, int g, int b, int d)
{
    Pixel* aux = NULL;
    int i = 0, j = 0;
    int x_max = 0, x_min = 3000, y_max = 0, y_min = 3000;

    if(L == NULL)
    {
        printf("A imagem esta nula");
        return;
    }

    int** verificados =(int**) malloc(1080 * sizeof(int*));
    for(int i = 0 ; i < 1080 ; i++)
        verificados[i] = (int*) calloc(1920, sizeof(int));


    for(i = 0 ; i < 1080 ; i++)
    {
        aux = L[i];
        for(j = 0 ; j < 1920 ; j++)
        {
            if(inInterval(aux, r, g, b, d) && verificados[i][j] == 0)
            {
                printf("Achamos uma cor dentro do limite RGB = %d %d %d\n", aux->r, aux->g, aux->b);

                x_max = i;
                x_min = i;
                y_max = j;
                y_min = j;
                verificados[i][j] = 1;

                recursivo(L , i, j, r, g, b, d, &x_max, &x_min, &y_max, &y_min, verificados);
                printf("xmax = %d, xmin = %d, ymax = %d, ymin= %d\n", x_max, x_min, y_max, y_min);
            }

            aux = aux->pnext;
        }
    }
}

int inInterval(Pixel* pixel, int r, int g, int b, int d)
{
    if(!(pixel->r >= r - d && pixel->r <= r + d))
        return 0;
    if(!(pixel->g >= g - d && pixel->g <= g + d))
        return 0;
    if(!(pixel->b >= b - d && pixel->b <= b + d))
        return 0;

    return 1;
}

void recursivo(Pixel* *L , int i, int j, int r, int g, int b, int d, int *x_max, int *x_min, int *y_max, int *y_min, int** V)
{
    printf("\nRecursivo: i = %d, j = %d, verificado = %d", i, j, V[i][j]);
    //começar algoritmo
    if(!inLimits(i, j))
        return;

    //ir a cima se for dentro
    if(inLimits(i - 1, j))
    if(inInterval(getPixel(L, i - 1, j), r, g , b, d) == 1 && V[i - 1][j] != 1)
    {
        V[i - 1][j] = 1;
        //se for menor do que o anterior guarda
        if(i - 1 < *x_min)
            *x_min = i - 1;
        //vai a ele
        recursivo(L, i - 1, j, r, g, b, d, x_max, x_min, y_max, y_min, V);
    }

    //ir à direita se for dentro
    if(inLimits(i, j + 1))
    if(inInterval(getPixel(L, i, j + 1), r, g , b, d) == 1 && V[i][j + 1] != 1)
    {
        V[i][j + 1] = 1;
        //se for maior do que o anterior guarda
        if(j + 1 > *y_max)
            *y_max = j + 1;
        //vai a ele
        recursivo(L, i, j + 1, r, g, b, d, x_max, x_min, y_max, y_min, V);
    }

    //ir a baixo se for dentro
    if(inLimits(i + 1, j))
    if(inInterval(getPixel(L, i + 1, j), r, g , b, d) == 1 && V[i + 1][j] != 1)
    {
        V[i + 1][j] = 1;
        //se for menor do que o anterior guarda
        if(i + 1 > *x_max)
            *x_max = i + 1;
        //vai a ele
        recursivo(L, i + 1, j, r, g, b, d, x_max, x_min, y_max, y_min, V);
    }

    //ir à esquerda se for dentro
    if(inLimits(i, j - 1))
    if(inInterval(getPixel(L, i, j - 1), r, g , b, d) == 1 && V[i][j - 1] != 1)
    {
        V[i][j - 1] = 1;
        //se for menor do que o anterior guarda
        if(j  - 1 < *y_min)
            *y_min = j - 1;
        //vai a ele
        recursivo(L, i, j - 1, r, g, b, d, x_max, x_min, y_max, y_min, V);
    }

    //retorna as coordenadas x max, x min, y max e y min
    return;
}

int inLimits(int i, int j)
{
    if(!(i >= 0 && i < 1080))
        return 0;
    if(!(j >= 0 && j < 1920))
        return 0;
    return 1;
}

Pixel* getPixel(Pixel* *L, int i, int j)
{
    Pixel* aux = NULL;
    aux = L[i];

    while(aux != NULL)
    {
        if(aux->column == j)
            return aux;
        aux = aux->pnext;
    }

    return NULL;
}

