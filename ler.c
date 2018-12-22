#include "ler.h"

FILE* open_file(char* path)
{
    FILE *F = fopen(path, "r");
    if(F == NULL)
    {
        printf("\n\n\nErro: O ficheiro nao existe\n\n\n");
        return NULL;
    }
    return F;
}

void close_file(FILE *F)
{
    if(F == NULL)
        return;

    fclose(F);
    if(F != NULL)
        free(F);
}

Pixel** read_file(FILE* F)
{
    char c[50];
    int lin, col, canais;
    int r = 0, g = 0, b = 0;
    int i = 0, j = 0;
    Pixel* *L = NULL;

    if(F == NULL)
        return NULL;

    while(fgets(c, 50, (FILE*) F))
        if(c[0] == 'I')
            break;

    //Se for a imgem que queremos guardamos
    if(c[0] == 'I')
    {
        fscanf(F,"%d %d %d", &lin, &col, &canais);
        L = make_vector(lin);

        for(i = 0 ; i < lin ; i++)
        {
            for(j = 0 ; j < col ; j++)
            {
                fscanf(F, "%d %d %d", &r, &g, &b);
                L[i] = insert_last(L[i], make_pixel(j, r, g, b));
            }
        }
    }
    return L;
}
