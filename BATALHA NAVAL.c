#include <stdio.h>

int main(){
    //tabuleiro
    int tabuleiro [10] [10];

    //agua
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i] [j] = 0;
        }    
    }

    //navios
    int navioH [3] = {3, 3, 3};
    int navioV [3] = {3, 3, 3};
    int navioD1 [3] = {3, 3, 3};
    int navioD2 [3] = {3, 3, 3};

    //posicao inicial
    int linhaH = 3;
    int colunaH = 4;

    int linhaV = 5;
    int colunaV = 8;

    int linhaD1 = 1;
    int colunaD1 = 0;

    int linhaD2 = 4;
    int colunaD2 = 7;


    //navio horizoltal
    for (int i = 0; i < 3; i++)
    {
        tabuleiro [linhaH] [colunaH + i] = navioH [i];
    }

    //navio vertical
    for (int i = 0; i < 3; i++)
    {
        tabuleiro [linhaV + i] [colunaV] = navioV [i];
    }

    //navio diagonal 1
    for (int i = 0; i < 3; i++){
        if (linhaD1 + i < 10 && colunaD1 + i < 10 && tabuleiro[linhaD1 + i][colunaD1 + i] == 0){
            tabuleiro[linhaD1 + i] [colunaD1 + i] = navioD1[i];
        }
    }
    
    //navio diagonal 2
    for (int i = 0; i < 3; i++){
        if (linhaD2 + i < 10 && colunaD2 - i >= 0 && tabuleiro[linhaD2 + i][colunaD2 - i] == 0){
            tabuleiro[linhaD2 + i] [colunaD2 - i] = navioD2[i];
        } 
    }


    //menu de escolha
    int escolha;
    printf("escolha uma habilidade para utilizar:\n");
    printf("1 - cone\n");
    printf("2 - cruz\n");
    printf("3 - octaedro\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    printf("\n");

    //habilidades
    int cone[5] [5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5] [5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1 ,1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

     int octaedro[5] [5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    //escolha da habilidade: cone, cruz, octaedro
    int habilidade[5] [5];

   if (escolha == 1){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                habilidade[i] [j] = cone[i] [j];
            }
        }
    }
    else if (escolha == 2){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                habilidade[i] [j] = cruz[i] [j];
            }
        }
    }
    else if (escolha == 3){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                habilidade[i] [j] = octaedro[i] [j];
            }
        }
    } else {
        printf("Opcao invalida!\n");
    }
    
    //habilidade no tabuleiro
    int origemLinha = 5;
    int origemColuna = 5;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int linha = origemLinha - 2 + i; // centraliza a matriz na origem
            int coluna = origemColuna - 2 + j;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10){
                if (habilidade[i] [j] == 1 && tabuleiro[linha] [coluna] == 0){
                    tabuleiro[linha] [coluna] = 5; // marca área 
                }
            }
        }
    }

    printf("TABULEIRO BATALHA NAVAL\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d  ", tabuleiro [i] [j]);
        }
        printf("\n");
    }
    

    return 0;
}