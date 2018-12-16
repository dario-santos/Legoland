#ifndef PESQUISA_H
#define PESQUISA_H

#include <stdio.h>
#include "pixel.h"

void pesquisar(Pixel** L, int r, int g, int b, int d);

int inInterval(Pixel* pixel, int r, int g, int b, int d);

void recursivo(Pixel* *L , int i, int j, int r, int g, int b, int d, int *x_max, int *x_min, int *y_max, int *y_min, int** V);

int inLimits(int i, int j);

Pixel* getPixel(Pixel* *L, int i, int j);

#endif /*PESQUISA_H*/
