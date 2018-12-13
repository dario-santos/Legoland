#include <stdio.h>
#include <stdlib.h>

#include "pixel.h"

int main(void)
{
    Pixel** G = make_lines(5);
    G[0] = NULL;
    G[0] = insert_pixel(G[0], make_pixel(5,255,255,255));
    G[0] = insert_pixel(G[0], make_pixel(6,12,121,5));
    Pixel *aux = G[0];
    while(aux!= NULL)
    {
        printf("%d\n", aux->column);
        aux = aux->pnext;
    }






    handle_menu();

    printf("\n\nLegoland v0.01\n");
    printf("Autor : Dario Santos 39973\n\n");



    return 0;
}
