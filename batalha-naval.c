#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Matriz que representa o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ==================================================
    // Coordenadas iniciais dos quatro navios
    // ==================================================

    // Navio horizontal
    int linhaH = 1;
    int colunaH = 2;

    // Navio vertical
    int linhaV = 4;
    int colunaV = 0;

    // Navio diagonal principal (↘)
    int linhaDP = 0;
    int colunaDP = 6;

    // Navio diagonal secundária (↙)
    int linhaDS = 2;
    int colunaDS = 9;

    // ==================================================
    // Posicionamento do navio horizontal
    // ==================================================
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                printf("Erro: sobreposicao no navio horizontal.\n");
                return 1;
            }
        }

        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = NAVIO;
        }

    } else {
        printf("Erro: navio horizontal fora dos limites.\n");
        return 1;
    }

    // ==================================================
    // Posicionamento do navio vertical
    // ==================================================
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                printf("Erro: sobreposicao no navio vertical.\n");
                return 1;
            }
        }

        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = NAVIO;
        }

    } else {
        printf("Erro: navio vertical fora dos limites.\n");
        return 1;
    }

    // ==================================================
    // Posicionamento do navio diagonal principal (↘)
    // Linha e coluna aumentam juntas
    // ==================================================
    if (linhaDP + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaDP + TAM_NAVIO <= TAM_TABULEIRO) {

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaDP + i][colunaDP + i] != AGUA) {
                printf("Erro: sobreposicao na diagonal principal.\n");
                return 1;
            }
        }

        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaDP + i][colunaDP + i] = NAVIO;
        }

    } else {
        printf("Erro: diagonal principal fora dos limites.\n");
        return 1;
    }

    // ==================================================
    // Posicionamento do navio diagonal secundaria (↙)
    // Linha aumenta e coluna diminui
    // ==================================================
    if (linhaDS + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaDS - (TAM_NAVIO - 1) >= 0) {

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaDS + i][colunaDS - i] != AGUA) {
                printf("Erro: sobreposicao na diagonal secundaria.\n");
                return 1;
            }
        }

        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaDS + i][colunaDS - i] = NAVIO;
        }

    } else {
        printf("Erro: diagonal secundaria fora dos limites.\n");
        return 1;
    }

    // ==================================================
    // Exibição do tabuleiro
    // ==================================================

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}