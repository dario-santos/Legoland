#ifndef LER_H
#define LER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pixel.h"

/*
 * Fun��o open_file(char *path)
 * ----------------------------
 *   path: caminho do ficheiro
 *
 *   retorno: ficheiro
 */
FILE* open_file(char *path);

/*
 * Fun��o close_file(FILE *F)
 * ----------------------------
 *   F: ficheiro para fechar
 */
void close_file(FILE *F);

/*
 * Fun��o read_file(FILE *F)
 * ----------------------------
 *   F: ficheiro a ler
 *   lin: numero de pixeis por linha da imagem
 *   col: numero de pixeis por coluna da imagem
 *
 *   retorno: vetor de listas com a imagem escolhida
 */
Pixel* *read_file(FILE *F, int *lin, int *col);

#endif /*LER_H*/
