#include "zone.h"

Zone* make_zone(int c, int r, int sz)
{
    Zone *aux = (Zone*) malloc(sizeof(Zone));

    aux->r = r;
    aux->c = c;

    aux->sz = sz;

    aux->pnext = NULL;
    aux->pprev = NULL;

    return aux;
}

Zone* insert_zone_first(Zone *Z, Zone *new_zone)
{
    if(Z == NULL)
        return new_zone;

    new_zone->pnext = Z;
    Z->pprev = new_zone;

    return new_zone;
}

Zone* insert_zone_last(Zone *Z, Zone *new_zone)
{
    Zone *aux = Z;
    if(Z == NULL)
        return new_zone;

    while(aux != NULL)
    {
        if(aux->pnext == NULL)
        {
            aux->pnext = new_zone;
            new_zone->pprev = aux;
            break;
        }
        aux = aux->pnext;
    }
    return Z;
}

Zone* insert_order(Zone *Z, Zone *new_zone)
{
    Zone *aux = Z;

    //procuramos a posicao em que vamos colocar o elemento
    while(aux != NULL)
    {
        if(aux->sz < new_zone->sz)
            break;

        aux = aux->pnext;
    }

    if(aux == NULL)
        return insert_zone_last(Z, new_zone);

    if(aux->pprev == NULL)
        return insert_zone_first(Z, new_zone);

    new_zone->pnext = aux;
    new_zone->pprev= aux->pprev;
    (aux->pprev)->pnext = new_zone;
    aux->pprev = new_zone;

    return Z;
}

void print_zones(Zone *Z)
{
    Zone *aux = Z;

    while(aux != NULL)
    {
        printf("C(%d,%d) = %d\n", aux->c, aux->r, aux->sz);
        aux = aux->pnext;
    }
}
