#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO 10

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = 3; // Navio horizontal
        } else if (direcao == 'V') {
            tabuleiro[linha + i][coluna] = 3; // Navio vertical
        }
    }
}

// Função para sobrepor uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int origemLinha, int origemColuna, int habilidade[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (habilidade[i][j] == 1) {
                tabuleiro[origemLinha + i][origemColuna + j] = 5; // 5 representa área afetada
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    posicionarNavio(tabuleiro, 2, 2, 3, 'H'); // Navio horizontal
    posicionarNavio(tabuleiro, 5, 5, 3, 'V'); // Navio vertical

    // Definição das habilidades
    int cone[TAMANHO][TAMANHO] = {0};
    int cruz[TAMANHO][TAMANHO] = {0};
    int octaedro[TAMANHO][TAMANHO] = {0};

    // Criar efeito Cone
    cone[0][2] = 1;
    cone[1][1] = cone[1][2] = cone[1][3] = 1;
    cone[2][0] = cone[2][1] = cone[2][2] = cone[2][3] = cone[2][4] = 1;

    // Criar efeito Cruz
    cruz[1][2] = cruz[2][1] = cruz[2][2] = cruz[2][3] = cruz[3][2] = 1;

    // Criar efeito Octaedro
    octaedro[1][2] = octaedro[2][1] = octaedro[2][2] = octaedro[2][3] = octaedro[3][2] = 1;

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, 3, 3, cone);
    aplicarHabilidade(tabuleiro, 6, 6, cruz);
    aplicarHabilidade(tabuleiro, 7, 7, octaedro);

    // Exibir tabuleiro final
    printf("Tabuleiro final:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
