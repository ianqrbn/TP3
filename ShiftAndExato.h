#ifndef ShiftAndExato_H
#define ShiftAndExato_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include <stdbool.h>

void preprocessamento(char *padrao, int m, uint64_t **M, int numPalavras);
bool ShiftAnd(char *texto, int n, char *padrao, int m, int inicioQuery, int fimQuery);
void leituraShiftAnd(FILE *nomearqEntrada, FILE *nomearqSaida);

#endif