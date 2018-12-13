#include "menu.h"

int menu()
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
    Pixel** L = NULL;
    int escolhido = 0;
    do{

        escolhido = menu();
        switch(escolhido)
        {
            case 0:
                break;

            case 1:
                L = read_submenu();
                break;

            case 2:
                pesquisar(L,100,0,0,10);
                break;

            default:
                printf("\n\nErro: opcao invalida, escolha de novo\n\n");
                break;
        }

    }while(escolhido != 0);
    //Limpar cada um dos elementos de L;
}

Pixel** read_submenu()
{
    int index = 0;
    do{
        printf("\nInsira a imagem que quer do ficheiro (1 -> primeira imagem, 2 -> segunda ect.)\n");
        printf("Inserido: ");

        scanf("%d", &index);

    }while(index <= 0);

    return ler_ficheiro(index);
}

