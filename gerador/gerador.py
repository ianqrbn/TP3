import random
import string

def gerar_string_aleatoria(n):
    caracteres = string.ascii_letters + string.digits
    string_aleatoria = ''.join(random.choice(caracteres) for _ in range(n))
    return string_aleatoria

def escrever_string_no_arquivo(nome_arquivo, conteudo, n):
    with open(nome_arquivo, 'w') as arquivo:
        arquivo.write(conteudo + '\n')
        
        # Seleciona uma parte aleatória da string original
        inicio = random.randint(0, n - 1)
        comprimento = random.randint(1, n - inicio)
        substring_aleatoria = conteudo[inicio:inicio + comprimento]
        arquivo.write(substring_aleatoria + '\n')
        
        arquivo.write("1\n")
        arquivo.write(f"1 {n}\n")

# Gerar e salvar 100 arquivos com strings de tamanho crescente
for i in range(1, 101):
    n = i * 10000  # Define o tamanho da string para cada arquivo
    string_aleatoria = gerar_string_aleatoria(n)
    
    # Nome do arquivo com o índice
    nome_arquivo = f"entrada{i}.txt"
    
    # Escrever a string e a substring aleatória no arquivo
    escrever_string_no_arquivo(nome_arquivo, string_aleatoria, n)
    print(f"A string foi escrita em {nome_arquivo} com {n} caracteres")
