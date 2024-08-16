#include <stdio.h>
#include <stdlib.h>
#include "BMH.h"
#include "ShiftAndExato.h"
#include "tempo.h"
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Uso: %s <input_file> <output_file> <selecao>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    char *selecao = argv[3];

    if (strcmp(selecao, "B") == 0) {
        leituraBMH(input_file, output_file);
    }
    else if (strcmp(selecao, "S") == 0) {
        leituraShiftAnd(input_file, output_file);
    }
    else {
        fprintf(stderr, "Seleção inválida. Use 'B' ou 'S'.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    return 0;
}
