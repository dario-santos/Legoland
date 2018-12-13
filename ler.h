#ifndef LER_H
#define LER_H
#include <stdlib.h>
#include <stdio.h>
#include "pixel.h"

/*
 * Fun��o ler_ficheiro
 * ----------------------------
 *   index: n�mero inteiro que simboliza a imagem que queremos
 *
 *   retorno: endere�o de mem�ria do vetor com as linhas da imagem
 */
Pixel** ler_ficheiro(int index);

#endif /*LER_H*/
