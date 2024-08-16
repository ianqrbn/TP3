#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tempo.h"
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
    int copiaJ = 0;

    preProcessamento(padrao, m, tabelaDeslocamento);

    while (i <= n - m) // i = onde começa a query e n = onde termina a query
    {
        j = m - 1;
        copiaJ = j;
        // Comparação a sequencia dee caracteres da direita para a esquerda
        while (j >= 0 && padrao[j] == texto[i + j])
        {
            j--;
        }

        if (j < 0)
        {
            return 1; // Se o padrão foi encontrado
        }
        else
        {
            // Desloca o padrão para a direita
            i += tabelaDeslocamento[(unsigned char)texto[i + copiaJ]];
        }
    }

    return 0; // padrao não foi encontrado
}

void leituraBMH(FILE *nomearqEntrada, FILE *nomearqSaida)
{
    char *texto = NULL;
    char *padrao = NULL;
    size_t tamanho = 0;
    int k, inicioQuery, fimQuery, casou;

    FILE *fp = fopen("grafico.txt", "a");

    getline(&texto, &tamanho, nomearqEntrada);
    texto[strlen(texto) - 1] = '\0';

    getline(&padrao, &tamanho, nomearqEntrada);
    padrao[strlen(padrao) - 1] = '\0';

    fscanf(nomearqEntrada, "%d", &k);

    for (int i = 0; i < k; i++)
    {
        fscanf(nomearqEntrada, "%d %d", &inicioQuery, &fimQuery);

        tempo tempoInicio = tempoAtual();
        casou = BMH(texto, padrao, inicioQuery - 1, fimQuery);
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
