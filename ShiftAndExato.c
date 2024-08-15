#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256 // Número máximo de caracteres ASCII

int ShiftAnd(char *padrao, char *texto, int inicioQuery, int fimQuery) {
    int m = strlen(padrao);
    unsigned int M[MAX] = {0};
    unsigned int R = 0;
    int i, j;

    // Pre-processamento
    for (j = 0; j < m; j++) {
        M[(unsigned char)padrao[j]] |= 1 << (m - j - 1); // Cria uma mascara para cada elemento do alfabeto relativo à posição no padrão
    }

    // Pesquisa
    for (i = inicioQuery; i <= fimQuery; i++) {
        R = ((R >> 1) | (1 << (m - 1))) & M[(unsigned char)texto[i]]; // Desloca à direita, seta o bit mais significativo como 1 e filtra o vetor R com a Mascara
        if (R & 1) { // Verifica o bit menos significativo
            return 1; // Casamento encontrado
        }
    }

    return 0; // Nenhum casamento encontrado
}

void leitura(FILE *nomearq) {
    char texto[MAX];
    char padrao[MAX];
    int k, inicioQuery, fimQuery;

    fscanf(nomearq, "%s", texto);
    fscanf(nomearq, "%s", padrao);
    fscanf(nomearq, "%d", &k);

    for (int i = 0; i < k; i++) {
        fscanf(nomearq, "%d %d", &inicioQuery, &fimQuery);
        if (ShiftAnd(padrao, texto, inicioQuery - 1, fimQuery - 1)) {
            printf("Sim\n");
        } else {
            printf("Não\n");
        }
    }

    fclose(nomearq);
}