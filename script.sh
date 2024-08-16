#!/bin/bash

# Defina o caminho para o executável do seu código C
EXECUTAVEL="./tp3"

# Caminho para a pasta de entradas
PASTA_ENTRADAS="./gerador"

# Itere sobre as 100 entradas
for i in $(seq 1 100); do
    # Defina o nome do arquivo de entrada na pasta "gerador"
    INPUT="$PASTA_ENTRADAS/entrada${i}.txt"
    
    # Execute o programa com o algoritmo B
    $EXECUTAVEL "$INPUT" /dev/null "B"
    
    # Execute o programa com o algoritmo S
    $EXECUTAVEL "$INPUT" /dev/null "S"
done
