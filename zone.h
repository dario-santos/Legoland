#ifndef ZONE_H
#define ZONE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct ZONE
{
    int c;
    int r;
    int sz;

    struct ZONE *pnext;
    struct ZONE *pprev;
}Zone;

/*
 * Fun��o make_zone(int c, int r, int sz)
 * ----------------------------
 *   c: ponto no eixo x
 *   r: ponto no eixo y
 *   sz(size): tamanho da zona (n� de pixeis)
 *
 *   retorno: elemento do tipo Zone com os dados passados
 */
Zone* make_zone(int c, int r, int sz);

/*
 * Fun��o insert_order(Zone *Z, Zone *new_zone)
 * ----------------------------
 *   Z: Lista de zonas
 *   new_zone: elemento do tipo Zone
 *
 *   retorno: Lista com o elemento introduzido na posicao correta
 */
Zone* insert_order(Zone *Z, Zone *new_zone);

/*
 * Fun��o insert_zone_last(Zone *Z, Zone *new_zone)
 * ----------------------------
 *   Z: Lista de zonas
 *   new_zone: elemento do tipo Zone
 *
 *   retorno: Lista com o elemento introduzido na ultima posicao
 */
Zone* insert_zone_last(Zone *Z, Zone *new_zone);

/*
 * Fun��o insert_zone_first(Zone *Z, Zone *new_zone)
 * ----------------------------
 *   Z: Lista de zonas
 *   new_zone: elemento do tipo Zone
 *
 *   retorno: Lista com o elemento introduzido na primeira posicao
 */
Zone* insert_zone_first(Zone *Z, Zone *new_zone);

/*
 * Fun��o print_zones(Zone *Z)
 * ----------------------------
 *   Z: Lista de zonas para imprimir no ecra
 *
 */
void print_zones(Zone *Z);

/*
 * Fun��o insert_order(Zone *Z, Zone *new_zone)
 * ----------------------------
 *   Z: Lista de zonas para libertar
 *
 */
void free_zones(Zone *Z);

#endif /*ZONE_H*/
