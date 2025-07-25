#include <stdio.h>

// Desafio Batalha Naval - MateCheck
#define TAM 10           // Tamanho do tabuleiro
#define NAVIO_TAM 3      // Tamanho dos navios
#define VALOR_NAVIO 3    // Valor para representar um navio
#define VALOR_HABILIDADE 5 // Valor para área afetada pela habilidade

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int origemLinha, int origemColuna) {
    int tamanho = 5;
    int meio = tamanho / 2;

    for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
    if (habilidade[i][j] == 1) {
    int linhaTab = origemLinha + (i - meio);
    int colunaTab = origemColuna + (j - meio);
    }
    
    // Verifica se está dentro dos limites do tabuleiro
    
    if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
    if (tabuleiro[linhaTab][colunaTab] == 0) {
    tabuleiro[linhaTab][colunaTab] = VALOR_HABILIDADE;
    }
    }
    }
    }

int main() {
    
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define posições dos navios
    int linhaH = 2, colunaH = 4;
    int linhaV = 6, colunaV = 7;

    if (colunaH + NAVIO_TAM <= TAM && linhaV + NAVIO_TAM <= TAM) {
        // Navio horizontal
        for (int i = 0; i < NAVIO_TAM; i++) {
            tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
        }

        // Navio vertical
        for (int i = 0; i < NAVIO_TAM; i++) {
            tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
        }
    } else {
        printf("Erro: os navios não cabem no tabuleiro.\n");
        return 1;
    }

    // Matriz de habilidade - Cone
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Matriz de habilidade - Cruz
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // Matriz de habilidade - Octaedro
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 1);       // Ponto de origem para cone
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Ponto de origem para cruz
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);   // Ponto de origem para octaedro

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
