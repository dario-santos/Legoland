#include "ler.h"

Pixel** read_file(int index)
{
    char c[50];
    int lin, col, canais;
    int r = 0, g = 0, b = 0;
    int i = 0, j = 0;
    int n = 0;
    Pixel* *L = NULL;

    FILE *f = fopen("imgs.txt", "r");
    if(f == NULL)
    {
        printf("\n\n\nErro: O ficheiro nao existe\n\n\n");
        return 0;
    }

    while(fgets(c, 50, (FILE*) f))
    {
        //Conta em que imagem vamos
        if(c[0] == 'I')
            n++;

        //Se for a imgem que queremos guardamos
        if(n == index && c[0] == 'I')
        {
            fscanf(f,"%d %d %d", &lin, &col, &canais);
            L = make_vector(lin);

            for(i = 0 ; i < lin ; i++)
            {
                for(j = 0 ; j < col ; j++)
                {
                    fscanf(f, "%d %d %d", &r, &g, &b);
                    L[i] = insert_last(L[i], make_pixel(j, r, g, b));

                }
            }
        }
    }

    fclose(f);
    if(f != NULL)
        free(f);

    return L;
}
