#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include "pixel.h"
#include "pesquisa.h"
#include "ler.h"

/*
 * Fun��o show_menu()
 * ----------------------------
 *   mostra o menu
 *
 *   retorno: opcao escolhida
 */
int show_menu();

/*
 * Fun��o handle_menu()
 * ----------------------------
 *   trata o input da funcao show_menu()
 *
 */
void handle_menu();

/*
 * Fun��o read_submenu()
 * ----------------------------
 *   submenu da secao de leitura do ficheiro
 *
 *   retorno: vetor de listas que representa a imagem
 */
Pixel* *read_submenu();

/*
 * Fun��o search_submenu(Pixel* *L)
 * ----------------------------
 *   L: vetor de listas que representa a imagem em que vamos pesquisar
 *
 */
void search_submenu(Pixel* *L);

#endif /*MENU_H*/
