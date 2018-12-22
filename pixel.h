#ifndef PIXEL_H
#define PIXEL_H

#include <stdlib.h>

typedef struct PIXEL
{
    int column;
    int r, g, b;

    struct PIXEL *pnext;
    struct PIXEL *pprev;

}Pixel;

/*
 * Fun��o make_vector(int n)
 * ----------------------------
 *   TV: n� de elementos que o vetor tera
 *
 *   retorno: vetor com n elementos
 */
Pixel* *make_vector(int TV);

/*
 * Fun��o make_pixel(int column, int r, int g, int b)
 * ----------------------------
 *   column: coluna do pixel
 *   r: codigo do vermelho do pixel
 *   g: codigo do verde do pixel
 *   b: codigo do azul do pixel
 *
 *   retorno: pixel com os atributos de entrada
 */
Pixel* make_pixel(int column, int r, int g, int b);

/*
 * Fun��o insert_last(Pixel *L, Pixel *new_pixel)
 * ----------------------------
 *   L: Lista a introduzir o pixel
 *   new_pixel: pixel para introduzir na lista
 *
 *   retorno: lista com o pixel adicionado na ultima posicao
 */
Pixel* insert_last(Pixel *L, Pixel *new_pixel);


/*
 * Fun��o free_list(Pixel *L)
 * ----------------------------
 *   L: Lista para libertar
 *   TV: tamanho do vetor
 */
void free_image(Pixel* *L, int TV);

/*
 * Fun��o free_list(Pixel *L)
 * ----------------------------
 *   L: Lista para libertar
 */
void free_list(Pixel *L);

#endif /*PIXEL_H*/
