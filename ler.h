#ifndef LER_H
#define LER_H
#include <stdlib.h>
#include <stdio.h>
#include "pixel.h"

/*
 * Função ler_ficheiro
 * ----------------------------
 *   index: número inteiro que simboliza a imagem que queremos
 *
 *   retorno: endereço de memória do vetor com as linhas da imagem
 */
Pixel** ler_ficheiro(int index);

#endif /*LER_H*/
