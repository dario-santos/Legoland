#include "menu.h"

void handle_menu()
{
    int escolhido = 0;
    do{
        escolhido = show_menu();
        switch(escolhido)
        {
            case 0:
                break;
            case 1:
                search_menu();
                break;
            default:
                printf("\n\n\nOpcao invalida\n\n\n");
                break;
        }
    }while(escolhido != 0);
}

int show_menu()
{
    int escolhido = 0;
    printf("1 - Pesquisar por regioes (BLOBs)\n\n");
    printf("0 - Sair\n\n");

    printf("Inserido: ");
    scanf("%d", &escolhido);

    return escolhido;
}

void search_menu()
{
    FILE* F = NULL;
    Zone* Z = NULL;
    Pixel* *L = NULL;
    int r = 0, g = 0, b = 0, d = 0;
    int i = 1;

    search_input(&r, &g, &b, &d);

    F = open_file("imgs.txt");

    do{
        L = read_file(F);
        Z = search_zones(L, r, g, b, d);

        if(Z != NULL)
        {
            printf("Zonas da imagem %d\n", i);
            print_zones(Z);
            free_zones(Z);
        }

        if(L != NULL)
            free_image(L);

        i++;
    }while(L != NULL);

    close_file(F);
}

void search_input(int *r, int *g, int *b, int *d)
{
    printf("Vai inserir a cor a procurar no formato RGB agora\n");
    do{
        printf("R:");
        scanf("%d", r);
    }while(*r < 0 || *r > 255);
    do{
        printf("G:");
        scanf("%d", g);
    }while(*g < 0 || *g > 255);
    do{
        printf("B:");
        scanf("%d", b);
    }while(*b < 0 || *b > 255);
    do{
        printf("Tolerancia:");
        scanf("%d", d);
    }while(*d < 0 || *d > 255);
}
