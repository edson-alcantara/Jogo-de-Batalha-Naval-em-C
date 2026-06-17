#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Matriz que representa o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Vetores que representam os navios
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaH = 2, colunaH = 1; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical

    int i, j;

    // Inicializa todo o tabuleiro com água (0)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==========================
    // Validação do navio horizontal
    // ==========================
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // ==========================
    // Validação do navio vertical
    // ==========================
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verifica sobreposição antes de posicionar
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] == 3) {
            printf("Erro: Sobreposicao de navios detectada.\n");
            return 1;
        }
    }

    // Posiciona o navio vertical
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // ==========================
    // Exibição do tabuleiro
    // ==========================
    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}