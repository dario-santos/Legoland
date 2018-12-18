#include "menu.h"

int show_menu()
{
    int escolhido = 0;
    printf("1 - Carregar ficheiro\n");
    printf("2 - Pesquisar por regioes (BLOBs)\n\n");

    printf("0 - Sair\n\n");

    printf("Inserido: ");
    scanf("%d", &escolhido);

    return escolhido;
}

void handle_menu()
{
    Pixel* *L = NULL;
    int input = 0;
    do{
        input = show_menu();
        switch(input)
        {
            case 0:
                free_image(L);
                break;

            case 1:
                free_image(L);
                L = read_submenu();
                break;

            case 2:
                search_submenu(L);
                break;

            default:
                printf("\n\nErro: opcao invalida, introduza uma opcao valida\n\n");
                break;
        }

    }while(input != 0);
    //Limpar cada um dos elementos de L;
}

Pixel* *read_submenu()
{
    int index = 0;
    do{
        printf("\nInsira o index da imagem a carregar do ficheiro (1 -> primeira imagem, 2 -> segunda, 3 -> terceira)\n");
        printf("Inserido: ");

        scanf("%d", &index);
    }while(index <= 0 || index > 3);

    return read_file(index);
}

void search_submenu(Pixel* *L)
{
    int r, g, b, d;
    printf("Vai inserir a cor a procurar no formato RGB agora\n");
    do{
        printf("R:");
        scanf("%d", &r);
    }while(r < 0 || r > 255);
    do{
        printf("G:");
        scanf("%d", &g);
    }while(g < 0 || g > 255);
    do{
        printf("B:");
        scanf("%d", &b);
    }while(b < 0 || b > 255);
    do{
        printf("Tolerancia:");
        scanf("%d", &d);
    }while(d < 0 || d > 255);

    Zone *Z = search_zones(L, r, g, b, d);

    print_zones(Z);
    if(Z != NULL)
        free_zones(Z);

}

void free_image(Pixel* *L)
{
    if(L != NULL)
    {
        int i = 0;
        for(i = 1079 ; i >= 0 ; i--)
            free_list(L[i]);
        free(L);
    }
}
