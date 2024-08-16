import matplotlib.pyplot as plt

# Valores de grafico.txt
dados1 = [
    0.000009, 0.000007, 0.000007, 0.000022, 0.000034, 0.000134, 0.000147, 0.000027, 0.000370, 0.000105, 
    0.000848, 0.000030, 0.000041, 0.000006, 0.000120, 0.000246, 0.000336, 0.000324, 0.000483, 0.000078, 
    0.000224, 0.000415, 0.000030, 0.000161, 0.000243, 0.000235, 0.000306, 0.000237, 0.000105, 0.000430, 
    0.000205, 0.000026, 0.000873, 0.000151, 0.000921, 0.000508, 0.000243, 0.000318, 0.000267, 0.000115, 
    0.000387, 0.000709, 0.000193, 0.000272, 0.000798, 0.000116, 0.000588, 0.000080, 0.000069, 0.000239, 
    0.000770, 0.000423, 0.000672, 0.000366, 0.000383, 0.000274, 0.000684, 0.001734, 0.000562, 0.001076, 
    0.000401, 0.000180, 0.000258, 0.000829, 0.000180, 0.000256, 0.000831, 0.000346, 0.000112, 0.000267, 
    0.002284, 0.001547, 0.000243, 0.002215, 0.000283, 0.000401, 0.000706, 0.000638, 0.002303, 0.001553, 
    0.001836, 0.001344, 0.000399, 0.002375, 0.000914, 0.001686, 0.000589, 0.000133, 0.000085, 0.000448, 
    0.001349, 0.000984, 0.000213, 0.001370, 0.002046, 0.000531, 0.000970, 0.002081, 0.002889, 0.003388, 
    0.001634, 0.001240, 0.001362
]

# Valores de grafico2.txt
dados2 = [
    0.002021, 0.006361, 0.045495, 0.050639, 0.000585, 0.183576, 0.057609, 0.504753, 0.014559, 0.029749, 
    0.000847, 0.071663, 0.385727, 0.746189, 0.587867, 1.286063, 0.044505, 0.213128, 0.293015, 0.029987, 
    0.455307, 0.851622, 0.428548, 0.613201, 0.567107, 0.397819, 1.025152, 0.736465, 0.021500, 3.409007, 
    0.599652, 3.674523, 2.440974, 1.035749, 1.544749, 0.751724, 0.547604, 1.749573, 4.084276, 0.858648, 
    0.934853, 4.920263, 0.407337, 3.779102, 0.369040, 0.046546, 1.160720, 4.382539, 2.510040, 1.372432, 
    1.549361, 2.282876, 1.696589, 4.337068, 15.336762, 1.551457, 8.083272, 2.713238, 0.123266, 1.066430, 
    7.105220, 1.128524, 1.487070, 5.188686, 2.111955, 0.143469, 1.927499, 14.474374, 15.315893, 1.557681, 
    24.084544, 2.174734, 4.254463, 6.255297, 4.939267, 27.131963, 11.901216, 22.994586, 9.243121, 4.143611, 
    21.591205, 10.301367, 13.821838, 6.736253, 0.708157, 0.225066, 0.866055, 15.867895, 7.159844, 1.877825, 
    9.589682, 31.435821, 5.981267, 4.030407, 20.078518, 45.795524, 47.504256, 10.319604, 15.811372, 18.123322
]

# Criando o eixo x para os tamanhos de entrada, de 10.000 até 1.000.000
entradas = list(range(10000, 1000001, 10000))

# Ajustando o comprimento para o menor tamanho entre entradas, dados1 e dados2
min_length = min(len(entradas), len(dados1), len(dados2))

entradas_truncadas = entradas[:min_length]
dados1_truncados = dados1[:min_length]
dados2_truncados = dados2[:min_length]

# Plotando os dados ajustados
plt.figure(figsize=(10, 6))
plt.plot(entradas_truncadas, dados1_truncados, label='BMH', marker='o')
plt.plot(entradas_truncadas, dados2_truncados, label='Shift-And', marker='o')

# Adicionando títulos e legendas
plt.xlabel('Tamanho da Entrada')
plt.ylabel('Tempo de Relógio (segundos)')
plt.title('Comparação de Tempo de Relógio entre Algoritmos')
plt.legend()

# Exibindo o gráfico
plt.grid(True)
plt.show()
