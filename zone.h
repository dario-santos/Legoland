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

Zone* make_zone(int c, int r, int sz);

Zone* insert_order(Zone *Z, Zone *new_zone);

void free_zones(Zone *Z);
#endif /*ZONE_H*/
