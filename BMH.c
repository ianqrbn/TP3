#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BMH.h"

#define MAX 256 // Número máximo de caracteres ASCII

void preProcessamento(char *padrao, int m, int *tabelaDeslocamento)
{
    int i;

    // Inicializa todas as posições da tabela de deslocamento com o tamanho do padrão
    for (i = 0; i < MAX; i++)
    {
        tabelaDeslocamento[i] = m;
    }

    // Preenche a tabela de deslocamento com os valores de salto
    for (i = 0; i < m - 1; i++)
    {
        tabelaDeslocamento[(unsigned char)padrao[i]] = m - i - 1;
    }
}

int BMH(char *texto, char *padrao, int i, int n)
{
    int m = strlen(padrao);
    int tabelaDeslocamento[MAX];
    int j;

    preProcessamento(padrao, m, tabelaDeslocamento);

    while (i <= n - m) // i = onde começa a querie e n = onde termina a querie
    {
        j = m - 1;
        // Comparação a sequencia dee caracteres da direita para a esquerda
        while (j >= 0 && padrao[j] == texto[i + j])
        {
            j--;
        }

        // Se o padrão foi encontrado
        if (j < 0)
        {
            return 1;
        }
        else
        {
            // Desloca o padrão para a direita
            i += tabelaDeslocamento[(unsigned char)texto[i + j]];
        }
    }

    return 0; // padrao não foi encontrado
}

void leituraBMH(FILE *nomearqEntrada, FILE *nomearqSaida)
{
    char *texto = NULL;
    char *padrao = NULL;
    size_t tamanho = 0; // Tamanho do buffer
    int k, a, b;

    getline(&texto, &tamanho, nomearqEntrada);
    texto[strlen(texto) - 1] = '\0'; // Remove o carctere '\n' da string

    getline(&padrao, &tamanho, nomearqEntrada);
    padrao[strlen(padrao) - 1] = '\0';

    fscanf(nomearqEntrada, "%d", &k);

    for (int i = 0; i < k; i++)
    {
        fscanf(nomearqEntrada, "%d %d", &a, &b);
        if (BMH(texto, padrao, a - 1, b))
        {
            fprintf(nomearqSaida, "Sim\n");
        }
        else
        {
            fprintf(nomearqSaida, "Não\n");
        }
    }

    free(texto);
    free(padrao);

    fclose(nomearqEntrada);
    fclose(nomearqSaida);
}
