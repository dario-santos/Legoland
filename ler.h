#ifndef LER_H
#define LER_H

#include <stdlib.h>
#include <stdio.h>

#include "pixel.h"

/*
 * Função open_file(char *path)
 * ----------------------------
 *   path: caminho do ficheiro
 *
 *   retorno: ficheiro
 */
FILE* open_file(char *path);

/*
 * Função close_file(FILE *F)
 * ----------------------------
 *   F: ficheiro para fechar
 */
void close_file(FILE *F);

/*
 * Função read_file(FILE *F)
 * ----------------------------
 *   F: ficheiro a ler
 *
 *   retorno: vetor de listas com a imagem escolhida
 */
Pixel* *read_file(FILE *F);

#endif /*LER_H*/
