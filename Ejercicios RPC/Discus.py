def puntuacion_maxima_discos(n, m, cuadrados):
    # Inicializamos la puntuación máxima como negativo infinito
    max_score = float('-inf')
    
    # Mantenemos el mejor puntaje alcanzable desde cada posición
    mejor_puntuacion = [0] * n

    def actualizar_mejor_puntuacion(i):
        puntuacion_inicio = cuadrados[i]
        for j in range(1, m + 1):
            if i + j < n:
                puntuacion = cuadrados[i + j] - puntuacion_inicio
                mejor_puntuacion[i + j] = max(mejor_puntuacion[i + j], puntuacion)
        return max(mejor_puntuacion[i], max_score)

    # Usamos map() para aplicar la función a cada índice
    max_score = max(map(actualizar_mejor_puntuacion, range(n)))

    return max_score

# Lectura de entrada
n, m = map(int, input().split())
cuadrados = list(map(int, input().split()))

# Cálculo de la puntuación máxima
resultado = puntuacion_maxima_discos(n, m, cuadrados)

# Salida del resultado
print(resultado)
