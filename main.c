#include <stdio.h>
#include <stdlib.h>
#include "BMH.h"
#include "tempo.h"

int main(int argc, char *argv[2])
{

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    leituraBMH(input_file, output_file);

    return 0;
}