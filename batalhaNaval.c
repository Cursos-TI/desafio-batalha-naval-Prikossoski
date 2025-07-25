#include <stdio.h>

// Desafio Batalha Naval - MateCheck
#define NAVIO_10 3
#define VALOR_NAVIO 1

void exibirTabuleiro(int tabuleiro[10][10]) {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

    printf("   ");
    for (int j = 0; j < 10; j++) {
    printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
    printf("%2c ", linha[i]);
    for (int j = 0; j < 10; j++) {
     if (tabuleiro[i][j] == VALOR_NAVIO)
      printf(" 3 ");  // Navio
      else
      printf(" ~ ");  // Água
     }
    printf("\n");
    }
    }

     int main() {

      int tabuleiro[10][10];

        // Inicializa o tabuleiro com água (0)

        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
        }

        // Posições iniciais dos navios
       int linhaH = 2, colunaH = 4;  // horizontal
       int linhaV = 6, colunaV = 7;  // vertical
       int linhaD1 = 0, colunaD1 = 0; // diagonal principal
       int linhaD2 = 0, colunaD2 = 7; // diagonal secundária

       // Verificações para garantir que os navios cabem no tabuleiro
       if (
        colunaH + NAVIO_10 <= 10 &&
        linhaV + NAVIO_10 <= 10 &&
        linhaD1 + NAVIO_10 <= 10 && colunaD1 + NAVIO_10 <= 10 &&
        linhaD2 + NAVIO_10 <= 10 && colunaD2 - (NAVIO_10 - 1) >= 0
        ) {
        // Navio horizontal
        for (int i = 0; i < NAVIO_10; i++) {
            tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
        }

        // Navio vertical
        for (int i = 0; i < NAVIO_10; i++) {
            tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
        }

        // Navio diagonal principal (↘)
        for (int i = 0; i < NAVIO_10; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = VALOR_NAVIO;
        }

        // Navio diagonal secundária (↙)
        for (int i = 0; i < NAVIO_10; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = VALOR_NAVIO;
        }

        // Exibe o tabuleiro final com os 4 navios
        exibirTabuleiro(tabuleiro);

       } else {
        printf("Erro: Um ou mais navios não cabem no tabuleiro.\n");
        return 1;
       }

    return 0;
     }