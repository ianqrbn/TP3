#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include <stdbool.h>
#include "tempo.h"

#define BITS_POR_PALAVRA 64  // Número de bits em um uint64_t

// Função para criar as máscaras para cada caractere do padrão
void preprocessamento(char *padrao, int m, uint64_t **M, int numPalavras) {
    for (int i = 0; i < 256; i++) { // Até 256 caracteres ASCII
        for (int j = 0; j < numPalavras; j++) {
            M[i][j] = 0;
        }
    }

    for (int j = 0; j < m; j++) {
        M[(unsigned char)padrao[j]][j / BITS_POR_PALAVRA] |= (1ULL << (j % BITS_POR_PALAVRA)); 
    }
}

bool ShiftAnd(char *texto, int n, char *padrao, int m, int inicioQuery, int fimQuery) {
    if (m > n) {
        printf("Tamanho de padrão maior que o texto.\n");
        return false;
    }

    // Calcula o número de palavras (64 bits) necessárias para armazenar o padrão
    int numPalavras = (m + BITS_POR_PALAVRA - 1) / BITS_POR_PALAVRA;

    // Aloca memória para as máscaras
    uint64_t **M = (uint64_t **)malloc(256 * sizeof(uint64_t *));
    for (int i = 0; i < 256; i++) {
        M[i] = (uint64_t *)malloc(numPalavras * sizeof(uint64_t));
    }

    preprocessamento(padrao, m, M, numPalavras);

    // Aloca e inicializa o vetor de estados
    uint64_t *R = (uint64_t *)malloc(numPalavras * sizeof(uint64_t));
    for (int i = 0; i < numPalavras; i++) {
        R[i] = 0;
    }

    // Pesquisa
    for (int i = inicioQuery; i < fimQuery; i++) {
        uint64_t carry = 1ULL; // variável de 64 bits com valor 1

        for (int j = 0; j < numPalavras; j++) {
            uint64_t novoR = ((R[j] << 1) | carry) & M[(unsigned char)texto[i]][j];
            carry = (R[j] >> (BITS_POR_PALAVRA - 1)) & 1ULL;
            R[j] = novoR;

            // Verifica o bit relevante do último bloco
            if (j == numPalavras - 1 && (R[j] & (1ULL << ((m - 1) % BITS_POR_PALAVRA)))) {
                for (int k = 0; k < 256; k++) {
                    free(M[k]);
                }
                free(M);
                free(R);
                return 1;  // Casamento encontrado
        }
    }
    }

    // Limpeza de memória
    for (int i = 0; i < 256; i++) {
        free(M[i]);
    }
    free(M);
    free(R);

    return 0;  // Nenhum casamento encontrado
}

void leituraShiftAnd(FILE *nomearqEntrada, FILE *nomearqSaida)
{
    char *texto = NULL;
    char *padrao = NULL;
    size_t tamanho = 0; 
    int k, inicioQuery, fimQuery, casou;
    FILE *fp = fopen("grafico2.txt", "a");

    getline(&texto, &tamanho, nomearqEntrada);
    texto[strlen(texto) - 1] = '\0'; 

    getline(&padrao, &tamanho, nomearqEntrada);
    padrao[strlen(padrao) - 1] = '\0';

    fscanf(nomearqEntrada, "%d", &k);

    for (int i = 0; i < k; i++)
    {
        fscanf(nomearqEntrada, "%d %d", &inicioQuery, &fimQuery);

        tempo tempoInicio = tempoAtual();
        casou = ShiftAnd(texto, strlen(texto), padrao, strlen(padrao), inicioQuery-1, fimQuery);
        tempo tempoFinal = tempoAtual();

        if (casou)
        {
            fprintf(nomearqSaida, "Sim\n");
        }
        else
        {
            fprintf(nomearqSaida, "Não\n");
        }  
        
        imprimeTempos(tempoInicio, tempoFinal, fp);

    }

    free(texto);
    free(padrao);

    fclose(nomearqEntrada);
    fclose(nomearqSaida);
    fclose(fp);
}

