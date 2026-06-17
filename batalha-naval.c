#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    int i, j;

    // =====================================================
    // Inicializa o tabuleiro com água
    // =====================================================
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // =====================================================
    // Posicionamento de 4 navios
    // =====================================================

    // Horizontal
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[1][2 + i] = NAVIO;
    }

    // Vertical
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[5 + i][1] = NAVIO;
    }

    // Diagonal principal
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[2 + i][6 + i] = NAVIO;
    }

    // Diagonal secundária
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[6 + i][8 - i] = NAVIO;
    }

    // =====================================================
    // Inicializa as matrizes de habilidades com 0
    // =====================================================
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // =====================================================
    // HABILIDADE CONE
    // Formato:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    // =====================================================
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {

            int centro = TAM_HABILIDADE / 2;

            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            }
        }
    }

    // =====================================================
    // HABILIDADE CRUZ
    // =====================================================
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {

            int centro = TAM_HABILIDADE / 2;

            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }

    // =====================================================
    // HABILIDADE OCTAEDRO (LOSANGO)
    // =====================================================
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {

            int centro = TAM_HABILIDADE / 2;

            if ((i - centro < 0 ? centro - i : i - centro) +
                (j - centro < 0 ? centro - j : j - centro)
                <= centro) {

                octaedro[i][j] = 1;
            }
        }
    }

    // =====================================================
    // Pontos de origem das habilidades
    // =====================================================
    int origemConeLinha = 2;
    int origemConeColuna = 2;

    int origemCruzLinha = 5;
    int origemCruzColuna = 5;

    int origemOctLinha = 7;
    int origemOctColuna = 3;

    // =====================================================
    // Sobreposição do CONE
    // =====================================================
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {

            if (cone[i][j] == 1) {

                int linhaTab =
                    origemConeLinha - (TAM_HABILIDADE / 2) + i;

                int colunaTab =
                    origemConeColuna - (TAM_HABILIDADE / 2) + j;

                if (linhaTab >= 0 &&
                    linhaTab < TAM_TABULEIRO &&
                    colunaTab >= 0 &&
                    colunaTab < TAM_TABULEIRO) {

                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }

    // =====================================================
    // Sobreposição da CRUZ
    // =====================================================
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {

            if (cruz[i][j] == 1) {

                int linhaTab =
                    origemCruzLinha - (TAM_HABILIDADE / 2) + i;

                int colunaTab =
                    origemCruzColuna - (TAM_HABILIDADE / 2) + j;

                if (linhaTab >= 0 &&
                    linhaTab < TAM_TABULEIRO &&
                    colunaTab >= 0 &&
                    colunaTab < TAM_TABULEIRO) {

                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }

    // =====================================================
    // Sobreposição do OCTAEDRO
    // =====================================================
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {

            if (octaedro[i][j] == 1) {

                int linhaTab =
                    origemOctLinha - (TAM_HABILIDADE / 2) + i;

                int colunaTab =
                    origemOctColuna - (TAM_HABILIDADE / 2) + j;

                if (linhaTab >= 0 &&
                    linhaTab < TAM_TABULEIRO &&
                    colunaTab >= 0 &&
                    colunaTab < TAM_TABULEIRO) {

                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }

    // =====================================================
    // Exibição do tabuleiro
    // =====================================================
    printf("\n===== BATALHA NAVAL =====\n\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {

        for (j = 0; j < TAM_TABULEIRO; j++) {

            if (tabuleiro[i][j] == AGUA)
                printf("~ ");

            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");

            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");
        }

        printf("\n");
    }

    return 0;
}