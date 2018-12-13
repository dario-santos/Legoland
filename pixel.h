#ifndef PIXEL_H
#define PIXEL_H
#include <stdlib.h>

typedef struct PIXEL
{
    int column;
    int r, g, b;

    struct PIXEL* pnext;
    struct PIXEL* pprev;

} Pixel;

Pixel** make_lines(int n);

Pixel* make_pixel(int column, int r, int g, int b);

Pixel* insert_pixel(Pixel* L, Pixel* np);

void free_list(Pixel* L);

#endif /*PIXEL_H*/
