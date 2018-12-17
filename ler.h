#ifndef LER_H
#define LER_H

#include <stdlib.h>
#include <stdio.h>
#include "pixel.h"

/*
 * Função read_file(int index)
 * ----------------------------
 *   index: numero inteiro que simboliza a imagem que queremos carregar do ficheiro
 *
 *   retorno: vetor de listas com a imagem escolhida
 */
Pixel* *read_file(int index);

#endif /*LER_H*/
