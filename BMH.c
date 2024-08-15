#include <stdio.h>
#include <stdlib.h>

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

    // Preenche a tabela de deslocamento com os valores apropriados
    for (i = 0; i < m - 1; i++)
    {
        tabelaDeslocamento[(unsigned char)padrao[i]] = m - i - 1;
    }
}

int BMH(char *texto, char *padrao, int i, int n)
{
    int m = strlen(padrao);
    int tabelaDeslocamento[MAX];
    int i, j;

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

void leitura(FILE *nomearq)
{
    char texto[MAX];
    char padrao[MAX];
    int k, a, b;

    fscanf(nomearq, "%s", texto);
    fscanf(nomearq, "%s", padrao);
    fscanf(nomearq, "%d", &k);

    for (int i = 0; i < k; i++)
    {
        fscanf(nomearq, "%d %d", &a, &b);
        if (BMH(texto, padrao, a - 1, b - 1))
        {
            printf("Sim\n");
        }
        else
        {
            printf("Não\n");
        }
    }
    fclose(nomearq);

    return 0;
}
