#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>

#include "pixel.h"
#include "zone.h"
#include "ler.h"
#include "pesquisa.h"

/*
 * Função handle_menu()
 * ----------------------------
 */
void handle_menu();

/*
 * Função show_menu()
 * ----------------------------
 *   retorno: opcao escolhida
 */
int show_menu();

/*
 * Função search_menu()
 * ----------------------------
 */
void search_menu();


void filename_input(char *path);
/*
 * Função search_input(int *r, int *g, int *b, int *d)
 * ----------------------------
 *   r: endereco de uma variavel para guardar o codigo do vermelho do pixel
 *   g: endereco de uma variavel para guardar o codigo do verde do pixel
 *   b: endereco de uma variavel para guardar o codigo do azul do pixel
 *   d: endereco de uma variavel para guardar a tolerancia
 */
void search_input(int *r, int *g, int *b, int *d);

#endif /*MENU_H*/
