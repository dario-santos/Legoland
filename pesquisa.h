#ifndef PESQUISA_H
#define PESQUISA_H

#include <stdio.h>
#include <stdlib.h>

#include "pixel.h"
#include "zone.h"

/*
 * Fun��o search_zones(Pixek* *L, int r, int g, int b, int d)
 * ----------------------------
 *   L: vetor de listas com a imagem em que vamos procurar
 *   lin: numero de pixeis por linhas da imagem
 *   col: numero de pixeis por coluna da imagem
 *   r: codigo do vermelho a procurar
 *   g: codigo do verde a procurar
 *   b: codigo do azul a procurar
 *   d: tolerancia
 *
 *   retorno: Lista com as zonas por ordem decrescente
 */
Zone* search_zones(Pixel* *L, int lin, int col, int r, int g, int b, int d);

/*
 * Fun��o in_interval(Pixel *pixel)
 * ----------------------------
 *   pixel: pixel para ver se est� dentro do intervalo de cor
 *
 *   retorno: 1 esta no intervalo, 0 nao esta
 */
int in_interval(Pixel *pixel);

/*
 * Fun��o recursive_search(Pixel* *L , int i, int j, int** V)
 * ----------------------------
 *   L: vetor de listas que representa a imagem a pesquisar
 *   i: linha do pixel atual
 *   j: coluna do pixel atual
 *   V: matriz de flags para ver os pixeis ja visitados
 *
 *   retorno: n� de pixeis da zona
 */
int recursive_search(Pixel* *L , int i, int j, int* *V);

/*
 * Fun��o in_limits(int i, int j)
 * ----------------------------
 *   i: linha do pixel atual
 *   j: coluna do pixel atual
 *
 *   retorno: 1 esta no intervalo, 0 nao esta
 */
int in_limits(int i, int j);

/*
 * Fun��o get_pixel(Pixel* *L, int i, int j)
 * ----------------------------
 *   L: Vetor de listas
 *   i: linha do pixel atual
 *   j: coluna do pixel atual
 *
 *   retorno: pixel com a coluna j na lista L[i]
 */
Pixel* get_pixel(Pixel* *L, int i, int j);

#endif /*PESQUISA_H*/
