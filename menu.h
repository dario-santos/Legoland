#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include "pixel.h"
#include "pesquisa.h"
#include "ler.h"

/*
 * Função show_menu()
 * ----------------------------
 *   mostra o menu
 *
 *   retorno: opcao escolhida
 */
int show_menu();

/*
 * Função handle_menu()
 * ----------------------------
 *   trata o input da funcao show_menu()
 *
 */
void handle_menu();

/*
 * Função read_submenu()
 * ----------------------------
 *   submenu da secao de leitura do ficheiro
 *
 *   retorno: vetor de listas que representa a imagem
 */
Pixel* *read_submenu();

/*
 * Função search_submenu(Pixel* *L)
 * ----------------------------
 *   L: vetor de listas que representa a imagem em que vamos pesquisar
 *
 */
void search_submenu(Pixel* *L);

#endif /*MENU_H*/
