#ifndef MENU_H
#define MENU_H

#include "pixel.h"
#include "pesquisa.h"
#include "ler.h"

int show_menu();

void handle_menu();

Pixel** read_submenu();

void seach_submenu(Pixel** L);

#endif /*MENU_H*/
