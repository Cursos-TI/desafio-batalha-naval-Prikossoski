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
                printf("🚢 ");
            else
                printf("🌊 ");
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

    // Define posições dos navios
    int linhaH = 2, colunaH = 4;
    int linhaV = 6, colunaV = 7;

    if (colunaH + NAVIO_10 <= 10 && linhaV + NAVIO_10 <= 10) {
        // Navio horizontal
        for (int i = 0; i < NAVIO_10; i++) {
            tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
        }

        // Navio vertical
        for (int i = 0; i < NAVIO_10; i++) {
            tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
        }
        } else {
        printf("Erro: os navios não cabem no tabuleiro.\n");
        return 1;
        }

        // Exibe o tabuleiro com navios posicionados
         exibirTabuleiro(tabuleiro);

        return 0;
        }
