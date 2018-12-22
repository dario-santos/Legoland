#include "pesquisa.h"

int R = 0, G = 0, B = 0, D = 0;
int X_MAX = 0, X_MIN = 0, Y_MAX = 0, Y_MIN = 0;

Zone* search_zones(Pixel* *L, int r, int g, int b, int d)
{
    R = r;
    G = g;
    B = b;
    D = d;

    Zone *Z = NULL;
    Pixel *aux = NULL;
    int i = 0, j = 0;
    int c1 = 0, r1 = 0;
    int sz = 0;

    if(L == NULL)
        return NULL;

    int* *visitados = (int**) malloc(1080 * sizeof(int*));
    for(int i = 0 ; i < 1080 ; i++)
        visitados[i] = (int*) calloc(1920, sizeof(int));

    for(i = 0 ; i < 1080 ; i++)
    {
        aux = L[i];
        for(j = 0 ; j < 1920 ; j++)
        {
            if(in_interval(aux) && visitados[i][j] == 0)
            {
                Y_MAX = i;
                Y_MIN = i;
                X_MAX = j;
                X_MIN = j;

                sz = recursive_search(L, i, j, visitados);

                //Como a imagem come�a a [0][0] temos que aumentar uma unidade
                ++X_MAX;
                ++X_MIN;
                ++Y_MAX;
                ++Y_MIN;

                c1 = (X_MAX + X_MIN)/2;
                r1 = (Y_MAX + Y_MIN)/2;

                Z = insert_order(Z, make_zone(c1, r1, sz));
            }
            aux = aux->pnext;
        }
    }

    for(int i = 0 ; i < 1080 ; i++)
        free(visitados[i]);
    free(visitados);

    return Z;
}

int in_interval(Pixel *pixel)
{
    if(!(pixel->r >= R - D && pixel->r <= R + D))
        return 0;
    if(!(pixel->g >= G - D && pixel->g <= G + D))
        return 0;
    if(!(pixel->b >= B - D && pixel->b <= B + D))
        return 0;

    return 1;
}

int recursive_search(Pixel* *L, int i, int j, int** V)
{
    //Quando as coordenadas n�o s�o v�lidas, o pixel a que chegamos j� foi verificado ou n�o est� na zona
    if(in_limits(i, j) == 0)
        return 0;
    if(V[i][j] == 1)
        return 0;
    if(in_interval(get_pixel(L, i, j)) == 0)
        return 0;

    //se cheg�mos aqui est� tudo bem
    //Dizemos que foi visitado
    V[i][j] = 1;

    //Atualizamos as vari�veis limite
    if(j < X_MIN)
        X_MIN = j;
    if(j > X_MAX)
        X_MAX = j;

    if(i < Y_MIN)
        Y_MIN = i;
    if(i > Y_MAX)
        Y_MAX = i;

    //chamada recursiva
    //Cima, Direita, Baixo, Esquerda
    return 1 + recursive_search(L, i - 1, j, V) +
        recursive_search(L, i, j + 1, V) +
        recursive_search(L, i + 1, j, V) +
        recursive_search(L, i, j - 1, V);
}

int in_limits(int i, int j)
{
    if(!(i >= 0 && i < 1080))
        return 0;
    if(!(j >= 0 && j < 1920))
        return 0;
    return 1;
}

Pixel* get_pixel(Pixel* *L, int i, int j)
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
